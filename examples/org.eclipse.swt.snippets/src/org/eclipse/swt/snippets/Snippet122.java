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
 * Clipboard example snippet: enable/disable menu depending on clipboard content availability
 *
 * For a list of all SWT example snippets see
 * http://dev.eclipse.org/viewcvs/index.cgi/%7Echeckout%7E/platform-swt-home/dev.html#snippets
 */
import org.eclipse.swt.*;
import org.eclipse.swt.dnd.*;
import org.eclipse.swt.events.*;
import org.eclipse.swt.layout.*;
import org.eclipse.swt.widgets.*;

public class Snippet122 {
	
public static void main(String[] args) {
	Display display = new Display();
	final Clipboard cb = new Clipboard(display);
	Shell shell = new Shell(display);
	shell.setLayout(new FillLayout());
	final Text text = new Text(shell, SWT.BORDER | SWT.MULTI | SWT.WRAP);
	Menu menu = new Menu(shell, SWT.POP_UP);
	final MenuItem copyItem = new MenuItem(menu, SWT.PUSH);
	copyItem.setText("Copy");
	copyItem.addSelectionListener(new SelectionAdapter(){
		public void widgetSelected(SelectionEvent e) {
			String selection = text.getSelectionText();
			if (selection == null) return;
			Object[] data = new Object[]{selection};
			Transfer[] types = new Transfer[] {TextTransfer.getInstance()};
			cb.setContents(data, types);
		}
	});
	final MenuItem pasteItem = new MenuItem(menu, SWT.PUSH);
	pasteItem.setText ("Paste");
	pasteItem.addSelectionListener(new SelectionAdapter(){
		public void widgetSelected(SelectionEvent e) {
			String string = (String)(cb.getContents(TextTransfer.getInstance()));
			if (string != null) {
				text.insert(string);
			}
		}
	});
	menu.addMenuListener(new MenuAdapter() {
		public void menuShown(MenuEvent e) {
			TransferData[] available = cb.getAvailableTypes();
			boolean enabled = false;
			for (int i = 0; i < available.length; i++) {
				if (TextTransfer.getInstance().isSupportedType(available[i])) {
					enabled = true;
					break;
				}
			}
			pasteItem.setEnabled(enabled);
		}
	});
	text.setMenu (menu);

	shell.setSize(200, 200);
	shell.open();
	while (!shell.isDisposed()) {
		if (!display.readAndDispatch())
			display.sleep();
	}
	cb.dispose();
	display.dispose();
}
}
