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
#include "structs.h"

#define OS_NATIVE(func) Java_org_eclipse_swt_internal_motif_OS_##func

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_motif_OS_Call
  (JNIEnv *env, jclass that, jint proc, jint arg0, jint arg1)
{
	jint rc;
	NATIVE_ENTER(env, that, "Call\n")
	rc = (*((jint (*)(jint, jint))proc)) (arg0, arg1);
	NATIVE_EXIT(env, that, "Call\n")
	return rc;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_motif_OS_fd_1set_1sizeof
  (JNIEnv *env, jclass that)
{
	jint rc;
	NATIVE_ENTER(env, that, "fd_1set_1sizeof\n")
	rc = sizeof(fd_set);
	NATIVE_EXIT(env, that, "fd_1set_1sizeof\n")
	return rc;
}

static int RESOURCES_START;
static int RESOURCES_END;

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_motif_OS_setResourceMem
  (JNIEnv *env, jclass that, jint start, jint end)
{
    RESOURCES_START = start;
    RESOURCES_END = end;
}

#define MAX_ARGS 32
JNIEXPORT void JNICALL OS_NATIVE(XtGetValues)
  (JNIEnv *env, jclass that, jint widget, jintArray argList, jint numArgs)
{
    jint *argList1=NULL;

    int valueBuff[MAX_ARGS];
    int zeroBuff[MAX_ARGS];
    int *values = valueBuff;
    int *zeros = zeroBuff;
    int i;

	NATIVE_ENTER(env, that, "XtGetValues\n")
    if (argList) argList1 = (*env)->GetIntArrayElements(env, argList, NULL);    

#ifndef SOLARIS
	if (numArgs > MAX_ARGS) {
		values = (int *) XtMalloc (numArgs * sizeof(int));
		zeros = (int *) XtMalloc (numArgs * sizeof(int));
	}
    for (i = 0; i < numArgs; i++) {   
        zeros[i] = values[i] = 0;
        if (argList1[i * 2 + 1] == 0) {
        	if ((RESOURCES_START <= argList1[i*2]) && (argList1[i*2] <= RESOURCES_END)) {
	            zeros[i] = 1;
    	        argList1[i * 2 + 1] = (int)&values[i];
            }
        }
    }
#endif
    XtGetValues((Widget)widget, (ArgList)argList1, numArgs);
#ifndef SOLARIS
    for (i = 0; i < numArgs; i++) {   
        if (zeros[i]) {
           char* charPtr = (char *)(argList1[i*2] - 1);
           switch ((int)*charPtr) {
              case 1: argList1[i * 2 + 1] = *(char *)(&values[i]); break;
              case 2: argList1[i * 2 + 1] = *(short *)(&values[i]); break;
              default:
                 argList1[i * 2 + 1] = values[i];
           }
        }
    }
	if (numArgs > MAX_ARGS) {
		XtFree((char *)values);
		XtFree((char *)zeros);
	}
#endif

    if (argList)(*env)->ReleaseIntArrayElements(env, argList, argList1, 0);
	NATIVE_EXIT(env, that, "XtGetValues\n")
}
