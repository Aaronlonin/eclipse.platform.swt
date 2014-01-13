/*******************************************************************************
 * Copyright (c) 2000, 2004 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.tests.junit;


import junit.framework.*;
import junit.textui.*;

import org.eclipse.swt.events.*;
import org.eclipse.swt.widgets.*;

/**
 * Automated Test Suite for class org.eclipse.swt.events.FocusEvent
 *
 * @see org.eclipse.swt.events.FocusEvent
 */
public class Test_org_eclipse_swt_events_FocusEvent extends Test_org_eclipse_swt_events_TypedEvent {

public Test_org_eclipse_swt_events_FocusEvent(String name) {
	super(name);
}

public static void main(String[] args) {
	TestRunner.run(suite());
}

public static Test suite() {
	TestSuite suite = new TestSuite();
	java.util.Vector<String> methodNames = methodNames();
	java.util.Enumeration<String> e = methodNames.elements();
	while (e.hasMoreElements()) {
		suite.addTest(new Test_org_eclipse_swt_events_FocusEvent(e.nextElement()));
	}
	return suite;
}

/* custom */
@Override
protected TypedEvent newTypedEvent(Event event) {
	return new FocusEvent(event);
}
}
