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
package org.eclipse.swt.internal.photon;


public class PhClipHeader {

	public byte type_0;
	public byte type_1;
	public byte type_2;
	public byte type_3;
	public byte type_4;
	public byte type_5;
	public byte type_6;
	public byte type_7;
	public short length;
	public short zero;
	public int data;
	
	public static final int sizeof = 16;

}

