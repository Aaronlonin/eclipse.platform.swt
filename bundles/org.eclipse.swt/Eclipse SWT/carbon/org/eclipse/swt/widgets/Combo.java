package org.eclipse.swt.widgets;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.*;
import org.eclipse.swt.events.*;
import org.eclipse.swt.graphics.*;
import org.eclipse.swt.internal.carbon.OS;
import org.eclipse.swt.internal.carbon.CFRange;
import org.eclipse.swt.internal.carbon.CGRect;

public class Combo extends Composite {

	/**
	 * the operating system limit for the number of characters
	 * that the text field in an instance of this class can hold
	 */
	public static int LIMIT;
	
	/*
	* These values can be different on different platforms.
	* Therefore they are not initialized in the declaration
	* to stop the compiler from inlining.
	*/
	static {
		LIMIT = 0x7FFFFFFF;
	}
	
	int menuHandle;

public Combo (Composite parent, int style) {
	super (parent, checkStyle (style));
}

public void add (String string) {
	checkWidget ();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);	
	
	char [] buffer = new char [string.length ()];
	string.getChars (0, buffer.length, buffer, 0);
	int ptr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
	if (ptr == 0) error (SWT.ERROR_ITEM_NOT_ADDED);
	int result;
	if ((style & SWT.READ_ONLY) != 0) {
		result = OS.AppendMenuItemTextWithCFString (menuHandle, ptr, 0, 0, null);
	} else {
		result = OS.HIComboBoxAppendTextItem (handle, ptr, null);
	}
	OS.CFRelease (ptr);
	if (result != OS.noErr) error (SWT.ERROR_ITEM_NOT_ADDED);
}

public void add (String string, int index) {
	checkWidget ();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);
	int count = getItemCount ();
	if (0 > index || index > count) error (SWT.ERROR_INVALID_RANGE);
	
	char [] buffer = new char [string.length ()];
	string.getChars (0, buffer.length, buffer, 0);
	int ptr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
	if (ptr == 0) error (SWT.ERROR_ITEM_NOT_ADDED);
	int result;
	if ((style & SWT.READ_ONLY) != 0) {
		result = OS.InsertMenuItemTextWithCFString (menuHandle, ptr, (short)index, 0, 0);
	} else {
		result = OS.HIComboBoxInsertTextItemAtIndex (handle, index, ptr);
	}
	OS.CFRelease (ptr);
	if (result != OS.noErr) error (SWT.ERROR_ITEM_NOT_ADDED);
}

public void addModifyListener (ModifyListener listener) {
	checkWidget();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	TypedListener typedListener = new TypedListener (listener);
	addListener (SWT.Modify, typedListener);
}

public void addSelectionListener(SelectionListener listener) {
	checkWidget();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	TypedListener typedListener = new TypedListener (listener);
	addListener (SWT.Selection,typedListener);
	addListener (SWT.DefaultSelection,typedListener);
}

static int checkStyle (int style) {
	/*
	* Feature in Windows.  It is not possible to create
	* a combo box that has a border using Windows style
	* bits.  All combo boxes draw their own border and
	* do not use the standard Windows border styles.
	* Therefore, no matter what style bits are specified,
	* clear the BORDER bits so that the SWT style will
	* match the Windows widget.
	*
	* The Windows behavior is currently implemented on
	* all platforms.
	*/
	style &= ~SWT.BORDER;

	/*
	* Even though it is legal to create this widget
	* with scroll bars, they serve no useful purpose
	* because they do not automatically scroll the
	* widget's client area.  The fix is to clear
	* the SWT style.
	*/
	style &= ~(SWT.H_SCROLL | SWT.V_SCROLL);
	style = checkBits (style, SWT.DROP_DOWN, SWT.SIMPLE, 0, 0, 0, 0);
	if ((style & SWT.SIMPLE) != 0) return style & ~SWT.READ_ONLY;
	return style;
}

protected void checkSubclass () {
	if (!isValidSubclass ()) error (SWT.ERROR_INVALID_SUBCLASS);
}

