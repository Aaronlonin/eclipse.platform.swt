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
#include "atk_stats.h"

#ifdef NATIVE_STATS

int ATK_nativeFunctionCount = 37;
int ATK_nativeFunctionCallCount[37];
char * ATK_nativeFunctionNames[] = {
	"ATK_1ACTION_1GET_1IFACE", 
	"ATK_1COMPONENT_1GET_1IFACE", 
	"ATK_1OBJECT_1FACTORY_1CLASS", 
	"ATK_1SELECTION_1GET_1IFACE", 
	"ATK_1TEXT_1GET_1IFACE", 
	"AtkObjectFactoryClass_1sizeof", 
	"AtkObjectFactory_1sizeof", 
	"GTK_1ACCESSIBLE", 
	"atk_1focus_1tracker_1notify", 
	"atk_1get_1default_1registry", 
	"atk_1object_1factory_1get_1accessible_1type", 
	"atk_1object_1initialize", 
	"atk_1registry_1get_1factory", 
	"atk_1registry_1set_1factory_1type", 
	"atk_1state_1set_1add_1state", 
	"atk_1state_1set_1new", 
	"call__II", 
	"call__III", 
	"call__IIII", 
	"call__IIIII", 
	"call__IIIIII", 
	"call__IIIIIII", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkActionIface_2", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkComponentIface_2", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkHypertextIface_2", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkObjectClass_2", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkObjectFactoryClass_2", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkSelectionIface_2", 
	"memmove__ILorg_eclipse_swt_internal_accessibility_gtk_AtkTextIface_2", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkActionIface_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkComponentIface_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkHypertextIface_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkObjectClass_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkObjectFactoryClass_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkSelectionIface_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_AtkTextIface_2I", 
	"memmove__Lorg_eclipse_swt_internal_accessibility_gtk_GtkAccessible_2I", 
};

#endif
