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
#include "cde_structs.h"

#define CDE_NATIVE(func) Java_org_eclipse_swt_internal_cde_CDE_##func

#ifndef NO_DtActionInvoke
JNIEXPORT jint JNICALL CDE_NATIVE(DtActionInvoke)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1, jobject arg2, jint arg3, jbyteArray arg4, jbyteArray arg5, jbyteArray arg6, jint arg7, jint arg8, jint arg9)
{
	jbyte *lparg1=NULL;
	DtActionArg _arg2, *lparg2=NULL;
	jbyte *lparg4=NULL;
	jbyte *lparg5=NULL;
	jbyte *lparg6=NULL;
	jint rc;
	CDE_NATIVE_ENTER(env, that, DtActionInvoke_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = getDtActionArgFields(env, arg2, &_arg2);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetByteArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetByteArrayElements(env, arg6, NULL);
	rc = (jint)DtActionInvoke((Widget)arg0, (char *)lparg1, lparg2, arg3, (char *)lparg4, (char *)lparg5, (char *)lparg6, arg7, (DtActionCallbackProc)arg8, (XtPointer)arg9);
	if (arg6) (*env)->ReleaseByteArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseByteArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	if (arg2) setDtActionArgFields(env, arg2, lparg2);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	CDE_NATIVE_EXIT(env, that, DtActionInvoke_FUNC);
	return rc;
}
#endif

#ifndef NO_DtAppInitialize
JNIEXPORT jboolean JNICALL CDE_NATIVE(DtAppInitialize)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jbyteArray arg3, jbyteArray arg4)
{
	jbyte *lparg3=NULL;
	jbyte *lparg4=NULL;
	jboolean rc;
	CDE_NATIVE_ENTER(env, that, DtAppInitialize_FUNC);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	rc = (jboolean)DtAppInitialize((XtAppContext)arg0, (Display *)arg1, (Widget)arg2, (char *)lparg3, (char *)lparg4);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	CDE_NATIVE_EXIT(env, that, DtAppInitialize_FUNC);
	return rc;
}
#endif

#ifndef NO_DtDbLoad
JNIEXPORT void JNICALL CDE_NATIVE(DtDbLoad)
	(JNIEnv *env, jclass that)
{
	CDE_NATIVE_ENTER(env, that, DtDbLoad_FUNC);
	DtDbLoad();
	CDE_NATIVE_EXIT(env, that, DtDbLoad_FUNC);
}
#endif

#ifndef NO_DtDtsDataTypeIsAction
JNIEXPORT jboolean JNICALL CDE_NATIVE(DtDtsDataTypeIsAction)
	(JNIEnv *env, jclass that, jbyteArray arg0)
{
	jbyte *lparg0=NULL;
	jboolean rc;
	CDE_NATIVE_ENTER(env, that, DtDtsDataTypeIsAction_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	rc = (jboolean)DtDtsDataTypeIsAction((char *)lparg0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	CDE_NATIVE_EXIT(env, that, DtDtsDataTypeIsAction_FUNC);
	return rc;
}
#endif

#ifndef NO_DtDtsDataTypeNames
JNIEXPORT jint JNICALL CDE_NATIVE(DtDtsDataTypeNames)
	(JNIEnv *env, jclass that)
{
	jint rc;
	CDE_NATIVE_ENTER(env, that, DtDtsDataTypeNames_FUNC);
	rc = (jint)DtDtsDataTypeNames();
	CDE_NATIVE_EXIT(env, that, DtDtsDataTypeNames_FUNC);
	return rc;
}
#endif

#ifndef NO_DtDtsDataTypeToAttributeValue
JNIEXPORT jint JNICALL CDE_NATIVE(DtDtsDataTypeToAttributeValue)
	(JNIEnv *env, jclass that, jbyteArray arg0, jbyteArray arg1, jbyteArray arg2)
{
	jbyte *lparg0=NULL;
	jbyte *lparg1=NULL;
	jbyte *lparg2=NULL;
	jint rc;
	CDE_NATIVE_ENTER(env, that, DtDtsDataTypeToAttributeValue_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetByteArrayElements(env, arg2, NULL);
	rc = (jint)DtDtsDataTypeToAttributeValue((char *)lparg0, (char *)lparg1, (char *)lparg2);
	if (arg2) (*env)->ReleaseByteArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	CDE_NATIVE_EXIT(env, that, DtDtsDataTypeToAttributeValue_FUNC);
	return rc;
}
#endif

#ifndef NO_DtDtsFileToDataType
JNIEXPORT jint JNICALL CDE_NATIVE(DtDtsFileToDataType)
	(JNIEnv *env, jclass that, jbyteArray arg0)
{
	jbyte *lparg0=NULL;
	jint rc;
	CDE_NATIVE_ENTER(env, that, DtDtsFileToDataType_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	rc = (jint)DtDtsFileToDataType((char *)lparg0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	CDE_NATIVE_EXIT(env, that, DtDtsFileToDataType_FUNC);
	return rc;
}
#endif

#ifndef NO_DtDtsFreeAttributeValue
JNIEXPORT void JNICALL CDE_NATIVE(DtDtsFreeAttributeValue)
	(JNIEnv *env, jclass that, jint arg0)
{
	CDE_NATIVE_ENTER(env, that, DtDtsFreeAttributeValue_FUNC);
	DtDtsFreeAttributeValue((char *)arg0);
	CDE_NATIVE_EXIT(env, that, DtDtsFreeAttributeValue_FUNC);
}
#endif

#ifndef NO_DtDtsFreeDataType
JNIEXPORT void JNICALL CDE_NATIVE(DtDtsFreeDataType)
	(JNIEnv *env, jclass that, jint arg0)
{
	CDE_NATIVE_ENTER(env, that, DtDtsFreeDataType_FUNC);
	DtDtsFreeDataType((char *)arg0);
	CDE_NATIVE_EXIT(env, that, DtDtsFreeDataType_FUNC);
}
#endif

#ifndef NO_DtDtsFreeDataTypeNames
JNIEXPORT void JNICALL CDE_NATIVE(DtDtsFreeDataTypeNames)
	(JNIEnv *env, jclass that, jint arg0)
{
	CDE_NATIVE_ENTER(env, that, DtDtsFreeDataTypeNames_FUNC);
	DtDtsFreeDataTypeNames((char **)arg0);
	CDE_NATIVE_EXIT(env, that, DtDtsFreeDataTypeNames_FUNC);
}
#endif