public void clearSelection () {
	checkWidget();
	if ((style & SWT.READ_ONLY) != 0) {
		OS.SetControl32BitValue (handle, 0);
	} else {
		char [] buffer = new char [0];
		int ptr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
		if (ptr == 0) return;	
		OS.SetControlData (handle, OS.kHIComboBoxEditTextPart, OS.kControlEditTextCFStringTag, 4, new int[] {ptr});
		OS.CFRelease (ptr);
	}
}

public Point computeSize (int wHint, int hHint, boolean changed) {
	checkWidget ();
	// NEEDS WORK
	int width = 100;
	int height = 30;
	if (wHint != SWT.DEFAULT) width = wHint;
	if (hHint != SWT.DEFAULT) height = hHint;
	return new Point (width, height);
}

public void copy () {
	checkWidget ();
	// NEEDS WORK
}

void createHandle () {
	// NEEDS WORK - SIMPLE
	if ((style & SWT.READ_ONLY) != 0) {
		int [] outControl = new int [1];
		int window = OS.GetControlOwner (parent.handle);
		/* From ControlDefinitions.h:
		 * 
		 * Passing in a menu ID of -12345 causes the popup not to try and get the menu from a
		 * resource. Instead, you can build the menu and later stuff the MenuRef field in
		 * the popup data information.                                                                         
		 */
		OS.CreatePopupButtonControl(window, null, 0, (short)-12345, true, (short)0, (short)0, 0, outControl);
		if (outControl [0] == 0) error (SWT.ERROR_NO_HANDLES);
		handle = outControl [0];
		int[] menuRef= new int[1];
		OS.CreateNewMenu ((short)0, 0, menuRef);
		if (menuRef [0] == 0) error (SWT.ERROR_NO_HANDLES);
		menuHandle = menuRef[0];
		OS.SetControlPopupMenuHandle(handle, menuHandle);
	} else {
		int [] outControl = new int [1];
		CGRect rect = new CGRect ();
		int kHIComboBoxAutoCompletionAttribute = (1 << 0);
		int inAttributes = kHIComboBoxAutoCompletionAttribute | OS.kHIComboBoxAutoSizeListAttribute;
		OS.HIComboBoxCreate(rect, 0, null, 0, inAttributes, outControl);
		if (outControl [0] == 0) error (SWT.ERROR_NO_HANDLES);
		handle = outControl [0];
		OS.HIViewSetVisible (handle, true);
	}
	OS.HIViewAddSubview (parent.handle, handle);
	OS.HIViewSetZOrder (handle, OS.kHIViewZOrderBelow, 0);
}

public void cut () {
	checkWidget ();
	// NEEDS WORK
}

public void deselect (int index) {
	checkWidget ();
	if (index == -1) return;
	// NEEDS WORK
}

public void deselectAll () {
	checkWidget ();
	// NEEDS WORK
}

public String getItem (int index) {
	checkWidget ();
	int count = getItemCount ();
	if (0 > index || index >= count) error (SWT.ERROR_INVALID_RANGE);
	int[] ptr = new int[1];
	int result;
	if ((style & SWT.READ_ONLY) != 0) {
		result = OS.CopyMenuItemTextAsCFString(menuHandle, (short)(index+1), ptr);
	} else {
		result = OS.HIComboBoxCopyTextItemAtIndex (handle, index, ptr);
	}
	if (result != OS.noErr) error(SWT.ERROR_CANNOT_GET_ITEM);
	int length = OS.CFStringGetLength (ptr [0]);
	char [] buffer= new char [length];
	CFRange range = new CFRange ();
	range.length = length;
	OS.CFStringGetCharacters (ptr [0], range, buffer);
	OS.CFRelease (ptr [0]);
	return new String (buffer);
}

public int getItemCount () {
	checkWidget ();
	int count;
	if ((style & SWT.READ_ONLY) != 0) {
		count = OS.CountMenuItems (menuHandle);
	} else {
		count = OS.HIComboBoxGetItemCount (handle);
	}
	return count;
}

public int getItemHeight () {
	checkWidget ();
	return 26; // NEEDS WORK
}

public String [] getItems () {
	checkWidget ();
	int count = getItemCount ();
	String [] result = new String [count];
	for (int i=0; i<count; i++) result [i] = getItem (i);
	return result;
}

