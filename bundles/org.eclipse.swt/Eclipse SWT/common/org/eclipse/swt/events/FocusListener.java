package org.eclipse.swt.events;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.internal.EventListenerCompatibility;

/**
 * Classes which implement this interface provide methods
 * that deal with the events that are generated as controls
 * gain and lose focus.
 * <p>
 * After creating an instance of a class that implements
 * this interface it can be added to a control using the
 * <code>addFocusListener</code> method and removed using
 * the <code>removeFocusListener</code> method. When a
 * control gains or loses focus, the appropriate method
 * will be invoked.
 * </p>
 *
 * @see FocusAdapter
 * @see FocusEvent
 */
public interface FocusListener extends EventListenerCompatibility {

/**
 * Sent when a control gets focus.
 *
 * @param e an event containing information about the focus change
 */
public void focusGained(FocusEvent e);

/**
 * Sent when a control loses focus.
 *
 * @param e an event containing information about the focus change
 */
public void focusLost(FocusEvent e);
}

