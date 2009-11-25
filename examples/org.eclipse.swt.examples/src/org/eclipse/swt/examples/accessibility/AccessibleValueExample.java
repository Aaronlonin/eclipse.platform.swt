/*******************************************************************************
 * Copyright (c) 2008 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.examples.accessibility;

import org.eclipse.swt.*;
import org.eclipse.swt.widgets.*;
import org.eclipse.swt.layout.*;
import org.eclipse.swt.accessibility.*;

/**
 * This example shows how to use an AccessibleValueListener to provide
 * additional information to an AT.
 */
public class AccessibleValueExample {
	public static void main(String[] args) {
		Display display = new Display();
		Shell shell = new Shell(display);
		shell.setLayout(new GridLayout());
		shell.setText("Accessible Value");
		
		Text text = new Text(shell, SWT.BORDER);
		text.setText("Tab over to the scale");
		
		final Scale scale = new Scale(shell, SWT.NONE);
		scale.setSelection(5);
		
		Accessible accessibleScale = scale.getAccessible();
		accessibleScale.addAccessibleListener(new AccessibleAdapter() {
			public void getName(AccessibleEvent e) {
				e.result = "This is the scale's new accessible name";
			}
		});
		accessibleScale.addAccessibleValueListener(new AccessibleValueAdapter() {
			public void setCurrentValue(AccessibleValueEvent e) {
				scale.setSelection(e.value.intValue());
			}
			public void getMinimumValue(AccessibleValueEvent e) {
				e.value = new Integer(scale.getMinimum());
			}
			public void getMaximumValue(AccessibleValueEvent e) {
				e.value = new Integer(scale.getMaximum());
			}
			public void getCurrentValue(AccessibleValueEvent e) {
				e.value = new Integer(scale.getSelection());
			}
		});

		shell.pack();
		shell.open();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) display.sleep();
		}
		display.dispose();
	}
}