package org.eclipse.swt.widgets;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.*;
import org.eclipse.swt.graphics.*;

public class Decorations extends Canvas {
	Image image;
	Menu menuBar;
	String text;
	boolean minimized, maximized;
	Button defaultButton, saveDefault;
	
Decorations () {
	/* Do nothing */
}

public Decorations (Composite parent, int style) {
	super (parent, checkStyle (style));
}

static int checkStyle (int style) {
	if ((style & (SWT.MENU | SWT.MIN | SWT.MAX | SWT.CLOSE)) != 0) {
		style |= SWT.TITLE;
	}
	return style;
}

protected void checkSubclass () {
	if (!isValidSubclass ()) error (SWT.ERROR_INVALID_SUBCLASS);
}

Control computeTabGroup () {
	return this;
}

Control computeTabRoot () {
	return this;
}

void createHandle (int index) {
	state |= CANVAS | GRAB;
}

public Button getDefaultButton () {
	checkWidget();
	return defaultButton;
}

public Image getImage () {
	checkWidget();
	return image;
}

public boolean getMaximized () {
	checkWidget();
	return maximized;
}

public Menu getMenuBar () {
	checkWidget();
	return menuBar;
}

public boolean getMinimized () {
	checkWidget();
	return minimized;
}

String getNameText () {
	return getText ();
}

public String getText () {
	checkWidget();
	return text;
}

boolean isTabGroup () {
	return true;
}

boolean isTabItem () {
	return false;
}

Decorations menuShell () {
	return this;
}

void releaseWidget () {
	super.releaseWidget ();
	defaultButton = saveDefault = null;
}

public void setDefaultButton (Button button) {
	checkWidget();
	setDefaultButton (button, true);
}

void setDefaultButton (Button button, boolean save) {
}

public void setImage (Image image) {
	checkWidget();
	if (image != null) {
		if (image.isDisposed()) error(SWT.ERROR_INVALID_ARGUMENT);
	}
	this.image = image;
}

public void setMaximized (boolean maximized) {
	checkWidget();
	this.maximized = maximized;
}

public void setMenuBar (Menu menu) {
	checkWidget();
	if (menuBar == menu) return;
	if (menu != null) {
		if (menu.isDisposed()) error(SWT.ERROR_INVALID_ARGUMENT);
		if ((menu.style & SWT.BAR) == 0) error (SWT.ERROR_MENU_NOT_BAR);
		if (menu.parent != this) error (SWT.ERROR_INVALID_PARENT);
	}
	menuBar = menu;
	//NOT DONE
	Display display = getDisplay ();
//	display.setMenuBar (menuBar);
}

public void setMinimized (boolean minimized) {
	checkWidget();
	this.minimized = minimized;
}

public void setText (String string) {
	checkWidget();
	if (string == null) error (SWT.ERROR_NULL_ARGUMENT);
	text = string;
}

}
