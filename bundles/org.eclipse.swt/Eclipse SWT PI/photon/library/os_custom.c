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

#include "swt.h"
#include "os_structs.h"

#define OS_NATIVE(func) Java_org_eclipse_swt_internal_photon_OS_##func

#ifdef PR_20268
#include "clip.c"
#include "pt_blit.c"
#include "pt_draw_widget.c"
#define PtBlit PtBlit_
#define PtClippedBlit PtClippedBlit_
#endif

#ifndef NO_PhGetTile
JNIEXPORT jint JNICALL OS_NATIVE(PhGetTile)
	(JNIEnv *env, jclass that)
{
	jint rc;
	NATIVE_ENTER(env, that, "PhGetTile\n")
	rc = (jint)PhGetTile();
	memset((void *)rc, 0, sizeof(PhTile_t));
	NATIVE_EXIT(env, that, "PhGetTile\n")
	return rc;
}
#endif
