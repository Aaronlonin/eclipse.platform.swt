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
	Callback windowCallback;
	int windowProc;
	EventTable eventTable, filterTable;
	int lastModifiers;
	
	/* Sync/Async Widget Communication */
	Synchronizer synchronizer = new Synchronizer (this);
	Thread thread;
	
	/* Display Shutdown */
	Runnable [] disposeList;
	
	/* Timers */
	int [] timerIDs;
	Runnable [] timerList;
	int timerProc;	
	
	/* Grabs */
	Control grabControl;

	/* Menus */
	static final int ID_START = 1000;
	Menu menuBar;
	Menu [] menus;
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

public void asyncExec (Runnable runnable) {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	synchronizer.asyncExec (runnable);
}

public void beep () {
	checkDevice ();
	OS.SysBeep ((short)100);
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
	id = id - ID_START;
	if (0 <= id && id < menus.length) return menus [id];
	return null;
}

MenuItem findMenuItem (int id) {
	if (items == null) return null;
	id = id - ID_START;
	if (0 <= id && id < items.length) return items [id];
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
	Control control = WidgetTable.get (theControl [0]);
	if (control instanceof Shell) return (Shell) control;
	return null;
}

public Rectangle getBounds () {
	checkDevice ();
	return new Rectangle (0, 0, 0, 0);
}

public Rectangle getClientArea () {
	checkDevice ();
	return new Rectangle (0, 0, 0, 0);
}

public static synchronized Display getCurrent () {
	return findDisplay (Thread.currentThread ());
}

public Control getCursorControl () {
	checkDevice ();
	org.eclipse.swt.internal.carbon.Point where = new org.eclipse.swt.internal.carbon.Point ();
	OS.GetGlobalMouse (where);
	int [] theWindow = new int [1];
	//NOT DONE - exclude window trim
	if (OS.FindWindow (where, theWindow) != OS.inContent) ; //return null;
	Rect rect = new Rect ();
	OS.GetWindowBounds (theWindow [0], (short) OS.kWindowStructureRgn, rect);	
	CGPoint inPoint = new CGPoint ();
	inPoint.x = where.h - rect.left;
	inPoint.y = where.v - rect.top;
	int [] theRoot = new int [1];
	OS.GetRootControl (theWindow [0], theRoot);
	OS.HIViewConvertPoint (inPoint, 0, theRoot [0]); 
	int [] theControl = new int [1];
	OS.HIViewGetSubviewHit (theRoot [0], inPoint, true, theControl);
	if (theControl [0] != 0) {
		//NOT DONE - check for disabled controls
		 return WidgetTable.get (theControl [0]);
	}
	return WidgetTable.get (theRoot [0]);
}

public Point getCursorLocation () {
	checkDevice ();
	org.eclipse.swt.internal.carbon.Point pt = new org.eclipse.swt.internal.carbon.Point();
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
	return 500; 
}

public Control getFocusControl () {
	checkDevice ();
	return null;
}

public int getIconDepth () {
	return 0;
}

int getLastEventTime () {
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
	switch (id) {
//		case SWT.COLOR_INFO_FOREGROUND: 		return COLOR_INFO_FOREGROUND;
//		case SWT.COLOR_INFO_BACKGROUND: 		return COLOR_INFO_BACKGROUND;	
//		case SWT.COLOR_TITLE_FOREGROUND:		return super.getSystemColor (SWT.COLOR_WHITE);
//		case SWT.COLOR_TITLE_BACKGROUND:		return super.getSystemColor (SWT.COLOR_DARK_BLUE);
//		case SWT.COLOR_TITLE_BACKGROUND_GRADIENT:	return super.getSystemColor (SWT.COLOR_BLUE);
//		case SWT.COLOR_TITLE_INACTIVE_FOREGROUND:	return super.getSystemColor (SWT.COLOR_BLACK);
//		case SWT.COLOR_TITLE_INACTIVE_BACKGROUND:	return super.getSystemColor (SWT.COLOR_DARK_GRAY);
//		case SWT.COLOR_TITLE_INACTIVE_BACKGROUND_GRADIENT:	return super.getSystemColor (SWT.COLOR_GRAY);
//		case SWT.COLOR_WIDGET_DARK_SHADOW:	xColor = COLOR_WIDGET_DARK_SHADOW; break;
//		case SWT.COLOR_WIDGET_NORMAL_SHADOW:	xColor = COLOR_WIDGET_NORMAL_SHADOW; break;
//		case SWT.COLOR_WIDGET_LIGHT_SHADOW: 	xColor = COLOR_WIDGET_LIGHT_SHADOW; break;
//		case SWT.COLOR_WIDGET_HIGHLIGHT_SHADOW:	xColor = COLOR_WIDGET_HIGHLIGHT_SHADOW; break;
//		case SWT.COLOR_WIDGET_BACKGROUND: 	xColor = COLOR_WIDGET_BACKGROUND; break;
//		case SWT.COLOR_WIDGET_FOREGROUND:
//		case SWT.COLOR_WIDGET_BORDER: 		xColor = COLOR_WIDGET_BORDER; break;
//		case SWT.COLOR_LIST_FOREGROUND: 	xColor = COLOR_LIST_FOREGROUND; break;
//		case SWT.COLOR_LIST_BACKGROUND: 	xColor = COLOR_LIST_BACKGROUND; break;
//		case SWT.COLOR_LIST_SELECTION: 		xColor = COLOR_LIST_SELECTION; break;
//		case SWT.COLOR_LIST_SELECTION_TEXT: 	xColor = COLOR_LIST_SELECTION_TEXT; break;
		default:
			return super.getSystemColor (id);	
	}
}

