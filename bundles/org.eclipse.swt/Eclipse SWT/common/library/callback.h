/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

/**
 * Callback implementation.
 */
#ifndef INC_callback_H
#define INC_callback_H

int callback(int index, ...);

#if defined (WIN32) || defined (_WIN32_WCE)
#include "windows.h"
#define PLATFORM "win32"
#define RETURN_TYPE LRESULT CALLBACK
#define RETURN_CAST (LRESULT)
#endif

#ifdef MOTIF
#define PLATFORM "motif"
#endif

#ifdef GTK
#define PLATFORM "gtk"
#endif

#ifdef PHOTON
#define PLATFORM "photon"
#endif

#ifndef PLATFORM
#define PLATFORM "unknown"
#endif

#ifndef RETURN_TYPE
#define RETURN_TYPE int
#endif

#ifndef RETURN_CAST
#define RETURN_CAST
#endif

#ifdef REDUCED_CALLBACKS
#define MAX_CALLBACKS 16
#else
#define MAX_CALLBACKS 128
#endif /* REDUCED_CALLBACKS */

#define MAX_ARGS 12

typedef struct SWT_CALLBACKINFO {
    jobject callin;
    JNIEnv *env;
    jmethodID methodID;
} SWT_CALLBACKINFO;

#endif /* ifndef INC_callback_H */

