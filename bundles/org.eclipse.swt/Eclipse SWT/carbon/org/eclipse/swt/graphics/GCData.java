package org.eclipse.swt.graphics;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.*;

/**
 * Instances of this class are descriptions of GCs in terms
 * of unallocated platform-specific data fields.
 * <p>
 * <b>IMPORTANT:</b> This class is <em>not</em> part of the public
 * API for SWT. It is marked public only so that it can be shared
 * within the packages provided by SWT. It is not available on all
 * platforms, and should never be called from application code.
 * </p>
 *
 * @private
 */
public final class GCData {
	public Device device;
	public Image image;
	public float[] foreground;
	public float[] background;
	public int clipRgn;
	public int lineWidth = 1;
	public int lineStyle = SWT.LINE_SOLID;
	public boolean xorMode;
	
	public Font font;
	public int fontAscent;
	public int fontDescent;
	public int layout;
	public int atsuiStyle;
	
	public int paintEvent;
	public int visibleRgn;
	public int control;
}
