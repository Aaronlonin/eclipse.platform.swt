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

#ifdef NATIVE_STATS
extern int GNOME_nativeFunctionCount;
extern int GNOME_nativeFunctionCallCount[];
extern char* GNOME_nativeFunctionNames[];
#define GNOME_NATIVE_ENTER(env, that, func) GNOME_nativeFunctionCallCount[func]++;
#define GNOME_NATIVE_EXIT(env, that, func) 
#else
#define GNOME_NATIVE_ENTER(env, that, func) 
#define GNOME_NATIVE_EXIT(env, that, func) 
#endif

typedef enum {
	GnomeVFSMimeApplication_1sizeof_FUNC,
	g_1free_FUNC,
	g_1list_1next_FUNC,
	g_1object_1unref_FUNC,
	gnome_1icon_1lookup_FUNC,
	gnome_1icon_1theme_1lookup_1icon_FUNC,
	gnome_1icon_1theme_1new_FUNC,
	gnome_1vfs_1get_1registered_1mime_1types_FUNC,
	gnome_1vfs_1init_FUNC,
	gnome_1vfs_1mime_1application_1free_FUNC,
	gnome_1vfs_1mime_1extensions_1list_1free_FUNC,
	gnome_1vfs_1mime_1get_1default_1application_FUNC,
	gnome_1vfs_1mime_1get_1extensions_1list_FUNC,
	gnome_1vfs_1mime_1registered_1mime_1type_1list_1free_FUNC,
	memmove_FUNC,
} GNOME_FUNCS;
