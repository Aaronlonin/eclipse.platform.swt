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


public class OSVERSIONINFO {
	public int dwOSVersionInfoSize; 
	public int dwMajorVersion;
	public int dwMinorVersion;
	public int dwBuildNumber;
	public int dwPlatformId;
//	TCHAR szCSDVersion [128];
//	public char [] szCSDVersion = new char [128];
	public static final int sizeofW = 276;
	public static final int sizeofA = 148;
	public static /*final*/ int sizeof = OS.IsUnicode ? sizeofW : sizeofA;
}
