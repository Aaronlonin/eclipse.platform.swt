/*******************************************************************************
 * Copyright (c) 2000, 2004 IBM Corporation and others.
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
#include "os_stats.h"

#define OS_NATIVE(func) Java_org_eclipse_swt_internal_motif_OS_##func

static int RESOURCES_START;
static int RESOURCES_END;

#ifndef NO_setResourceMem
JNIEXPORT void JNICALL OS_NATIVE(setResourceMem)
  (JNIEnv *env, jclass that, jint start, jint end)
{
	OS_NATIVE_ENTER(env, that, setResourceMem_FUNC)
    RESOURCES_START = start;
    RESOURCES_END = end;
	OS_NATIVE_EXIT(env, that, setResourceMem_FUNC)
}
#endif

#ifndef NO_XtGetValues
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

	OS_NATIVE_ENTER(env, that, XtGetValues_FUNC)
	if (argList) if ((argList1 = (*env)->GetIntArrayElements(env, argList, NULL)) == NULL) goto failTag;
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
	XtGetValues((Widget)widget, (ArgList)argList1, numArgs);
failTag:
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
	if (argList)(*env)->ReleaseIntArrayElements(env, argList, argList1, 0);
	OS_NATIVE_EXIT(env, that, XtGetValues_FUNC)
}
#endif

#ifndef NO_MonitorEnter
JNIEXPORT jint JNICALL OS_NATIVE(MonitorEnter)
	(JNIEnv *env, jclass that, jobject arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, MonitorEnter_FUNC);
	rc = (jint)(*env)->MonitorEnter(env, arg0);
	OS_NATIVE_EXIT(env, that, MonitorEnter_FUNC);
	return rc;
}
#endif

#ifndef NO_MonitorExit
JNIEXPORT jint JNICALL OS_NATIVE(MonitorExit)
	(JNIEnv *env, jclass that, jobject arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, MonitorExit_FUNC);
	rc = (jint)(*env)->MonitorExit(env, arg0);
	OS_NATIVE_EXIT(env, that, MonitorExit_FUNC);
	return rc;
}
#endif
