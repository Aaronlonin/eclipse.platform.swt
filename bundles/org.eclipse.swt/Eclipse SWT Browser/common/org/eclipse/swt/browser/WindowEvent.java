/*******************************************************************************
 * Copyright (c) 2003 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.browser;

import org.eclipse.swt.widgets.*;
import org.eclipse.swt.events.*;
import org.eclipse.swt.graphics.*;

/**
 * This event is sent to WindowListeners.
 * 
 * <p>
 * NOTE: The API in the browser package is NOT finalized.
 * Use at your own risk, because it will most certainly change.
 * The only reason this API is being released at this time is so that 
 * other teams can try it out.
 * </p>
 * 
 * @since 3.0
 */
public class WindowEvent extends TypedEvent {
	
	/** 
	 * Browser provided by the application. Default is null and null
	 * will cancel the associated navigation request.
	 */
	public Browser browser;

	/** 
	 * Requested location for the Shell hosting the Browser. Null if no location
	 * has been requested.
	 */
	public Point location;

	/** 
	 * Requested size for the Shell hosting the Browser. Null if no size has been
	 * requested.
	 */
	public Point size;
	
WindowEvent(Widget w) {
	super(w);
}
}