public Point getSelection () {
	checkWidget ();
	Point selection;
	if ((style & SWT.READ_ONLY) != 0) {
		// NEEDS WORK
		selection = new Point(0, 0);
	} else {
		short [] s = new short [2];
		OS.GetControlData (handle, (short)OS.kHIComboBoxEditTextPart, OS.kControlEditTextSelectionTag, 4, s, null);
		selection = new Point (s[0], s[2]);
	}
	return selection;
}

public int getSelectionIndex () {
	checkWidget ();
	int index;
	if ((style & SWT.READ_ONLY) != 0) {
		index = OS.GetControlValue (handle) - 1;
	} else {
		// NEEDS WORK
    	index = indexOf(getText ());
	}
	return index;
}

public String getText () {
	checkWidget ();
	int [] ptr = new int [1];
	int result;
	if ((style & SWT.READ_ONLY) != 0) {
		int index = OS.GetControlValue (handle) - 1;
		result = OS.CopyMenuItemTextAsCFString(menuHandle, (short)(index+1), ptr);
	} else {
		int [] actualSize = new int [1];
		result = OS.GetControlData (handle, (short)OS.kHIComboBoxEditTextPart, OS.kControlEditTextCFStringTag, 4, ptr, actualSize);
	}
	if (result != OS.noErr) return "";
	int length = OS.CFStringGetLength (ptr [0]);
	char [] buffer= new char [length];
	CFRange range = new CFRange ();
	range.length = length;
	OS.CFStringGetCharacters (ptr [0], range, buffer);
	OS.CFRelease (ptr [0]);
	return new String (buffer);
}

public int getTextHeight () {
	checkWidget();
	return 26; // NEEDS WORK
}

public int getTextLimit () {
	checkWidget();
    return LIMIT; // NEEDS WORK
}

public int indexOf (String string) {
	return indexOf (string, 0);
}

public int indexOf (String string, int start) {
	checkWidget();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);
	int count = getItemCount ();
	for (int i=start; i<count; i++) {
		if (string.equals (getItem (i))) {
			return i;
		}
	}
	return -1;
}

public void paste () {
	checkWidget ();
	// NEEDS WORK
}

public void remove (int index) {
	checkWidget ();
	if (index == -1) error (SWT.ERROR_INVALID_RANGE);
	int count = getItemCount ();
	if (0 > index || index >= count) error (SWT.ERROR_INVALID_RANGE);
	if ((style & SWT.READ_ONLY) != 0) {
		OS.DeleteMenuItems (menuHandle, (short)(index+1), 1);
	} else {
		OS.HIComboBoxRemoveItemAtIndex (handle, index);
	}
}

public void remove (int start, int end) {
	checkWidget();
	if (start > end) return;
	int count = getItemCount ();
	if (0 > start || start >= count) error (SWT.ERROR_INVALID_RANGE);
	int newEnd = Math.min (end, count - 1);
	if ((style & SWT.READ_ONLY) != 0) {
		OS.DeleteMenuItems (menuHandle, (short)(start+1), newEnd-start+1);
		OS.SetControl32BitMaximum (handle, OS.CountMenuItems (menuHandle));
	} else {
		// NEEDS WORK
		for (int i=newEnd; i>=start; i--) {
			OS.HIComboBoxRemoveItemAtIndex(handle, i);
		}
	}
}

public void remove (String string) {
	checkWidget ();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);
	// NEEDS WORK
	int count = getItemCount ();
	for (int i=0; i<count; i++) {
		String s = getItem (i);
		if (string.equals (s)) {
			remove (i);
			return;
		}
	}
	error (SWT.ERROR_INVALID_ARGUMENT);
}

public void removeAll () {
	checkWidget ();
	int count = getItemCount ();
	if ((style & SWT.READ_ONLY) != 0) {
		OS.DeleteMenuItems (menuHandle, (short)1, count);
	} else {
		// NEEDS WORK
		if (count > 0) {
			for (int i=count-1; i>=0; i--) {
  				OS.HIComboBoxRemoveItemAtIndex (handle, i);
			}
		}
	}
}

