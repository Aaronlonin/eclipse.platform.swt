package org.eclipse.swt.widgets;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */


import org.eclipse.swt.internal.*;
import org.eclipse.swt.internal.carbon.OS;
import org.eclipse.swt.internal.carbon.CGPoint;
import org.eclipse.swt.internal.carbon.Rect;
import org.eclipse.swt.internal.carbon.HICommand;

import org.eclipse.swt.*;
import org.eclipse.swt.graphics.*;

public class Display extends Device {

	/* Windows and Events */
	Event [] eventQueue;
	Callback actionCallback, commandCallback, controlCallback, itemDataCallback, itemNotificationCallback, keyboardCallback, menuCallback, mouseCallback, windowCallback;
	int actionProc, commandProc, controlProc, itemDataProc, itemNotificationProc, keyboardProc, menuProc, mouseProc, windowProc;
	EventTable eventTable, filterTable;
	int queue, lastModifiers;
	
	/* Sync/Async Widget Communication */
	Synchronizer synchronizer = new Synchronizer (this);
	Thread thread;
	
	/* Display Shutdown */
	Runnable [] disposeList;
	
	/* Timers */
	int [] timerIds;
	Runnable [] timerList;
	Callback timerCallback;
	int timerProc;	
		
	/* Current caret */
	Caret currentCaret;
	Callback caretCallback;
	int caretID, caretProc;
	
	/* Grabs */
	Control grabControl;

	/* Menus */
	static final int ID_START = 1000;
	Menu menuBar;
	Menu [] menus, popups;
	MenuItem [] items;
	
	/* Key Mappings. */
	static int [] [] KeyTable = {

		/* Non-Numeric Keypad Keys */
		{126,	SWT.ARROW_UP},
		{125,	SWT.ARROW_DOWN},
		{123,	SWT.ARROW_LEFT},
		{124,	SWT.ARROW_RIGHT},
		{116,	SWT.PAGE_UP},
		{121,	SWT.PAGE_DOWN},
		{115,	SWT.HOME},
		{119,	SWT.END},
		{71,	SWT.INSERT},

		/* Virtual and Ascii Keys */
		{51,	SWT.BS},
		{36,	SWT.CR},
		{117,	SWT.DEL},
		{53,	SWT.ESC},
		{76,	SWT.LF},
		{48,	SWT.TAB},	
		
		/* Functions Keys */
		{122,		SWT.F1},
		{120,		SWT.F2},
		{99,		SWT.F3},
		{118,		SWT.F4},
		{96,		SWT.F5},
		{97,		SWT.F6},
		{98,		SWT.F7},
		{100,		SWT.F8},
		{101,		SWT.F9},
		{109,		SWT.F10},
		{103,		SWT.F11},
		{111,		SWT.F12},
		
		/* Numeric Keypad Keys */
	};

	/* Multiple Displays. */
	static Display Default;
	static Display [] Displays = new Display [4];
				
	/* Package Name */
	static final String PACKAGE_PREFIX = "org.eclipse.swt.widgets.";
			
	/* Display Data */
	Object data;
	String [] keys;
	Object [] values;
	
