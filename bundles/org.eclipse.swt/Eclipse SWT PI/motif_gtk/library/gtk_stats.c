/*******************************************************************************
* Copyright (c) 2000, 2004 IBM Corporation and others. All rights reserved.
* The contents of this file are made available under the terms
* of the GNU Lesser General Public License (LGPL) Version 2.1 that
* accompanies this distribution (lgpl-v21.txt).  The LGPL is also
* available at http://www.gnu.org/licenses/lgpl.html.  If the version
* of the LGPL at http://www.gnu.org is different to the version of
* the LGPL accompanying this distribution and there is any conflict
* between the two license versions, the terms of the LGPL accompanying
* this distribution shall govern.
* 
* Contributors:
*     IBM Corporation - initial API and implementation
*******************************************************************************/

#include "swt.h"
#include "os_structs.h"

#ifdef NATIVE_STATS

int GTK_nativeFunctionCount = 12;
int GTK_nativeFunctionCallCount[12];
char * GTK_nativeFunctionNames[] = {
	"GTK_1WIDGET_1HEIGHT", 
	"GTK_1WIDGET_1WIDTH", 
	"g_1signal_1connect", 
	"gtk_1events_1pending", 
	"gtk_1init_1check", 
	"gtk_1main", 
	"gtk_1main_1iteration", 
	"gtk_1plug_1new", 
	"gtk_1widget_1destroy", 
	"gtk_1widget_1show", 
	"gtk_1widget_1show_1now", 
	"gtk_1window_1new", 
};

#endif
