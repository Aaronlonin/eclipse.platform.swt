package org.eclipse.swt.tests.junit;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.*;
import org.eclipse.swt.widgets.*;
import org.eclipse.swt.custom.*;
import junit.framework.*;
import junit.textui.*;

/**
 * Automated Test Suite for class org.eclipse.swt.custom.LineBackgroundListener
 *
 * @see org.eclipse.swt.custom.LineBackgroundListener
 */
public class Test_org_eclipse_swt_custom_LineBackgroundListener extends SwtTestCase {
	Shell shell;
	StyledText styledText;

public Test_org_eclipse_swt_custom_LineBackgroundListener(String name) {
	super(name);
}
public static void main(String[] args) {
	TestRunner.run(suite());
}
protected void setUp() {
	shell = new Shell();
	styledText = new StyledText(shell, SWT.NULL);
	shell.open();
}
public static Test suite() {
	TestSuite suite = new TestSuite();
	java.util.Vector methodNames = methodNames();
	java.util.Enumeration e = methodNames.elements();
	while (e.hasMoreElements()) {
		suite.addTest(new Test_org_eclipse_swt_custom_LineBackgroundListener((String)e.nextElement()));
	}
	return suite;
}
protected void tearDown() {
}

public void test_lineGetBackgroundLorg_eclipse_swt_custom_LineBackgroundEvent() {
	LineBackgroundListener listener = new LineBackgroundListener() {
		public void lineGetBackground(LineBackgroundEvent event) {
			assertTrue(":1:", event.lineOffset==0);
			assertTrue(":2:",event.lineText.equals("0123456789"));
		}
	};
	styledText.addLineBackgroundListener(listener);
	styledText.setText("0123456789");
	// force get line bg callback
	styledText.selectAll();
	styledText.copy();
	styledText.removeLineBackgroundListener(listener);
}

public static java.util.Vector methodNames() {
	java.util.Vector methodNames = new java.util.Vector();
	methodNames.addElement("test_lineGetBackgroundLorg_eclipse_swt_custom_LineBackgroundEvent");
	return methodNames;
}
protected void runTest() throws Throwable {
	if (getName().equals("test_lineGetBackgroundLorg_eclipse_swt_custom_LineBackgroundEvent")) test_lineGetBackgroundLorg_eclipse_swt_custom_LineBackgroundEvent();
}
}
