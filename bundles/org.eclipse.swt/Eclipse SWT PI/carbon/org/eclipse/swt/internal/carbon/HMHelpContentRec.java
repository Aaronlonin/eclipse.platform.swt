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

 
public class HMHelpContentRec {
	public int version;
//	Rect absHotRect;
	public short absHotRect_top;
	public short absHotRect_left;
	public short absHotRect_bottom;
	public short absHotRect_right;
	public short tagSide;
//	HMHelpContent       content[2];
	public int content0_contentType;
	public int content0_tagCFString; 
	public int content1_contentType;
	public int content1_tagCFString;
	public static final int sizeof = 534;
}
