package org.eclipse.swt.tests.junit;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.events.*;
import junit.framework.*;
import junit.textui.*;

/**
 * Automated Test Suite for class org.eclipse.swt.events.SelectionAdapter
 *
 * @see org.eclipse.swt.events.SelectionAdapter
 */
public class Test_org_eclipse_swt_events_SelectionAdapter extends SwtTestCase {

public Test_org_eclipse_swt_events_SelectionAdapter(String name) {
	super(name);
}


protected void setUp() {
}

protected void tearDown() {
}

public void test_Constructor() {
	warnUnimpl("Test test_Constructor not written");
}

public void test_widgetSelectedLorg_eclipse_swt_events_SelectionEvent() {
	warnUnimpl("Test test_widgetSelectedLorg_eclipse_swt_events_SelectionEvent not written");
}

public void test_widgetDefaultSelectedLorg_eclipse_swt_events_SelectionEvent() {
	warnUnimpl("Test test_widgetDefaultSelectedLorg_eclipse_swt_events_SelectionEvent not written");
}

public static java.util.Vector methodNames() {
	java.util.Vector methodNames = new java.util.Vector();
	methodNames.addElement("test_Constructor");
	methodNames.addElement("test_widgetSelectedLorg_eclipse_swt_events_SelectionEvent");
	methodNames.addElement("test_widgetDefaultSelectedLorg_eclipse_swt_events_SelectionEvent");
	return methodNames;
}
protected void runTest() throws Throwable {
	if (getName().equals("test_Constructor")) test_Constructor();
	else if (getName().equals("test_widgetSelectedLorg_eclipse_swt_events_SelectionEvent")) test_widgetSelectedLorg_eclipse_swt_events_SelectionEvent();
	else if (getName().equals("test_widgetDefaultSelectedLorg_eclipse_swt_events_SelectionEvent")) test_widgetDefaultSelectedLorg_eclipse_swt_events_SelectionEvent();
}
}
