package org.eclipse.swt.events;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.internal.EventListenerCompatibility;

/**
 * Classes which implement this interface provide methods
 * that deal with changes in state of <code>Shell</code>s.
 * <p>
 * After creating an instance of a class that implements
 * this interface it can be added to a control using the
 * <code>addShellListener</code> method and removed using
 * the <code>removeShellListener</code> method. When the
 * state of a shell changes, the appropriate method will
 * be invoked.
 * </p>
 *
 * @see ShellAdapter
 * @see ShellEvent
 */
public interface ShellListener extends EventListenerCompatibility {

/**
 * Sent when a shell becomes the active window.
 *
 * @param e an event containing information about the activation
 */
public void shellActivated(ShellEvent e);

/**
 * Sent when a shell is closed.
 *
 * @param e an event containing information about the close
 */
public void shellClosed(ShellEvent e);

/**
 * Sent when a shell stops being the active window.
 *
 * @param e an event containing information about the deactivation
 */
public void shellDeactivated(ShellEvent e);

/**
 * Sent when a shell is un-minimized.
 *
 * @param e an event containing information about the un-minimization
 */
public void shellDeiconified(ShellEvent e);

/**
 * Sent when a shell is minimized.
 *
 * @param e an event containing information about the minimization
 */
public void shellIconified(ShellEvent e);
}