public Font getSystemFont () {
	checkDevice ();
	return null;
}

public Thread getThread () {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	return thread;
}

protected void init () {
	super.init ();
	
	/* Create the callbacks */
	windowCallback = new Callback (this, "windowProc", 3);
	windowProc = windowCallback.getAddress ();
	if (windowProc == 0) error (SWT.ERROR_NO_MORE_CALLBACKS);
	
	/* Install Application Event Handlers */
	int[] mask1 = new int[] {
		OS.kEventClassCommand, OS.kEventProcessCommand,
		OS.kEventClassMouse, OS.kEventMouseDown,
		OS.kEventClassMouse, OS.kEventMouseDragged,
		OS.kEventClassMouse, OS.kEventMouseEntered,
		OS.kEventClassMouse, OS.kEventMouseExited,
		OS.kEventClassMouse, OS.kEventMouseMoved,
		OS.kEventClassMouse, OS.kEventMouseUp,
		OS.kEventClassMouse, OS.kEventMouseWheelMoved,
	};
	int appTarget = OS.GetApplicationEventTarget ();
	OS.InstallEventHandler (appTarget, windowProc, mask1.length / 2, mask1, 0, null);
	
	/* Install Keyboard Event Handlers */
	int [] mask2 = new int[] {
		OS.kEventClassKeyboard, OS.kEventRawKeyDown,
		OS.kEventClassKeyboard, OS.kEventRawKeyModifiersChanged,
		OS.kEventClassKeyboard, OS.kEventRawKeyRepeat,
		OS.kEventClassKeyboard, OS.kEventRawKeyUp,
	};
	int focusTarget = OS.GetUserFocusEventTarget ();
	OS.InstallEventHandler (focusTarget, windowProc, mask2.length / 2, mask2, 0, null);
}

public int internal_new_GC (GCData data) {
	if (isDisposed()) SWT.error(SWT.ERROR_DEVICE_DISPOSED);
	return 0;
}

public void internal_dispose_GC (int gc, GCData data) {
}

static boolean isValidClass (Class clazz) {
	String name = clazz.getName ();
	int index = name.lastIndexOf ('.');
	return name.substring (0, index + 1).equals (PACKAGE_PREFIX);
}