public void removeModifyListener (ModifyListener listener) {
	checkWidget();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (eventTable == null) return;
	eventTable.unhook (SWT.Modify, listener);
}

public void removeSelectionListener (SelectionListener listener) {
	checkWidget();
	if (listener == null) error (SWT.ERROR_NULL_ARGUMENT);
	if (eventTable == null) return;
	eventTable.unhook (SWT.Selection, listener);
	eventTable.unhook (SWT.DefaultSelection,listener);
}

public void select (int index) {
	checkWidget ();
	int count = getItemCount ();
	if (0 > index || index >= count) error (SWT.ERROR_INVALID_RANGE);
	if ((style & SWT.READ_ONLY) != 0) {
		OS.SetControl32BitValue (handle, index+1);
	} else {
		int[] ptr = new int[1];
		if (OS.HIComboBoxCopyTextItemAtIndex (handle, index, ptr) != OS.noErr) return;
		OS.SetControlData (handle, (short)OS.kHIComboBoxEditTextPart, OS.kControlEditTextCFStringTag, 4, ptr);
		OS.CFRelease (ptr [0]);		
	}
}

public void setItem (int index, String string) {
	checkWidget ();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);
	int count = getItemCount ();
	if (0 > index || index >= count) error (SWT.ERROR_INVALID_RANGE);
	char [] buffer = new char [string.length ()];
	string.getChars (0, buffer.length, buffer, 0);
	int ptr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
	if (ptr == 0) error (SWT.ERROR_ITEM_NOT_ADDED);
	int result;
	if ((style & SWT.READ_ONLY) != 0) {
		result = OS.SetMenuItemTextWithCFString (menuHandle, (short)(index+1), ptr);
	} else {
		result = OS.HIComboBoxInsertTextItemAtIndex (handle, index, ptr);
		OS.HIComboBoxRemoveItemAtIndex (handle, index+1);
	}
	OS.CFRelease(ptr);
	if (result != OS.noErr) error (SWT.ERROR_ITEM_NOT_ADDED);
}

public void setItems (String [] items) {
	checkWidget();
	if (items == null) error (SWT.ERROR_NULL_ARGUMENT);
	removeAll();
	if (items.length == 0) return;
	for (int i= 0; i < items.length; i++) {
		String string = items[i];
		if (string == null) continue;
		char [] buffer = new char [string.length ()];
		string.getChars (0, buffer.length, buffer, 0);
		int ptr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
		if (ptr == 0) error (SWT.ERROR_ITEM_NOT_ADDED);
		int result;
		if ((style & SWT.READ_ONLY) != 0) {
			result = OS.AppendMenuItemTextWithCFString (menuHandle, ptr, 0, 0, null);
		} else {
			int [] outIndex = new int[1];
			result = OS.HIComboBoxAppendTextItem (handle, ptr, outIndex);
		}
		OS.CFRelease(ptr);
		if (result != OS.noErr) error (SWT.ERROR_ITEM_NOT_ADDED);
	}
}

public void setSelection (Point selection) {
	checkWidget ();
	if (selection == null) error (SWT.ERROR_NULL_ARGUMENT);
	if ((style & SWT.READ_ONLY) != 0) {
		// NEEDS WORK
	} else {
		short [] s = new short [] {(short)selection.x, (short)selection.y };
		OS.SetControlData (handle, OS.kHIComboBoxEditTextPart, OS.kControlEditTextSelectionTag, 4, s);
	}
}

public void setText (String string) {
	checkWidget ();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);
	if ((style & SWT.READ_ONLY) != 0) {
		int index = indexOf (string);
		if (index != -1) select(index);
	} else {
		char [] buffer = new char [string.length ()];
		string.getChars (0, buffer.length, buffer, 0);
		int ptr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
		if (ptr == 0) return;	
		OS.SetControlData (handle, OS.kHIComboBoxEditTextPart, OS.kControlEditTextCFStringTag, 4, new int[] {ptr});
		OS.CFRelease (ptr);
	}
}

public void setTextLimit (int limit) {
	checkWidget ();
	if (limit == 0) error (SWT.ERROR_CANNOT_BE_ZERO);
	// NEEDS WORK
}

}
