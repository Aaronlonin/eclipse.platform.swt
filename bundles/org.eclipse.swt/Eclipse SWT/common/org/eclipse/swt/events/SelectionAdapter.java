package org.eclipse.swt.events;

/*
 * Licensed Materials - Property of IBM,
 * (c) Copyright IBM Corp. 1998, 2001  All Rights Reserved
 */

/**
 * This adapter class provides default implementations for the
 * methods described by the <code>SelectionListener</code> interface.
 * <p>
 * Classes that wish to deal with <code>SelectionEvent</code>s can
 * extend this class and override only the methods which they are
 * interested in.
 * </p>
 *
 * @see SelectionListener
 * @see SelectionEvent
 */
public abstract class SelectionAdapter implements SelectionListener {

/**
 * Sent when selection occurs in the control.
 * The default behavior is to do nothing.
 *
 * @param e an event containing information about the selection
 */
public void widgetSelected(SelectionEvent e) {
}

/**
 * Sent when default selection occurs in the control.
 * The default behavior is to do nothing.
 *
 * @param e an event containing information about the default selection
 */
public void widgetDefaultSelected(SelectionEvent e) {
}
}
