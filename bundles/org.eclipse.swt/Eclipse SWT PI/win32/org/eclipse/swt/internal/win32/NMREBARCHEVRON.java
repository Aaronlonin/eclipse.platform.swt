/*******************************************************************************
 * Copyright (c) 2000, 2003 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.internal.win32;

public class NMREBARCHEVRON extends NMHDR {
	// NMHDR hdr;
	public int uBand;		// UINT
	public int wID;		// UINT
	public int lParam;	// LPARAM
	// RECT rc;
	public int left, top, right, bottom;
	public int lParamNM;	// LPARAM
	public static int sizeof = 44;
}
