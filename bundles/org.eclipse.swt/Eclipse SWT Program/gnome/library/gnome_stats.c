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
#include "gnome_stats.h"

#ifdef NATIVE_STATS

int GNOME_nativeFunctionCount = 15;
int GNOME_nativeFunctionCallCount[15];
char * GNOME_nativeFunctionNames[] = {
	"GnomeVFSMimeApplication_1sizeof",
	"g_1free",
	"g_1list_1next",
	"g_1object_1unref",
	"gnome_1icon_1lookup",
	"gnome_1icon_1theme_1lookup_1icon",
	"gnome_1icon_1theme_1new",
	"gnome_1vfs_1get_1registered_1mime_1types",
	"gnome_1vfs_1init",
	"gnome_1vfs_1mime_1application_1free",
	"gnome_1vfs_1mime_1extensions_1list_1free",
	"gnome_1vfs_1mime_1get_1default_1application",
	"gnome_1vfs_1mime_1get_1extensions_1list",
	"gnome_1vfs_1mime_1registered_1mime_1type_1list_1free",
	"memmove",
};

#define STATS_NATIVE(func) Java_org_eclipse_swt_tools_internal_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(GNOME_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return GNOME_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(GNOME_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, GNOME_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(GNOME_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return GNOME_nativeFunctionCallCount[index];
}

#endif
