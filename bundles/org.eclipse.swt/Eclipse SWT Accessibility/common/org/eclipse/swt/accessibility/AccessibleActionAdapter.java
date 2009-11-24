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
package org.eclipse.swt.accessibility;

/**
 * This adapter class provides default implementations for the
 * methods in the <code>AccessibleActionListener</code> interface.
 * <p>
 * Classes that wish to deal with <code>AccessibleAction</code> events can
 * extend this class and override only the methods that they are
 * interested in.
 * </p>
 *
 * @see AccessibleActionListener
 * @see AccessibleActionEvent
 *
 * @since 3.6
 */
public class AccessibleActionAdapter implements AccessibleActionListener {
	/**
	 * Returns the number of accessible actions available in this object.
	 * <p>
	 * If there are more than one, the first one (index 0) is considered the
	 * "default" action of the object.
	 * </p>
	 * 
	 * @param e an event object containing the following fields:<ul>
	 * <li>[out] count - the number of actions, or zero if there are no actions
	 * </ul>
	 */
	public void getActionCount(AccessibleActionEvent e) {};

	/**
	 * Performs the specified action on the object.
	 * 
	 * @param e an event object containing the following fields:<ul>
	 * <li>[in] index - a 0 based index specifying the action to perform.
	 * 		If the index lies outside the valid range no action is performed.
	 * </ul>
	 */
	public void doAction(AccessibleActionEvent e) {};

	/**
	 * Returns a description of the specified action.
	 * 
	 * @param e an event object containing the following fields:<ul>
	 * <li>[in] index - a 0 based index specifying which action's description to return
	 * <li>[out] string - a localized string describing the specified action,
	 * 		or null if the index lies outside the valid range
	 * </ul>
	 */
	public void getDescription(AccessibleActionEvent e) {};

	/**
	 * Returns a string representing one or more key bindings, if there
	 * are any, associated with the specified action.
	 * <p>
	 * The key bindings in the returned string are delimited by semicolons.
	 * </p><p>
	 * A key binding can describe either a mnemonic, or an accelerator. As a
	 * general rule, if the control or child can receive keyboard focus, then
	 * you should expose its mnemonic(s), and if it cannot receive keyboard
	 * focus, then you should expose its accelerator(s).
	 * </p><p>
	 * There is no need to implement this method for single action, single key binding
	 * controls since that would be redundant with AccessibleListener.getKeyboardShortcut.
	 * </p>
	 * 
	 * @param e an event object containing the following fields:<ul>
	 * <li>[in] index - a 0 based index specifying which action's key bindings to return
	 * <li>[out] string - a semicolon-delimited string of localized keyboard shortcut strings
	 * 		(example: "ALT+N;CTRL+N"), or null if the index lies outside the valid range
	 * </ul>
	 */
	public void getKeyBinding(AccessibleActionEvent e) {};

	/**
	 * Returns the non-localized name of the specified action.
	 * <p>
	 * There is no need to implement this method for single action controls
	 * since that would be redundant with AccessibleControlListener.getDefaultAction.
	 * </p>
	 * 
	 * @param e an event object containing the following fields:<ul>
	 * <li>[in] index - a 0 based index specifying which action's non-localized name to return
	 * <li>[out] string - the name of the specified action,
	 * 		or null if the index lies outside the valid range
	 * </ul>
	 */
	public void getName(AccessibleActionEvent e) {};
}
