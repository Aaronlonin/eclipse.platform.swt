/*******************************************************************************
 * Copyright (c) 2000, 2003 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.tests.junit;


/**
 * Automated Test Suite for class org.eclipse.swt.events.MouseListener
 *
 * @see org.eclipse.swt.events.MouseListener
 */
public class Test_org_eclipse_swt_events_MouseListener extends SwtTestCase {

public Test_org_eclipse_swt_events_MouseListener(String name) {
	super(name);
}


protected void setUp() {
}

protected void tearDown() {
}

public void test_mouseDoubleClickLorg_eclipse_swt_events_MouseEvent() {
	warnUnimpl("Test test_mouseDoubleClickLorg_eclipse_swt_events_MouseEvent not written");
}

public void test_mouseDownLorg_eclipse_swt_events_MouseEvent() {
	warnUnimpl("Test test_mouseDownLorg_eclipse_swt_events_MouseEvent not written");
}

public void test_mouseUpLorg_eclipse_swt_events_MouseEvent() {
	warnUnimpl("Test test_mouseUpLorg_eclipse_swt_events_MouseEvent not written");
}

public static java.util.Vector methodNames() {
	java.util.Vector methodNames = new java.util.Vector();
	methodNames.addElement("test_mouseDoubleClickLorg_eclipse_swt_events_MouseEvent");
	methodNames.addElement("test_mouseDownLorg_eclipse_swt_events_MouseEvent");
	methodNames.addElement("test_mouseUpLorg_eclipse_swt_events_MouseEvent");
	return methodNames;
}
protected void runTest() throws Throwable {
	if (getName().equals("test_mouseDoubleClickLorg_eclipse_swt_events_MouseEvent")) test_mouseDoubleClickLorg_eclipse_swt_events_MouseEvent();
	else if (getName().equals("test_mouseDownLorg_eclipse_swt_events_MouseEvent")) test_mouseDownLorg_eclipse_swt_events_MouseEvent();
	else if (getName().equals("test_mouseUpLorg_eclipse_swt_events_MouseEvent")) test_mouseUpLorg_eclipse_swt_events_MouseEvent();
}
}
