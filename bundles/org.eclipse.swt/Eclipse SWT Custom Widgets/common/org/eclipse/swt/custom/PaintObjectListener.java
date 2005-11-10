/*******************************************************************************
 * Copyright (c) 2000, 2005 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.custom;

import org.eclipse.swt.internal.SWTEventListener;

public interface PaintObjectListener extends SWTEventListener {
/**
 * This method is called when an object needs to be drawn.
 * 
 * <p>
 * The following event fields are used:<ul>
 * <li>event.x the x location (input)</li>
 * <li>event.y the y location (input)</li>
 * <li>event.ascent the line ascent (input)</li>
 * <li>event.descent the line descent (input)</li>
 * <li>event.gc the gc (input)</li>
 * <li>event.start the start offset (input)</li>
 * <li>event.length the length (input)</li>
 * </ul>
 *
 * @param event the given event
 * @see PaintObjectEvent
 * @since 3.2
 */
public void paintObject(PaintObjectEvent event);
}
