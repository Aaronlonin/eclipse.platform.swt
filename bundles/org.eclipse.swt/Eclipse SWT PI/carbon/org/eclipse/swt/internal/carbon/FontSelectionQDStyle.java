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
package org.eclipse.swt.internal.carbon;


public class FontSelectionQDStyle {
	public int version;
	//FMFontFamilyInstance instance;
	public short instance_fontFamily;
	public short instance_fontStyle;
	public short size;
	public boolean hasColor;
	public byte reserved;
	//RGBColor color
	public short color_red;
	public short color_green;
	public short color_blue;
	public static final int sizeof = 18;
}
