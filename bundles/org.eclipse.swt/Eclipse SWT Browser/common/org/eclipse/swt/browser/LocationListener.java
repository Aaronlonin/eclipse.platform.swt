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

import org.eclipse.swt.internal.SWTEventListener;

/**
 * This listener interface may be implemented in order to receive
 * LocationEvents.
 * 
 * <p>
 * NOTE: The API in the browser package is NOT finalized.
 * Use at your own risk, because it will most certainly change.
 * The only reason this API is being released at this time is so that 
 * other teams can try it out.
 * </p>
 * 
 * @see LocationEvent
 * 
 * @since 3.0
 */
public interface LocationListener extends SWTEventListener {

/**
 * This method is called when the current location is changed.
 * <p>
 *
 * @param event.location the current location 
 *
 * @see LocationEvent
 * 
 * @since 3.0
 */ 
public void changed(LocationEvent event);
}
