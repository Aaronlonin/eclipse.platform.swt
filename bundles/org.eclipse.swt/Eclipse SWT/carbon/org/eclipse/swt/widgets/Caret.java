package org.eclipse.swt.widgets;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.internal.carbon.OS;

import org.eclipse.swt.*;
import org.eclipse.swt.graphics.*;

public class Caret extends Widget {
	Canvas parent;
	int x, y, width, height;
	boolean isVisible, isShowing;
	int blinkRate;
	Image image;

public Caret (Canvas parent, int style) {
	super (parent, style);
	this.parent = parent;
	createWidget ();
}

boolean blinkCaret () {
	if (!isVisible) return true;
	if (!isShowing) return showCaret ();
	if (blinkRate == 0) return true;
	return hideCaret ();
}

void createWidget () {
	Display display = parent.getDisplay ();
	blinkRate = display.getCaretBlinkTime ();
	isVisible = true;
	if (parent.getCaret () == null) {
		parent.setCaret (this);
	}
}

boolean drawCaret () {
	if (parent == null) return false;
	if (parent.isDisposed ()) return false;
	int nWidth = width, nHeight = height;
	if (image != null) {
		Rectangle rect = image.getBounds ();
		nWidth = rect.width;
		nHeight = rect.height;
	}
	if (nWidth <= 0) nWidth = 2;
	GC gc = new GC (parent);
	gc.setXORMode (true);
	gc.fillRectangle (x, y, nWidth, nHeight);
	gc.dispose ();
	return true;
}

public Rectangle getBounds () {
	checkWidget();
	if (image != null) {
		Rectangle rect = image.getBounds ();
		return new Rectangle (x, y, rect.width, rect.height);
	}
	return new Rectangle (x, y, width, height);
}

public Display getDisplay () {
	Composite parent = this.parent;
	if (parent == null) error (SWT.ERROR_WIDGET_DISPOSED);
	return parent.getDisplay ();
}

public Font getFont () {
	checkWidget();
	return parent.getFont ();
}


public Image getImage () {
	checkWidget();
	return image;
}

public Point getLocation () {
	checkWidget();
	return new Point (x, y);
}

public Canvas getParent () {
	checkWidget();
	return parent;
}

public Point getSize () {
	checkWidget();
	if (image != null) {
		Rectangle rect = image.getBounds ();
		return new Point (rect.width, rect.height);
	}
	return new Point (width, height);
}

public boolean getVisible () {
	checkWidget();
	return isVisible;
}

boolean hideCaret () {
	if (!isShowing) return true;
	isShowing = false;
	return drawCaret ();
}

public boolean isVisible () {
	checkWidget();
	return isVisible && parent.isVisible () && parent.hasFocus ();
}

boolean isFocusCaret () {
	Display display = getDisplay ();
	return this == display.currentCaret;
}

void killFocus () {
	Display display = getDisplay ();
	if (display.currentCaret != this) return;
	display.setCurrentCaret (null);
	if (isVisible) hideCaret ();
}

void releaseChild () {
	super.releaseChild ();
	if (this == parent.getCaret ()) parent.setCaret (null);
}

void releaseWidget () {
	super.releaseWidget ();
	Display display = getDisplay ();
	if (display.currentCaret == this) {
		hideCaret ();
		display.setCurrentCaret (null);
	}
	parent = null;
	image = null;
}

public void setBounds (int x, int y, int width, int height) {
	checkWidget();
	if (this.x == x && this.y == y && this.width == width && this.height == height) return;
	boolean isFocus = isFocusCaret ();
	if (isFocus) hideCaret ();
	this.x = x; this.y = y;
	this.width = width; this.height = height;
//	parent.updateCaret ();
	if (isFocus) showCaret ();
}

public void setBounds (Rectangle rect) {
	checkWidget();
	if (rect == null) error (SWT.ERROR_NULL_ARGUMENT);
	setBounds (rect.x, rect.y, rect.width, rect.height);
}

void setFocus () {
	Display display = getDisplay ();
	if (display.currentCaret == this) return;
	display.setCurrentCaret (this);
	if (isVisible) showCaret ();
}

public void setFont (Font font) {
	checkWidget();
	if (font != null && font.isDisposed ()) {
		error (SWT.ERROR_INVALID_ARGUMENT);
	}
}

public void setImage (Image image) {
	checkWidget();
	if (image != null && image.isDisposed ()) {
		error (SWT.ERROR_INVALID_ARGUMENT);
	}
	boolean isFocus = isFocusCaret ();
	if (isFocus) hideCaret ();
	this.image = image;
	if (isFocus) showCaret ();
}

public void setLocation (int x, int y) {
	checkWidget();
	setBounds (x, y, width, height);
}

public void setLocation (Point location) {
	checkWidget();
	if (location == null) error (SWT.ERROR_NULL_ARGUMENT);
	setLocation (location.x, location.y);
}

public void setSize (int width, int height) {
	checkWidget();
	setBounds (x, y, width, height);
}

public void setSize (Point size) {
	checkWidget();
	if (size == null) error (SWT.ERROR_NULL_ARGUMENT);
	setSize (size.x, size.y);
}

public void setVisible (boolean visible) {
	checkWidget();
	if (visible == isVisible) return;
	isVisible = visible;
	if (!isFocusCaret ()) return;
	if (isVisible) {
		showCaret ();
	} else {
		hideCaret ();
	}
}

boolean showCaret () {
	if (isShowing) return true;
	isShowing = true;
	return drawCaret ();
}

}
