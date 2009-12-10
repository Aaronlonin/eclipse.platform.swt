/*******************************************************************************
 * Copyright (c) 2009 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/

package org.eclipse.swt.examples.accessibility;

import org.eclipse.swt.SWT;
import org.eclipse.swt.accessibility.ACC;
import org.eclipse.swt.accessibility.Accessible;
import org.eclipse.swt.accessibility.AccessibleControlAdapter;
import org.eclipse.swt.accessibility.AccessibleControlEvent;
import org.eclipse.swt.accessibility.AccessibleTextEvent;
import org.eclipse.swt.accessibility.AccessibleTextExtendedEvent;
import org.eclipse.swt.accessibility.AccessibleTextExtendedListener;
import org.eclipse.swt.graphics.GC;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;

public class AccessibleTextExtendedListenerExample {

	public static void main(String[] args) {
		final Display display = new Display();
		final Shell shell = new Shell(display, SWT.SHELL_TRIM);
		shell.setLayout(new FillLayout());
		Canvas canvas = new Canvas(shell, SWT.NONE);
		final String text = "line one\nline two\nline three";
		canvas.addListener(SWT.Paint, new Listener() {
			public void handleEvent(Event event) {
				event.gc.drawText(text, 10, 10);
			}
		});
		canvas.addListener(SWT.KeyDown, new Listener() {
			public void handleEvent(Event event) {
			}
		});
		Accessible acc = canvas.getAccessible();
		acc.addAccessibleControlListener(new AccessibleControlAdapter() {
			public void getRole(AccessibleControlEvent e) {
				e.detail = ACC.ROLE_TEXT;
			}
			public void getLocation(AccessibleControlEvent e) {
				GC gc = new GC(shell);
				Point extent = gc.textExtent(text);
				gc.dispose();
				e.x = 10;
				e.y = 10;
				e.width = extent.x;
				e.height = extent.y;
			}
			public void getState(AccessibleControlEvent e) {
				e.detail = ACC.STATE_FOCUSABLE; //how do you say enabled?
			}
			public void getValue(AccessibleControlEvent e) {
				e.result = text;
			}
		});
		acc.addAccessibleTextExtendedListener(new AccessibleTextExtendedListener() {
			public void getSelectionRange(AccessibleTextEvent e) {
				e.offset = 1;
				e.length = 10;
			}
			public void getCaretOffset(AccessibleTextEvent e) {
				e.offset = 16;
			}
			public void setSelection(AccessibleTextExtendedEvent e) {
				System.out.println("Never Called: setSelection");
			}
			public void setCaretOffset(AccessibleTextExtendedEvent e) {
				System.out.println("Never Called: setCaretOffset");
			}
			public void scrollText(AccessibleTextExtendedEvent e) {
				System.out.println("Never Called: scrollText");
			}
			public void removeSelection(AccessibleTextExtendedEvent e) {
				System.out.println("Never Called: removeSelection");
				
			}
			public void getTextBounds(AccessibleTextExtendedEvent e) {
				e.x = 10;
				e.y = 10;
				e.width = 100;
				e.height = 100;
			}
			public void getText(AccessibleTextExtendedEvent e) {
				int start = 0, end = text.length();
				switch (e.type) {
					case ACC.TEXT_BOUNDARY_ALL:
						start = e.start;
						end = e.end; 
						break;
					case ACC.TEXT_BOUNDARY_CHAR:
						start = e.count >= 0 ? e.start + e.count : e.start - e.count;
						start = Math.max(0, Math.min(end, start));
						end = start;
						e.count = start - e.start;
						e.start = start;
						e.end = start;
						break;
					case ACC.TEXT_BOUNDARY_LINE:
						int offset = e.count <= 0 ? e.start : e.end;
						offset = Math.min(offset, text.length());
						int lineCount = 0;
						int index = 0;
						while(index != -1) {
							lineCount ++;
							index = text.indexOf("\n", index);
							if (index != -1) index++;
						}
						e.count = e.count < 0 ? Math.max(e.count, -lineCount) : Math.min(e.count, lineCount);
				 		index = 0;
						int lastIndex = 0;
						String[] lines = new String[lineCount];
						for (int i = 0; i < lines.length; i++) {
							index = text.indexOf("\n", index);
							lines[i] = index != -1 ? 
											text.substring(lastIndex, index) :
											text.substring(lastIndex);
							lastIndex = index;
							index++;
						}
						int len = 0;
						int lineAtOffset = 0;
						for (int i = 0; i < lines.length; i++) {
							len += lines[i].length();
							if (len >= e.offset) {
								lineAtOffset = i;
								break;
							}
						}
						int result = Math.max(0, Math.min(lineCount-1, lineAtOffset + e.count));
						e.count = result -lineAtOffset;
						e.result = lines[result];
						break;
					case ACC.TEXT_BOUNDARY_PARAGRAPH:
						//TODO
						break;
					case ACC.TEXT_BOUNDARY_SENTENCE:
						//TODO
						break;
					case ACC.TEXT_BOUNDARY_WORD:
						//TODO
						break;
				}
				e.result = text.substring(start, end);
			}
			public void getSelectionCount(AccessibleTextExtendedEvent e) {
				e.count = 1;
			}
			public void getSelection(AccessibleTextExtendedEvent e) {
				getSelectionRange(e);
				e.start = e.offset;
				e.end = e.offset + e.length;
			}
			public void getRanges(AccessibleTextExtendedEvent e) {
				e.start = 0;
				e.end = text.length() - 1;
				int[] ranges = {0,1,2,4,7,18};
				e.ranges = ranges;
			}
			public void getOffsetAtPoint(AccessibleTextExtendedEvent e) {
				System.out.println("Not Called: getOffsetAtPoint");
			}
			public void getHyperlinkIndex(AccessibleTextExtendedEvent e) {
				System.out.println("Not Called: getHyperlinkIndex");
			}
			public void getHyperlinkCount(AccessibleTextExtendedEvent e) {
				System.out.println("Not Called: getHyperlinkCount");
			}
			public void getHyperlink(AccessibleTextExtendedEvent e) {
				System.out.println("Not Called: getHyperlink");
			}
			public void getCharacterCount(AccessibleTextExtendedEvent e) {
				e.count = text.length();
			}
			public void addSelection(AccessibleTextExtendedEvent e) {
				System.out.println("NEVER CALLED: addSelection" );
			}
			public void getVisibleRanges(AccessibleTextExtendedEvent e) {
				
			}
		});
		shell.open();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch())
				display.sleep();
		}
		display.dispose();
	}

}
