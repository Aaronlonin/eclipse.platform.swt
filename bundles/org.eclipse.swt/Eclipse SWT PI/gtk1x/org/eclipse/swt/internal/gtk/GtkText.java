package org.eclipse.swt.internal.gtk;

/*
 * Copyright (c) IBM Corp. 2000, 2001.  All rights reserved.
 *
 * The contents of this file are made available under the terms
 * of the GNU Lesser General Public License (LGPL) Version 2.1 that
 * accompanies this distribution (lgpl-v21.txt).  The LGPL is also
 * available at http://www.gnu.org/licenses/lgpl.html.  If the version
 * of the LGPL at http://www.gnu.org is different to the version of
 * the LGPL accompanying this distribution and there is any conflict
 * between the two license versions, the terms of the LGPL accompanying
 * this distribution shall govern.
 */

public class GtkText extends GtkEditable {
	public int first_line_start_index;
	public int first_onscreen_hor_pixel;
	public int first_onscreen_ver_pixel;
	public int default_tab_width;
	public int cursor_pos_x;
	public int cursor_pos_y;
	public int cursor_virtual_x;
	
	private GtkText() {}
	public GtkText(int ptr) {
		OS.memmove(this, ptr);
	}
}