boolean isValidThread () {
	return thread == Thread.currentThread ();
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

public boolean readAndDispatch () {
	checkDevice ();
	int [] outEvent = new int [1];
	int status = OS.ReceiveNextEvent (0, null, OS.kEventDurationNoWait, true, outEvent);
	if (status == OS.noErr) {
		OS.SendEventToEventTarget (outEvent [0], OS.GetEventDispatcherTarget ());
		OS.ReleaseEvent (outEvent [0]);
		runDeferredEvents ();
		Rect rect = new Rect ();
		int [] outModifiers = new int [1];
		short [] outResult = new short [1];
		CGPoint ioPoint = new CGPoint ();
		org.eclipse.swt.internal.carbon.Point outPt = new org.eclipse.swt.internal.carbon.Point ();
		try {
			while (grabControl != null && !grabControl.isDisposed () && outResult [0] != OS.kMouseTrackingMouseUp) {
				OS.TrackMouseLocationWithOptions (0, 0, OS.kEventDurationForever, outPt, outModifiers, outResult);
				int type = 0;
				switch (outResult [0]) {
					case OS.kMouseTrackingMouseDown:					type = SWT.MouseDown; break;
					case OS.kMouseTrackingMouseUp:						type = SWT.MouseUp; break;
					case OS.kMouseTrackingMouseExited: 				type = SWT.MouseExit; break;
					case OS.kMouseTrackingMouseEntered: 				type = SWT.MouseEnter; break;
					case OS.kMouseTrackingMouseDragged: 				type = SWT.MouseMove; break;
					case OS.kMouseTrackingMouseKeyModifiersChanged: {
						lastModifiers = outModifiers [0];
						break;
					}
					case OS.kMouseTrackingUserCancelled:				break;
					case OS.kMouseTrackingTimedOut: 					break;
					case OS.kMouseTrackingMouseMoved: 					type = SWT.MouseMove; break;
				}
				if (type != 0) {	
					int handle = grabControl.handle;
					int window = OS.GetControlOwner (handle);
					OS.GetWindowBounds (window, (short) OS.kWindowStructureRgn, rect);
					ioPoint.x = outPt.h - rect.left;
					ioPoint.y = outPt.v - rect.top;
					OS.HIViewConvertPoint (ioPoint, 0, handle); 
					grabControl.sendMouseEvent (type, (short)0, (short)ioPoint.x, (short)ioPoint.y, outModifiers [0]);
				}
			}
		} finally {
			grabControl = null;
		}
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
	/* Dispose callbacks */
	windowCallback.dispose ();
	windowCallback = null;
	windowProc = 0;
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
	/* AW
	int x = point.x;
	int y = point.y;
	int xWindow = OS.XDefaultRootWindow (xDisplay);	
	OS.XWarpPointer (xDisplay, OS.None, xWindow, 0, 0, 0, 0, x, y);
	*/
	System.out.println("Display.setCursorLocation: nyi");
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
	int status = OS.ReceiveNextEvent (0, null, OS.kEventDurationForever, false, null);
	return status == OS.noErr;
}

public void syncExec (Runnable runnable) {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	synchronizer.syncExec (runnable);
}

public void timerExec (int milliseconds, Runnable runnable) {
	checkDevice ();
	if (timerList == null) timerList = new Runnable [4];
	if (timerIDs == null) timerIDs = new int [4];
	int index = 0;
	while (index < timerList.length) {
		if (timerList [index] == null) break;
		index++;
	}
	if (index == timerList.length) {
		Runnable [] newTimerList = new Runnable [timerList.length + 4];
		System.arraycopy (timerList, 0, newTimerList, 0, timerList.length);
		timerList = newTimerList;
		int [] newTimerIDs = new int [timerIDs.length + 4];
		System.arraycopy (timerIDs, 0, newTimerIDs, 0, timerIDs.length);
		timerIDs = newTimerIDs;
	}
	int[] timer= new int[1];
	//OS.InstallEventLoopTimer(OS.GetCurrentEventLoop(), milliseconds / 1000.0, 0.0, timerProc, index, timer);
	int timerID = timer[0];
	
	if (timerID != 0) {
		timerIDs [index] = timerID;
		timerList [index] = runnable;
	}
}

public void update () {
	checkDevice ();
}

int windowProc (int nextHandler, int theEvent, int userData) {
	int eventClass = OS.GetEventClass (theEvent);
	int eventKind = OS.GetEventKind (theEvent);
	switch (eventClass) {
				
		case OS.kEventClassCommand: {
			HICommand command = new HICommand ();
			OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeHICommand, null, HICommand.sizeof, null, command);
			switch (eventKind) {
				case OS.kEventProcessCommand: {
					if (command.commandID == OS.kAEQuitApplication) {
//						close ();
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
						OS.HiliteMenu ((short)0);
					}
				}
			}
			break;
		}
			
		case OS.kEventClassControl: {
			int [] theControl = new int [1];
			OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeControlRef, null, 4, null, theControl);
			Control control = WidgetTable.get (theControl [0]);
			if (control != null) {
				switch (eventKind) {
					case OS.kEventControlBoundsChanged:	return control.kEventControlBoundsChanged (nextHandler, theEvent, userData);
					case OS.kEventControlDraw:				return control.kEventControlDraw (nextHandler, theEvent, userData);
				}
			}
			break;
		}
		
		case OS.kEventClassKeyboard: {
			int theWindow = OS.FrontWindow ();
			if (theWindow == 0) return OS.eventNotHandledErr;
			int [] theControl = new int [1];
			OS.GetKeyboardFocus (theWindow, theControl);
			//TEMPORARY CODE
			if (theControl [0] == 0) {
				OS.GetRootControl (theWindow, theControl);
			}
			Control control = WidgetTable.get (theControl [0]);
			if (control != null) {
				switch (eventKind) {
					case OS.kEventRawKeyDown:				return control.kEventRawKeyDown (nextHandler, theEvent, userData);
					case OS.kEventRawKeyModifiersChanged:	return control.kEventRawKeyModifiersChanged (nextHandler, theEvent, userData);
					case OS.kEventRawKeyRepeat:			return control.kEventRawKeyRepeat (nextHandler, theEvent, userData);
					case OS.kEventRawKeyUp:				return control.kEventRawKeyUp (nextHandler, theEvent, userData);
				}
			}
			break;
		}
		
		case OS.kEventClassMenu: {
			int [] theMenu = new int [1];
			OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeMenuRef, null, 4, null, theMenu);
			short menuID = OS.GetMenuID (theMenu [0]);
			Menu menu = findMenu (menuID);
			if (menu != null) {
				switch (eventKind) {
					case OS.kEventMenuOpening:	return menu.kEventMenuOpening (nextHandler, theEvent, userData);
					case OS.kEventMenuClosed:	return menu.kEventMenuClosed (nextHandler, theEvent, userData);
				}
			}
			break;
		}
		
		case OS.kEventClassMouse: {
			org.eclipse.swt.internal.carbon.Point where = new org.eclipse.swt.internal.carbon.Point ();
			OS.GetEventParameter (theEvent, OS.kEventParamMouseLocation, OS.typeQDPoint, null, where.sizeof, null, where);
			int [] theWindow = new int [1];
			OS.GetEventParameter (theEvent, OS.kEventParamWindowRef, OS.typeWindowRef, null, 4, null, theWindow);
			if (theWindow [0] == 0) {
				short part = OS.FindWindow (where, theWindow);
				if (eventKind == OS.kEventMouseDown && part == OS.inMenuBar) {
					OS.MenuSelect (where);
					return OS.noErr;
				}
			}
			int [] theRoot = new int [1];
			OS.GetRootControl (theWindow [0], theRoot);
			int [] theControl = new int [1];
			Rect rect = new Rect ();
			OS.GetWindowBounds (theWindow [0], (short) OS.kWindowStructureRgn, rect);
			CGPoint inPoint = new CGPoint ();
			inPoint.x = where.h - rect.left;
			inPoint.y = where.v - rect.top;
			OS.HIViewConvertPoint (inPoint, 0, theRoot [0]); 
			OS.HIViewGetSubviewHit (theRoot [0], inPoint, true, theControl);
			//FIXME - look for part code?
			if (theControl [0] == 0) {
				if (0 <= inPoint.x && inPoint.x < (rect.right - rect.left)) {
					if (0 <= inPoint.y && inPoint.y < (rect.bottom - rect.top)) {
						OS.HIViewGetViewForMouseEvent (theRoot [0], theEvent, theControl);
					}
				}
			}
			Control control = WidgetTable.get (theControl [0]);
			if (control != null) {
				switch (eventKind) {
					case OS.kEventMouseDown:  			return control.kEventMouseDown (nextHandler, theEvent, userData);
					case OS.kEventMouseUp: 			return control.kEventMouseUp (nextHandler, theEvent, userData);
					case OS.kEventMouseDragged:		return control.kEventMouseDragged (nextHandler, theEvent, userData);
//					case OS.kEventMouseEntered:			return control.kEventMouseEntered (nextHandler, theEvent, userData);
//					case OS.kEventMouseExited:			return control.kEventMouseExited (nextHandler, theEvent, userData);
					case OS.kEventMouseMoved:			return control.kEventMouseMoved (nextHandler, theEvent, userData);
					case OS.kEventMouseWheelMoved:		return control.kEventMouseWheelMoved (nextHandler, theEvent, userData);
				}
			}
			break;
		}
		
		case OS.kEventClassWindow: {
			int [] theWindow = new int [1];
			OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeWindowRef, null, 4, null, theWindow);
			int [] theRoot = new int [1];
			OS.GetRootControl (theWindow [0], theRoot);
			Control control = WidgetTable.get (theRoot [0]);
			if (control != null) {
				switch (eventKind) {
					case OS.kEventWindowActivated:		return control.kEventWindowActivated (nextHandler, theEvent, userData);	
					case OS.kEventWindowBoundsChanged:	return control.kEventWindowBoundsChanged (nextHandler, theEvent, userData);
					case OS.kEventWindowClose:			return control.kEventWindowClose (nextHandler, theEvent, userData);
					case OS.kEventWindowCollapsed:		return control.kEventWindowCollapsed (nextHandler, theEvent, userData);
					case OS.kEventWindowDeactivated:	return control.kEventWindowDeactivated (nextHandler, theEvent, userData);
					case OS.kEventWindowExpanded:		return control.kEventWindowExpanded (nextHandler, theEvent, userData);
				}
			}
			break;
		}
		
	}
	return OS.eventNotHandledErr;
}
	
public void wake () {
	if (isDisposed ()) error (SWT.ERROR_DEVICE_DISPOSED);
	if (thread == Thread.currentThread ()) return;
}
}
