/*******************************************************************************
 * Copyright (c) 2008 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.internal.ole.win32;

import org.eclipse.swt.internal.win32.*;

public final class SHDRAGIMAGE {
	public SIZE sizeDragImage;
	public POINT ptOffset;
	public int /*long*/ hbmpDragImage;
	public int crColorKey;
	public static final int sizeof = COM.SHDRAGIMAGE_sizeof ();
}
