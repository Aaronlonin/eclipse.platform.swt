/*******************************************************************************
 * Copyright (c) 2000, 2007 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    IBM Corporation - initial API and implementation
 *******************************************************************************/

#include "swt.h"
#include "os_structs.h"
#include "os_stats.h"

#define OS_NATIVE(func) Java_org_eclipse_swt_internal_cocoa_OS_##func

#ifndef NO_GetCurrentProcess
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentProcess)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, GetCurrentProcess_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL)) == NULL) goto fail;
	rc = (jint)GetCurrentProcess((ProcessSerialNumber *)lparg0);
fail:
	if (arg0 && lparg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, GetCurrentProcess_FUNC);
	return rc;
}
#endif

#ifndef NO_NSBitsPerPixelFromDepth
JNIEXPORT jint JNICALL OS_NATIVE(NSBitsPerPixelFromDepth)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, NSBitsPerPixelFromDepth_FUNC);
	rc = (jint)NSBitsPerPixelFromDepth(arg0);
	OS_NATIVE_EXIT(env, that, NSBitsPerPixelFromDepth_FUNC);
	return rc;
}
#endif

#ifndef NO_SetFrontProcess
JNIEXPORT jint JNICALL OS_NATIVE(SetFrontProcess)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, SetFrontProcess_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL)) == NULL) goto fail;
	rc = (jint)SetFrontProcess((ProcessSerialNumber *)lparg0);
fail:
	if (arg0 && lparg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, SetFrontProcess_FUNC);
	return rc;
}
#endif

#ifndef NO_TransformProcessType
JNIEXPORT jint JNICALL OS_NATIVE(TransformProcessType)
	(JNIEnv *env, jclass that, jintArray arg0, jint arg1)
{
	jint *lparg0=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, TransformProcessType_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL)) == NULL) goto fail;
	rc = (jint)TransformProcessType((ProcessSerialNumber *)lparg0, arg1);
fail:
	if (arg0 && lparg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, TransformProcessType_FUNC);
	return rc;
}
#endif

#ifndef NO_class_1addMethods
JNIEXPORT void JNICALL OS_NATIVE(class_1addMethods)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, class_1addMethods_FUNC);
	class_addMethods((Class)arg0, (struct objc_method_list*)arg1);
	OS_NATIVE_EXIT(env, that, class_1addMethods_FUNC);
}
#endif

#ifndef NO_memmove__ILorg_eclipse_swt_internal_cocoa_objc_1class_2I
JNIEXPORT void JNICALL OS_NATIVE(memmove__ILorg_eclipse_swt_internal_cocoa_objc_1class_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	struct objc_class _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memmove__ILorg_eclipse_swt_internal_cocoa_objc_1class_2I_FUNC);
	if (arg1) if ((lparg1 = getobjc_classFields(env, arg1, &_arg1)) == NULL) goto fail;
	memmove((void *)arg0, (const void *)lparg1, (size_t)arg2);
fail:
	OS_NATIVE_EXIT(env, that, memmove__ILorg_eclipse_swt_internal_cocoa_objc_1class_2I_FUNC);
}
#endif

#ifndef NO_memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_1list_2I
JNIEXPORT void JNICALL OS_NATIVE(memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_1list_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	struct objc_method_list _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_1list_2I_FUNC);
	if (arg1) if ((lparg1 = getobjc_method_listFields(env, arg1, &_arg1)) == NULL) goto fail;
	memmove((void *)arg0, (const void *)lparg1, (size_t)arg2);
fail:
	OS_NATIVE_EXIT(env, that, memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_1list_2I_FUNC);
}
#endif

#ifndef NO_memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_2I
JNIEXPORT void JNICALL OS_NATIVE(memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	struct objc_method _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_2I_FUNC);
	if (arg1) if ((lparg1 = getobjc_methodFields(env, arg1, &_arg1)) == NULL) goto fail;
	memmove((void *)arg0, (const void *)lparg1, (size_t)arg2);
fail:
	OS_NATIVE_EXIT(env, that, memmove__ILorg_eclipse_swt_internal_cocoa_objc_1method_2I_FUNC);
}
#endif

#ifndef NO_memmove__Lorg_eclipse_swt_internal_cocoa_objc_1class_2II
JNIEXPORT void JNICALL OS_NATIVE(memmove__Lorg_eclipse_swt_internal_cocoa_objc_1class_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	struct objc_class _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cocoa_objc_1class_2II_FUNC);
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setobjc_classFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cocoa_objc_1class_2II_FUNC);
}
#endif

#ifndef NO_memmove__Lorg_eclipse_swt_internal_cocoa_objc_1method_1list_2II
JNIEXPORT void JNICALL OS_NATIVE(memmove__Lorg_eclipse_swt_internal_cocoa_objc_1method_1list_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	struct objc_method_list _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cocoa_objc_1method_1list_2II_FUNC);
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setobjc_method_listFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cocoa_objc_1method_1list_2II_FUNC);
}
#endif

#ifndef NO_objc_1addClass
JNIEXPORT void JNICALL OS_NATIVE(objc_1addClass)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, objc_1addClass_FUNC);
	objc_addClass((Class)arg0);
	OS_NATIVE_EXIT(env, that, objc_1addClass_FUNC);
}
#endif

#ifndef NO_objc_1getClass
JNIEXPORT jint JNICALL OS_NATIVE(objc_1getClass)
	(JNIEnv *env, jclass that, jbyteArray arg0)
{
	jbyte *lparg0=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1getClass_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL)) == NULL) goto fail;
	rc = (jint)objc_getClass((const char *)lparg0);
