package org.eclipse.swt.internal.win32;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */
public class DROPFILES {
	public int pFiles; // Offset of the file list from the beginning of this structure, in bytes.
	//public POINT pt; // Drop point. The coordinates depend on fNC.
	public int pt_x;
	public int pt_y;
	public int fNC;   // Nonclient area flag. If this member is TRUE, pt specifies the screen 
				      // coordinates of a point in a window's nonclient area. If it is FALSE, 
				      // pt specifies the client coordinates of a point in the client area. 
	public int fWide; // Value that indicates whether the file contains ANSI or Unicode 
					  // characters. If it is zero, it contains ANSI characters. Otherwise, it 
				      // contains Unicode characters.

	public static final int sizeof = 20;
}
