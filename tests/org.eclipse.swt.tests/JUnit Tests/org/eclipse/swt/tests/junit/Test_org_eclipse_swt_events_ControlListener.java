package org.eclipse.swt.tests.junit;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.events.*;
import junit.framework.*;
import junit.textui.*;

/**
 * Automated Test Suite for class org.eclipse.swt.events.ControlListener
 *
 * @see org.eclipse.swt.events.ControlListener
 */
public class Test_org_eclipse_swt_events_ControlListener extends SwtTestCase {

public Test_org_eclipse_swt_events_ControlListener(String name) {
	super(name);
}


protected void setUp() {
}

protected void tearDown() {
}

public void test_controlMovedLorg_eclipse_swt_events_ControlEvent() {
	warnUnimpl("Test test_controlMovedLorg_eclipse_swt_events_ControlEvent not written");
}

public void test_controlResizedLorg_eclipse_swt_events_ControlEvent() {
	warnUnimpl("Test test_controlResizedLorg_eclipse_swt_events_ControlEvent not written");
}

public static java.util.Vector methodNames() {
	java.util.Vector methodNames = new java.util.Vector();
	methodNames.addElement("test_controlMovedLorg_eclipse_swt_events_ControlEvent");
	methodNames.addElement("test_controlResizedLorg_eclipse_swt_events_ControlEvent");
	return methodNames;
}
protected void runTest() throws Throwable {
	if (getName().equals("test_controlMovedLorg_eclipse_swt_events_ControlEvent")) test_controlMovedLorg_eclipse_swt_events_ControlEvent();
	else if (getName().equals("test_controlResizedLorg_eclipse_swt_events_ControlEvent")) test_controlResizedLorg_eclipse_swt_events_ControlEvent();
}
}
