package org.eclipse.swt.tests.junit;

/*
 * (c) Copyright IBM Corp. 2000, 2002. All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

/**
 * Automated Test Suite for class org.eclipse.swt.events.TreeListener
 *
 * @see org.eclipse.swt.events.TreeListener
 */
public class Test_org_eclipse_swt_events_TreeListener extends SwtTestCase {

public Test_org_eclipse_swt_events_TreeListener(String name) {
	super(name);
}


protected void setUp() {
}

protected void tearDown() {
}

public void test_treeCollapsedLorg_eclipse_swt_events_TreeEvent() {
	warnUnimpl("Test test_treeCollapsedLorg_eclipse_swt_events_TreeEvent not written");
}

public void test_treeExpandedLorg_eclipse_swt_events_TreeEvent() {
	warnUnimpl("Test test_treeExpandedLorg_eclipse_swt_events_TreeEvent not written");
}

public static java.util.Vector methodNames() {
	java.util.Vector methodNames = new java.util.Vector();
	methodNames.addElement("test_treeCollapsedLorg_eclipse_swt_events_TreeEvent");
	methodNames.addElement("test_treeExpandedLorg_eclipse_swt_events_TreeEvent");
	return methodNames;
}
protected void runTest() throws Throwable {
	if (getName().equals("test_treeCollapsedLorg_eclipse_swt_events_TreeEvent")) test_treeCollapsedLorg_eclipse_swt_events_TreeEvent();
	else if (getName().equals("test_treeExpandedLorg_eclipse_swt_events_TreeEvent")) test_treeExpandedLorg_eclipse_swt_events_TreeEvent();
}
}