	/*
	* TEMPORARY CODE.  Install the runnable that
	* gets the current display. This code will
	* be removed in the future.
	*/
	static {
		DeviceFinder = new Runnable () {
			public void run () {
				Device device = getCurrent ();
				if (device == null) {
					device = getDefault ();
				}
				setDevice (device);
			}
		};
	}
	
/*
* TEMPORARY CODE.
*/
static void setDevice (Device device) {
	CurrentDevice = device;
}

static int translateKey (int key) {
	for (int i=0; i<KeyTable.length; i++) {
		if (KeyTable [i] [0] == key) return KeyTable [i] [1];
	}
	return 0;
}

static int untranslateKey (int key) {
	for (int i=0; i<KeyTable.length; i++) {
		if (KeyTable [i] [1] == key) return KeyTable [i] [0];
	}
	return 0;
}

int actionProc (int theControl, int partCode) {
	Widget widget = WidgetTable.get (theControl);
	if (widget != null) return widget.actionProc (theControl, partCode);
	return OS.noErr;
}

public void addFilter (int eventType, Listener listener) {
	checkDevice ();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (filterTable == null) filterTable = new EventTable ();
	filterTable.hook (eventType, listener);
}

public void addListener (int eventType, Listener listener) {
	checkDevice ();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (eventTable == null) eventTable = new EventTable ();
	eventTable.hook (eventType, listener);
}

void addMenu (Menu menu) {
	if (menus == null) menus = new Menu [12];
	for (int i=0; i<menus.length; i++) {
		if (menus [i] == null) {
			menu.id = (short)(ID_START + i);
			menus [i] = menu;
			return;
		}
	}
	Menu [] newMenus = new Menu [menus.length + 12];
	menu.id = (short)(ID_START + menus.length);
	newMenus [menus.length] = menu;
	System.arraycopy (menus, 0, newMenus, 0, menus.length);
	menus = newMenus;
}

void addMenuItem (MenuItem item) {
	if (items == null) items = new MenuItem [12];
	for (int i=0; i<items.length; i++) {
		if (items [i] == null) {
			item.id = ID_START + i;
			items [i] = item;
			return;
		}
	}
	MenuItem [] newItems = new MenuItem [items.length + 12];
	item.id = ID_START + items.length;
	newItems [items.length] = item;
	System.arraycopy (items, 0, newItems, 0, items.length);
	items = newItems;
}

void addPopup (Menu menu) {
	if (popups == null) popups = new Menu [4];
	int length = popups.length;
	for (int i=0; i<length; i++) {
		if (popups [i] == menu) return;
	}
	int index = 0;
	while (index < length) {
		if (popups [index] == null) break;
		index++;
	}
	if (index == length) {
		Menu [] newPopups = new Menu [length + 4];
		System.arraycopy (popups, 0, newPopups, 0, length);
		popups = newPopups;
	}
	popups [index] = menu;
}

public void asyncExec (Runnable runnable) {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	synchronizer.asyncExec (runnable);
}

public void beep () {
	checkDevice ();
	OS.SysBeep ((short) 100);
}

int caretProc (int id, int clientData) {
	if (currentCaret == null) return 0;
	if (currentCaret.blinkCaret ()) {
		int blinkRate = currentCaret.blinkRate;
		OS.SetEventLoopTimerNextFireTime (id, blinkRate / 1000.0);
	} else {
		currentCaret = null;
	}
	return 0;
}

protected void checkDevice () {
	if (!isValidThread ()) error (SWT.ERROR_THREAD_INVALID_ACCESS);
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
}

protected void checkSubclass () {
	if (!Display.isValidClass (getClass ())) error (SWT.ERROR_INVALID_SUBCLASS);
}

public Display () {
	this (null);
}

public Display (DeviceData data) {
	super (data);
}

static synchronized void checkDisplay (Thread thread) {
	for (int i=0; i<Displays.length; i++) {
		if (Displays [i] != null && Displays [i].thread == thread) {
			SWT.error (SWT.ERROR_THREAD_INVALID_ACCESS);
		}
	}
}

int commandProc (int nextHandler, int theEvent, int userData) {
	int eventKind = OS.GetEventKind (theEvent);
	HICommand command = new HICommand ();
	OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeHICommand, null, HICommand.sizeof, null, command);
	switch (eventKind) {
		case OS.kEventProcessCommand: {
			if (command.commandID == OS.kAEQuitApplication) {
				close ();
				return OS.noErr;
			}
			if ((command.attributes & OS.kHICommandFromMenu) != 0) {
				int menuRef = command.menu_menuRef;
				short menuID = OS.GetMenuID (menuRef);
				Menu menu = findMenu (menuID);
				if (menu != null) {
					int [] outCommandID = new int [1];
					short menuIndex = command.menu_menuItemIndex;
					OS.GetMenuItemCommandID (menuRef, menuIndex, outCommandID);
					MenuItem item = findMenuItem (outCommandID [0]);
					return item.kEventProcessCommand (nextHandler, theEvent, userData);
				}
				OS.HiliteMenu ((short) 0);
			}
		}
	}
	return OS.eventNotHandledErr;
}

int controlProc (int nextHandler, int theEvent, int userData) {
	Widget widget = WidgetTable.get (userData);
	if (widget != null) return widget.controlProc (nextHandler, theEvent, userData);
	return OS.eventNotHandledErr;
}

public void close () {
	checkDevice ();
	Event event = new Event ();
	sendEvent (SWT.Close, event);
	if (event.doit) dispose ();
}

protected void create (DeviceData data) {
	checkSubclass ();
	checkDisplay (thread = Thread.currentThread ());
	createDisplay (data);
	register (this);
	if (Default == null) Default = this;
}

void createDisplay (DeviceData data) {
	queue = OS.GetCurrentEventQueue ();
	OS.TXNInitTextension (0, 0, 0);
}

synchronized static void deregister (Display display) {
	for (int i=0; i<Displays.length; i++) {
		if (display == Displays [i]) Displays [i] = null;
	}
}

protected void destroy () {
	if (this == Default) Default = null;
	deregister (this);
	destroyDisplay ();
}

void destroyDisplay () {
}

public void disposeExec (Runnable runnable) {
	checkDevice ();
	if (disposeList == null) disposeList = new Runnable [4];
	for (int i=0; i<disposeList.length; i++) {
		if (disposeList [i] == null) {
			disposeList [i] = runnable;
			return;
		}
	}
	Runnable [] newDisposeList = new Runnable [disposeList.length + 4];
	System.arraycopy (disposeList, 0, newDisposeList, 0, disposeList.length);
	newDisposeList [disposeList.length] = runnable;
	disposeList = newDisposeList;
}

void error (int code) {
	SWT.error(code);
}

boolean filterEvent (Event event) {
	if (filterTable != null) filterTable.sendEvent (event);
	return false;
}

boolean filters (int eventType) {
	if (filterTable == null) return false;
	return filterTable.hooks (eventType);
}

