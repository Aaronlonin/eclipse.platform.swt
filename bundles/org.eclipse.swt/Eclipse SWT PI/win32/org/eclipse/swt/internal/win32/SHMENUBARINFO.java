package org.eclipse.swt.internal.win32;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */
public class SHMENUBARINFO {
	public int cbSize;
	public int hwndParent;
	public int dwFlags;
	public int nToolBarId;
	public int hInstRes;
	public int nBmpId;
	public int cBmpImages;
	public int hwndMB;
	public static final int sizeof = OS.IsSP ? 36 : 32;
}