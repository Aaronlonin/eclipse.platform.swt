package org.eclipse.swt.widgets;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.internal.carbon.OS;
import org.eclipse.swt.internal.carbon.RGBColor;
import org.eclipse.swt.internal.carbon.Rect;

import org.eclipse.swt.*;
import org.eclipse.swt.graphics.*;

public class Composite extends Scrollable {
	Layout layout;
	Control[] tabList;

Composite () {
	/* Do nothing */
}

public Composite (Composite parent, int style) {
	super (parent, style);
}

Control [] _getChildren () {
	short [] count = new short [1];
	OS.CountSubControls (handle, count);
	if (count [0] == 0) return new Control [0];
	Control [] children = new Control [count [0]];
	int [] outControl= new int [1];
	int i = 0, j = 0;
	while (i < count [0]) {
		int status = OS.GetIndexedSubControl (handle, (short)(i+1), outControl);
		if (status == OS.noErr) {
			Widget widget = WidgetTable.get (outControl [0]);
			if (widget != null && widget != this) {
				if (widget instanceof Control) {
					children [j++] = (Control) widget;
				}
			}
		}
		i++;
	}
	if (j == count [0]) return children;
	Control [] newChildren = new Control [j];
	System.arraycopy (children, 0, newChildren, 0, j);
	return newChildren;
}

Control [] _getTabList () {
	if (tabList == null) return null;
	int count = 0;
	for (int i=0; i<tabList.length; i++) {
		if (!tabList [i].isDisposed ()) count++;
	}
	if (count == tabList.length) return tabList;
	Control [] newList = new Control [count];
	int index = 0;
	for (int i=0; i<tabList.length; i++) {
		if (!tabList [i].isDisposed ()) {
			newList [index++] = tabList [i];
		}
	}
	tabList = newList;
	return tabList;
}

public Point computeSize (int wHint, int hHint, boolean changed) {
	checkWidget();
	Point size;
	if (layout != null) {
		if ((wHint == SWT.DEFAULT) || (hHint == SWT.DEFAULT)) {
			size = layout.computeSize (this, wHint, hHint, changed);
		} else {
			size = new Point (wHint, hHint);
		}
	} else {
		size = minimumSize ();
	}
	if (size.x == 0) size.x = DEFAULT_WIDTH;
	if (size.y == 0) size.y = DEFAULT_HEIGHT;
	if (wHint != SWT.DEFAULT) size.x = wHint;
	if (hHint != SWT.DEFAULT) size.y = hHint;
	Rectangle trim = computeTrim (0, 0, size.x, size.y);
	return new Point (trim.width, trim.height);
}

protected void checkSubclass () {
	/* Do nothing - Subclassing is allowed */
}

Control [] computeTabList () {
	Control result [] = super.computeTabList ();
	if (result.length == 0) return result;
	Control [] list = tabList != null ? _getTabList () : _getChildren ();
	for (int i=0; i<list.length; i++) {
		Control child = list [i];
		Control [] childList = child.computeTabList ();
		if (childList.length != 0) {
			Control [] newResult = new Control [result.length + childList.length];
			System.arraycopy (result, 0, newResult, 0, result.length);
			System.arraycopy (childList, 0, newResult, result.length, childList.length);
			result = newResult;
		}
	}
	return result;
}

void createHandle () {
	state |= CANVAS | GRAB;
	if ((style & (SWT.H_SCROLL | SWT.V_SCROLL)) != 0) {
		createScrolledHandle (parent.handle);
	} else {
		createHandle (parent.handle);
	}
}

void createHandle (int parentHandle) {
	int features = OS.kControlSupportsEmbedding | OS.kControlSupportsFocus | OS.kControlGetsFocusOnClick;
	int [] outControl = new int [1];
	int window = OS.GetControlOwner (parentHandle);
	OS.CreateUserPaneControl (window, null, features, outControl);
	if (outControl [0] == 0) error (SWT.ERROR_NO_HANDLES);
	handle = outControl [0];
}

void createScrolledHandle (int parentHandle) {
	int features = OS.kControlSupportsEmbedding;
	int [] outControl = new int [1];
	int window = OS.GetControlOwner (parentHandle);
	OS.CreateUserPaneControl (window, null, features, outControl);
	if (outControl [0] == 0) error (SWT.ERROR_NO_HANDLES);
	scrolledHandle = outControl [0];
	outControl [0] = 0;
	features |= OS.kControlSupportsFocus | OS.kControlGetsFocusOnClick;
	OS.CreateUserPaneControl (window, null, features, outControl);
	if (outControl [0] == 0) error (SWT.ERROR_NO_HANDLES);
	handle = outControl [0];
}

void draw (int control) {
	if (control != handle) return;
	if ((state & CANVAS) == 0) return;
	if ((style & SWT.NO_BACKGROUND) != 0) return;
	Rect rect = new Rect ();
	OS.GetControlBounds (handle, rect);
	if (background != null) {
		int red = (short) (background [0] * 255);
		int green = (short) (background [1] * 255);
		int blue = (short) (background [2] * 255);
		RGBColor color = new RGBColor ();
		color.red = (short) (red << 8 | red);
		color.green = (short) (green << 8 | green);
		color.blue = (short) (blue << 8 | blue);
		OS.RGBForeColor (color);
		OS.PaintRect (rect);
	} else {
		OS.EraseRect (rect);
	}
}

public Control [] getChildren () {
	checkWidget();
	return _getChildren ();
}

int getChildrenCount () {
	/*
	* NOTE:  The current implementation will count
	* non-registered children.
	*/
	short [] count = new short [1];
	OS.CountSubControls (handle, count);
	return count [0];
}

public Layout getLayout () {
	checkWidget();
	return layout;
}

public Control [] getTabList () {
	checkWidget ();
	Control [] tabList = _getTabList ();
	if (tabList == null) {
		int count = 0;
		Control [] list =_getChildren ();
		for (int i=0; i<list.length; i++) {
			if (list [i].isTabGroup ()) count++;
		}
		tabList = new Control [count];
		int index = 0;
		for (int i=0; i<list.length; i++) {
			if (list [i].isTabGroup ()) {
				tabList [index++] = list [i];
			}
		}
	}
	return tabList;
}

int kEventControlBoundsChanged (int nextHandler, int theEvent, int userData) {
	int result = super.kEventControlBoundsChanged (nextHandler, theEvent, userData);
	if (result == OS.noErr) return result;
	int [] theControl = new int [1];
	OS.GetEventParameter (theEvent, OS.kEventParamDirectObject, OS.typeControlRef, null, 4, null, theControl);
	if (theControl [0] == handle && layout != null) {
		int [] attributes = new int [1];
		OS.GetEventParameter (theEvent, OS.kEventParamAttributes, OS.typeUInt32, null, attributes.length * 4, null, attributes);
		if ((attributes [0] & OS.kControlBoundsChangeSizeChanged) != 0) {
			layout.layout (this, false);
		}
	}
	return OS.eventNotHandledErr;
}

int kEventControlClick (int nextHandler, int theEvent, int userData) {
	int result = super.kEventControlClick (nextHandler, theEvent, userData);
	if (result == OS.noErr) return result;
	if ((state & CANVAS) != 0 && (style & SWT.NO_FOCUS) == 0 && hooksKeys ()) {
		int [] theControl = new int [1];
		int window = OS.GetControlOwner (handle);
		OS.GetKeyboardFocus (window, theControl);
		if (handle != theControl [0]) {
			short [] count = new short [1];
			OS.CountSubControls (handle, count);
			if (count [0] == 0) {
				if (OS.SetKeyboardFocus (window, handle, (short) OS.kControlFocusNextPart) == OS.noErr) {
					return OS.noErr;
				}
			}
		}
	}
	return result;
}

int kEventControlSetFocusPart (int nextHandler, int theEvent, int userData) {
	int result = super.kEventControlSetFocusPart (nextHandler, theEvent, userData);
	if (result == OS.noErr) return result;
	return ((state & CANVAS) != 0 && (style & SWT.NO_FOCUS) == 0 && hooksKeys ()) ? OS.noErr : result;
}

boolean hooksKeys () {
	return hooks (SWT.KeyDown) || hooks (SWT.KeyUp) || hooks (SWT.Traverse);
}

public void layout () {
	checkWidget();
	layout (true);
}

public void layout (boolean changed) {
	checkWidget();
	if (layout == null) return;
	int count = getChildrenCount ();
	if (count == 0) return;
	layout.layout (this, changed);
}

Point minimumSize () {
	Control [] children = _getChildren ();
	int width = 0, height = 0;
	for (int i=0; i<children.length; i++) {
		Rectangle rect = children [i].getBounds ();
		width = Math.max (width, rect.x + rect.width);
		height = Math.max (height, rect.y + rect.height);
	}
	return new Point (width, height);
}

void releaseChildren () {
	Control [] children = _getChildren ();
	for (int i=0; i<children.length; i++) {
		Control child = children [i];
		if (!child.isDisposed ()) child.releaseResources ();
	}
}

void releaseWidget () {
	releaseChildren ();
	super.releaseWidget ();
	layout = null;
	tabList = null;
}

public boolean setFocus () {
	checkWidget ();
	if ((style & SWT.NO_FOCUS) != 0) return false;
	Control [] children = _getChildren ();
	for (int i= 0; i < children.length; i++) {
		if (children [i].setFocus ()) return true;
	}
	return super.setFocus ();
}

public void setLayout (Layout layout) {
	checkWidget();
	this.layout = layout;
}

public void setTabList (Control [] tabList) {
	checkWidget ();
	if (tabList != null) {
		for (int i=0; i<tabList.length; i++) {
			Control control = tabList [i];
			if (control == null) error (SWT.ERROR_INVALID_ARGUMENT);
			if (control.isDisposed ()) error (SWT.ERROR_INVALID_ARGUMENT);
			/*
			* This code is intentionally commented.
			* Tab lists are currently only supported
			* for the direct children of a composite.
			*/
//			Shell shell = control.getShell ();
//			while (control != shell && control != this) {
//				control = control.parent;
//			}
//			if (control != this) error (SWT.ERROR_INVALID_PARENT);
			if (control.parent != this) error (SWT.ERROR_INVALID_PARENT);
		}
		Control [] newList = new Control [tabList.length];
		System.arraycopy (tabList, 0, newList, 0, tabList.length);
		tabList = newList;
	} 
	this.tabList = tabList;
}

void setZOrder () {
	super.setZOrder ();
	if (scrolledHandle != 0) OS.HIViewAddSubview (scrolledHandle, handle);
}

}