Menu findMenu (int id) {
	if (menus == null) return null;
	int index = id - ID_START;
	if (0 <= index && index < menus.length) return menus [index];
	return null;
}

MenuItem findMenuItem (int id) {
	if (items == null) return null;
	int index = id - ID_START;
	if (0 <= index && index < items.length) return items [index];
	return null;
}

public Widget findWidget (int handle) {
	checkDevice ();
	return WidgetTable.get (handle);
}

public static synchronized Display findDisplay (Thread thread) {
	for (int i=0; i<Displays.length; i++) {
		Display display = Displays [i];
		if (display != null && display.thread == thread) {
			return display;
		}
	}
	return null;
}

public Shell getActiveShell () {
	checkDevice ();
	int theWindow = OS.FrontWindow ();
	if (theWindow == 0) return null;
	int [] theControl = new int [1];
	OS.GetRootControl (theWindow, theControl);
	Widget widget = WidgetTable.get (theControl [0]);
	if (widget instanceof Shell) return (Shell) widget;
	return null;
}

public static synchronized Display getCurrent () {
	return findDisplay (Thread.currentThread ());
}

int getCaretBlinkTime () {
	return OS.GetCaretTime () * 1000 / 60;
}

public Control getCursorControl () {
	checkDevice ();
	org.eclipse.swt.internal.carbon.Point where = new org.eclipse.swt.internal.carbon.Point ();
	OS.GetGlobalMouse (where);
	int [] theWindow = new int [1];
	if (OS.FindWindow (where, theWindow) != OS.inContent) return null;
	if (theWindow [0] == 0) return null;
	Rect rect = new Rect ();
	OS.GetWindowBounds (theWindow [0], (short) OS.kWindowContentRgn, rect);
	CGPoint inPoint = new CGPoint ();
	inPoint.x = where.h - rect.left;
	inPoint.y = where.v - rect.top;
	int [] theRoot = new int [1];
	OS.GetRootControl (theWindow [0], theRoot);
	int [] theControl = new int [1];
	OS.HIViewGetSubviewHit (theRoot [0], inPoint, true, theControl);
	if (theControl [0] != 0) {
		do {
			Widget widget = WidgetTable.get (theControl [0]);
			if (widget != null && widget instanceof Control) {
				Control control = (Control) widget;
				if (control.getEnabled ()) return control;
			}
			OS.GetSuperControl (theControl [0], theControl);
		} while (theControl [0] != 0);
	}
	Widget widget = WidgetTable.get (theRoot [0]);
	if (widget != null && widget instanceof Control) return (Control) widget;
	return null;
}

public Point getCursorLocation () {
	checkDevice ();
	org.eclipse.swt.internal.carbon.Point pt = new org.eclipse.swt.internal.carbon.Point ();
	OS.GetGlobalMouse (pt);
	return new Point (pt.h, pt.v);
}

public static synchronized Display getDefault () {
	if (Default == null) Default = new Display ();
	return Default;
}