fail:
	if (arg0 && lparg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, objc_1getClass_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1lookUpClass
JNIEXPORT jint JNICALL OS_NATIVE(objc_1lookUpClass)
	(JNIEnv *env, jclass that, jbyteArray arg0)
{
	jbyte *lparg0=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1lookUpClass_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL)) == NULL) goto fail;
	rc = (jint)objc_lookUpClass((const char *)lparg0);
fail:
	if (arg0 && lparg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, objc_1lookUpClass_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__II
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__II)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__II_FUNC);
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__II_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__III
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__III)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__III_FUNC);
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, arg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__III_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IIII
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IIII)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IIII_FUNC);
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, arg2, arg3);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IIII_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IIIII
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IIIII)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IIIII_FUNC);
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, arg2, arg3, arg4);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IIIII_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IIIIII
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IIIIII)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IIIIII_FUNC);
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, arg2, arg3, arg4, arg5);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IIIIII_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSPoint_2
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSPoint_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jobject arg3)
{
	NSPoint _arg3, *lparg3=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSPoint_2_FUNC);
	if (arg3) if ((lparg3 = getNSPointFields(env, arg3, &_arg3)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, arg2, *lparg3);
fail:
	if (arg3 && lparg3) setNSPointFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSPoint_2_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSRect_2I
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSRect_2I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jobject arg3, jint arg4)
{
	NSRect _arg3, *lparg3=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSRect_2I_FUNC);
	if (arg3) if ((lparg3 = getNSRectFields(env, arg3, &_arg3)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, arg2, *lparg3, arg4);
fail:
	if (arg3 && lparg3) setNSRectFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IIILorg_eclipse_swt_internal_cocoa_NSRect_2I_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	NSPoint _arg2, *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2_FUNC);
	if (arg2) if ((lparg2 = getNSPointFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, lparg2);
fail:
	if (arg2 && lparg2) setNSPointFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2I
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jint arg3)
{
	NSPoint _arg2, *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2I_FUNC);
	if (arg2) if ((lparg2 = getNSPointFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, *lparg2, arg3);
fail:
	if (arg2 && lparg2) setNSPointFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSPoint_2I_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	NSRect _arg2, *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2_FUNC);
	if (arg2) if ((lparg2 = getNSRectFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, *lparg2);
fail:
	if (arg2 && lparg2) setNSRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2I
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jint arg3)
{
	NSRect _arg2, *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2I_FUNC);
	if (arg2) if ((lparg2 = getNSRectFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, *lparg2, arg3);
fail:
	if (arg2 && lparg2) setNSRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2I_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2IIZ
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2IIZ)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jint arg3, jint arg4, jboolean arg5)
{
	NSRect _arg2, *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2IIZ_FUNC);
	if (arg2) if ((lparg2 = getNSRectFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, *lparg2, arg3, arg4, arg5);
fail:
	if (arg2 && lparg2) setNSRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSRect_2IIZ_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSSize_2
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSSize_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	NSSize _arg2, *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSSize_2_FUNC);
	if (arg2) if ((lparg2 = getNSSizeFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, *lparg2);
fail:
	if (arg2 && lparg2) setNSSizeFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__IILorg_eclipse_swt_internal_cocoa_NSSize_2_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__II_3CI
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__II_3CI)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jcharArray arg2, jint arg3)
{
	jchar *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__II_3CI_FUNC);
	if (arg2) if ((lparg2 = (*env)->GetCharArrayElements(env, arg2, NULL)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, lparg2, arg3);
fail:
	if (arg2 && lparg2) (*env)->ReleaseCharArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__II_3CI_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend__II_3IIIIIIIIIII
JNIEXPORT jint JNICALL OS_NATIVE(objc_1msgSend__II_3IIIIIIIIIII)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jint arg3, jint arg4, jint arg5, jint arg6, jint arg7, jint arg8, jint arg9, jint arg10, jint arg11, jint arg12)
{
	jint *lparg2=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, objc_1msgSend__II_3IIIIIIIIIII_FUNC);
	if (arg2) if ((lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL)) == NULL) goto fail;
	rc = (jint)objc_msgSend((id)arg0, (SEL)arg1, lparg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
fail:
	if (arg2 && lparg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, objc_1msgSend__II_3IIIIIIIIIII_FUNC);
	return rc;
}
#endif

#ifndef NO_objc_1msgSend_1stret
JNIEXPORT void JNICALL OS_NATIVE(objc_1msgSend_1stret)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	NSRect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, objc_1msgSend_1stret_FUNC);
	if (arg0) if ((lparg0 = getNSRectFields(env, arg0, &_arg0)) == NULL) goto fail;
	objc_msgSend_stret(lparg0, (id)arg1, (SEL)arg2);
fail:
	if (arg0 && lparg0) setNSRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, objc_1msgSend_1stret_FUNC);
}
#endif

#ifndef NO_sel_1registerName
JNIEXPORT jint JNICALL OS_NATIVE(sel_1registerName)
	(JNIEnv *env, jclass that, jbyteArray arg0)
{
	jbyte *lparg0=NULL;
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, sel_1registerName_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL)) == NULL) goto fail;
	rc = (jint)sel_registerName((const char *)lparg0);
fail:
	if (arg0 && lparg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, sel_1registerName_FUNC);
	return rc;
}
#endif

