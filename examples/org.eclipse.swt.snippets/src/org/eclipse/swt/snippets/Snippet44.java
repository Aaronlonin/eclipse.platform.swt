/*******************************************************************************
 * Copyright (c) 2000, 2004 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.snippets;

/*
 * Cursor example snippet: set the hand cursor into a control
 *
 * For a list of all SWT example snippets see
 * http://dev.eclipse.org/viewcvs/index.cgi/%7Echeckout%7E/platform-swt-home/dev.html#snippets
 */
import org.eclipse.swt.*;
import org.eclipse.swt.graphics.*;
import org.eclipse.swt.widgets.*;

public class Snippet44 {

public static void main (String [] args) {
	Display display = new Display ();
	final Cursor cursor = new Cursor (display, SWT.CURSOR_HAND);
	Shell shell = new Shell (display);
	shell.open ();
	final Button b = new Button (shell, 0);
	b.setBounds (10, 10, 200, 200);
	b.addListener (SWT.Selection, new Listener () {
		public void handleEvent (Event e) {
			b.setCursor (cursor);
		}
	});
	while (!shell.isDisposed ()) {
		if (!display.readAndDispatch ()) display.sleep ();
	}
	cursor.dispose ();
	display.dispose ();
}
} 