public Object getData (String key) {
	checkDevice ();
	if (key == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (keys == null) return null;
	for (int i=0; i<keys.length; i++) {
		if (keys [i].equals (key)) return values [i];
	}
	return null;
}

public Object getData () {
	checkDevice ();
	return data;
}

public int getDoubleClickTime () {
	checkDevice ();
	return OS.GetDblTime (); 
}

public Control getFocusControl () {
	checkDevice ();
	int theWindow = OS.FrontWindow ();
	if (theWindow == 0) return null;
	int [] theControl = new int [1];
	OS.GetKeyboardFocus (theWindow, theControl);
	do {
		Widget widget = WidgetTable.get (theControl [0]);
		if (widget != null && widget instanceof Control) {
			Control control = (Control) widget;
			if (control.getEnabled ()) return control;
		}
		OS.GetSuperControl (theControl [0], theControl);
	} while (theControl [0] != 0);
	return null;
}

int getLastEventTime () {
	/*
	* This code is intentionally commented.  Event time is
	* in seconds and we need an accurate time in milliseconds.
	*/
//	return (int) (OS.GetLastUserEventTime () * 1000.0);
	return (int) System.currentTimeMillis ();
}

Menu getMenuBar () {
	return menuBar;
}

public Shell [] getShells () {
	checkDevice ();
	/*
	* NOTE:  Need to check that the shells that belong
	* to another display have not been disposed by the
	* other display's thread as the shells list is being
	* processed.
	*/
	int count = 0;
	Shell [] shells = WidgetTable.shells ();
	for (int i=0; i<shells.length; i++) {
		Shell shell = shells [i];
		if (!shell.isDisposed () && this == shell.getDisplay ()) {
			count++;
		}
	}
	if (count == shells.length) return shells;
	int index = 0;
	Shell [] result = new Shell [count];
	for (int i=0; i<shells.length; i++) {
		Shell shell = shells [i];
		if (!shell.isDisposed () && this == shell.getDisplay ()) {
			result [index++] = shell;
		}
	}
	return result;
}

public Thread getSyncThread () {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	return synchronizer.syncThread;
}

public Color getSystemColor (int id) {
	checkDevice ();
	//NOT DONE
	switch (id) {
		case SWT.COLOR_INFO_FOREGROUND: 					return Color.carbon_new (this, new float [] {0x00 / 255f, 0x00 / 255f, 0x00 / 255f});
		case SWT.COLOR_INFO_BACKGROUND: 					return Color.carbon_new (this, new float [] {0xFF / 255f, 0xFF / 255f, 0xE1 / 255f});
		case SWT.COLOR_TITLE_FOREGROUND:					return super.getSystemColor (SWT.COLOR_WHITE);
		case SWT.COLOR_TITLE_BACKGROUND:					return super.getSystemColor (SWT.COLOR_DARK_BLUE);
		case SWT.COLOR_TITLE_BACKGROUND_GRADIENT:			return super.getSystemColor (SWT.COLOR_BLUE);
		case SWT.COLOR_TITLE_INACTIVE_FOREGROUND:			return super.getSystemColor (SWT.COLOR_BLACK);
		case SWT.COLOR_TITLE_INACTIVE_BACKGROUND:			return super.getSystemColor (SWT.COLOR_DARK_GRAY);
		case SWT.COLOR_TITLE_INACTIVE_BACKGROUND_GRADIENT:	return super.getSystemColor (SWT.COLOR_GRAY);
		case SWT.COLOR_WIDGET_DARK_SHADOW:					return Color.carbon_new (this, new float [] {0x33 / 255f, 0x33 / 255f, 0x33 / 255f});
		case SWT.COLOR_WIDGET_NORMAL_SHADOW:				return Color.carbon_new (this, new float [] {0x66 / 255f, 0x66 / 255f, 0x66 / 255f});
		case SWT.COLOR_WIDGET_LIGHT_SHADOW: 				return Color.carbon_new (this, new float [] {0x99 / 255f, 0x99 / 255f, 0x99 / 255f});
		case SWT.COLOR_WIDGET_HIGHLIGHT_SHADOW:			return Color.carbon_new (this, new float [] {0xCC / 255f, 0xCC / 255f, 0xCC / 255f});
		case SWT.COLOR_WIDGET_BACKGROUND: 					return Color.carbon_new (this, new float [] {0xFF / 255f, 0xFF / 255f, 0xFF / 255f});
		case SWT.COLOR_WIDGET_FOREGROUND:
		case SWT.COLOR_WIDGET_BORDER: 						return Color.carbon_new (this, new float [] {0x00 / 255f, 0x00 / 255f, 0x00 / 255f});
		case SWT.COLOR_LIST_FOREGROUND: 					return Color.carbon_new (this, new float [] {0x00 / 255f, 0x00 / 255f, 0x00 / 255f});
		case SWT.COLOR_LIST_BACKGROUND: 					return Color.carbon_new (this, new float [] {0xFF / 255f, 0xFF / 255f, 0xFF / 255f});
		case SWT.COLOR_LIST_SELECTION: 					return Color.carbon_new (this, new float [] {0x66 / 255f, 0x66 / 255f, 0xCC / 255f});
		case SWT.COLOR_LIST_SELECTION_TEXT: 				return Color.carbon_new (this, new float [] {0xFF / 255f, 0xFF / 255f, 0xFF / 255f});
		default:
			return super.getSystemColor (id);	
	}
}

public Thread getThread () {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	return thread;
}

protected void init () {
	super.init ();
	
	/* Create Callbacks */
	actionCallback = new Callback (this, "actionProc", 2);
	actionProc = actionCallback.getAddress ();
	if (actionProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	caretCallback = new Callback(this, "caretProc", 2);
	caretProc = caretCallback.getAddress();
	if (caretProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	commandCallback = new Callback (this, "commandProc", 3);
	commandProc = commandCallback.getAddress ();
	if (commandProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	controlCallback = new Callback (this, "controlProc", 3);
	controlProc = controlCallback.getAddress ();
	if (controlProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	itemDataCallback = new Callback (this, "itemDataProc", 5);
	itemDataProc = itemDataCallback.getAddress ();
	if (itemDataProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	itemNotificationCallback = new Callback (this, "itemNotificationProc", 3);
	itemNotificationProc = itemNotificationCallback.getAddress ();
	if (itemNotificationProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	keyboardCallback = new Callback (this, "keyboardProc", 3);
	keyboardProc = keyboardCallback.getAddress ();
	if (keyboardProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	menuCallback = new Callback (this, "menuProc", 3);
	menuProc = menuCallback.getAddress ();
	if (menuProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	mouseCallback = new Callback (this, "mouseProc", 3);
	mouseProc = mouseCallback.getAddress ();
	if (mouseProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	timerCallback = new Callback (this, "timerProc", 2);
	timerProc = timerCallback.getAddress ();
	if (timerProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	windowCallback = new Callback (this, "windowProc", 3);
	windowProc = windowCallback.getAddress ();
	if (windowProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
		
	/* Install Event Handlers */
	int[] mask1 = new int[] {
		OS.kEventClassCommand, OS.kEventProcessCommand,
	};
	int appTarget = OS.GetApplicationEventTarget ();
	OS.InstallEventHandler (appTarget, commandProc, mask1.length / 2, mask1, 0, null);
	int[] mask2 = new int[] {
		OS.kEventClassMouse, OS.kEventMouseDown,
		OS.kEventClassMouse, OS.kEventMouseDragged,
		OS.kEventClassMouse, OS.kEventMouseEntered,
		OS.kEventClassMouse, OS.kEventMouseExited,
		OS.kEventClassMouse, OS.kEventMouseMoved,
		OS.kEventClassMouse, OS.kEventMouseUp,
		OS.kEventClassMouse, OS.kEventMouseWheelMoved,
	};
	OS.InstallEventHandler (appTarget, mouseProc, mask2.length / 2, mask2, 0, null);
	int [] mask3 = new int[] {
		OS.kEventClassKeyboard, OS.kEventRawKeyDown,
		OS.kEventClassKeyboard, OS.kEventRawKeyModifiersChanged,
		OS.kEventClassKeyboard, OS.kEventRawKeyRepeat,
		OS.kEventClassKeyboard, OS.kEventRawKeyUp,
	};
	int focusTarget = OS.GetUserFocusEventTarget ();
	OS.InstallEventHandler (focusTarget, keyboardProc, mask3.length / 2, mask3, 0, null);
}

public int internal_new_GC (GCData data) {
	if (isDisposed()) SWT.error(SWT.ERROR_DEVICE_DISPOSED);
	//NOT DONE
	return 0;
}

public void internal_dispose_GC (int gc, GCData data) {
	//NOT DONE
}

static boolean isValidClass (Class clazz) {
	String name = clazz.getName ();
	int index = name.lastIndexOf ('.');
	return name.substring (0, index + 1).equals (PACKAGE_PREFIX);
}

boolean isValidThread () {
	return thread == Thread.currentThread ();
}

int itemDataProc (int browser, int item, int property, int itemData, int setValue) {
	Widget widget = WidgetTable.get (browser);
	if (widget != null) return widget.itemDataProc (browser, item, property, itemData, setValue);
	return OS.noErr;
}

int itemNotificationProc (int browser, int item, int message) {
	Widget widget = WidgetTable.get (browser);
	if (widget != null) return widget.itemNotificationProc (browser, item, message);
	return OS.noErr;
}

int keyboardProc (int nextHandler, int theEvent, int userData) {
	Widget widget = WidgetTable.get (userData);
	if (widget == null) {
		int theWindow = OS.FrontWindow ();
		if (theWindow == 0) return OS.eventNotHandledErr;
		int [] theControl = new int [1];
		OS.GetKeyboardFocus (theWindow, theControl);
		//TEMPORARY CODE
		if (theControl [0] == 0) {
			OS.GetRootControl (theWindow, theControl);
		}
		widget = WidgetTable.get (theControl [0]);
	}
	if (widget != null) return widget.keyboardProc (nextHandler, theEvent, userData);
	return OS.eventNotHandledErr;
}

void postEvent (Event event) {
	/*
	* Place the event at the end of the event queue.
	* This code is always called in the Display's
	* thread so it must be re-enterant but does not
	* need to be synchronized.
	*/
	if (eventQueue == null) eventQueue = new Event [4];
	int index = 0;
	int length = eventQueue.length;
	while (index < length) {
		if (eventQueue [index] == null) break;
		index++;
	}
	if (index == length) {
		Event [] newQueue = new Event [length + 4];
		System.arraycopy (eventQueue, 0, newQueue, 0, length);
		eventQueue = newQueue;
	}
	eventQueue [index] = event;
}
	
int menuProc (int nextHandler, int theEvent, int userData) {
	if (userData != 0) {
		Widget widget = WidgetTable.get (userData);
		if (widget != null) return widget.menuProc (nextHandler, theEvent, userData);
	} else {
		int [] theMenu = new int [1];
		OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeMenuRef, null, 4, null, theMenu);
		short menuID = OS.GetMenuID (theMenu [0]);
		Menu menu = findMenu (menuID);
		if (menu != null) return menu.menuProc (nextHandler, theEvent, userData);
	}
	return OS.eventNotHandledErr;
}

int mouseProc (int nextHandler, int theEvent, int userData) {
	org.eclipse.swt.internal.carbon.Point where = new org.eclipse.swt.internal.carbon.Point ();
	OS.GetEventParameter (theEvent, OS.kEventParamMouseLocation, OS.typeQDPoint, null, where.sizeof, null, where);
	int [] theWindow = new int [1];
	int part = OS.FindWindow (where, theWindow);
	switch (part) {
		case OS.inMenuBar: {
			int eventKind = OS.GetEventKind (theEvent);
			if (eventKind == OS.kEventMouseDown) {
				OS.MenuSelect (where);
				return OS.noErr;
			}
			break;
		}
		case OS.inContent: {
			Rect rect = new Rect ();
			OS.GetWindowBounds (theWindow [0], (short) OS.kWindowContentRgn, rect);
			CGPoint inPoint = new CGPoint ();
			inPoint.x = where.h - rect.left;
			inPoint.y = where.v - rect.top;
			int [] theRoot = new int [1];
			OS.GetRootControl (theWindow [0], theRoot);
			int [] theControl = new int [1];
			OS.HIViewGetSubviewHit (theRoot [0], inPoint, true, theControl);
			//TEMPOARY CODE
			if (theControl [0] == 0) theControl [0] = theRoot [0];
			Widget widget = WidgetTable.get (theControl [0]);
//			if (control != null && control.handle == theControl [0]) {
			if (widget != null) {
				return widget.mouseProc (nextHandler, theEvent, userData);
			}
			break;
		}
	}
	return OS.eventNotHandledErr;
}

public boolean readAndDispatch () {
	checkDevice ();
	int [] outEvent = new int [1];
	int status = OS.ReceiveNextEvent (0, null, OS.kEventDurationNoWait, true, outEvent);
	if (status == OS.noErr) {
		OS.SendEventToEventTarget (outEvent [0], OS.GetEventDispatcherTarget ());
		OS.ReleaseEvent (outEvent [0]);
		runDeferredEvents ();
		if (runPopups ()) grabControl = null;
		runGrabs ();
		return true;
	}
	return runAsyncMessages ();
}

static synchronized void register (Display display) {
	for (int i=0; i<Displays.length; i++) {
		if (Displays [i] == null) {
			Displays [i] = display;
			return;
		}
	}
	Display [] newDisplays = new Display [Displays.length + 4];
	System.arraycopy (Displays, 0, newDisplays, 0, Displays.length);
	newDisplays [Displays.length] = display;
	Displays = newDisplays;
}

protected void release () {
	Shell [] shells = WidgetTable.shells ();
	for (int i=0; i<shells.length; i++) {
		Shell shell = shells [i];
		if (!shell.isDisposed ()) {
			if (this == shell.getDisplay ()) shell.dispose ();
		}
	}
	while (readAndDispatch ()) {};
	if (disposeList != null) {
		for (int i=0; i<disposeList.length; i++) {
			if (disposeList [i] != null) disposeList [i].run ();
		}
	}
	disposeList = null;	
	synchronizer.releaseSynchronizer ();
	synchronizer = null;
	releaseDisplay ();
	super.release ();
}

void releaseDisplay () {
	actionCallback.dispose ();
	caretCallback.dispose ();
	commandCallback.dispose ();
	controlCallback.dispose ();
	itemDataCallback.dispose ();
	itemNotificationCallback.dispose ();
	keyboardCallback.dispose ();
	menuCallback.dispose ();
	mouseCallback.dispose ();
	windowCallback.dispose ();
	actionCallback = caretCallback = commandCallback = controlCallback = itemDataCallback = itemNotificationCallback = keyboardCallback = menuCallback = mouseCallback = windowCallback = null;
	actionProc = caretProc = commandProc = controlProc = itemDataProc = itemNotificationProc = keyboardProc = menuProc = mouseProc = windowProc = 0;
	timerCallback.dispose ();
	timerCallback = null;
	timerProc = 0;
	//NOT DONE - call terminate TXN if this is the last display 
	//NOTE: - display create and dispose needs to be synchronized on all platforms
//	 TXNTerminateTextension ();

}

public void removeFilter (int eventType, Listener listener) {
	checkDevice ();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (filterTable == null) return;
	filterTable.unhook (eventType, listener);
	if (filterTable.size () == 0) filterTable = null;
}

public void removeListener (int eventType, Listener listener) {
	checkDevice ();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (eventTable == null) return;
	eventTable.unhook (eventType, listener);
}

void removeMenu (Menu menu) {
	if (menus == null) return;
	menus [menu.id - ID_START] = null;
}

void removeMenuItem (MenuItem item) {
	if (items == null) return;
	items [item.id - ID_START] = null;
}

void removePopup (Menu menu) {
	if (popups == null) return;
	for (int i=0; i<popups.length; i++) {
		if (popups [i] == menu) {
			popups [i] = null;
			return;
		}
	}
}

boolean runAsyncMessages () {
	return synchronizer.runAsyncMessages ();
}

boolean runDeferredEvents () {
	/*
	* Run deferred events.  This code is always
	* called  in the Display's thread so it must
	* be re-enterant need not be synchronized.
	*/
	while (eventQueue != null) {
		
		/* Take an event off the queue */
		Event event = eventQueue [0];
		if (event == null) break;
		int length = eventQueue.length;
		System.arraycopy (eventQueue, 1, eventQueue, 0, --length);
		eventQueue [length] = null;

		/* Run the event */
		Widget widget = event.widget;
		if (widget != null && !widget.isDisposed ()) {
			Widget item = event.item;
			if (item == null || !item.isDisposed ()) {
				widget.notifyListeners (event.type, event);
			}
		}

		/*
		* At this point, the event queue could
		* be null due to a recursive invokation
		* when running the event.
		*/
	}

	/* Clear the queue */
	eventQueue = null;
	return true;
}

void runGrabs () {
	if (grabControl == null) return;
	Rect rect = new Rect ();
	int [] outModifiers = new int [1];
	short [] outResult = new short [1];
	CGPoint ioPoint = new CGPoint ();
	org.eclipse.swt.internal.carbon.Point outPt = new org.eclipse.swt.internal.carbon.Point ();
	try {
		while (grabControl != null && !grabControl.isDisposed () && outResult [0] != OS.kMouseTrackingMouseUp) {
			lastModifiers = OS.GetCurrentEventKeyModifiers ();
			int oldState = OS.GetCurrentEventButtonState ();
			OS.TrackMouseLocationWithOptions (0, 0, OS.kEventDurationForever, outPt, outModifiers, outResult);
			int type = 0, button = 0;
			switch ((int)outResult [0]) {
				case OS.kMouseTrackingMouseDown: {
					type = SWT.MouseDown;
					int newState = OS.GetCurrentEventButtonState ();
					if ((oldState & 0x1) == 0 && (newState & 0x1) != 0) button = 1;
					if ((oldState & 0x2) == 0 && (newState & 0x2) != 0) button = 2;
					if ((oldState & 0x4) == 0 && (newState & 0x4) != 0) button = 3;
					break;
				}
				case OS.kMouseTrackingMouseUp: {
					type = SWT.MouseUp;
					int newState = OS.GetCurrentEventButtonState ();
					if ((oldState & 0x1) != 0 && (newState & 0x1) == 0) button = 1;
					if ((oldState & 0x2) != 0 && (newState & 0x2) == 0) button = 2;
					if ((oldState & 0x4) != 0 && (newState & 0x4) == 0) button = 3;
					break;
				}
				case OS.kMouseTrackingMouseExited: 				type = SWT.MouseExit; break;
				case OS.kMouseTrackingMouseEntered: 				type = SWT.MouseEnter; break;
				case OS.kMouseTrackingMouseDragged: 				type = SWT.MouseMove; break;
				case OS.kMouseTrackingMouseKeyModifiersChanged:	break;
				case OS.kMouseTrackingUserCancelled:				break;
				case OS.kMouseTrackingTimedOut: 					break;
				case OS.kMouseTrackingMouseMoved: 					type = SWT.MouseMove; break;
			}
			if (type != 0) {	
				int handle = grabControl.handle;
				int window = OS.GetControlOwner (handle);
				OS.GetWindowBounds (window, (short) OS.kWindowContentRgn, rect);
				int x = outPt.h - rect.left;
				int y = outPt.v - rect.top;
				OS.GetControlBounds (handle, rect);
				x -= rect.left;
				y -=  rect.top;
				int chord = OS.GetCurrentEventButtonState ();
				grabControl.sendMouseEvent (type, (short)button, chord, (short)x, (short)y, outModifiers [0]);
			}
		}
	} finally {
		grabControl = null;
	}
}

boolean runPopups () {
	if (popups == null) return false;
	boolean result = false;
	while (popups != null) {
		Menu menu = popups [0];
		if (menu == null) break;
		int length = popups.length;
		System.arraycopy (popups, 1, popups, 0, --length);
		popups [length] = null;
		menu._setVisible (true);
		result = true;
	}
	popups = null;
	return result;
}

void sendEvent (int eventType, Event event) {
	if (eventTable == null && filterTable == null) {
		return;
	}
	if (event == null) event = new Event ();
	event.display = this;
	event.type = eventType;
	if (event.time == 0) event.time = getLastEventTime ();
	if (!filterEvent (event)) {
		if (eventTable != null) eventTable.sendEvent (event);
	}
}

/**
 * On platforms which support it, sets the application name
 * to be the argument. On Motif, for example, this can be used
 * to set the name used for resource lookup.
 *
 * @param name the new app name
 */
public static void setAppName (String name) {
}

void setCurrentCaret (Caret caret) {
	if (caretID != 0) OS.RemoveEventLoopTimer (caretID);
	caretID = 0;
	currentCaret = caret;
	if (currentCaret != null) {
		int blinkRate = currentCaret.blinkRate;
		int [] timerId = new int [1];
		double time = blinkRate / 1000.0;
		int eventLoop = OS.GetCurrentEventLoop ();
		OS.InstallEventLoopTimer (eventLoop, time, time, caretProc, 0, timerId);
		caretID = timerId [0];
	}
}

/**
 * Sets the location of the on-screen pointer relative to the top left corner
 * of the screen.  <b>Note: It is typically considered bad practice for a
 * program to move the on-screen pointer location.</b>
 *
 * @param point new position 
 * @since 2.0
 * @exception SWTException <ul>
 *    <li>ERROR_THREAD_INVALID_ACCESS - if not called from the thread that created the receiver</li>
 *    <li>ERROR_NULL_ARGUMENT - if the point is null
 * </ul>
 */
public void setCursorLocation (Point point) {
	checkDevice ();
	if (point == null) error (SWT.ERROR_NULL_ARGUMENT);
	/* Not possible on the MAC */
}

public void setData (String key, Object value) {
	checkDevice ();
	if (key == null) error (SWT.ERROR_NULL_ARGUMENT);
	
	/* Remove the key/value pair */
	if (value == null) {
		if (keys == null) return;
		int index = 0;
		while (index < keys.length && !keys [index].equals (key)) index++;
		if (index == keys.length) return;
		if (keys.length == 1) {
			keys = null;
			values = null;
		} else {
			String [] newKeys = new String [keys.length - 1];
			Object [] newValues = new Object [values.length - 1];
			System.arraycopy (keys, 0, newKeys, 0, index);
			System.arraycopy (keys, index + 1, newKeys, index, newKeys.length - index);
			System.arraycopy (values, 0, newValues, 0, index);
			System.arraycopy (values, index + 1, newValues, index, newValues.length - index);
			keys = newKeys;
			values = newValues;
		}
		return;
	}
	
	/* Add the key/value pair */
	if (keys == null) {
		keys = new String [] {key};
		values = new Object [] {value};
		return;
	}
	for (int i=0; i<keys.length; i++) {
		if (keys [i].equals (key)) {
			values [i] = value;
			return;
		}
	}
	String [] newKeys = new String [keys.length + 1];
	Object [] newValues = new Object [values.length + 1];
	System.arraycopy (keys, 0, newKeys, 0, keys.length);
	System.arraycopy (values, 0, newValues, 0, values.length);
	newKeys [keys.length] = key;
	newValues [values.length] = value;
	keys = newKeys;
	values = newValues;
}

public void setData (Object data) {
	checkDevice ();
	this.data = data;
}

public void setSynchronizer (Synchronizer synchronizer) {
	checkDevice ();
	if (synchronizer == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (this.synchronizer != null) {
		this.synchronizer.runAsyncMessages();
	}
	this.synchronizer = synchronizer;
}

void setMenuBar (Menu menu) {
	menuBar = menu;
	//NOT DONE
	int inMenu = menuBar != null ? menu.handle : 0; 
	OS.SetRootMenu (inMenu);
}

public boolean sleep () {
	checkDevice ();
	return OS.ReceiveNextEvent (0, null, OS.kEventDurationForever, false, null) == OS.noErr;
}

public void syncExec (Runnable runnable) {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	synchronizer.syncExec (runnable);
}

public void timerExec (int milliseconds, Runnable runnable) {
	checkDevice ();
	if (runnable == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (timerList == null) timerList = new Runnable [4];
	if (timerIds == null) timerIds = new int [4];
	int index = 0;
	while (index < timerList.length) {
		if (timerList [index] == runnable) break;
		index++;
	}
	if (index != timerList.length) {
		int timerId = timerIds [index];
		if (milliseconds < 0) {
			OS.RemoveEventLoopTimer (timerId);
			timerList [index] = null;
			timerIds [index] = 0;
		} else {
			OS.SetEventLoopTimerNextFireTime (timerId, milliseconds / 1000.0);
		}
		return;
	} 
	if (milliseconds < 0) return;
	index = 0;
	while (index < timerList.length) {
		if (timerList [index] == null) break;
		index++;
	}
	if (index == timerList.length) {
		Runnable [] newTimerList = new Runnable [timerList.length + 4];
		System.arraycopy (timerList, 0, newTimerList, 0, timerList.length);
		timerList = newTimerList;
		int [] newTimerIds = new int [timerIds.length + 4];
		System.arraycopy (timerIds, 0, newTimerIds, 0, timerIds.length);
		timerIds = newTimerIds;
	}
	int [] timerId = new int [1];
	int eventLoop = OS.GetCurrentEventLoop ();
	OS.InstallEventLoopTimer (eventLoop, milliseconds / 1000.0, 0.0, timerProc, index, timerId);
	if (timerId [0] != 0) {
		timerIds [index] = timerId [0];
		timerList [index] = runnable;
	}
}

int timerProc (int id, int index) {
	if (timerList == null) return 0;
	if (0 <= index && index < timerList.length) {
		Runnable runnable = timerList [index];
		timerList [index] = null;
		timerIds [index] = 0;
		if (runnable != null) runnable.run ();
	}
	return 0;
}

public void update () {
	checkDevice ();
	//NOT DONE
}

public void wake () {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	if (thread == Thread.currentThread ()) return;
	int [] event = new int [1];
	OS.CreateEvent (0, 0, 0, 0.0, OS.kEventAttributeUserEvent, event);
	OS.PostEventToQueue (queue, event [0], (short) OS.kEventPriorityStandard);
}

int windowProc (int nextHandler, int theEvent, int userData) {
	Widget widget = WidgetTable.get (userData);
	if (widget == null) {
		int [] theWindow = new int [1];
		OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeWindowRef, null, 4, null, theWindow);
		int [] theRoot = new int [1];
		OS.GetRootControl (theWindow [0], theRoot);
		widget = WidgetTable.get (theRoot [0]);
	}
	if (widget != null)  return widget.windowProc (nextHandler, theEvent, userData); 
	return OS.eventNotHandledErr;
}

}
