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

#define OS_NATIVE(func) Java_org_eclipse_swt_internal_carbon_OS_##func

#ifndef NO_AECountItems
JNIEXPORT jint JNICALL OS_NATIVE(AECountItems)
	(JNIEnv *env, jclass that, jobject arg0, jintArray arg1)
{
	AEDesc _arg0, *lparg0=NULL;
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AECountItems_FUNC);
	if (arg0) lparg0 = getAEDescFields(env, arg0, &_arg0);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)AECountItems((const AEDescList *)lparg0, (long *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	if (arg0) setAEDescFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, AECountItems_FUNC);
	return rc;
}
#endif

#ifndef NO_AEGetNthPtr
JNIEXPORT jint JNICALL OS_NATIVE(AEGetNthPtr)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2, jintArray arg3, jintArray arg4, jint arg5, jint arg6, jintArray arg7)
{
	AEDesc _arg0, *lparg0=NULL;
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint *lparg7=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AEGetNthPtr_FUNC);
	if (arg0) lparg0 = getAEDescFields(env, arg0, &_arg0);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg7) lparg7 = (*env)->GetIntArrayElements(env, arg7, NULL);
	rc = (jint)AEGetNthPtr((const AEDescList *)lparg0, arg1, (DescType)arg2, (AEKeyword *)lparg3, (DescType *)lparg4, (void *)arg5, (Size)arg6, (Size *)lparg7);
	if (arg7) (*env)->ReleaseIntArrayElements(env, arg7, lparg7, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg0) setAEDescFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, AEGetNthPtr_FUNC);
	return rc;
}
#endif

#ifndef NO_AEProcessAppleEvent
JNIEXPORT jint JNICALL OS_NATIVE(AEProcessAppleEvent)
	(JNIEnv *env, jclass that, jobject arg0)
{
	EventRecord _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AEProcessAppleEvent_FUNC);
	if (arg0) lparg0 = getEventRecordFields(env, arg0, &_arg0);
	rc = (jint)AEProcessAppleEvent((const EventRecord *)lparg0);
	if (arg0) setEventRecordFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, AEProcessAppleEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSFontGetPostScriptName
JNIEXPORT jint JNICALL OS_NATIVE(ATSFontGetPostScriptName)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSFontGetPostScriptName_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)ATSFontGetPostScriptName((ATSFontRef)arg0, (ATSOptionFlags)arg1, (CFStringRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, ATSFontGetPostScriptName_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUBatchBreakLines
JNIEXPORT jint JNICALL OS_NATIVE(ATSUBatchBreakLines)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jintArray arg4)
{
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUBatchBreakLines_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)ATSUBatchBreakLines((ATSUTextLayout)arg0, arg1, arg2, arg3, (ItemCount *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, ATSUBatchBreakLines_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUCreateStyle
JNIEXPORT jint JNICALL OS_NATIVE(ATSUCreateStyle)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUCreateStyle_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)ATSUCreateStyle((ATSUStyle *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, ATSUCreateStyle_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUCreateTextLayout
JNIEXPORT jint JNICALL OS_NATIVE(ATSUCreateTextLayout)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUCreateTextLayout_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)ATSUCreateTextLayout((ATSUTextLayout *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, ATSUCreateTextLayout_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUCreateTextLayoutWithTextPtr
JNIEXPORT jint JNICALL OS_NATIVE(ATSUCreateTextLayoutWithTextPtr)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jintArray arg5, jintArray arg6, jintArray arg7)
{
	jint *lparg5=NULL;
	jint *lparg6=NULL;
	jint *lparg7=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUCreateTextLayoutWithTextPtr_FUNC);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	if (arg7) lparg7 = (*env)->GetIntArrayElements(env, arg7, NULL);
	rc = (jint)ATSUCreateTextLayoutWithTextPtr((ConstUniCharArrayPtr)arg0, arg1, arg2, arg3, arg4, (const UniCharCount *)lparg5, (ATSUStyle *)lparg6, (ATSUTextLayout *)lparg7);
	if (arg7) (*env)->ReleaseIntArrayElements(env, arg7, lparg7, 0);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	OS_NATIVE_EXIT(env, that, ATSUCreateTextLayoutWithTextPtr_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUDisposeStyle
JNIEXPORT jint JNICALL OS_NATIVE(ATSUDisposeStyle)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUDisposeStyle_FUNC);
	rc = (jint)ATSUDisposeStyle((ATSUStyle)arg0);
	OS_NATIVE_EXIT(env, that, ATSUDisposeStyle_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUDisposeTextLayout
JNIEXPORT jint JNICALL OS_NATIVE(ATSUDisposeTextLayout)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUDisposeTextLayout_FUNC);
	rc = (jint)ATSUDisposeTextLayout((ATSUTextLayout)arg0);
	OS_NATIVE_EXIT(env, that, ATSUDisposeTextLayout_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUDrawText
JNIEXPORT jint JNICALL OS_NATIVE(ATSUDrawText)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUDrawText_FUNC);
	rc = (jint)ATSUDrawText((ATSUTextLayout)arg0, (UniCharArrayOffset)arg1, (UniCharCount)arg2, (ATSUTextMeasurement)arg3, (ATSUTextMeasurement)arg4);
	OS_NATIVE_EXIT(env, that, ATSUDrawText_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUFindFontFromName
JNIEXPORT jint JNICALL OS_NATIVE(ATSUFindFontFromName)
	(JNIEnv *env, jclass that, jbyteArray arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5, jintArray arg6)
{
	jbyte *lparg0=NULL;
	jint *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUFindFontFromName_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	rc = (jint)ATSUFindFontFromName(lparg0, arg1, arg2, arg3, arg4, arg5, lparg6);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, ATSUFindFontFromName_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUFindFontName
JNIEXPORT jint JNICALL OS_NATIVE(ATSUFindFontName)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5, jbyteArray arg6, jintArray arg7, jintArray arg8)
{
	jbyte *lparg6=NULL;
	jint *lparg7=NULL;
	jint *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUFindFontName_FUNC);
	if (arg6) lparg6 = (*env)->GetByteArrayElements(env, arg6, NULL);
	if (arg7) lparg7 = (*env)->GetIntArrayElements(env, arg7, NULL);
	if (arg8) lparg8 = (*env)->GetIntArrayElements(env, arg8, NULL);
	rc = (jint)ATSUFindFontName((ATSUFontID)arg0, arg1, arg2, arg3, arg4, arg5, (Ptr)lparg6, lparg7, lparg8);
	if (arg8) (*env)->ReleaseIntArrayElements(env, arg8, lparg8, 0);
	if (arg7) (*env)->ReleaseIntArrayElements(env, arg7, lparg7, 0);
	if (arg6) (*env)->ReleaseByteArrayElements(env, arg6, lparg6, 0);
	OS_NATIVE_EXIT(env, that, ATSUFindFontName_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetFontIDs
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetFontIDs)
	(JNIEnv *env, jclass that, jintArray arg0, jint arg1, jintArray arg2)
{
	jint *lparg0=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetFontIDs_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)ATSUGetFontIDs((ATSUFontID *)lparg0, arg1, lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, ATSUGetFontIDs_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetGlyphBounds__IIIIISII_3I
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetGlyphBounds__IIIIISII_3I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jshort arg5, jint arg6, jint arg7, jintArray arg8)
{
	jint *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetGlyphBounds__IIIIISII_3I_FUNC);
	if (arg8) lparg8 = (*env)->GetIntArrayElements(env, arg8, NULL);
	rc = (jint)ATSUGetGlyphBounds((ATSUTextLayout)arg0, (ATSUTextMeasurement)arg1, (ATSUTextMeasurement)arg2, (UniCharArrayOffset)arg3, arg4, arg5, arg6, (ATSTrapezoid *)arg7, (ItemCount *)lparg8);
	if (arg8) (*env)->ReleaseIntArrayElements(env, arg8, lparg8, 0);
	OS_NATIVE_EXIT(env, that, ATSUGetGlyphBounds__IIIIISII_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetGlyphBounds__IIIIISILorg_eclipse_swt_internal_carbon_ATSTrapezoid_2_3I
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetGlyphBounds__IIIIISILorg_eclipse_swt_internal_carbon_ATSTrapezoid_2_3I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jshort arg5, jint arg6, jobject arg7, jintArray arg8)
{
	ATSTrapezoid _arg7, *lparg7=NULL;
	jint *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetGlyphBounds__IIIIISILorg_eclipse_swt_internal_carbon_ATSTrapezoid_2_3I_FUNC);
	if (arg7) lparg7 = getATSTrapezoidFields(env, arg7, &_arg7);
	if (arg8) lparg8 = (*env)->GetIntArrayElements(env, arg8, NULL);
	rc = (jint)ATSUGetGlyphBounds((ATSUTextLayout)arg0, (ATSUTextMeasurement)arg1, (ATSUTextMeasurement)arg2, (UniCharArrayOffset)arg3, arg4, arg5, arg6, (ATSTrapezoid *)lparg7, (ItemCount *)lparg8);
	if (arg8) (*env)->ReleaseIntArrayElements(env, arg8, lparg8, 0);
	if (arg7) setATSTrapezoidFields(env, arg7, lparg7);
	OS_NATIVE_EXIT(env, that, ATSUGetGlyphBounds__IIIIISILorg_eclipse_swt_internal_carbon_ATSTrapezoid_2_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetLayoutControl
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetLayoutControl)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jintArray arg4)
{
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetLayoutControl_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)ATSUGetLayoutControl((ATSUTextLayout)arg0, (ATSUAttributeTag)arg1, arg2, (ATSUAttributeValuePtr)lparg3, (ByteCount *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, ATSUGetLayoutControl_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetLineControl
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetLineControl)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jintArray arg4, jintArray arg5)
{
	jint *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetLineControl_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)ATSUGetLineControl((ATSUTextLayout)arg0, (UniCharArrayOffset)arg1, (ATSUAttributeTag)arg2, (ByteCount)arg3, (ATSUAttributeValuePtr)lparg4, (ByteCount *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, ATSUGetLineControl_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetSoftLineBreaks
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetSoftLineBreaks)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jintArray arg4, jintArray arg5)
{
	jint *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetSoftLineBreaks_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)ATSUGetSoftLineBreaks((ATSUTextLayout)arg0, (UniCharArrayOffset)arg1, (UniCharCount)arg2, (ItemCount)arg3, (UniCharArrayOffset *)lparg4, (ItemCount *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, ATSUGetSoftLineBreaks_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetTextHighlight
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetTextHighlight)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetTextHighlight_FUNC);
	rc = (jint)ATSUGetTextHighlight((ATSUTextLayout)arg0, arg1, arg2, arg3, arg4, (RgnHandle)arg5);
	OS_NATIVE_EXIT(env, that, ATSUGetTextHighlight_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUGetUnjustifiedBounds
JNIEXPORT jint JNICALL OS_NATIVE(ATSUGetUnjustifiedBounds)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jintArray arg4, jintArray arg5, jintArray arg6)
{
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint *lparg5=NULL;
	jint *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUGetUnjustifiedBounds_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	rc = (jint)ATSUGetUnjustifiedBounds((ATSUTextLayout)arg0, arg1, arg2, (ATSUTextMeasurement *)lparg3, (ATSUTextMeasurement *)lparg4, (ATSUTextMeasurement *)lparg5, (ATSUTextMeasurement *)lparg6);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, ATSUGetUnjustifiedBounds_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUHighlightText
JNIEXPORT jint JNICALL OS_NATIVE(ATSUHighlightText)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUHighlightText_FUNC);
	rc = (jint)ATSUHighlightText((ATSUTextLayout)arg0, (ATSUTextMeasurement)arg1, (ATSUTextMeasurement)arg2, arg3, arg4);
	OS_NATIVE_EXIT(env, that, ATSUHighlightText_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUNextCursorPosition
JNIEXPORT jint JNICALL OS_NATIVE(ATSUNextCursorPosition)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUNextCursorPosition_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)ATSUNextCursorPosition((ATSUTextLayout)arg0, (UniCharArrayOffset)arg1, (ATSUCursorMovementType)arg2, (UniCharArrayOffset *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, ATSUNextCursorPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUOffsetToPosition
JNIEXPORT jint JNICALL OS_NATIVE(ATSUOffsetToPosition)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2, jobject arg3, jobject arg4, jbooleanArray arg5)
{
	ATSUCaret _arg3, *lparg3=NULL;
	ATSUCaret _arg4, *lparg4=NULL;
	jboolean *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUOffsetToPosition_FUNC);
	if (arg3) lparg3 = getATSUCaretFields(env, arg3, &_arg3);
	if (arg4) lparg4 = getATSUCaretFields(env, arg4, &_arg4);
	if (arg5) lparg5 = (*env)->GetBooleanArrayElements(env, arg5, NULL);
	rc = (jint)ATSUOffsetToPosition((ATSUTextLayout)arg0, arg1, arg2, lparg3, lparg4, (Boolean *)lparg5);
	if (arg5) (*env)->ReleaseBooleanArrayElements(env, arg5, lparg5, 0);
	if (arg4) setATSUCaretFields(env, arg4, lparg4);
	if (arg3) setATSUCaretFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, ATSUOffsetToPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUPositionToOffset
JNIEXPORT jint JNICALL OS_NATIVE(ATSUPositionToOffset)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jbooleanArray arg4, jintArray arg5)
{
	jint *lparg3=NULL;
	jboolean *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUPositionToOffset_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetBooleanArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)ATSUPositionToOffset((ATSUTextLayout)arg0, arg1, arg2, (UniCharArrayOffset *)lparg3, (Boolean *)lparg4, (UniCharArrayOffset *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseBooleanArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, ATSUPositionToOffset_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUPreviousCursorPosition
JNIEXPORT jint JNICALL OS_NATIVE(ATSUPreviousCursorPosition)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUPreviousCursorPosition_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)ATSUPreviousCursorPosition((ATSUTextLayout)arg0, (UniCharArrayOffset)arg1, (ATSUCursorMovementType)arg2, (UniCharArrayOffset *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, ATSUPreviousCursorPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetAttributes
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetAttributes)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jintArray arg3, jintArray arg4)
{
	jint *lparg2=NULL;
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetAttributes_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)ATSUSetAttributes((ATSUStyle)arg0, (ItemCount)arg1, (ATSUAttributeTag *)lparg2, (ByteCount *)lparg3, (ATSUAttributeValuePtr *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, ATSUSetAttributes_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetFontFeatures
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetFontFeatures)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshortArray arg2, jshortArray arg3)
{
	jshort *lparg2=NULL;
	jshort *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetFontFeatures_FUNC);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetShortArrayElements(env, arg3, NULL);
	rc = (jint)ATSUSetFontFeatures((ATSUStyle)arg0, (ItemCount)arg1, (const ATSUFontFeatureType *)lparg2, (const ATSUFontFeatureSelector *)lparg3);
	if (arg3) (*env)->ReleaseShortArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, ATSUSetFontFeatures_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetHighlightingMethod
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetHighlightingMethod)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	ATSUUnhighlightData _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetHighlightingMethod_FUNC);
	if (arg2) lparg2 = getATSUUnhighlightDataFields(env, arg2, &_arg2);
	rc = (jint)ATSUSetHighlightingMethod((ATSUTextLayout)arg0, arg1, lparg2);
	if (arg2) setATSUUnhighlightDataFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, ATSUSetHighlightingMethod_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetLayoutControls
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetLayoutControls)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jintArray arg3, jintArray arg4)
{
	jint *lparg2=NULL;
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetLayoutControls_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)ATSUSetLayoutControls((ATSUTextLayout)arg0, (ItemCount)arg1, (ATSUAttributeTag *)lparg2, (ByteCount *)lparg3, (ATSUAttributeValuePtr *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, ATSUSetLayoutControls_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetLineControls
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetLineControls)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jintArray arg4, jintArray arg5)
{
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetLineControls_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)ATSUSetLineControls((ATSUTextLayout)arg0, (UniCharArrayOffset)arg1, (ItemCount)arg2, (const ATSUAttributeTag *)lparg3, (const ByteCount *)lparg4, (const ATSUAttributeValuePtr *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, ATSUSetLineControls_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetRunStyle
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetRunStyle)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetRunStyle_FUNC);
	rc = (jint)ATSUSetRunStyle((ATSUTextLayout)arg0, (ATSUStyle)arg1, (UniCharArrayOffset)arg2, (UniCharCount)arg3);
	OS_NATIVE_EXIT(env, that, ATSUSetRunStyle_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetSoftLineBreak
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetSoftLineBreak)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetSoftLineBreak_FUNC);
	rc = (jint)ATSUSetSoftLineBreak((ATSUTextLayout)arg0, arg1);
	OS_NATIVE_EXIT(env, that, ATSUSetSoftLineBreak_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetTabArray
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetTabArray)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetTabArray_FUNC);
	rc = (jint)ATSUSetTabArray((ATSUTextLayout)arg0, (const ATSUTab *)arg1, arg2);
	OS_NATIVE_EXIT(env, that, ATSUSetTabArray_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetTextPointerLocation
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetTextPointerLocation)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetTextPointerLocation_FUNC);
	rc = (jint)ATSUSetTextPointerLocation((ATSUTextLayout)arg0, (ConstUniCharArrayPtr)arg1, (UniCharArrayOffset)arg2, (UniCharCount)arg3, (UniCharCount)arg4);
	OS_NATIVE_EXIT(env, that, ATSUSetTextPointerLocation_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUSetTransientFontMatching
JNIEXPORT jint JNICALL OS_NATIVE(ATSUSetTransientFontMatching)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUSetTransientFontMatching_FUNC);
	rc = (jint)ATSUSetTransientFontMatching((ATSUTextLayout)arg0, arg1);
	OS_NATIVE_EXIT(env, that, ATSUSetTransientFontMatching_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUTextDeleted
JNIEXPORT jint JNICALL OS_NATIVE(ATSUTextDeleted)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUTextDeleted_FUNC);
	rc = (jint)ATSUTextDeleted((ATSUTextLayout)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, ATSUTextDeleted_FUNC);
	return rc;
}
#endif

#ifndef NO_ATSUTextInserted
JNIEXPORT jint JNICALL OS_NATIVE(ATSUTextInserted)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ATSUTextInserted_FUNC);
	rc = (jint)ATSUTextInserted((ATSUTextLayout)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, ATSUTextInserted_FUNC);
	return rc;
}
#endif

#ifndef NO_ActiveNonFloatingWindow
JNIEXPORT jint JNICALL OS_NATIVE(ActiveNonFloatingWindow)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ActiveNonFloatingWindow_FUNC);
	rc = (jint)ActiveNonFloatingWindow();
	OS_NATIVE_EXIT(env, that, ActiveNonFloatingWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_AddDataBrowserItems
JNIEXPORT jint JNICALL OS_NATIVE(AddDataBrowserItems)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AddDataBrowserItems_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)AddDataBrowserItems((ControlRef)arg0, (DataBrowserItemID)arg1, (UInt32)arg2, (const DataBrowserItemID *)lparg3, (DataBrowserPropertyID)arg4);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, AddDataBrowserItems_FUNC);
	return rc;
}
#endif

#ifndef NO_AddDataBrowserListViewColumn
JNIEXPORT jint JNICALL OS_NATIVE(AddDataBrowserListViewColumn)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	DataBrowserListViewColumnDesc _arg1={0}, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AddDataBrowserListViewColumn_FUNC);
	if (arg1) lparg1 = getDataBrowserListViewColumnDescFields(env, arg1, &_arg1);
	rc = (jint)AddDataBrowserListViewColumn((ControlRef)arg0, (DataBrowserListViewColumnDesc *)lparg1, (DataBrowserTableViewColumnIndex)arg2);
	if (arg1) setDataBrowserListViewColumnDescFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, AddDataBrowserListViewColumn_FUNC);
	return rc;
}
#endif

#ifndef NO_AddDragItemFlavor
JNIEXPORT jint JNICALL OS_NATIVE(AddDragItemFlavor)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jbyteArray arg3, jint arg4, jint arg5)
{
	jbyte *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AddDragItemFlavor_FUNC);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	rc = (jint)AddDragItemFlavor((DragRef)arg0, (DragItemRef)arg1, (FlavorType)arg2, (const void *)lparg3, (Size)arg4, (FlavorFlags)arg5);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, AddDragItemFlavor_FUNC);
	return rc;
}
#endif

#ifndef NO_AppendMenuItemTextWithCFString
JNIEXPORT jint JNICALL OS_NATIVE(AppendMenuItemTextWithCFString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jshortArray arg4)
{
	jshort *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, AppendMenuItemTextWithCFString_FUNC);
	if (arg4) lparg4 = (*env)->GetShortArrayElements(env, arg4, NULL);
	rc = (jint)AppendMenuItemTextWithCFString((MenuRef)arg0, (CFStringRef)arg1, (MenuItemAttributes)arg2, (MenuCommand)arg3, (MenuItemIndex *)lparg4);
	if (arg4) (*env)->ReleaseShortArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, AppendMenuItemTextWithCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_AutoSizeDataBrowserListViewColumns
JNIEXPORT jint JNICALL OS_NATIVE(AutoSizeDataBrowserListViewColumns)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, AutoSizeDataBrowserListViewColumns_FUNC);
	rc = (jint)AutoSizeDataBrowserListViewColumns((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, AutoSizeDataBrowserListViewColumns_FUNC);
	return rc;
}
#endif

#ifndef NO_BeginUpdate
JNIEXPORT void JNICALL OS_NATIVE(BeginUpdate)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, BeginUpdate_FUNC);
	BeginUpdate((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, BeginUpdate_FUNC);
}
#endif

#ifndef NO_BringToFront
JNIEXPORT void JNICALL OS_NATIVE(BringToFront)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, BringToFront_FUNC);
	BringToFront((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, BringToFront_FUNC);
}
#endif

#ifndef NO_CFArrayAppendValue
JNIEXPORT void JNICALL OS_NATIVE(CFArrayAppendValue)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CFArrayAppendValue_FUNC);
	CFArrayAppendValue((CFMutableArrayRef)arg0, (const void *)arg1);
	OS_NATIVE_EXIT(env, that, CFArrayAppendValue_FUNC);
}
#endif

#ifndef NO_CFArrayCreateMutable
JNIEXPORT jint JNICALL OS_NATIVE(CFArrayCreateMutable)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFArrayCreateMutable_FUNC);
	rc = (jint)CFArrayCreateMutable((CFAllocatorRef)arg0, (CFIndex)arg1, (const CFArrayCallBacks *)arg2);
	OS_NATIVE_EXIT(env, that, CFArrayCreateMutable_FUNC);
	return rc;
}
#endif

#ifndef NO_CFArrayGetCount
JNIEXPORT jint JNICALL OS_NATIVE(CFArrayGetCount)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFArrayGetCount_FUNC);
	rc = (jint)CFArrayGetCount((CFArrayRef)arg0);
	OS_NATIVE_EXIT(env, that, CFArrayGetCount_FUNC);
	return rc;
}
#endif

#ifndef NO_CFArrayGetValueAtIndex
JNIEXPORT jint JNICALL OS_NATIVE(CFArrayGetValueAtIndex)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFArrayGetValueAtIndex_FUNC);
	rc = (jint)CFArrayGetValueAtIndex((CFArrayRef)arg0, arg1);
	OS_NATIVE_EXIT(env, that, CFArrayGetValueAtIndex_FUNC);
	return rc;
}
#endif

#ifndef NO_CFRelease
JNIEXPORT void JNICALL OS_NATIVE(CFRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CFRelease_FUNC);
	CFRelease((CFTypeRef)arg0);
	OS_NATIVE_EXIT(env, that, CFRelease_FUNC);
}
#endif

#ifndef NO_CFStringCreateWithBytes
JNIEXPORT jint JNICALL OS_NATIVE(CFStringCreateWithBytes)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1, jint arg2, jint arg3, jboolean arg4)
{
	jbyte *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CFStringCreateWithBytes_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jint)CFStringCreateWithBytes((CFAllocatorRef)arg0, (const UInt8 *)lparg1, (CFIndex)arg2, (CFStringEncoding)arg3, arg4);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CFStringCreateWithBytes_FUNC);
	return rc;
}
#endif

#ifndef NO_CFStringCreateWithCharacters
JNIEXPORT jint JNICALL OS_NATIVE(CFStringCreateWithCharacters)
	(JNIEnv *env, jclass that, jint arg0, jcharArray arg1, jint arg2)
{
	jchar *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CFStringCreateWithCharacters_FUNC);
	if (arg1) lparg1 = (*env)->GetCharArrayElements(env, arg1, NULL);
	rc = (jint)CFStringCreateWithCharacters((CFAllocatorRef)arg0, (const UniChar *)lparg1, (CFIndex)arg2);
	if (arg1) (*env)->ReleaseCharArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CFStringCreateWithCharacters_FUNC);
	return rc;
}
#endif

#ifndef NO_CFStringGetBytes
JNIEXPORT jint JNICALL OS_NATIVE(CFStringGetBytes)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jbyte arg3, jboolean arg4, jbyteArray arg5, jint arg6, jintArray arg7)
{
	CFRange _arg1, *lparg1=NULL;
	jbyte *lparg5=NULL;
	jint *lparg7=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CFStringGetBytes_FUNC);
	if (arg1) lparg1 = getCFRangeFields(env, arg1, &_arg1);
	if (arg5) lparg5 = (*env)->GetByteArrayElements(env, arg5, NULL);
	if (arg7) lparg7 = (*env)->GetIntArrayElements(env, arg7, NULL);
	rc = (jint)CFStringGetBytes((CFStringRef)arg0, *(CFRange *)lparg1, (CFStringEncoding)arg2, (UInt8)arg3, (Boolean)arg4, (UInt8 *)lparg5, (CFIndex)arg6, (CFIndex *)lparg7);
	if (arg7) (*env)->ReleaseIntArrayElements(env, arg7, lparg7, 0);
	if (arg5) (*env)->ReleaseByteArrayElements(env, arg5, lparg5, 0);
	if (arg1) setCFRangeFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CFStringGetBytes_FUNC);
	return rc;
}
#endif

#ifndef NO_CFStringGetCharacters
JNIEXPORT void JNICALL OS_NATIVE(CFStringGetCharacters)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jcharArray arg2)
{
	CFRange _arg1, *lparg1=NULL;
	jchar *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, CFStringGetCharacters_FUNC);
	if (arg1) lparg1 = getCFRangeFields(env, arg1, &_arg1);
	if (arg2) lparg2 = (*env)->GetCharArrayElements(env, arg2, NULL);
	CFStringGetCharacters((CFStringRef)arg0, *(CFRange *)lparg1, (UniChar *)lparg2);
	if (arg2) (*env)->ReleaseCharArrayElements(env, arg2, lparg2, 0);
	if (arg1) setCFRangeFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CFStringGetCharacters_FUNC);
}
#endif

#ifndef NO_CFStringGetLength
JNIEXPORT jint JNICALL OS_NATIVE(CFStringGetLength)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFStringGetLength_FUNC);
	rc = (jint)CFStringGetLength((CFStringRef)arg0);
	OS_NATIVE_EXIT(env, that, CFStringGetLength_FUNC);
	return rc;
}
#endif

#ifndef NO_CFStringGetSystemEncoding
JNIEXPORT jint JNICALL OS_NATIVE(CFStringGetSystemEncoding)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFStringGetSystemEncoding_FUNC);
	rc = (jint)CFStringGetSystemEncoding();
	OS_NATIVE_EXIT(env, that, CFStringGetSystemEncoding_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLCopyFileSystemPath
JNIEXPORT jint JNICALL OS_NATIVE(CFURLCopyFileSystemPath)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFURLCopyFileSystemPath_FUNC);
	rc = (jint)CFURLCopyFileSystemPath((CFURLRef)arg0, (CFURLPathStyle)arg1);
	OS_NATIVE_EXIT(env, that, CFURLCopyFileSystemPath_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLCopyLastPathComponent
JNIEXPORT jint JNICALL OS_NATIVE(CFURLCopyLastPathComponent)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFURLCopyLastPathComponent_FUNC);
	rc = (jint)CFURLCopyLastPathComponent((CFURLRef)arg0);
	OS_NATIVE_EXIT(env, that, CFURLCopyLastPathComponent_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLCreateCopyAppendingPathComponent
JNIEXPORT jint JNICALL OS_NATIVE(CFURLCreateCopyAppendingPathComponent)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jboolean arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFURLCreateCopyAppendingPathComponent_FUNC);
	rc = (jint)CFURLCreateCopyAppendingPathComponent((CFAllocatorRef)arg0, (CFURLRef)arg1, (CFStringRef)arg2, (Boolean)arg3);
	OS_NATIVE_EXIT(env, that, CFURLCreateCopyAppendingPathComponent_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLCreateCopyDeletingLastPathComponent
JNIEXPORT jint JNICALL OS_NATIVE(CFURLCreateCopyDeletingLastPathComponent)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFURLCreateCopyDeletingLastPathComponent_FUNC);
	rc = (jint)CFURLCreateCopyDeletingLastPathComponent((CFAllocatorRef)arg0, (CFURLRef)arg1);
	OS_NATIVE_EXIT(env, that, CFURLCreateCopyDeletingLastPathComponent_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLCreateFromFSRef
JNIEXPORT jint JNICALL OS_NATIVE(CFURLCreateFromFSRef)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1)
{
	jbyte *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CFURLCreateFromFSRef_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jint)CFURLCreateFromFSRef((CFAllocatorRef)arg0, (const struct FSRef *)lparg1);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CFURLCreateFromFSRef_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLCreateWithFileSystemPath
JNIEXPORT jint JNICALL OS_NATIVE(CFURLCreateWithFileSystemPath)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jboolean arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CFURLCreateWithFileSystemPath_FUNC);
	rc = (jint)CFURLCreateWithFileSystemPath((CFAllocatorRef)arg0, (CFStringRef)arg1, (CFURLPathStyle)arg2, arg3);
	OS_NATIVE_EXIT(env, that, CFURLCreateWithFileSystemPath_FUNC);
	return rc;
}
#endif

#ifndef NO_CFURLGetFSRef
JNIEXPORT jboolean JNICALL OS_NATIVE(CFURLGetFSRef)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1)
{
	jbyte *lparg1=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, CFURLGetFSRef_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jboolean)CFURLGetFSRef((CFURLRef)arg0, (struct FSRef *)lparg1);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CFURLGetFSRef_FUNC);
	return rc;
}
#endif

#ifndef NO_CGBitmapContextCreate
JNIEXPORT jint JNICALL OS_NATIVE(CGBitmapContextCreate)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5, jint arg6)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGBitmapContextCreate_FUNC);
	rc = (jint)CGBitmapContextCreate((void *)arg0, (size_t)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4, (CGColorSpaceRef)arg5, (CGImageAlphaInfo)arg6);
	OS_NATIVE_EXIT(env, that, CGBitmapContextCreate_FUNC);
	return rc;
}
#endif

#ifndef NO_CGColorSpaceCreateDeviceRGB
JNIEXPORT jint JNICALL OS_NATIVE(CGColorSpaceCreateDeviceRGB)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGColorSpaceCreateDeviceRGB_FUNC);
	rc = (jint)CGColorSpaceCreateDeviceRGB();
	OS_NATIVE_EXIT(env, that, CGColorSpaceCreateDeviceRGB_FUNC);
	return rc;
}
#endif

#ifndef NO_CGColorSpaceRelease
JNIEXPORT void JNICALL OS_NATIVE(CGColorSpaceRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGColorSpaceRelease_FUNC);
	CGColorSpaceRelease((CGColorSpaceRef)arg0);
	OS_NATIVE_EXIT(env, that, CGColorSpaceRelease_FUNC);
}
#endif

#ifndef NO_CGContextAddArc
JNIEXPORT void JNICALL OS_NATIVE(CGContextAddArc)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2, jfloat arg3, jfloat arg4, jfloat arg5, jboolean arg6)
{
	OS_NATIVE_ENTER(env, that, CGContextAddArc_FUNC);
	CGContextAddArc((CGContextRef)arg0, (float)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5, (Boolean)arg6);
	OS_NATIVE_EXIT(env, that, CGContextAddArc_FUNC);
}
#endif

#ifndef NO_CGContextAddArcToPoint
JNIEXPORT void JNICALL OS_NATIVE(CGContextAddArcToPoint)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2, jfloat arg3, jfloat arg4, jfloat arg5)
{
	OS_NATIVE_ENTER(env, that, CGContextAddArcToPoint_FUNC);
	CGContextAddArcToPoint((CGContextRef)arg0, arg1, arg2, arg3, arg4, arg5);
	OS_NATIVE_EXIT(env, that, CGContextAddArcToPoint_FUNC);
}
#endif

#ifndef NO_CGContextAddLineToPoint
JNIEXPORT void JNICALL OS_NATIVE(CGContextAddLineToPoint)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2)
{
	OS_NATIVE_ENTER(env, that, CGContextAddLineToPoint_FUNC);
	CGContextAddLineToPoint((CGContextRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, CGContextAddLineToPoint_FUNC);
}
#endif

#ifndef NO_CGContextAddLines
JNIEXPORT void JNICALL OS_NATIVE(CGContextAddLines)
	(JNIEnv *env, jclass that, jint arg0, jfloatArray arg1, jint arg2)
{
	jfloat *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextAddLines_FUNC);
	if (arg1) lparg1 = (*env)->GetFloatArrayElements(env, arg1, NULL);
	CGContextAddLines((CGContextRef)arg0, (const CGPoint *)lparg1, (size_t)arg2);
	if (arg1) (*env)->ReleaseFloatArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CGContextAddLines_FUNC);
}
#endif

#ifndef NO_CGContextBeginPath
JNIEXPORT void JNICALL OS_NATIVE(CGContextBeginPath)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextBeginPath_FUNC);
	CGContextBeginPath((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextBeginPath_FUNC);
}
#endif

#ifndef NO_CGContextClearRect
JNIEXPORT void JNICALL OS_NATIVE(CGContextClearRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	CGRect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextClearRect_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	CGContextClearRect((CGContextRef)arg0, *(CGRect *)lparg1);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CGContextClearRect_FUNC);
}
#endif

#ifndef NO_CGContextClip
JNIEXPORT void JNICALL OS_NATIVE(CGContextClip)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextClip_FUNC);
	CGContextClip((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextClip_FUNC);
}
#endif

#ifndef NO_CGContextClosePath
JNIEXPORT void JNICALL OS_NATIVE(CGContextClosePath)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextClosePath_FUNC);
	CGContextClosePath((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextClosePath_FUNC);
}
#endif

#ifndef NO_CGContextDrawImage
JNIEXPORT void JNICALL OS_NATIVE(CGContextDrawImage)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	CGRect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextDrawImage_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	CGContextDrawImage((CGContextRef)arg0, *(CGRect *)lparg1, (CGImageRef)arg2);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CGContextDrawImage_FUNC);
}
#endif

#ifndef NO_CGContextEOFillPath
JNIEXPORT void JNICALL OS_NATIVE(CGContextEOFillPath)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextEOFillPath_FUNC);
	CGContextEOFillPath((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextEOFillPath_FUNC);
}
#endif

#ifndef NO_CGContextFillPath
JNIEXPORT void JNICALL OS_NATIVE(CGContextFillPath)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextFillPath_FUNC);
	CGContextFillPath((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextFillPath_FUNC);
}
#endif

#ifndef NO_CGContextFillRect
JNIEXPORT void JNICALL OS_NATIVE(CGContextFillRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	CGRect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextFillRect_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	CGContextFillRect((CGContextRef)arg0, *(CGRect *)lparg1);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CGContextFillRect_FUNC);
}
#endif

#ifndef NO_CGContextFlush
JNIEXPORT void JNICALL OS_NATIVE(CGContextFlush)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextFlush_FUNC);
	CGContextFlush((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextFlush_FUNC);
}
#endif

#ifndef NO_CGContextMoveToPoint
JNIEXPORT void JNICALL OS_NATIVE(CGContextMoveToPoint)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2)
{
	OS_NATIVE_ENTER(env, that, CGContextMoveToPoint_FUNC);
	CGContextMoveToPoint((CGContextRef)arg0, (float)arg1, (float)arg2);
	OS_NATIVE_EXIT(env, that, CGContextMoveToPoint_FUNC);
}
#endif

#ifndef NO_CGContextRelease
JNIEXPORT void JNICALL OS_NATIVE(CGContextRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextRelease_FUNC);
	CGContextRelease((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextRelease_FUNC);
}
#endif

#ifndef NO_CGContextRestoreGState
JNIEXPORT void JNICALL OS_NATIVE(CGContextRestoreGState)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextRestoreGState_FUNC);
	CGContextRestoreGState((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextRestoreGState_FUNC);
}
#endif

#ifndef NO_CGContextSaveGState
JNIEXPORT void JNICALL OS_NATIVE(CGContextSaveGState)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextSaveGState_FUNC);
	CGContextSaveGState((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextSaveGState_FUNC);
}
#endif

#ifndef NO_CGContextScaleCTM
JNIEXPORT void JNICALL OS_NATIVE(CGContextScaleCTM)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2)
{
	OS_NATIVE_ENTER(env, that, CGContextScaleCTM_FUNC);
	CGContextScaleCTM((CGContextRef)arg0, (float)arg1, (float)arg2);
	OS_NATIVE_EXIT(env, that, CGContextScaleCTM_FUNC);
}
#endif

#ifndef NO_CGContextSelectFont
JNIEXPORT void JNICALL OS_NATIVE(CGContextSelectFont)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1, jfloat arg2, jint arg3)
{
	jbyte *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextSelectFont_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	CGContextSelectFont((CGContextRef)arg0, (const char *)lparg1, (float)arg2, (CGTextEncoding)arg3);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CGContextSelectFont_FUNC);
}
#endif

#ifndef NO_CGContextSetFillColor
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetFillColor)
	(JNIEnv *env, jclass that, jint arg0, jfloatArray arg1)
{
	jfloat *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextSetFillColor_FUNC);
	if (arg1) lparg1 = (*env)->GetFloatArrayElements(env, arg1, NULL);
	CGContextSetFillColor((CGContextRef)arg0, (const float *)lparg1);
	if (arg1) (*env)->ReleaseFloatArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CGContextSetFillColor_FUNC);
}
#endif

#ifndef NO_CGContextSetFillColorSpace
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetFillColorSpace)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetFillColorSpace_FUNC);
	CGContextSetFillColorSpace((CGContextRef)arg0, (CGColorSpaceRef)arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetFillColorSpace_FUNC);
}
#endif

#ifndef NO_CGContextSetFont
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetFont)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetFont_FUNC);
	CGContextSetFont((CGContextRef)arg0, (CGFontRef)arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetFont_FUNC);
}
#endif

#ifndef NO_CGContextSetFontSize
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetFontSize)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetFontSize_FUNC);
	CGContextSetFontSize((CGContextRef)arg0, (float)arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetFontSize_FUNC);
}
#endif

#ifndef NO_CGContextSetLineCap
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetLineCap)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetLineCap_FUNC);
	CGContextSetLineCap((CGContextRef)arg0, arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetLineCap_FUNC);
}
#endif

#ifndef NO_CGContextSetLineDash
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetLineDash)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloatArray arg2, jint arg3)
{
	jfloat *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, CGContextSetLineDash_FUNC);
	if (arg2) lparg2 = (*env)->GetFloatArrayElements(env, arg2, NULL);
	CGContextSetLineDash((CGContextRef)arg0, (float)arg1, (const float *)lparg2, (size_t)arg3);
	if (arg2) (*env)->ReleaseFloatArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, CGContextSetLineDash_FUNC);
}
#endif

#ifndef NO_CGContextSetLineWidth
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetLineWidth)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetLineWidth_FUNC);
	CGContextSetLineWidth((CGContextRef)arg0, (float)arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetLineWidth_FUNC);
}
#endif

#ifndef NO_CGContextSetRGBFillColor
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetRGBFillColor)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2, jfloat arg3, jfloat arg4)
{
	OS_NATIVE_ENTER(env, that, CGContextSetRGBFillColor_FUNC);
	CGContextSetRGBFillColor((CGContextRef)arg0, (float)arg1, (float)arg2, (float)arg3, (float)arg4);
	OS_NATIVE_EXIT(env, that, CGContextSetRGBFillColor_FUNC);
}
#endif

#ifndef NO_CGContextSetRGBStrokeColor
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetRGBStrokeColor)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2, jfloat arg3, jfloat arg4)
{
	OS_NATIVE_ENTER(env, that, CGContextSetRGBStrokeColor_FUNC);
	CGContextSetRGBStrokeColor((CGContextRef)arg0, (float)arg1, (float)arg2, (float)arg3, (float)arg4);
	OS_NATIVE_EXIT(env, that, CGContextSetRGBStrokeColor_FUNC);
}
#endif

#ifndef NO_CGContextSetShouldAntialias
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetShouldAntialias)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetShouldAntialias_FUNC);
	CGContextSetShouldAntialias((CGContextRef)arg0, arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetShouldAntialias_FUNC);
}
#endif

#ifndef NO_CGContextSetShouldSmoothFonts
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetShouldSmoothFonts)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetShouldSmoothFonts_FUNC);
	CGContextSetShouldSmoothFonts((CGContextRef)arg0, arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetShouldSmoothFonts_FUNC);
}
#endif

#ifndef NO_CGContextSetStrokeColor
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetStrokeColor)
	(JNIEnv *env, jclass that, jint arg0, jfloatArray arg1)
{
	jfloat *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextSetStrokeColor_FUNC);
	if (arg1) lparg1 = (*env)->GetFloatArrayElements(env, arg1, NULL);
	CGContextSetStrokeColor((CGContextRef)arg0, (const float *)lparg1);
	if (arg1) (*env)->ReleaseFloatArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CGContextSetStrokeColor_FUNC);
}
#endif

#ifndef NO_CGContextSetStrokeColorSpace
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetStrokeColorSpace)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetStrokeColorSpace_FUNC);
	CGContextSetStrokeColorSpace((CGContextRef)arg0, (CGColorSpaceRef)arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetStrokeColorSpace_FUNC);
}
#endif

#ifndef NO_CGContextSetTextDrawingMode
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetTextDrawingMode)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CGContextSetTextDrawingMode_FUNC);
	CGContextSetTextDrawingMode((CGContextRef)arg0, (CGTextDrawingMode)arg1);
	OS_NATIVE_EXIT(env, that, CGContextSetTextDrawingMode_FUNC);
}
#endif

#ifndef NO_CGContextSetTextMatrix
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetTextMatrix)
	(JNIEnv *env, jclass that, jint arg0, jfloatArray arg1)
{
	jfloat *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextSetTextMatrix_FUNC);
	if (arg1) lparg1 = (*env)->GetFloatArrayElements(env, arg1, NULL);
	CGContextSetTextMatrix((CGContextRef)arg0, *(CGAffineTransform *)lparg1);
	if (arg1) (*env)->ReleaseFloatArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CGContextSetTextMatrix_FUNC);
}
#endif

#ifndef NO_CGContextSetTextPosition
JNIEXPORT void JNICALL OS_NATIVE(CGContextSetTextPosition)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2)
{
	OS_NATIVE_ENTER(env, that, CGContextSetTextPosition_FUNC);
	CGContextSetTextPosition((CGContextRef)arg0, (float)arg1, (float)arg2);
	OS_NATIVE_EXIT(env, that, CGContextSetTextPosition_FUNC);
}
#endif

#ifndef NO_CGContextShowText
JNIEXPORT void JNICALL OS_NATIVE(CGContextShowText)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1, jint arg2)
{
	jbyte *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextShowText_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	CGContextShowText((CGContextRef)arg0, (const char *)lparg1, (size_t)arg2);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CGContextShowText_FUNC);
}
#endif

#ifndef NO_CGContextShowTextAtPoint
JNIEXPORT void JNICALL OS_NATIVE(CGContextShowTextAtPoint)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2, jbyteArray arg3, jint arg4)
{
	jbyte *lparg3=NULL;
	OS_NATIVE_ENTER(env, that, CGContextShowTextAtPoint_FUNC);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	CGContextShowTextAtPoint((CGContextRef)arg0, (float)arg1, (float)arg2, (const char *)lparg3, (size_t)arg4);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, CGContextShowTextAtPoint_FUNC);
}
#endif

#ifndef NO_CGContextStrokePath
JNIEXPORT void JNICALL OS_NATIVE(CGContextStrokePath)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextStrokePath_FUNC);
	CGContextStrokePath((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextStrokePath_FUNC);
}
#endif

#ifndef NO_CGContextStrokeRect
JNIEXPORT void JNICALL OS_NATIVE(CGContextStrokeRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	CGRect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, CGContextStrokeRect_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	CGContextStrokeRect((CGContextRef)arg0, *(CGRect *)lparg1);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CGContextStrokeRect_FUNC);
}
#endif

#ifndef NO_CGContextSynchronize
JNIEXPORT void JNICALL OS_NATIVE(CGContextSynchronize)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGContextSynchronize_FUNC);
	CGContextSynchronize((CGContextRef)arg0);
	OS_NATIVE_EXIT(env, that, CGContextSynchronize_FUNC);
}
#endif

#ifndef NO_CGContextTranslateCTM
JNIEXPORT void JNICALL OS_NATIVE(CGContextTranslateCTM)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2)
{
	OS_NATIVE_ENTER(env, that, CGContextTranslateCTM_FUNC);
	CGContextTranslateCTM((CGContextRef)arg0, (float)arg1, (float)arg2);
	OS_NATIVE_EXIT(env, that, CGContextTranslateCTM_FUNC);
}
#endif

#ifndef NO_CGDataProviderCreateWithData
JNIEXPORT jint JNICALL OS_NATIVE(CGDataProviderCreateWithData)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDataProviderCreateWithData_FUNC);
	rc = (jint)CGDataProviderCreateWithData((void *)arg0, (const void *)arg1, (size_t)arg2, (void *)arg3);
	OS_NATIVE_EXIT(env, that, CGDataProviderCreateWithData_FUNC);
	return rc;
}
#endif

#ifndef NO_CGDataProviderRelease
JNIEXPORT void JNICALL OS_NATIVE(CGDataProviderRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGDataProviderRelease_FUNC);
	CGDataProviderRelease((CGDataProviderRef)arg0);
	OS_NATIVE_EXIT(env, that, CGDataProviderRelease_FUNC);
}
#endif

#ifndef NO_CGDisplayBaseAddress
JNIEXPORT jint JNICALL OS_NATIVE(CGDisplayBaseAddress)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDisplayBaseAddress_FUNC);
	rc = (jint)CGDisplayBaseAddress((CGDirectDisplayID)arg0);
	OS_NATIVE_EXIT(env, that, CGDisplayBaseAddress_FUNC);
	return rc;
}
#endif

#ifndef NO_CGDisplayBitsPerPixel
JNIEXPORT jint JNICALL OS_NATIVE(CGDisplayBitsPerPixel)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDisplayBitsPerPixel_FUNC);
	rc = (jint)CGDisplayBitsPerPixel((CGDirectDisplayID)arg0);
	OS_NATIVE_EXIT(env, that, CGDisplayBitsPerPixel_FUNC);
	return rc;
}
#endif

#ifndef NO_CGDisplayBitsPerSample
JNIEXPORT jint JNICALL OS_NATIVE(CGDisplayBitsPerSample)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDisplayBitsPerSample_FUNC);
	rc = (jint)CGDisplayBitsPerSample((CGDirectDisplayID)arg0);
	OS_NATIVE_EXIT(env, that, CGDisplayBitsPerSample_FUNC);
	return rc;
}
#endif

#ifndef NO_CGDisplayBytesPerRow
JNIEXPORT jint JNICALL OS_NATIVE(CGDisplayBytesPerRow)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDisplayBytesPerRow_FUNC);
	rc = (jint)CGDisplayBytesPerRow((CGDirectDisplayID)arg0);
	OS_NATIVE_EXIT(env, that, CGDisplayBytesPerRow_FUNC);
	return rc;
}
#endif

#ifndef NO_CGDisplayPixelsHigh
JNIEXPORT jint JNICALL OS_NATIVE(CGDisplayPixelsHigh)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDisplayPixelsHigh_FUNC);
	rc = (jint)CGDisplayPixelsHigh((CGDirectDisplayID)arg0);
	OS_NATIVE_EXIT(env, that, CGDisplayPixelsHigh_FUNC);
	return rc;
}
#endif

#ifndef NO_CGDisplayPixelsWide
JNIEXPORT jint JNICALL OS_NATIVE(CGDisplayPixelsWide)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGDisplayPixelsWide_FUNC);
	rc = (jint)CGDisplayPixelsWide((CGDirectDisplayID)arg0);
	OS_NATIVE_EXIT(env, that, CGDisplayPixelsWide_FUNC);
	return rc;
}
#endif

#ifndef NO_CGFontCreateWithPlatformFont
JNIEXPORT jint JNICALL OS_NATIVE(CGFontCreateWithPlatformFont)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CGFontCreateWithPlatformFont_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)CGFontCreateWithPlatformFont(lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, CGFontCreateWithPlatformFont_FUNC);
	return rc;
}
#endif

#ifndef NO_CGFontRelease
JNIEXPORT void JNICALL OS_NATIVE(CGFontRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGFontRelease_FUNC);
	CGFontRelease((CGFontRef)arg0);
	OS_NATIVE_EXIT(env, that, CGFontRelease_FUNC);
}
#endif

#ifndef NO_CGGetDisplaysWithRect
JNIEXPORT jint JNICALL OS_NATIVE(CGGetDisplaysWithRect)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jintArray arg2, jintArray arg3)
{
	CGRect _arg0, *lparg0=NULL;
	jint *lparg2=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CGGetDisplaysWithRect_FUNC);
	if (arg0) lparg0 = getCGRectFields(env, arg0, &_arg0);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)CGGetDisplaysWithRect(*lparg0, (CGDisplayCount)arg1, (CGDirectDisplayID *)lparg2, (CGDisplayCount *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg0) setCGRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, CGGetDisplaysWithRect_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageCreate
JNIEXPORT jint JNICALL OS_NATIVE(CGImageCreate)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5, jint arg6, jint arg7, jfloatArray arg8, jboolean arg9, jint arg10)
{
	jfloat *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageCreate_FUNC);
	if (arg8) lparg8 = (*env)->GetFloatArrayElements(env, arg8, NULL);
	rc = (jint)CGImageCreate((size_t)arg0, (size_t)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4, (CGColorSpaceRef)arg5, (CGImageAlphaInfo)arg6, (CGDataProviderRef)arg7, (const float *)lparg8, (Boolean)arg9, (CGColorRenderingIntent)arg10);
	if (arg8) (*env)->ReleaseFloatArrayElements(env, arg8, lparg8, 0);
	OS_NATIVE_EXIT(env, that, CGImageCreate_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetAlphaInfo
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetAlphaInfo)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetAlphaInfo_FUNC);
	rc = (jint)CGImageGetAlphaInfo((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetAlphaInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetBitsPerComponent
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetBitsPerComponent)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetBitsPerComponent_FUNC);
	rc = (jint)CGImageGetBitsPerComponent((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetBitsPerComponent_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetBitsPerPixel
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetBitsPerPixel)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetBitsPerPixel_FUNC);
	rc = (jint)CGImageGetBitsPerPixel((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetBitsPerPixel_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetBytesPerRow
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetBytesPerRow)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetBytesPerRow_FUNC);
	rc = (jint)CGImageGetBytesPerRow((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetBytesPerRow_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetColorSpace
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetColorSpace)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetColorSpace_FUNC);
	rc = (jint)CGImageGetColorSpace((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetColorSpace_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetHeight
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetHeight)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetHeight_FUNC);
	rc = (jint)CGImageGetHeight((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetHeight_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageGetWidth
JNIEXPORT jint JNICALL OS_NATIVE(CGImageGetWidth)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGImageGetWidth_FUNC);
	rc = (jint)CGImageGetWidth((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageGetWidth_FUNC);
	return rc;
}
#endif

#ifndef NO_CGImageRelease
JNIEXPORT void JNICALL OS_NATIVE(CGImageRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CGImageRelease_FUNC);
	CGImageRelease((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, CGImageRelease_FUNC);
}
#endif

#ifndef NO_CGPostKeyboardEvent
JNIEXPORT jint JNICALL OS_NATIVE(CGPostKeyboardEvent)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CGPostKeyboardEvent_FUNC);
	rc = (jint)CGPostKeyboardEvent((CGCharCode)arg0, (CGKeyCode)arg1, (boolean_t)arg2);
	OS_NATIVE_EXIT(env, that, CGPostKeyboardEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_CGPostMouseEvent
JNIEXPORT jint JNICALL OS_NATIVE(CGPostMouseEvent)
	(JNIEnv *env, jclass that, jobject arg0, jboolean arg1, jint arg2, jboolean arg3, jboolean arg4, jboolean arg5)
{
	CGPoint _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CGPostMouseEvent_FUNC);
	if (arg0) lparg0 = getCGPointFields(env, arg0, &_arg0);
	rc = (jint)CGPostMouseEvent(*lparg0, (boolean_t)arg1, arg2, (boolean_t)arg3, (boolean_t)arg4, (boolean_t)arg5);
	if (arg0) setCGPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, CGPostMouseEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_CGWarpMouseCursorPosition
JNIEXPORT jint JNICALL OS_NATIVE(CGWarpMouseCursorPosition)
	(JNIEnv *env, jclass that, jobject arg0)
{
	CGPoint _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CGWarpMouseCursorPosition_FUNC);
	if (arg0) lparg0 = getCGPointFields(env, arg0, &_arg0);
	rc = (jint)CGWarpMouseCursorPosition(*lparg0);
	if (arg0) setCGPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, CGWarpMouseCursorPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_CPSEnableForegroundOperation
JNIEXPORT jint JNICALL OS_NATIVE(CPSEnableForegroundOperation)
	(JNIEnv *env, jclass that, jintArray arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CPSEnableForegroundOperation_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)CPSEnableForegroundOperation(lparg0, arg1, arg2, arg3, arg4);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, CPSEnableForegroundOperation_FUNC);
	return rc;
}
#endif

#ifndef NO_CPSSetProcessName
JNIEXPORT jint JNICALL OS_NATIVE(CPSSetProcessName)
	(JNIEnv *env, jclass that, jintArray arg0, jbyteArray arg1)
{
	jint *lparg0=NULL;
	jbyte *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CPSSetProcessName_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jint)CPSSetProcessName(lparg0, lparg1);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, CPSSetProcessName_FUNC);
	return rc;
}
#endif

#ifndef NO_CallNextEventHandler
JNIEXPORT jint JNICALL OS_NATIVE(CallNextEventHandler)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CallNextEventHandler_FUNC);
	rc = (jint)CallNextEventHandler((EventHandlerCallRef)arg0, (EventRef)arg1);
	OS_NATIVE_EXIT(env, that, CallNextEventHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_CharWidth
JNIEXPORT jshort JNICALL OS_NATIVE(CharWidth)
	(JNIEnv *env, jclass that, jshort arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, CharWidth_FUNC);
	rc = (jshort)CharWidth((CharParameter)arg0);
	OS_NATIVE_EXIT(env, that, CharWidth_FUNC);
	return rc;
}
#endif

#ifndef NO_ClearCurrentScrap
JNIEXPORT jint JNICALL OS_NATIVE(ClearCurrentScrap)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ClearCurrentScrap_FUNC);
	rc = (jint)ClearCurrentScrap();
	OS_NATIVE_EXIT(env, that, ClearCurrentScrap_FUNC);
	return rc;
}
#endif

#ifndef NO_ClearKeyboardFocus
JNIEXPORT jint JNICALL OS_NATIVE(ClearKeyboardFocus)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ClearKeyboardFocus_FUNC);
	rc = (jint)ClearKeyboardFocus((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, ClearKeyboardFocus_FUNC);
	return rc;
}
#endif

#ifndef NO_ClearMenuBar
JNIEXPORT void JNICALL OS_NATIVE(ClearMenuBar)
	(JNIEnv *env, jclass that)
{
	OS_NATIVE_ENTER(env, that, ClearMenuBar_FUNC);
	ClearMenuBar();
	OS_NATIVE_EXIT(env, that, ClearMenuBar_FUNC);
}
#endif

#ifndef NO_ClipCGContextToRegion
JNIEXPORT jint JNICALL OS_NATIVE(ClipCGContextToRegion)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	Rect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ClipCGContextToRegion_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	rc = (jint)ClipCGContextToRegion((CGContextRef)arg0, (const Rect *)lparg1, (RgnHandle)arg2);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, ClipCGContextToRegion_FUNC);
	return rc;
}
#endif

#ifndef NO_CloseDataBrowserContainer
JNIEXPORT jint JNICALL OS_NATIVE(CloseDataBrowserContainer)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CloseDataBrowserContainer_FUNC);
	rc = (jint)CloseDataBrowserContainer((ControlRef)arg0, (DataBrowserItemID)arg1);
	OS_NATIVE_EXIT(env, that, CloseDataBrowserContainer_FUNC);
	return rc;
}
#endif

#ifndef NO_ClosePoly
JNIEXPORT void JNICALL OS_NATIVE(ClosePoly)
	(JNIEnv *env, jclass that)
{
	OS_NATIVE_ENTER(env, that, ClosePoly_FUNC);
	ClosePoly();
	OS_NATIVE_EXIT(env, that, ClosePoly_FUNC);
}
#endif

#ifndef NO_CloseRgn
JNIEXPORT void JNICALL OS_NATIVE(CloseRgn)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, CloseRgn_FUNC);
	CloseRgn((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, CloseRgn_FUNC);
}
#endif

#ifndef NO_CollapseWindow
JNIEXPORT jint JNICALL OS_NATIVE(CollapseWindow)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, CollapseWindow_FUNC);
	rc = (jint)CollapseWindow((WindowRef)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, CollapseWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_ConvertEventRefToEventRecord
JNIEXPORT jboolean JNICALL OS_NATIVE(ConvertEventRefToEventRecord)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	EventRecord _arg1, *lparg1=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, ConvertEventRefToEventRecord_FUNC);
	if (arg1) lparg1 = getEventRecordFields(env, arg1, &_arg1);
	rc = (jboolean)ConvertEventRefToEventRecord((EventRef)arg0, (EventRecord *)lparg1);
	if (arg1) setEventRecordFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, ConvertEventRefToEventRecord_FUNC);
	return rc;
}
#endif

#ifndef NO_ConvertFromPStringToUnicode
JNIEXPORT jint JNICALL OS_NATIVE(ConvertFromPStringToUnicode)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1, jint arg2, jintArray arg3, jcharArray arg4)
{
	jbyte *lparg1=NULL;
	jint *lparg3=NULL;
	jchar *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ConvertFromPStringToUnicode_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetCharArrayElements(env, arg4, NULL);
	rc = (jint)ConvertFromPStringToUnicode((TextToUnicodeInfo)arg0, (ConstStr255Param)lparg1, arg2, lparg3, lparg4);
	if (arg4) (*env)->ReleaseCharArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, ConvertFromPStringToUnicode_FUNC);
	return rc;
}
#endif

#ifndef NO_ConvertFromUnicodeToPString
JNIEXPORT jint JNICALL OS_NATIVE(ConvertFromUnicodeToPString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jcharArray arg2, jbyteArray arg3)
{
	jchar *lparg2=NULL;
	jbyte *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ConvertFromUnicodeToPString_FUNC);
	if (arg2) lparg2 = (*env)->GetCharArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	rc = (jint)ConvertFromUnicodeToPString((UnicodeToTextInfo)arg0, arg1, (ConstUniCharArrayPtr)lparg2, lparg3);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseCharArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, ConvertFromUnicodeToPString_FUNC);
	return rc;
}
#endif

#ifndef NO_CopyBits
JNIEXPORT void JNICALL OS_NATIVE(CopyBits)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jobject arg3, jshort arg4, jint arg5)
{
	Rect _arg2, *lparg2=NULL;
	Rect _arg3, *lparg3=NULL;
	OS_NATIVE_ENTER(env, that, CopyBits_FUNC);
	if (arg2) lparg2 = getRectFields(env, arg2, &_arg2);
	if (arg3) lparg3 = getRectFields(env, arg3, &_arg3);
	CopyBits((const BitMap *)arg0, (const BitMap *)arg1, (const Rect *)lparg2, (const Rect *)lparg3, (short)arg4, (RgnHandle)arg5);
	if (arg3) setRectFields(env, arg3, lparg3);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, CopyBits_FUNC);
}
#endif

#ifndef NO_CopyControlTitleAsCFString
JNIEXPORT jint JNICALL OS_NATIVE(CopyControlTitleAsCFString)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CopyControlTitleAsCFString_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)CopyControlTitleAsCFString((ControlRef)arg0, (CFStringRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CopyControlTitleAsCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_CopyDeepMask
JNIEXPORT void JNICALL OS_NATIVE(CopyDeepMask)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jobject arg3, jobject arg4, jobject arg5, jshort arg6, jint arg7)
{
	Rect _arg3, *lparg3=NULL;
	Rect _arg4, *lparg4=NULL;
	Rect _arg5, *lparg5=NULL;
	OS_NATIVE_ENTER(env, that, CopyDeepMask_FUNC);
	if (arg3) lparg3 = getRectFields(env, arg3, &_arg3);
	if (arg4) lparg4 = getRectFields(env, arg4, &_arg4);
	if (arg5) lparg5 = getRectFields(env, arg5, &_arg5);
	CopyDeepMask((const BitMap *)arg0, (const BitMap *)arg1, (const BitMap *)arg2, (const Rect *)lparg3, (const Rect *)lparg4, (const Rect *)lparg5, (short)arg6, (RgnHandle)arg7);
	if (arg5) setRectFields(env, arg5, lparg5);
	if (arg4) setRectFields(env, arg4, lparg4);
	if (arg3) setRectFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, CopyDeepMask_FUNC);
}
#endif

#ifndef NO_CopyMenuItemTextAsCFString
JNIEXPORT jint JNICALL OS_NATIVE(CopyMenuItemTextAsCFString)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CopyMenuItemTextAsCFString_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)CopyMenuItemTextAsCFString((MenuRef)arg0, (MenuItemIndex)arg1, (CFStringRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, CopyMenuItemTextAsCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_CopyRgn
JNIEXPORT void JNICALL OS_NATIVE(CopyRgn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, CopyRgn_FUNC);
	CopyRgn((RgnHandle)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, CopyRgn_FUNC);
}
#endif

#ifndef NO_CountDragItemFlavors
JNIEXPORT jint JNICALL OS_NATIVE(CountDragItemFlavors)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshortArray arg2)
{
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CountDragItemFlavors_FUNC);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)CountDragItemFlavors((DragRef)arg0, (DragItemRef)arg1, (UInt16 *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, CountDragItemFlavors_FUNC);
	return rc;
}
#endif

#ifndef NO_CountDragItems
JNIEXPORT jint JNICALL OS_NATIVE(CountDragItems)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1)
{
	jshort *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CountDragItems_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	rc = (jint)CountDragItems((DragRef)arg0, (UInt16 *)lparg1);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CountDragItems_FUNC);
	return rc;
}
#endif

#ifndef NO_CountMenuItems
JNIEXPORT jshort JNICALL OS_NATIVE(CountMenuItems)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, CountMenuItems_FUNC);
	rc = (jshort)CountMenuItems((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, CountMenuItems_FUNC);
	return rc;
}
#endif

#ifndef NO_CountSubControls
JNIEXPORT jint JNICALL OS_NATIVE(CountSubControls)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1)
{
	jshort *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CountSubControls_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	rc = (jint)CountSubControls((ControlRef)arg0, (UInt16 *)lparg1);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CountSubControls_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateBevelButtonControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateBevelButtonControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jshort arg3, jshort arg4, jint arg5, jshort arg6, jshort arg7, jshort arg8, jintArray arg9)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg9=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateBevelButtonControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg9) lparg9 = (*env)->GetIntArrayElements(env, arg9, NULL);
	rc = (jint)CreateBevelButtonControl((WindowRef)arg0, (const Rect *)lparg1, (CFStringRef)arg2, (ControlBevelThickness)arg3, (ControlBevelButtonBehavior)arg4, (ControlButtonContentInfoPtr)arg5, (SInt16)arg6, (ControlBevelButtonMenuBehavior)arg7, (ControlBevelButtonMenuPlacement)arg8, (ControlRef *)lparg9);
	if (arg9) (*env)->ReleaseIntArrayElements(env, arg9, lparg9, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateBevelButtonControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateCGContextForPort
JNIEXPORT jint JNICALL OS_NATIVE(CreateCGContextForPort)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateCGContextForPort_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)CreateCGContextForPort((CGrafPtr)arg0, (CGContextRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CreateCGContextForPort_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateCheckBoxControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateCheckBoxControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jint arg3, jboolean arg4, jintArray arg5)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateCheckBoxControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)CreateCheckBoxControl((WindowRef)arg0, (const Rect *)lparg1, (CFStringRef)arg2, (SInt32)arg3, (Boolean)arg4, (ControlRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateCheckBoxControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateDataBrowserControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateDataBrowserControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jintArray arg3)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateDataBrowserControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)CreateDataBrowserControl((WindowRef)arg0, (const Rect *)lparg1, (DataBrowserViewStyle)arg2, (ControlRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateDataBrowserControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateEditUnicodeTextControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateEditUnicodeTextControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jboolean arg3, jobject arg4, jintArray arg5)
{
	Rect _arg1, *lparg1=NULL;
	ControlFontStyleRec _arg4, *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateEditUnicodeTextControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg4) lparg4 = getControlFontStyleRecFields(env, arg4, &_arg4);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)CreateEditUnicodeTextControl((WindowRef)arg0, lparg1, (CFStringRef)arg2, arg3, lparg4, (ControlRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) setControlFontStyleRecFields(env, arg4, lparg4);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateEditUnicodeTextControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateEvent
JNIEXPORT jint JNICALL OS_NATIVE(CreateEvent)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jdouble arg3, jint arg4, jintArray arg5)
{
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateEvent_FUNC);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)CreateEvent((CFAllocatorRef)arg0, (UInt32)arg1, (UInt32)arg2, (EventTime)arg3, (EventAttributes)arg4, (EventRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	OS_NATIVE_EXIT(env, that, CreateEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateGroupBoxControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateGroupBoxControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jboolean arg3, jintArray arg4)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateGroupBoxControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)CreateGroupBoxControl((WindowRef)arg0, (const Rect *)lparg1, (CFStringRef)arg2, (Boolean)arg3, (ControlRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateGroupBoxControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateIconControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateIconControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2, jboolean arg3, jintArray arg4)
{
	Rect _arg1, *lparg1=NULL;
	ControlButtonContentInfo _arg2, *lparg2=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateIconControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getControlButtonContentInfoFields(env, arg2, &_arg2);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)CreateIconControl((WindowRef)arg0, lparg1, lparg2, arg3, (ControlRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg2) setControlButtonContentInfoFields(env, arg2, lparg2);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateIconControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateNewMenu
JNIEXPORT jint JNICALL OS_NATIVE(CreateNewMenu)
	(JNIEnv *env, jclass that, jshort arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateNewMenu_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)CreateNewMenu((MenuID)arg0, (MenuAttributes)arg1, (MenuRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, CreateNewMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateNewWindow
JNIEXPORT jint JNICALL OS_NATIVE(CreateNewWindow)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jintArray arg3)
{
	Rect _arg2, *lparg2=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateNewWindow_FUNC);
	if (arg2) lparg2 = getRectFields(env, arg2, &_arg2);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)CreateNewWindow((WindowClass)arg0, (WindowAttributes)arg1, (const Rect *)lparg2, (WindowRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, CreateNewWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_CreatePopupArrowControl
JNIEXPORT jint JNICALL OS_NATIVE(CreatePopupArrowControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jshort arg2, jshort arg3, jintArray arg4)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreatePopupArrowControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)CreatePopupArrowControl((WindowRef)arg0, (const Rect *)lparg1, (ControlPopupArrowOrientation)arg2, (ControlPopupArrowSize)arg3, (ControlRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreatePopupArrowControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreatePopupButtonControl
JNIEXPORT jint JNICALL OS_NATIVE(CreatePopupButtonControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jshort arg3, jboolean arg4, jshort arg5, jshort arg6, jint arg7, jintArray arg8)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreatePopupButtonControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg8) lparg8 = (*env)->GetIntArrayElements(env, arg8, NULL);
	rc = (jint)CreatePopupButtonControl((WindowRef)arg0, lparg1, (CFStringRef)arg2, arg3, arg4, arg5, arg6, arg7, (ControlRef *)lparg8);
	if (arg8) (*env)->ReleaseIntArrayElements(env, arg8, lparg8, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreatePopupButtonControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateProgressBarControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateProgressBarControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jint arg3, jint arg4, jboolean arg5, jintArray arg6)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateProgressBarControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	rc = (jint)CreateProgressBarControl((WindowRef)arg0, lparg1, arg2, arg3, arg4, arg5, (ControlRef *)lparg6);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateProgressBarControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreatePushButtonControl
JNIEXPORT jint JNICALL OS_NATIVE(CreatePushButtonControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jintArray arg3)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreatePushButtonControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)CreatePushButtonControl((WindowRef)arg0, (const Rect *)lparg1, (CFStringRef)arg2, (ControlRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreatePushButtonControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreatePushButtonWithIconControl
JNIEXPORT jint JNICALL OS_NATIVE(CreatePushButtonWithIconControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jobject arg3, jshort arg4, jintArray arg5)
{
	Rect _arg1, *lparg1=NULL;
	ControlButtonContentInfo _arg3, *lparg3=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreatePushButtonWithIconControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg3) lparg3 = getControlButtonContentInfoFields(env, arg3, &_arg3);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)CreatePushButtonWithIconControl((WindowRef)arg0, lparg1, (CFStringRef)arg2, (ControlButtonContentInfo *)lparg3, (ControlPushButtonIconAlignment)arg4, (ControlRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) setControlButtonContentInfoFields(env, arg3, lparg3);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreatePushButtonWithIconControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateRadioButtonControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateRadioButtonControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jint arg3, jboolean arg4, jintArray arg5)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateRadioButtonControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)CreateRadioButtonControl((WindowRef)arg0, (const Rect *)lparg1, (CFStringRef)arg2, (SInt32)arg3, (Boolean)arg4, (ControlRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateRadioButtonControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateRootControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateRootControl)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateRootControl_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)CreateRootControl((WindowRef)arg0, (ControlRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CreateRootControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateScrollBarControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateScrollBarControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jint arg3, jint arg4, jint arg5, jboolean arg6, jint arg7, jintArray arg8)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateScrollBarControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg8) lparg8 = (*env)->GetIntArrayElements(env, arg8, NULL);
	rc = (jint)CreateScrollBarControl((WindowRef)arg0, lparg1, arg2, arg3, arg4, arg5, arg6, (ControlActionUPP)arg7, (ControlRef *)lparg8);
	if (arg8) (*env)->ReleaseIntArrayElements(env, arg8, lparg8, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateScrollBarControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateSeparatorControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateSeparatorControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jintArray arg2)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateSeparatorControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)CreateSeparatorControl((WindowRef)arg0, lparg1, (ControlRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateSeparatorControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateSliderControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateSliderControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jint arg3, jint arg4, jint arg5, jshort arg6, jboolean arg7, jint arg8, jintArray arg9)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg9=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateSliderControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg9) lparg9 = (*env)->GetIntArrayElements(env, arg9, NULL);
	rc = (jint)CreateSliderControl((WindowRef)arg0, (const Rect *)lparg1, (SInt32)arg2, (SInt32)arg3, (SInt32)arg4, (ControlSliderOrientation)arg5, (UInt16)arg6, (Boolean)arg7, (ControlActionUPP)arg8, (ControlRef *)lparg9);
	if (arg9) (*env)->ReleaseIntArrayElements(env, arg9, lparg9, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateSliderControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateStandardAlert
JNIEXPORT jint JNICALL OS_NATIVE(CreateStandardAlert)
	(JNIEnv *env, jclass that, jshort arg0, jint arg1, jint arg2, jobject arg3, jintArray arg4)
{
	AlertStdCFStringAlertParamRec _arg3, *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateStandardAlert_FUNC);
	if (arg3) lparg3 = getAlertStdCFStringAlertParamRecFields(env, arg3, &_arg3);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)CreateStandardAlert((AlertType)arg0, (CFStringRef)arg1, (CFStringRef)arg2, (const AlertStdCFStringAlertParamRec *)lparg3, (DialogRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) setAlertStdCFStringAlertParamRecFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, CreateStandardAlert_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateStaticTextControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateStaticTextControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jobject arg3, jintArray arg4)
{
	Rect _arg1, *lparg1=NULL;
	ControlFontStyleRec _arg3, *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateStaticTextControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg3) lparg3 = getControlFontStyleRecFields(env, arg3, &_arg3);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)CreateStaticTextControl((WindowRef)arg0, lparg1, (CFStringRef)arg2, (const ControlFontStyleRec *)lparg3, (ControlRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) setControlFontStyleRecFields(env, arg3, lparg3);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateStaticTextControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateTabsControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateTabsControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jshort arg2, jshort arg3, jshort arg4, jint arg5, jintArray arg6)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateTabsControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	rc = (jint)CreateTabsControl((WindowRef)arg0, (const Rect *)lparg1, (ControlTabSize)arg2, (ControlTabDirection)arg3, (UInt16)arg4, (const ControlTabEntry *)arg5, (ControlRef *)lparg6);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateTabsControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateTextToUnicodeInfoByEncoding
JNIEXPORT jint JNICALL OS_NATIVE(CreateTextToUnicodeInfoByEncoding)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateTextToUnicodeInfoByEncoding_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)CreateTextToUnicodeInfoByEncoding((TextEncoding)arg0, (TextToUnicodeInfo *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CreateTextToUnicodeInfoByEncoding_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateUnicodeToTextInfoByEncoding
JNIEXPORT jint JNICALL OS_NATIVE(CreateUnicodeToTextInfoByEncoding)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateUnicodeToTextInfoByEncoding_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)CreateUnicodeToTextInfoByEncoding((TextEncoding)arg0, (UnicodeToTextInfo *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CreateUnicodeToTextInfoByEncoding_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateUserPaneControl
JNIEXPORT jint JNICALL OS_NATIVE(CreateUserPaneControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jintArray arg3)
{
	Rect _arg1, *lparg1=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateUserPaneControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)CreateUserPaneControl((WindowRef)arg0, lparg1, arg2, (ControlRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, CreateUserPaneControl_FUNC);
	return rc;
}
#endif

#ifndef NO_CreateWindowGroup
JNIEXPORT jint JNICALL OS_NATIVE(CreateWindowGroup)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, CreateWindowGroup_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)CreateWindowGroup((WindowGroupAttributes)arg0, (WindowGroupRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, CreateWindowGroup_FUNC);
	return rc;
}
#endif

#ifndef NO_DMGetFirstScreenDevice
JNIEXPORT jint JNICALL OS_NATIVE(DMGetFirstScreenDevice)
	(JNIEnv *env, jclass that, jboolean arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, DMGetFirstScreenDevice_FUNC);
	rc = (jint)DMGetFirstScreenDevice((Boolean)arg0);
	OS_NATIVE_EXIT(env, that, DMGetFirstScreenDevice_FUNC);
	return rc;
}
#endif

#ifndef NO_DMGetNextScreenDevice
JNIEXPORT jint JNICALL OS_NATIVE(DMGetNextScreenDevice)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, DMGetNextScreenDevice_FUNC);
	rc = (jint)DMGetNextScreenDevice((GDHandle)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, DMGetNextScreenDevice_FUNC);
	return rc;
}
#endif

#ifndef NO_DeleteMenu
JNIEXPORT void JNICALL OS_NATIVE(DeleteMenu)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, DeleteMenu_FUNC);
	DeleteMenu((MenuID)arg0);
	OS_NATIVE_EXIT(env, that, DeleteMenu_FUNC);
}
#endif

#ifndef NO_DeleteMenuItem
JNIEXPORT void JNICALL OS_NATIVE(DeleteMenuItem)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, DeleteMenuItem_FUNC);
	DeleteMenuItem((MenuRef)arg0, (short)arg1);
	OS_NATIVE_EXIT(env, that, DeleteMenuItem_FUNC);
}
#endif

#ifndef NO_DeleteMenuItems
JNIEXPORT jint JNICALL OS_NATIVE(DeleteMenuItems)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, DeleteMenuItems_FUNC);
	rc = (jint)DeleteMenuItems((MenuRef)arg0, (MenuItemIndex)arg1, (ItemCount)arg2);
	OS_NATIVE_EXIT(env, that, DeleteMenuItems_FUNC);
	return rc;
}
#endif

#ifndef NO_DiffRgn
JNIEXPORT void JNICALL OS_NATIVE(DiffRgn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	OS_NATIVE_ENTER(env, that, DiffRgn_FUNC);
	DiffRgn((RgnHandle)arg0, (RgnHandle)arg1, (RgnHandle)arg2);
	OS_NATIVE_EXIT(env, that, DiffRgn_FUNC);
}
#endif

#ifndef NO_DisableControl
JNIEXPORT jint JNICALL OS_NATIVE(DisableControl)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, DisableControl_FUNC);
	rc = (jint)DisableControl((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, DisableControl_FUNC);
	return rc;
}
#endif

#ifndef NO_DisableMenuCommand
JNIEXPORT void JNICALL OS_NATIVE(DisableMenuCommand)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, DisableMenuCommand_FUNC);
	DisableMenuCommand((MenuRef)arg0, (MenuCommand)arg1);
	OS_NATIVE_EXIT(env, that, DisableMenuCommand_FUNC);
}
#endif

#ifndef NO_DisableMenuItem
JNIEXPORT void JNICALL OS_NATIVE(DisableMenuItem)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, DisableMenuItem_FUNC);
	DisableMenuItem((MenuRef)arg0, (MenuItemIndex)arg1);
	OS_NATIVE_EXIT(env, that, DisableMenuItem_FUNC);
}
#endif

#ifndef NO_DisposeControl
JNIEXPORT void JNICALL OS_NATIVE(DisposeControl)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposeControl_FUNC);
	DisposeControl((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, DisposeControl_FUNC);
}
#endif

#ifndef NO_DisposeDrag
JNIEXPORT jint JNICALL OS_NATIVE(DisposeDrag)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, DisposeDrag_FUNC);
	rc = (jint)DisposeDrag((DragRef)arg0);
	OS_NATIVE_EXIT(env, that, DisposeDrag_FUNC);
	return rc;
}
#endif

#ifndef NO_DisposeGWorld
JNIEXPORT void JNICALL OS_NATIVE(DisposeGWorld)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposeGWorld_FUNC);
	DisposeGWorld((GWorldPtr)arg0);
	OS_NATIVE_EXIT(env, that, DisposeGWorld_FUNC);
}
#endif

#ifndef NO_DisposeHandle
JNIEXPORT void JNICALL OS_NATIVE(DisposeHandle)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposeHandle_FUNC);
	DisposeHandle((Handle)arg0);
	OS_NATIVE_EXIT(env, that, DisposeHandle_FUNC);
}
#endif

#ifndef NO_DisposeMenu
JNIEXPORT void JNICALL OS_NATIVE(DisposeMenu)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposeMenu_FUNC);
	DisposeMenu((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, DisposeMenu_FUNC);
}
#endif

#ifndef NO_DisposePtr
JNIEXPORT void JNICALL OS_NATIVE(DisposePtr)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposePtr_FUNC);
	DisposePtr((Ptr)arg0);
	OS_NATIVE_EXIT(env, that, DisposePtr_FUNC);
}
#endif

#ifndef NO_DisposeRgn
JNIEXPORT void JNICALL OS_NATIVE(DisposeRgn)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposeRgn_FUNC);
	DisposeRgn((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, DisposeRgn_FUNC);
}
#endif

#ifndef NO_DisposeTextToUnicodeInfo
JNIEXPORT jint JNICALL OS_NATIVE(DisposeTextToUnicodeInfo)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DisposeTextToUnicodeInfo_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)DisposeTextToUnicodeInfo((TextToUnicodeInfo *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, DisposeTextToUnicodeInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_DisposeUnicodeToTextInfo
JNIEXPORT jint JNICALL OS_NATIVE(DisposeUnicodeToTextInfo)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DisposeUnicodeToTextInfo_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)DisposeUnicodeToTextInfo((UnicodeToTextInfo *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, DisposeUnicodeToTextInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_DisposeWindow
JNIEXPORT void JNICALL OS_NATIVE(DisposeWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DisposeWindow_FUNC);
	DisposeWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, DisposeWindow_FUNC);
}
#endif

#ifndef NO_DrawControlInCurrentPort
JNIEXPORT void JNICALL OS_NATIVE(DrawControlInCurrentPort)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, DrawControlInCurrentPort_FUNC);
	DrawControlInCurrentPort((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, DrawControlInCurrentPort_FUNC);
}
#endif

#ifndef NO_DrawMenuBar
JNIEXPORT void JNICALL OS_NATIVE(DrawMenuBar)
	(JNIEnv *env, jclass that)
{
	OS_NATIVE_ENTER(env, that, DrawMenuBar_FUNC);
	DrawMenuBar();
	OS_NATIVE_EXIT(env, that, DrawMenuBar_FUNC);
}
#endif

#ifndef NO_DrawText
JNIEXPORT void JNICALL OS_NATIVE(DrawText)
	(JNIEnv *env, jclass that, jbyteArray arg0, jshort arg1, jshort arg2)
{
	jbyte *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, DrawText_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	DrawText((const void *)lparg0, (short)arg1, (short)arg2);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, DrawText_FUNC);
}
#endif

#ifndef NO_DrawThemeButton
JNIEXPORT jint JNICALL OS_NATIVE(DrawThemeButton)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jobject arg2, jobject arg3, jint arg4, jint arg5, jint arg6)
{
	Rect _arg0, *lparg0=NULL;
	ThemeButtonDrawInfo _arg2, *lparg2=NULL;
	ThemeButtonDrawInfo _arg3, *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DrawThemeButton_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	if (arg2) lparg2 = getThemeButtonDrawInfoFields(env, arg2, &_arg2);
	if (arg3) lparg3 = getThemeButtonDrawInfoFields(env, arg3, &_arg3);
	rc = (jint)DrawThemeButton((Rect *)lparg0, (ThemeButtonKind)arg1, (const ThemeButtonDrawInfo *)lparg2, (const ThemeButtonDrawInfo *)lparg3, (ThemeEraseUPP)arg4, (ThemeButtonDrawUPP)arg5, (UInt32)arg6);
	if (arg3) setThemeButtonDrawInfoFields(env, arg3, lparg3);
	if (arg2) setThemeButtonDrawInfoFields(env, arg2, lparg2);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, DrawThemeButton_FUNC);
	return rc;
}
#endif

#ifndef NO_DrawThemeEditTextFrame
JNIEXPORT jint JNICALL OS_NATIVE(DrawThemeEditTextFrame)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1)
{
	Rect _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DrawThemeEditTextFrame_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	rc = (jint)DrawThemeEditTextFrame((const Rect *)lparg0, (ThemeDrawState)arg1);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, DrawThemeEditTextFrame_FUNC);
	return rc;
}
#endif

#ifndef NO_DrawThemeFocusRect
JNIEXPORT jint JNICALL OS_NATIVE(DrawThemeFocusRect)
	(JNIEnv *env, jclass that, jobject arg0, jboolean arg1)
{
	Rect _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DrawThemeFocusRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	rc = (jint)DrawThemeFocusRect((const Rect *)lparg0, (Boolean)arg1);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, DrawThemeFocusRect_FUNC);
	return rc;
}
#endif

#ifndef NO_DrawThemePopupArrow
JNIEXPORT jint JNICALL OS_NATIVE(DrawThemePopupArrow)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2, jint arg3, jint arg4, jint arg5)
{
	Rect _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DrawThemePopupArrow_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	rc = (jint)DrawThemePopupArrow(lparg0, (ThemeArrowOrientation)arg1, (ThemePopupArrowSize)arg2, (ThemeDrawState)arg3, (ThemeEraseUPP)arg4, (UInt32)arg5);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, DrawThemePopupArrow_FUNC);
	return rc;
}
#endif

#ifndef NO_DrawThemeSeparator
JNIEXPORT jint JNICALL OS_NATIVE(DrawThemeSeparator)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1)
{
	Rect _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DrawThemeSeparator_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	rc = (jint)DrawThemeSeparator((const Rect *)lparg0, (ThemeDrawState)arg1);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, DrawThemeSeparator_FUNC);
	return rc;
}
#endif

#ifndef NO_DrawThemeTextBox
JNIEXPORT jint JNICALL OS_NATIVE(DrawThemeTextBox)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jboolean arg3, jobject arg4, jshort arg5, jint arg6)
{
	Rect _arg4, *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, DrawThemeTextBox_FUNC);
	if (arg4) lparg4 = getRectFields(env, arg4, &_arg4);
	rc = (jint)DrawThemeTextBox((CFStringRef)arg0, (ThemeFontID)arg1, (ThemeDrawState)arg2, (Boolean)arg3, (const Rect *)lparg4, (SInt16)arg5, (void *)arg6);
	if (arg4) setRectFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, DrawThemeTextBox_FUNC);
	return rc;
}
#endif

#ifndef NO_EmbedControl
JNIEXPORT jint JNICALL OS_NATIVE(EmbedControl)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, EmbedControl_FUNC);
	rc = (jint)EmbedControl((ControlRef)arg0, (ControlRef)arg1);
	OS_NATIVE_EXIT(env, that, EmbedControl_FUNC);
	return rc;
}
#endif

#ifndef NO_EmptyRect
JNIEXPORT jboolean JNICALL OS_NATIVE(EmptyRect)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, EmptyRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	rc = (jboolean)EmptyRect((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, EmptyRect_FUNC);
	return rc;
}
#endif

#ifndef NO_EmptyRgn
JNIEXPORT jboolean JNICALL OS_NATIVE(EmptyRgn)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, EmptyRgn_FUNC);
	rc = (jboolean)EmptyRgn((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, EmptyRgn_FUNC);
	return rc;
}
#endif

#ifndef NO_EnableControl
JNIEXPORT jint JNICALL OS_NATIVE(EnableControl)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, EnableControl_FUNC);
	rc = (jint)EnableControl((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, EnableControl_FUNC);
	return rc;
}
#endif

#ifndef NO_EnableMenuCommand
JNIEXPORT void JNICALL OS_NATIVE(EnableMenuCommand)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, EnableMenuCommand_FUNC);
	EnableMenuCommand((MenuRef)arg0, (MenuCommand)arg1);
	OS_NATIVE_EXIT(env, that, EnableMenuCommand_FUNC);
}
#endif

#ifndef NO_EnableMenuItem
JNIEXPORT void JNICALL OS_NATIVE(EnableMenuItem)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, EnableMenuItem_FUNC);
	EnableMenuItem((MenuRef)arg0, (MenuItemIndex)arg1);
	OS_NATIVE_EXIT(env, that, EnableMenuItem_FUNC);
}
#endif

#ifndef NO_EndUpdate
JNIEXPORT void JNICALL OS_NATIVE(EndUpdate)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, EndUpdate_FUNC);
	EndUpdate((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, EndUpdate_FUNC);
}
#endif

#ifndef NO_EqualRect
JNIEXPORT jboolean JNICALL OS_NATIVE(EqualRect)
	(JNIEnv *env, jclass that, jobject arg0, jobject arg1)
{
	Rect _arg0, *lparg0=NULL;
	Rect _arg1, *lparg1=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, EqualRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	rc = (jboolean)EqualRect(lparg0, lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, EqualRect_FUNC);
	return rc;
}
#endif

#ifndef NO_EraseRect
JNIEXPORT void JNICALL OS_NATIVE(EraseRect)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, EraseRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	EraseRect((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, EraseRect_FUNC);
}
#endif

#ifndef NO_EraseRgn
JNIEXPORT void JNICALL OS_NATIVE(EraseRgn)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, EraseRgn_FUNC);
	EraseRgn((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, EraseRgn_FUNC);
}
#endif

#ifndef NO_FMCreateFontFamilyInstanceIterator
JNIEXPORT jint JNICALL OS_NATIVE(FMCreateFontFamilyInstanceIterator)
	(JNIEnv *env, jclass that, jshort arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FMCreateFontFamilyInstanceIterator_FUNC);
	rc = (jint)FMCreateFontFamilyInstanceIterator((FMFontFamily)arg0, (FMFontFamilyInstanceIterator *)arg1);
	OS_NATIVE_EXIT(env, that, FMCreateFontFamilyInstanceIterator_FUNC);
	return rc;
}
#endif

#ifndef NO_FMCreateFontFamilyIterator
JNIEXPORT jint JNICALL OS_NATIVE(FMCreateFontFamilyIterator)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FMCreateFontFamilyIterator_FUNC);
	rc = (jint)FMCreateFontFamilyIterator((const FMFilter *)arg0, (void *)arg1, (OptionBits)arg2, (FMFontFamilyIterator *)arg3);
	OS_NATIVE_EXIT(env, that, FMCreateFontFamilyIterator_FUNC);
	return rc;
}
#endif

#ifndef NO_FMDisposeFontFamilyInstanceIterator
JNIEXPORT jint JNICALL OS_NATIVE(FMDisposeFontFamilyInstanceIterator)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FMDisposeFontFamilyInstanceIterator_FUNC);
	rc = (jint)FMDisposeFontFamilyInstanceIterator((FMFontFamilyInstanceIterator *)arg0);
	OS_NATIVE_EXIT(env, that, FMDisposeFontFamilyInstanceIterator_FUNC);
	return rc;
}
#endif

#ifndef NO_FMDisposeFontFamilyIterator
JNIEXPORT jint JNICALL OS_NATIVE(FMDisposeFontFamilyIterator)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FMDisposeFontFamilyIterator_FUNC);
	rc = (jint)FMDisposeFontFamilyIterator((FMFontFamilyIterator *)arg0);
	OS_NATIVE_EXIT(env, that, FMDisposeFontFamilyIterator_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetATSFontRefFromFont
JNIEXPORT jint JNICALL OS_NATIVE(FMGetATSFontRefFromFont)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FMGetATSFontRefFromFont_FUNC);
	rc = (jint)FMGetATSFontRefFromFont(arg0);
	OS_NATIVE_EXIT(env, that, FMGetATSFontRefFromFont_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetFontFamilyFromName
JNIEXPORT jshort JNICALL OS_NATIVE(FMGetFontFamilyFromName)
	(JNIEnv *env, jclass that, jbyteArray arg0)
{
	jbyte *lparg0=NULL;
	jshort rc;
	OS_NATIVE_ENTER(env, that, FMGetFontFamilyFromName_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	rc = (jshort)FMGetFontFamilyFromName((ConstStr255Param)lparg0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, FMGetFontFamilyFromName_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetFontFamilyInstanceFromFont
JNIEXPORT jint JNICALL OS_NATIVE(FMGetFontFamilyInstanceFromFont)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1, jshortArray arg2)
{
	jshort *lparg1=NULL;
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FMGetFontFamilyInstanceFromFont_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)FMGetFontFamilyInstanceFromFont((FMFont)arg0, (FMFontFamily *)lparg1, (FMFontStyle *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, FMGetFontFamilyInstanceFromFont_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetFontFamilyName
JNIEXPORT jint JNICALL OS_NATIVE(FMGetFontFamilyName)
	(JNIEnv *env, jclass that, jshort arg0, jbyteArray arg1)
{
	jbyte *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FMGetFontFamilyName_FUNC);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jint)FMGetFontFamilyName(arg0, lparg1);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, FMGetFontFamilyName_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetFontFromFontFamilyInstance
JNIEXPORT jint JNICALL OS_NATIVE(FMGetFontFromFontFamilyInstance)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jintArray arg2, jshortArray arg3)
{
	jint *lparg2=NULL;
	jshort *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FMGetFontFromFontFamilyInstance_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetShortArrayElements(env, arg3, NULL);
	rc = (jint)FMGetFontFromFontFamilyInstance((FMFontFamily)arg0, (FMFontStyle)arg1, (FMFont *)lparg2, (FMFontStyle *)lparg3);
	if (arg3) (*env)->ReleaseShortArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, FMGetFontFromFontFamilyInstance_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetNextFontFamily
JNIEXPORT jint JNICALL OS_NATIVE(FMGetNextFontFamily)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1)
{
	jshort *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FMGetNextFontFamily_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	rc = (jint)FMGetNextFontFamily((FMFontFamilyIterator *)arg0, (FMFontFamily *)lparg1);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, FMGetNextFontFamily_FUNC);
	return rc;
}
#endif

#ifndef NO_FMGetNextFontFamilyInstance
JNIEXPORT jint JNICALL OS_NATIVE(FMGetNextFontFamilyInstance)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jshortArray arg2, jshortArray arg3)
{
	jint *lparg1=NULL;
	jshort *lparg2=NULL;
	jshort *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FMGetNextFontFamilyInstance_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetShortArrayElements(env, arg3, NULL);
	rc = (jint)FMGetNextFontFamilyInstance((FMFontFamilyInstanceIterator *)arg0, (FMFont *)lparg1, (FMFontStyle *)lparg2, (FMFontSize *)lparg3);
	if (arg3) (*env)->ReleaseShortArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, FMGetNextFontFamilyInstance_FUNC);
	return rc;
}
#endif

#ifndef NO_FPIsFontPanelVisible
JNIEXPORT jboolean JNICALL OS_NATIVE(FPIsFontPanelVisible)
	(JNIEnv *env, jclass that)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, FPIsFontPanelVisible_FUNC);
	rc = (jboolean)FPIsFontPanelVisible();
	OS_NATIVE_EXIT(env, that, FPIsFontPanelVisible_FUNC);
	return rc;
}
#endif

#ifndef NO_FPShowHideFontPanel
JNIEXPORT jint JNICALL OS_NATIVE(FPShowHideFontPanel)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FPShowHideFontPanel_FUNC);
	rc = (jint)FPShowHideFontPanel();
	OS_NATIVE_EXIT(env, that, FPShowHideFontPanel_FUNC);
	return rc;
}
#endif

#ifndef NO_FSGetCatalogInfo
JNIEXPORT jint JNICALL OS_NATIVE(FSGetCatalogInfo)
	(JNIEnv *env, jclass that, jbyteArray arg0, jint arg1, jbyteArray arg2, jbyteArray arg3, jbyteArray arg4, jbyteArray arg5)
{
	jbyte *lparg0=NULL;
	jbyte *lparg2=NULL;
	jbyte *lparg3=NULL;
	jbyte *lparg4=NULL;
	jbyte *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FSGetCatalogInfo_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	if (arg2) lparg2 = (*env)->GetByteArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetByteArrayElements(env, arg5, NULL);
	rc = (jint)FSGetCatalogInfo((FSRef *)lparg0, (FSCatalogInfoBitmap)arg1, (FSCatalogInfo *)lparg2, (HFSUniStr255 *)lparg3, (FSSpec *)lparg4, (FSRef *)lparg5);
	if (arg5) (*env)->ReleaseByteArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseByteArrayElements(env, arg2, lparg2, 0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, FSGetCatalogInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_FSpGetFInfo
JNIEXPORT jint JNICALL OS_NATIVE(FSpGetFInfo)
	(JNIEnv *env, jclass that, jbyteArray arg0, jbyteArray arg1)
{
	jbyte *lparg0=NULL;
	jbyte *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FSpGetFInfo_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jint)FSpGetFInfo((FSSpec *)lparg0, (FInfo *)lparg1);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, FSpGetFInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_FSpMakeFSRef
JNIEXPORT jint JNICALL OS_NATIVE(FSpMakeFSRef)
	(JNIEnv *env, jclass that, jbyteArray arg0, jbyteArray arg1)
{
	jbyte *lparg0=NULL;
	jbyte *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FSpMakeFSRef_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	rc = (jint)FSpMakeFSRef((const FSSpec *)lparg0, (FSRef *)lparg1);
	if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, FSpMakeFSRef_FUNC);
	return rc;
}
#endif

#ifndef NO_FetchFontInfo
JNIEXPORT jint JNICALL OS_NATIVE(FetchFontInfo)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jshort arg2, jobject arg3)
{
	FontInfo _arg3, *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, FetchFontInfo_FUNC);
	if (arg3) lparg3 = getFontInfoFields(env, arg3, &_arg3);
	rc = (jint)FetchFontInfo(arg0, arg1, arg2, lparg3);
	if (arg3) setFontInfoFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, FetchFontInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_FindWindow
JNIEXPORT jshort JNICALL OS_NATIVE(FindWindow)
	(JNIEnv *env, jclass that, jobject arg0, jintArray arg1)
{
	Point _arg0, *lparg0=NULL;
	jint *lparg1=NULL;
	jshort rc;
	OS_NATIVE_ENTER(env, that, FindWindow_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jshort)FindWindow(*(Point *)lparg0, (WindowRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, FindWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_Fix2Long
JNIEXPORT jint JNICALL OS_NATIVE(Fix2Long)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, Fix2Long_FUNC);
	rc = (jint)Fix2Long(arg0);
	OS_NATIVE_EXIT(env, that, Fix2Long_FUNC);
	return rc;
}
#endif

#ifndef NO_FrameOval
JNIEXPORT void JNICALL OS_NATIVE(FrameOval)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, FrameOval_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	FrameOval((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, FrameOval_FUNC);
}
#endif

#ifndef NO_FramePoly
JNIEXPORT void JNICALL OS_NATIVE(FramePoly)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, FramePoly_FUNC);
	FramePoly((PolyHandle)arg0);
	OS_NATIVE_EXIT(env, that, FramePoly_FUNC);
}
#endif

#ifndef NO_FrameRect
JNIEXPORT void JNICALL OS_NATIVE(FrameRect)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, FrameRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	FrameRect((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, FrameRect_FUNC);
}
#endif

#ifndef NO_FrameRoundRect
JNIEXPORT void JNICALL OS_NATIVE(FrameRoundRect)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, FrameRoundRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	FrameRoundRect((const Rect *)lparg0, (short)arg1, (short)arg2);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, FrameRoundRect_FUNC);
}
#endif

#ifndef NO_FrontWindow
JNIEXPORT jint JNICALL OS_NATIVE(FrontWindow)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, FrontWindow_FUNC);
	rc = (jint)FrontWindow();
	OS_NATIVE_EXIT(env, that, FrontWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_Gestalt
JNIEXPORT jint JNICALL OS_NATIVE(Gestalt)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, Gestalt_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)Gestalt((OSType)arg0, (long *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, Gestalt_FUNC);
	return rc;
}
#endif

#ifndef NO_GetAppFont
JNIEXPORT jshort JNICALL OS_NATIVE(GetAppFont)
	(JNIEnv *env, jclass that)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetAppFont_FUNC);
	rc = (jshort)GetAppFont();
	OS_NATIVE_EXIT(env, that, GetAppFont_FUNC);
	return rc;
}
#endif

#ifndef NO_GetApplicationEventTarget
JNIEXPORT jint JNICALL OS_NATIVE(GetApplicationEventTarget)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetApplicationEventTarget_FUNC);
	rc = (jint)GetApplicationEventTarget();
	OS_NATIVE_EXIT(env, that, GetApplicationEventTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_GetAvailableWindowAttributes
JNIEXPORT jint JNICALL OS_NATIVE(GetAvailableWindowAttributes)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetAvailableWindowAttributes_FUNC);
	rc = (jint)GetAvailableWindowAttributes((WindowClass)arg0);
	OS_NATIVE_EXIT(env, that, GetAvailableWindowAttributes_FUNC);
	return rc;
}
#endif

#ifndef NO_GetAvailableWindowPositioningBounds
JNIEXPORT jint JNICALL OS_NATIVE(GetAvailableWindowPositioningBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetAvailableWindowPositioningBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	rc = (jint)GetAvailableWindowPositioningBounds((GDHandle)arg0, (Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetAvailableWindowPositioningBounds_FUNC);
	return rc;
}
#endif

#ifndef NO_GetBestControlRect
JNIEXPORT jint JNICALL OS_NATIVE(GetBestControlRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jshortArray arg2)
{
	Rect _arg1, *lparg1=NULL;
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetBestControlRect_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)GetBestControlRect((ControlRef)arg0, (Rect *)lparg1, (SInt16 *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetBestControlRect_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCaretTime
JNIEXPORT jint JNICALL OS_NATIVE(GetCaretTime)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCaretTime_FUNC);
	rc = (jint)GetCaretTime();
	OS_NATIVE_EXIT(env, that, GetCaretTime_FUNC);
	return rc;
}
#endif

#ifndef NO_GetClip
JNIEXPORT void JNICALL OS_NATIVE(GetClip)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, GetClip_FUNC);
	GetClip((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, GetClip_FUNC);
}
#endif

#ifndef NO_GetControl32BitMaximum
JNIEXPORT jint JNICALL OS_NATIVE(GetControl32BitMaximum)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControl32BitMaximum_FUNC);
	rc = (jint)GetControl32BitMaximum((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControl32BitMaximum_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControl32BitMinimum
JNIEXPORT jint JNICALL OS_NATIVE(GetControl32BitMinimum)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControl32BitMinimum_FUNC);
	rc = (jint)GetControl32BitMinimum((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControl32BitMinimum_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControl32BitValue
JNIEXPORT jint JNICALL OS_NATIVE(GetControl32BitValue)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControl32BitValue_FUNC);
	rc = (jint)GetControl32BitValue((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControl32BitValue_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlBounds
JNIEXPORT void JNICALL OS_NATIVE(GetControlBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, GetControlBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	GetControlBounds((ControlRef)arg0, (Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetControlBounds_FUNC);
}
#endif

#ifndef NO_GetControlData__ISIILorg_eclipse_swt_internal_carbon_ControlFontStyleRec_2_3I
JNIEXPORT jint JNICALL OS_NATIVE(GetControlData__ISIILorg_eclipse_swt_internal_carbon_ControlFontStyleRec_2_3I)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jint arg3, jobject arg4, jintArray arg5)
{
	ControlFontStyleRec _arg4, *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlData__ISIILorg_eclipse_swt_internal_carbon_ControlFontStyleRec_2_3I_FUNC);
	if (arg4) lparg4 = getControlFontStyleRecFields(env, arg4, &_arg4);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)GetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (void *)lparg4, (Size *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) setControlFontStyleRecFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, GetControlData__ISIILorg_eclipse_swt_internal_carbon_ControlFontStyleRec_2_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlData__ISIILorg_eclipse_swt_internal_carbon_Rect_2_3I
JNIEXPORT jint JNICALL OS_NATIVE(GetControlData__ISIILorg_eclipse_swt_internal_carbon_Rect_2_3I)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jint arg3, jobject arg4, jintArray arg5)
{
	Rect _arg4, *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlData__ISIILorg_eclipse_swt_internal_carbon_Rect_2_3I_FUNC);
	if (arg4) lparg4 = getRectFields(env, arg4, &_arg4);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)GetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (void *)lparg4, (Size *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) setRectFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, GetControlData__ISIILorg_eclipse_swt_internal_carbon_Rect_2_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlData__ISII_3B_3I
JNIEXPORT jint JNICALL OS_NATIVE(GetControlData__ISII_3B_3I)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jint arg3, jbyteArray arg4, jintArray arg5)
{
	jbyte *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlData__ISII_3B_3I_FUNC);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)GetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (void *)lparg4, (Size *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, GetControlData__ISII_3B_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlData__ISII_3I_3I
JNIEXPORT jint JNICALL OS_NATIVE(GetControlData__ISII_3I_3I)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jint arg3, jintArray arg4, jintArray arg5)
{
	jint *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlData__ISII_3I_3I_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)GetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (void *)lparg4, (Size *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, GetControlData__ISII_3I_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlData__ISII_3S_3I
JNIEXPORT jint JNICALL OS_NATIVE(GetControlData__ISII_3S_3I)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jint arg3, jshortArray arg4, jintArray arg5)
{
	jshort *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlData__ISII_3S_3I_FUNC);
	if (arg4) lparg4 = (*env)->GetShortArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)GetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (void *)lparg4, (Size *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseShortArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, GetControlData__ISII_3S_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlEventTarget
JNIEXPORT jint JNICALL OS_NATIVE(GetControlEventTarget)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlEventTarget_FUNC);
	rc = (jint)GetControlEventTarget((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControlEventTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlFeatures
JNIEXPORT jint JNICALL OS_NATIVE(GetControlFeatures)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlFeatures_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetControlFeatures((ControlRef)arg0, lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetControlFeatures_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlOwner
JNIEXPORT jint JNICALL OS_NATIVE(GetControlOwner)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlOwner_FUNC);
	rc = (jint)GetControlOwner((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControlOwner_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlProperty
JNIEXPORT jint JNICALL OS_NATIVE(GetControlProperty)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jintArray arg4, jintArray arg5)
{
	jint *lparg4=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlProperty_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)GetControlProperty((ControlRef)arg0, arg1, arg2, arg3, lparg4, lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, GetControlProperty_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlReference
JNIEXPORT jint JNICALL OS_NATIVE(GetControlReference)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlReference_FUNC);
	rc = (jint)GetControlReference((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControlReference_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlRegion
JNIEXPORT jint JNICALL OS_NATIVE(GetControlRegion)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlRegion_FUNC);
	rc = (jint)GetControlRegion((ControlRef)arg0, (ControlPartCode)arg1, (RgnHandle)arg2);
	OS_NATIVE_EXIT(env, that, GetControlRegion_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlValue
JNIEXPORT jshort JNICALL OS_NATIVE(GetControlValue)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetControlValue_FUNC);
	rc = (jshort)GetControlValue((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControlValue_FUNC);
	return rc;
}
#endif

#ifndef NO_GetControlViewSize
JNIEXPORT jint JNICALL OS_NATIVE(GetControlViewSize)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetControlViewSize_FUNC);
	rc = (jint)GetControlViewSize((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, GetControlViewSize_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCurrentEventButtonState
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentEventButtonState)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCurrentEventButtonState_FUNC);
	rc = (jint)GetCurrentEventButtonState();
	OS_NATIVE_EXIT(env, that, GetCurrentEventButtonState_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCurrentEventKeyModifiers
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentEventKeyModifiers)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCurrentEventKeyModifiers_FUNC);
	rc = (jint)GetCurrentEventKeyModifiers();
	OS_NATIVE_EXIT(env, that, GetCurrentEventKeyModifiers_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCurrentEventLoop
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentEventLoop)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCurrentEventLoop_FUNC);
	rc = (jint)GetCurrentEventLoop();
	OS_NATIVE_EXIT(env, that, GetCurrentEventLoop_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCurrentEventQueue
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentEventQueue)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCurrentEventQueue_FUNC);
	rc = (jint)GetCurrentEventQueue();
	OS_NATIVE_EXIT(env, that, GetCurrentEventQueue_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCurrentProcess
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentProcess)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCurrentProcess_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)GetCurrentProcess((ProcessSerialNumber *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, GetCurrentProcess_FUNC);
	return rc;
}
#endif

#ifndef NO_GetCurrentScrap
JNIEXPORT jint JNICALL OS_NATIVE(GetCurrentScrap)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetCurrentScrap_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)GetCurrentScrap((ScrapRef *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, GetCurrentScrap_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserCallbacks
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserCallbacks)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	DataBrowserCallbacks _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserCallbacks_FUNC);
	if (arg1) lparg1 = getDataBrowserCallbacksFields(env, arg1, &_arg1);
	rc = (jint)GetDataBrowserCallbacks((ControlRef)arg0, (DataBrowserCallbacks *)lparg1);
	if (arg1) setDataBrowserCallbacksFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetDataBrowserCallbacks_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserItemCount
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserItemCount)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2, jint arg3, jintArray arg4)
{
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserItemCount_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)GetDataBrowserItemCount((ControlRef)arg0, (DataBrowserItemID)arg1, (Boolean)arg2, (DataBrowserItemState)arg3, (UInt32 *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserItemCount_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserItemDataButtonValue
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserItemDataButtonValue)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1)
{
	jshort *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserItemDataButtonValue_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	rc = (jint)GetDataBrowserItemDataButtonValue((ControlRef)arg0, lparg1);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserItemDataButtonValue_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserItemPartBounds
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserItemPartBounds)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jobject arg4)
{
	Rect _arg4, *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserItemPartBounds_FUNC);
	if (arg4) lparg4 = getRectFields(env, arg4, &_arg4);
	rc = (jint)GetDataBrowserItemPartBounds((ControlRef)arg0, (DataBrowserItemID)arg1, (DataBrowserPropertyID)arg2, (DataBrowserPropertyPart)arg3, (Rect *)lparg4);
	if (arg4) setRectFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, GetDataBrowserItemPartBounds_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserItemState
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserItemState)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserItemState_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserItemState((ControlRef)arg0, arg1, lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserItemState_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserItems
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserItems)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserItems_FUNC);
	rc = (jint)GetDataBrowserItems((ControlRef)arg0, (DataBrowserItemID)arg1, (Boolean)arg2, (DataBrowserItemState)arg3, (Handle)arg4);
	OS_NATIVE_EXIT(env, that, GetDataBrowserItems_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserListViewHeaderBtnHeight
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserListViewHeaderBtnHeight)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1)
{
	jshort *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserListViewHeaderBtnHeight_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	rc = (jint)GetDataBrowserListViewHeaderBtnHeight((ControlRef)arg0, lparg1);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserListViewHeaderBtnHeight_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserListViewHeaderDesc
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserListViewHeaderDesc)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	DataBrowserListViewHeaderDesc _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserListViewHeaderDesc_FUNC);
	if (arg2) lparg2 = getDataBrowserListViewHeaderDescFields(env, arg2, &_arg2);
	rc = (jint)GetDataBrowserListViewHeaderDesc((ControlRef)arg0, (DataBrowserTableViewColumnID)arg1, (DataBrowserListViewHeaderDesc *)lparg2);
	if (arg2) setDataBrowserListViewHeaderDescFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, GetDataBrowserListViewHeaderDesc_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserScrollBarInset
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserScrollBarInset)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserScrollBarInset_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	rc = (jint)GetDataBrowserScrollBarInset((ControlRef)arg0, lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetDataBrowserScrollBarInset_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserScrollPosition
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserScrollPosition)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserScrollPosition_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserScrollPosition((ControlRef)arg0, (UInt32 *)lparg1, (UInt32 *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserScrollPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserSelectionAnchor
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserSelectionAnchor)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserSelectionAnchor_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserSelectionAnchor((ControlRef)arg0, (UInt32 *)lparg1, (UInt32 *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserSelectionAnchor_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserSelectionFlags
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserSelectionFlags)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserSelectionFlags_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetDataBrowserSelectionFlags((ControlRef)arg0, lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserSelectionFlags_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserSortProperty
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserSortProperty)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserSortProperty_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetDataBrowserSortProperty((ControlRef)arg0, lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserSortProperty_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserTableViewColumnPosition
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserTableViewColumnPosition)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserTableViewColumnPosition_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserTableViewColumnPosition((ControlRef)arg0, (DataBrowserTableViewColumnID)arg1, (DataBrowserTableViewColumnIndex *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserTableViewColumnPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserTableViewItemID
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserTableViewItemID)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserTableViewItemID_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserTableViewItemID((ControlRef)arg0, (DataBrowserTableViewRowIndex)arg1, (DataBrowserItemID *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserTableViewItemID_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserTableViewItemRow
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserTableViewItemRow)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserTableViewItemRow_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserTableViewItemRow((ControlRef)arg0, (DataBrowserTableViewRowIndex)arg1, (DataBrowserItemID *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserTableViewItemRow_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserTableViewNamedColumnWidth
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserTableViewNamedColumnWidth)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshortArray arg2)
{
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserTableViewNamedColumnWidth_FUNC);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)GetDataBrowserTableViewNamedColumnWidth((ControlRef)arg0, (DataBrowserTableViewColumnID)arg1, (UInt16 *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserTableViewNamedColumnWidth_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDataBrowserTableViewRowHeight
JNIEXPORT jint JNICALL OS_NATIVE(GetDataBrowserTableViewRowHeight)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1)
{
	jshort *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDataBrowserTableViewRowHeight_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	rc = (jint)GetDataBrowserTableViewRowHeight((ControlRef)arg0, (UInt16 *)lparg1);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDataBrowserTableViewRowHeight_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDblTime
JNIEXPORT jint JNICALL OS_NATIVE(GetDblTime)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDblTime_FUNC);
	rc = (jint)GetDblTime();
	OS_NATIVE_EXIT(env, that, GetDblTime_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDefFontSize
JNIEXPORT jshort JNICALL OS_NATIVE(GetDefFontSize)
	(JNIEnv *env, jclass that)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetDefFontSize_FUNC);
	rc = (jshort)GetDefFontSize();
	OS_NATIVE_EXIT(env, that, GetDefFontSize_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDeviceList
JNIEXPORT jint JNICALL OS_NATIVE(GetDeviceList)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDeviceList_FUNC);
	rc = (jint)GetDeviceList();
	OS_NATIVE_EXIT(env, that, GetDeviceList_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDragAllowableActions
JNIEXPORT jint JNICALL OS_NATIVE(GetDragAllowableActions)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDragAllowableActions_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetDragAllowableActions((DragRef)arg0, (DragActions *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDragAllowableActions_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDragDropAction
JNIEXPORT jint JNICALL OS_NATIVE(GetDragDropAction)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDragDropAction_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetDragDropAction((DragRef)arg0, (DragActions *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDragDropAction_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDragItemReferenceNumber
JNIEXPORT jint JNICALL OS_NATIVE(GetDragItemReferenceNumber)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDragItemReferenceNumber_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetDragItemReferenceNumber((DragRef)arg0, arg1, (DragItemRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetDragItemReferenceNumber_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDragModifiers
JNIEXPORT jint JNICALL OS_NATIVE(GetDragModifiers)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1, jshortArray arg2, jshortArray arg3)
{
	jshort *lparg1=NULL;
	jshort *lparg2=NULL;
	jshort *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDragModifiers_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetShortArrayElements(env, arg3, NULL);
	rc = (jint)GetDragModifiers((DragRef)arg0, (SInt16 *)lparg1, (SInt16 *)lparg2, (SInt16 *)lparg3);
	if (arg3) (*env)->ReleaseShortArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetDragModifiers_FUNC);
	return rc;
}
#endif

#ifndef NO_GetDragMouse
JNIEXPORT jint JNICALL OS_NATIVE(GetDragMouse)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2)
{
	Point _arg1, *lparg1=NULL;
	Point _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetDragMouse_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getPointFields(env, arg2, &_arg2);
	rc = (jint)GetDragMouse((DragRef)arg0, (Point *)lparg1, (Point *)lparg2);
	if (arg2) setPointFields(env, arg2, lparg2);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetDragMouse_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventClass
JNIEXPORT jint JNICALL OS_NATIVE(GetEventClass)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventClass_FUNC);
	rc = (jint)GetEventClass((EventRef)arg0);
	OS_NATIVE_EXIT(env, that, GetEventClass_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventDispatcherTarget
JNIEXPORT jint JNICALL OS_NATIVE(GetEventDispatcherTarget)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventDispatcherTarget_FUNC);
	rc = (jint)GetEventDispatcherTarget();
	OS_NATIVE_EXIT(env, that, GetEventDispatcherTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventKind
JNIEXPORT jint JNICALL OS_NATIVE(GetEventKind)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventKind_FUNC);
	rc = (jint)GetEventKind((EventRef)arg0);
	OS_NATIVE_EXIT(env, that, GetEventKind_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_CGPoint_2
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_CGPoint_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jobject arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	CGPoint _arg6, *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_CGPoint_2_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = getCGPointFields(env, arg6, &_arg6);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) setCGPointFields(env, arg6, lparg6);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_CGPoint_2_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_HICommand_2
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_HICommand_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jobject arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	HICommand _arg6, *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_HICommand_2_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = getHICommandFields(env, arg6, &_arg6);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) setHICommandFields(env, arg6, lparg6);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_HICommand_2_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Point_2
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Point_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jobject arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	Point _arg6, *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Point_2_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = getPointFields(env, arg6, &_arg6);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) setPointFields(env, arg6, lparg6);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Point_2_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_RGBColor_2
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_RGBColor_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jobject arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	RGBColor _arg6, *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_RGBColor_2_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = getRGBColorFields(env, arg6, &_arg6);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) setRGBColorFields(env, arg6, lparg6);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_RGBColor_2_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Rect_2
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Rect_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jobject arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	Rect _arg6, *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Rect_2_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = getRectFields(env, arg6, &_arg6);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) setRectFields(env, arg6, lparg6);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3ILorg_eclipse_swt_internal_carbon_Rect_2_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3I_3B
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3I_3B)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jbyteArray arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	jbyte *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3I_3B_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetByteArrayElements(env, arg6, NULL);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) (*env)->ReleaseByteArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3I_3B_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3I_3C
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3I_3C)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jcharArray arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	jchar *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3I_3C_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetCharArrayElements(env, arg6, NULL);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) (*env)->ReleaseCharArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3I_3C_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3I_3I
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3I_3I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jintArray arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	jint *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3I_3I_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3I_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventParameter__III_3II_3I_3S
JNIEXPORT jint JNICALL OS_NATIVE(GetEventParameter__III_3II_3I_3S)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5, jshortArray arg6)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	jshort *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetEventParameter__III_3II_3I_3S_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg6) lparg6 = (*env)->GetShortArrayElements(env, arg6, NULL);
	rc = (jint)GetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (EventParamType *)lparg3, (UInt32)arg4, (UInt32 *)lparg5, (void *)lparg6);
	if (arg6) (*env)->ReleaseShortArrayElements(env, arg6, lparg6, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetEventParameter__III_3II_3I_3S_FUNC);
	return rc;
}
#endif

#ifndef NO_GetEventTime
JNIEXPORT jdouble JNICALL OS_NATIVE(GetEventTime)
	(JNIEnv *env, jclass that, jint arg0)
{
	jdouble rc;
	OS_NATIVE_ENTER(env, that, GetEventTime_FUNC);
	rc = (jdouble)GetEventTime((EventRef)arg0);
	OS_NATIVE_EXIT(env, that, GetEventTime_FUNC);
	return rc;
}
#endif

#ifndef NO_GetFlavorData
JNIEXPORT jint JNICALL OS_NATIVE(GetFlavorData)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jbyteArray arg3, jintArray arg4, jint arg5)
{
	jbyte *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetFlavorData_FUNC);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)GetFlavorData((DragRef)arg0, (DragItemRef)arg1, (FlavorType)arg2, (void *)lparg3, (Size *)lparg4, arg5);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetFlavorData_FUNC);
	return rc;
}
#endif

#ifndef NO_GetFlavorDataSize
JNIEXPORT jint JNICALL OS_NATIVE(GetFlavorDataSize)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetFlavorDataSize_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)GetFlavorDataSize((DragRef)arg0, (DragItemRef)arg1, (FlavorType)arg2, (Size *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetFlavorDataSize_FUNC);
	return rc;
}
#endif

#ifndef NO_GetFlavorType
JNIEXPORT jint JNICALL OS_NATIVE(GetFlavorType)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshort arg2, jintArray arg3)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetFlavorType_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)GetFlavorType((DragRef)arg0, (DragItemRef)arg1, arg2, (FlavorType *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetFlavorType_FUNC);
	return rc;
}
#endif

#ifndef NO_GetFontInfo
JNIEXPORT void JNICALL OS_NATIVE(GetFontInfo)
	(JNIEnv *env, jclass that, jobject arg0)
{
	FontInfo _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, GetFontInfo_FUNC);
	if (arg0) lparg0 = getFontInfoFields(env, arg0, &_arg0);
	GetFontInfo((FontInfo *)lparg0);
	if (arg0) setFontInfoFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, GetFontInfo_FUNC);
}
#endif

#ifndef NO_GetGDevice
JNIEXPORT jint JNICALL OS_NATIVE(GetGDevice)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetGDevice_FUNC);
	rc = (jint)GetGDevice();
	OS_NATIVE_EXIT(env, that, GetGDevice_FUNC);
	return rc;
}
#endif

#ifndef NO_GetGWorld
JNIEXPORT void JNICALL OS_NATIVE(GetGWorld)
	(JNIEnv *env, jclass that, jintArray arg0, jintArray arg1)
{
	jint *lparg0=NULL;
	jint *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, GetGWorld_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	GetGWorld((CGrafPtr *)lparg0, (GDHandle *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, GetGWorld_FUNC);
}
#endif

#ifndef NO_GetGlobalMouse
JNIEXPORT void JNICALL OS_NATIVE(GetGlobalMouse)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Point _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, GetGlobalMouse_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	GetGlobalMouse((Point *)lparg0);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, GetGlobalMouse_FUNC);
}
#endif

#ifndef NO_GetHandleSize
JNIEXPORT jint JNICALL OS_NATIVE(GetHandleSize)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetHandleSize_FUNC);
	rc = (jint)GetHandleSize((Handle)arg0);
	OS_NATIVE_EXIT(env, that, GetHandleSize_FUNC);
	return rc;
}
#endif

#ifndef NO_GetIconFamilyData
JNIEXPORT jint JNICALL OS_NATIVE(GetIconFamilyData)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetIconFamilyData_FUNC);
	rc = (jint)GetIconFamilyData((IconFamilyHandle)arg0, (OSType)arg1, (Handle)arg2);
	OS_NATIVE_EXIT(env, that, GetIconFamilyData_FUNC);
	return rc;
}
#endif

#ifndef NO_GetIconRef
JNIEXPORT jint JNICALL OS_NATIVE(GetIconRef)
	(JNIEnv *env, jclass that, jshort arg0, jint arg1, jint arg2, jintArray arg3)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetIconRef_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)GetIconRef((SInt16)arg0, (OSType)arg1, (OSType)arg2, (IconRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetIconRef_FUNC);
	return rc;
}
#endif

#ifndef NO_GetIndMenuItemWithCommandID
JNIEXPORT jint JNICALL OS_NATIVE(GetIndMenuItemWithCommandID)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jshortArray arg4)
{
	jint *lparg3=NULL;
	jshort *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetIndMenuItemWithCommandID_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetShortArrayElements(env, arg4, NULL);
	rc = (jint)GetIndMenuItemWithCommandID((MenuRef)arg0, (MenuCommand)arg1, (UInt32)arg2, (MenuRef *)lparg3, (MenuItemIndex *)lparg4);
	if (arg4) (*env)->ReleaseShortArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, GetIndMenuItemWithCommandID_FUNC);
	return rc;
}
#endif

#ifndef NO_GetIndexedSubControl
JNIEXPORT jint JNICALL OS_NATIVE(GetIndexedSubControl)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetIndexedSubControl_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetIndexedSubControl((ControlRef)arg0, (UInt16)arg1, (ControlRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetIndexedSubControl_FUNC);
	return rc;
}
#endif

#ifndef NO_GetItemMark
JNIEXPORT void JNICALL OS_NATIVE(GetItemMark)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshortArray arg2)
{
	jshort *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, GetItemMark_FUNC);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	GetItemMark((MenuRef)arg0, arg1, lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetItemMark_FUNC);
}
#endif

#ifndef NO_GetKeyboardFocus
JNIEXPORT jint JNICALL OS_NATIVE(GetKeyboardFocus)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetKeyboardFocus_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetKeyboardFocus((WindowRef)arg0, (ControlRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetKeyboardFocus_FUNC);
	return rc;
}
#endif

#ifndef NO_GetLastUserEventTime
JNIEXPORT jdouble JNICALL OS_NATIVE(GetLastUserEventTime)
	(JNIEnv *env, jclass that)
{
	jdouble rc;
	OS_NATIVE_ENTER(env, that, GetLastUserEventTime_FUNC);
	rc = (jdouble)GetLastUserEventTime();
	OS_NATIVE_EXIT(env, that, GetLastUserEventTime_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMBarHeight
JNIEXPORT jint JNICALL OS_NATIVE(GetMBarHeight)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMBarHeight_FUNC);
	rc = (jint)GetMBarHeight();
	OS_NATIVE_EXIT(env, that, GetMBarHeight_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMainDevice
JNIEXPORT jint JNICALL OS_NATIVE(GetMainDevice)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMainDevice_FUNC);
	rc = (jint)GetMainDevice();
	OS_NATIVE_EXIT(env, that, GetMainDevice_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMainEventQueue
JNIEXPORT jint JNICALL OS_NATIVE(GetMainEventQueue)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMainEventQueue_FUNC);
	rc = (jint)GetMainEventQueue();
	OS_NATIVE_EXIT(env, that, GetMainEventQueue_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuCommandMark
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuCommandMark)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jcharArray arg2)
{
	jchar *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuCommandMark_FUNC);
	if (arg2) lparg2 = (*env)->GetCharArrayElements(env, arg2, NULL);
	rc = (jint)GetMenuCommandMark((MenuRef)arg0, (MenuCommand)arg1, (UniChar *)lparg2);
	if (arg2) (*env)->ReleaseCharArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetMenuCommandMark_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuEventTarget
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuEventTarget)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuEventTarget_FUNC);
	rc = (jint)GetMenuEventTarget((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, GetMenuEventTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuFont
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuFont)
	(JNIEnv *env, jclass that, jint arg0, jshortArray arg1, jshortArray arg2)
{
	jshort *lparg1=NULL;
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuFont_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)GetMenuFont((MenuRef)arg0, (SInt16 *)lparg1, (UInt16 *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetMenuFont_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuHeight
JNIEXPORT jshort JNICALL OS_NATIVE(GetMenuHeight)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetMenuHeight_FUNC);
	rc = (jshort)GetMenuHeight((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, GetMenuHeight_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuID
JNIEXPORT jshort JNICALL OS_NATIVE(GetMenuID)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetMenuID_FUNC);
	rc = (jshort)GetMenuID((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, GetMenuID_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuItemCommandID
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuItemCommandID)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuItemCommandID_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetMenuItemCommandID((MenuRef)arg0, (SInt16)arg1, (MenuCommand *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetMenuItemCommandID_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuItemHierarchicalMenu
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuItemHierarchicalMenu)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuItemHierarchicalMenu_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetMenuItemHierarchicalMenu((MenuRef)arg0, (SInt16)arg1, (MenuRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetMenuItemHierarchicalMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuItemRefCon
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuItemRefCon)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuItemRefCon_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetMenuItemRefCon((MenuRef)arg0, (SInt16)arg1, (UInt32 *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetMenuItemRefCon_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuTrackingData
JNIEXPORT jint JNICALL OS_NATIVE(GetMenuTrackingData)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	MenuTrackingData _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetMenuTrackingData_FUNC);
	if (arg1) lparg1 = getMenuTrackingDataFields(env, arg1, &_arg1);
	rc = (jint)GetMenuTrackingData((MenuRef)arg0, lparg1);
	if (arg1) setMenuTrackingDataFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetMenuTrackingData_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMenuWidth
JNIEXPORT jshort JNICALL OS_NATIVE(GetMenuWidth)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetMenuWidth_FUNC);
	rc = (jshort)GetMenuWidth((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, GetMenuWidth_FUNC);
	return rc;
}
#endif

#ifndef NO_GetMouse
JNIEXPORT void JNICALL OS_NATIVE(GetMouse)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Point _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, GetMouse_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	GetMouse((Point *)lparg0);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, GetMouse_FUNC);
}
#endif

#ifndef NO_GetNextDevice
JNIEXPORT jint JNICALL OS_NATIVE(GetNextDevice)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetNextDevice_FUNC);
	rc = (jint)GetNextDevice((GDHandle)arg0);
	OS_NATIVE_EXIT(env, that, GetNextDevice_FUNC);
	return rc;
}
#endif

#ifndef NO_GetPixBounds
JNIEXPORT void JNICALL OS_NATIVE(GetPixBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, GetPixBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	GetPixBounds((PixMapHandle)arg0, (Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetPixBounds_FUNC);
}
#endif

#ifndef NO_GetPixDepth
JNIEXPORT jshort JNICALL OS_NATIVE(GetPixDepth)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, GetPixDepth_FUNC);
	rc = (jshort)GetPixDepth((PixMapHandle)arg0);
	OS_NATIVE_EXIT(env, that, GetPixDepth_FUNC);
	return rc;
}
#endif

#ifndef NO_GetPort
JNIEXPORT void JNICALL OS_NATIVE(GetPort)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, GetPort_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	GetPort((GrafPtr *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, GetPort_FUNC);
}
#endif

#ifndef NO_GetPortBitMapForCopyBits
JNIEXPORT jint JNICALL OS_NATIVE(GetPortBitMapForCopyBits)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetPortBitMapForCopyBits_FUNC);
	rc = (jint)GetPortBitMapForCopyBits((CGrafPtr)arg0);
	OS_NATIVE_EXIT(env, that, GetPortBitMapForCopyBits_FUNC);
	return rc;
}
#endif

#ifndef NO_GetPortBounds
JNIEXPORT void JNICALL OS_NATIVE(GetPortBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, GetPortBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	GetPortBounds((CGrafPtr)arg0, (Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetPortBounds_FUNC);
}
#endif

#ifndef NO_GetPortClipRegion
JNIEXPORT void JNICALL OS_NATIVE(GetPortClipRegion)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, GetPortClipRegion_FUNC);
	GetPortClipRegion((CGrafPtr)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, GetPortClipRegion_FUNC);
}
#endif

#ifndef NO_GetPortVisibleRegion
JNIEXPORT jint JNICALL OS_NATIVE(GetPortVisibleRegion)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetPortVisibleRegion_FUNC);
	rc = (jint)GetPortVisibleRegion((CGrafPtr)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, GetPortVisibleRegion_FUNC);
	return rc;
}
#endif

#ifndef NO_GetPreviousWindow
JNIEXPORT jint JNICALL OS_NATIVE(GetPreviousWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetPreviousWindow_FUNC);
	rc = (jint)GetPreviousWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, GetPreviousWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_GetPtrSize
JNIEXPORT jint JNICALL OS_NATIVE(GetPtrSize)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetPtrSize_FUNC);
	rc = (jint)GetPtrSize((Ptr)arg0);
	OS_NATIVE_EXIT(env, that, GetPtrSize_FUNC);
	return rc;
}
#endif

#ifndef NO_GetRegionBounds
JNIEXPORT void JNICALL OS_NATIVE(GetRegionBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, GetRegionBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	GetRegionBounds((RgnHandle)arg0, (Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetRegionBounds_FUNC);
}
#endif

#ifndef NO_GetRootControl
JNIEXPORT jint JNICALL OS_NATIVE(GetRootControl)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetRootControl_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetRootControl((WindowRef)arg0, (ControlRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetRootControl_FUNC);
	return rc;
}
#endif

#ifndef NO_GetScrapFlavorCount
JNIEXPORT jint JNICALL OS_NATIVE(GetScrapFlavorCount)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetScrapFlavorCount_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetScrapFlavorCount((ScrapRef)arg0, (UInt32 *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetScrapFlavorCount_FUNC);
	return rc;
}
#endif

#ifndef NO_GetScrapFlavorData
JNIEXPORT jint JNICALL OS_NATIVE(GetScrapFlavorData)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jbyteArray arg3)
{
	jint *lparg2=NULL;
	jbyte *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetScrapFlavorData_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	rc = (jint)GetScrapFlavorData((ScrapRef)arg0, (ScrapFlavorType)arg1, (Size *)lparg2, (void *)lparg3);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetScrapFlavorData_FUNC);
	return rc;
}
#endif

#ifndef NO_GetScrapFlavorInfoList
JNIEXPORT jint JNICALL OS_NATIVE(GetScrapFlavorInfoList)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetScrapFlavorInfoList_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetScrapFlavorInfoList((ScrapRef)arg0, (UInt32 *)lparg1, (ScrapFlavorInfo *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetScrapFlavorInfoList_FUNC);
	return rc;
}
#endif

#ifndef NO_GetScrapFlavorSize
JNIEXPORT jint JNICALL OS_NATIVE(GetScrapFlavorSize)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetScrapFlavorSize_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetScrapFlavorSize((ScrapRef)arg0, (ScrapFlavorType)arg1, (Size *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetScrapFlavorSize_FUNC);
	return rc;
}
#endif

#ifndef NO_GetScriptManagerVariable
JNIEXPORT jint JNICALL OS_NATIVE(GetScriptManagerVariable)
	(JNIEnv *env, jclass that, jshort arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetScriptManagerVariable_FUNC);
	rc = (jint)GetScriptManagerVariable(arg0);
	OS_NATIVE_EXIT(env, that, GetScriptManagerVariable_FUNC);
	return rc;
}
#endif

#ifndef NO_GetSuperControl
JNIEXPORT jint JNICALL OS_NATIVE(GetSuperControl)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetSuperControl_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetSuperControl((ControlRef)arg0, (ControlRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetSuperControl_FUNC);
	return rc;
}
#endif

#ifndef NO_GetTabContentRect
JNIEXPORT jint JNICALL OS_NATIVE(GetTabContentRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetTabContentRect_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	rc = (jint)GetTabContentRect((ControlRef)arg0, lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetTabContentRect_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeBrushAsColor
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeBrushAsColor)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jboolean arg2, jobject arg3)
{
	RGBColor _arg3, *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeBrushAsColor_FUNC);
	if (arg3) lparg3 = getRGBColorFields(env, arg3, &_arg3);
	rc = (jint)GetThemeBrushAsColor(arg0, arg1, arg2, lparg3);
	if (arg3) setRGBColorFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, GetThemeBrushAsColor_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeButtonContentBounds
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeButtonContentBounds)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jobject arg2, jobject arg3)
{
	Rect _arg0, *lparg0=NULL;
	ThemeButtonDrawInfo _arg2, *lparg2=NULL;
	Rect _arg3, *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeButtonContentBounds_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	if (arg2) lparg2 = getThemeButtonDrawInfoFields(env, arg2, &_arg2);
	if (arg3) lparg3 = getRectFields(env, arg3, &_arg3);
	rc = (jint)GetThemeButtonContentBounds(lparg0, arg1, lparg2, lparg3);
	if (arg3) setRectFields(env, arg3, lparg3);
	if (arg2) setThemeButtonDrawInfoFields(env, arg2, lparg2);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, GetThemeButtonContentBounds_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeDrawingState
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeDrawingState)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeDrawingState_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)GetThemeDrawingState((ThemeDrawingState *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, GetThemeDrawingState_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeFont
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeFont)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jbyteArray arg2, jshortArray arg3, jbyteArray arg4)
{
	jbyte *lparg2=NULL;
	jshort *lparg3=NULL;
	jbyte *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeFont_FUNC);
	if (arg2) lparg2 = (*env)->GetByteArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetShortArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	rc = (jint)GetThemeFont((ThemeFontID)arg0, (ScriptCode)arg1, (char *)lparg2, (SInt16 *)lparg3, (Style *)lparg4);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseShortArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseByteArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, GetThemeFont_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeMenuItemExtra
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeMenuItemExtra)
	(JNIEnv *env, jclass that, jshort arg0, jshortArray arg1, jshortArray arg2)
{
	jshort *lparg1=NULL;
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeMenuItemExtra_FUNC);
	if (arg1) lparg1 = (*env)->GetShortArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)GetThemeMenuItemExtra(arg0, lparg1, lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseShortArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetThemeMenuItemExtra_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeMetric
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeMetric)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeMetric_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetThemeMetric(arg0, lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetThemeMetric_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeTextColor
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeTextColor)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jboolean arg2, jobject arg3)
{
	RGBColor _arg3, *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeTextColor_FUNC);
	if (arg3) lparg3 = getRGBColorFields(env, arg3, &_arg3);
	rc = (jint)GetThemeTextColor(arg0, arg1, arg2, lparg3);
	if (arg3) setRGBColorFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, GetThemeTextColor_FUNC);
	return rc;
}
#endif

#ifndef NO_GetThemeTextDimensions
JNIEXPORT jint JNICALL OS_NATIVE(GetThemeTextDimensions)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jboolean arg3, jobject arg4, jshortArray arg5)
{
	Point _arg4, *lparg4=NULL;
	jshort *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetThemeTextDimensions_FUNC);
	if (arg4) lparg4 = getPointFields(env, arg4, &_arg4);
	if (arg5) lparg5 = (*env)->GetShortArrayElements(env, arg5, NULL);
	rc = (jint)GetThemeTextDimensions((CFStringRef)arg0, (ThemeFontID)arg1, (ThemeDrawState)arg2, (Boolean)arg3, (Point *)lparg4, (SInt16 *)lparg5);
	if (arg5) (*env)->ReleaseShortArrayElements(env, arg5, lparg5, 0);
	if (arg4) setPointFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, GetThemeTextDimensions_FUNC);
	return rc;
}
#endif

#ifndef NO_GetUserFocusEventTarget
JNIEXPORT jint JNICALL OS_NATIVE(GetUserFocusEventTarget)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetUserFocusEventTarget_FUNC);
	rc = (jint)GetUserFocusEventTarget();
	OS_NATIVE_EXIT(env, that, GetUserFocusEventTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_GetUserFocusWindow
JNIEXPORT jint JNICALL OS_NATIVE(GetUserFocusWindow)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetUserFocusWindow_FUNC);
	rc = (jint)GetUserFocusWindow();
	OS_NATIVE_EXIT(env, that, GetUserFocusWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWRefCon
JNIEXPORT jint JNICALL OS_NATIVE(GetWRefCon)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWRefCon_FUNC);
	rc = (jint)GetWRefCon((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, GetWRefCon_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowActivationScope
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowActivationScope)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowActivationScope_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetWindowActivationScope((WindowRef)arg0, (WindowActivationScope *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetWindowActivationScope_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowBounds
JNIEXPORT void JNICALL OS_NATIVE(GetWindowBounds)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jobject arg2)
{
	Rect _arg2, *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, GetWindowBounds_FUNC);
	if (arg2) lparg2 = getRectFields(env, arg2, &_arg2);
	GetWindowBounds((WindowRef)arg0, (WindowRegionCode)arg1, (Rect *)lparg2);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, GetWindowBounds_FUNC);
}
#endif

#ifndef NO_GetWindowDefaultButton
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowDefaultButton)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowDefaultButton_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)GetWindowDefaultButton((WindowRef)arg0, (ControlRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetWindowDefaultButton_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowEventTarget
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowEventTarget)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowEventTarget_FUNC);
	rc = (jint)GetWindowEventTarget((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, GetWindowEventTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowFromPort
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowFromPort)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowFromPort_FUNC);
	rc = (jint)GetWindowFromPort((CGrafPtr)arg0);
	OS_NATIVE_EXIT(env, that, GetWindowFromPort_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowGroupOfClass
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowGroupOfClass)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowGroupOfClass_FUNC);
	rc = (jint)GetWindowGroupOfClass(arg0);
	OS_NATIVE_EXIT(env, that, GetWindowGroupOfClass_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowModality
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowModality)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowModality_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)GetWindowModality((WindowRef)arg0, (WindowModality *)lparg1, (WindowRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, GetWindowModality_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowPort
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowPort)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowPort_FUNC);
	rc = (jint)GetWindowPort((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, GetWindowPort_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowRegion
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowRegion)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowRegion_FUNC);
	rc = (jint)GetWindowRegion((WindowRef)arg0, (WindowRegionCode)arg1, (RgnHandle)arg2);
	OS_NATIVE_EXIT(env, that, GetWindowRegion_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowResizeLimits
JNIEXPORT jint JNICALL OS_NATIVE(GetWindowResizeLimits)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2)
{
	CGPoint _arg1, *lparg1=NULL;
	CGPoint _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, GetWindowResizeLimits_FUNC);
	if (arg1) lparg1 = getCGPointFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getCGPointFields(env, arg2, &_arg2);
	rc = (jint)GetWindowResizeLimits((WindowRef)arg0, (HISize *)lparg1, (HISize *)lparg2);
	if (arg2) setCGPointFields(env, arg2, lparg2);
	if (arg1) setCGPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetWindowResizeLimits_FUNC);
	return rc;
}
#endif

#ifndef NO_GetWindowStructureWidths
JNIEXPORT void JNICALL OS_NATIVE(GetWindowStructureWidths)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, GetWindowStructureWidths_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	GetWindowStructureWidths((WindowRef)arg0, (Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, GetWindowStructureWidths_FUNC);
}
#endif

#ifndef NO_HIComboBoxAppendTextItem
JNIEXPORT jint JNICALL OS_NATIVE(HIComboBoxAppendTextItem)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIComboBoxAppendTextItem_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)HIComboBoxAppendTextItem((HIViewRef)arg0, (CFStringRef)arg1, (CFIndex *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, HIComboBoxAppendTextItem_FUNC);
	return rc;
}
#endif

#ifndef NO_HIComboBoxCopyTextItemAtIndex
JNIEXPORT jint JNICALL OS_NATIVE(HIComboBoxCopyTextItemAtIndex)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIComboBoxCopyTextItemAtIndex_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)HIComboBoxCopyTextItemAtIndex((HIViewRef)arg0, (CFIndex)arg1, (CFStringRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, HIComboBoxCopyTextItemAtIndex_FUNC);
	return rc;
}
#endif

#ifndef NO_HIComboBoxCreate
JNIEXPORT jint JNICALL OS_NATIVE(HIComboBoxCreate)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jobject arg2, jint arg3, jint arg4, jintArray arg5)
{
	CGRect _arg0, *lparg0=NULL;
	ControlFontStyleRec _arg2, *lparg2=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIComboBoxCreate_FUNC);
	if (arg0) lparg0 = getCGRectFields(env, arg0, &_arg0);
	if (arg2) lparg2 = getControlFontStyleRecFields(env, arg2, &_arg2);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)HIComboBoxCreate((const HIRect *)lparg0, (CFStringRef)arg1, (const ControlFontStyleRec *)lparg2, (CFArrayRef)arg3, (OptionBits)arg4, (HIViewRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg2) setControlFontStyleRecFields(env, arg2, lparg2);
	if (arg0) setCGRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, HIComboBoxCreate_FUNC);
	return rc;
}
#endif

#ifndef NO_HIComboBoxGetItemCount
JNIEXPORT jint JNICALL OS_NATIVE(HIComboBoxGetItemCount)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIComboBoxGetItemCount_FUNC);
	rc = (jint)HIComboBoxGetItemCount((HIViewRef)arg0);
	OS_NATIVE_EXIT(env, that, HIComboBoxGetItemCount_FUNC);
	return rc;
}
#endif

#ifndef NO_HIComboBoxInsertTextItemAtIndex
JNIEXPORT jint JNICALL OS_NATIVE(HIComboBoxInsertTextItemAtIndex)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIComboBoxInsertTextItemAtIndex_FUNC);
	rc = (jint)HIComboBoxInsertTextItemAtIndex((HIViewRef)arg0, (CFIndex)arg1, (CFStringRef)arg2);
	OS_NATIVE_EXIT(env, that, HIComboBoxInsertTextItemAtIndex_FUNC);
	return rc;
}
#endif

#ifndef NO_HIComboBoxRemoveItemAtIndex
JNIEXPORT jint JNICALL OS_NATIVE(HIComboBoxRemoveItemAtIndex)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIComboBoxRemoveItemAtIndex_FUNC);
	rc = (jint)HIComboBoxRemoveItemAtIndex((HIViewRef)arg0, (CFIndex)arg1);
	OS_NATIVE_EXIT(env, that, HIComboBoxRemoveItemAtIndex_FUNC);
	return rc;
}
#endif

#ifndef NO_HIObjectCopyClassID
JNIEXPORT jint JNICALL OS_NATIVE(HIObjectCopyClassID)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIObjectCopyClassID_FUNC);
	rc = (jint)HIObjectCopyClassID((HIObjectRef)arg0);
	OS_NATIVE_EXIT(env, that, HIObjectCopyClassID_FUNC);
	return rc;
}
#endif

#ifndef NO_HIObjectCreate
JNIEXPORT jint JNICALL OS_NATIVE(HIObjectCreate)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIObjectCreate_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)HIObjectCreate((CFStringRef)arg0, (EventRef)arg1, (HIObjectRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, HIObjectCreate_FUNC);
	return rc;
}
#endif

#ifndef NO_HIObjectRegisterSubclass
JNIEXPORT jint JNICALL OS_NATIVE(HIObjectRegisterSubclass)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jintArray arg5, jint arg6, jintArray arg7)
{
	jint *lparg5=NULL;
	jint *lparg7=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIObjectRegisterSubclass_FUNC);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	if (arg7) lparg7 = (*env)->GetIntArrayElements(env, arg7, NULL);
	rc = (jint)HIObjectRegisterSubclass((CFStringRef)arg0, (CFStringRef)arg1, (OptionBits)arg2, (EventHandlerUPP)arg3, (UInt32)arg4, (const EventTypeSpec *)lparg5, (void *)arg6, (HIObjectClassRef *)lparg7);
	if (arg7) (*env)->ReleaseIntArrayElements(env, arg7, lparg7, 0);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	OS_NATIVE_EXIT(env, that, HIObjectRegisterSubclass_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewAddSubview
JNIEXPORT jint JNICALL OS_NATIVE(HIViewAddSubview)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewAddSubview_FUNC);
	rc = (jint)HIViewAddSubview((HIViewRef)arg0, (HIViewRef)arg1);
	OS_NATIVE_EXIT(env, that, HIViewAddSubview_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewClick
JNIEXPORT jint JNICALL OS_NATIVE(HIViewClick)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewClick_FUNC);
	rc = (jint)HIViewClick((HIViewRef)arg0, (EventRef)arg1);
	OS_NATIVE_EXIT(env, that, HIViewClick_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewConvertPoint
JNIEXPORT jint JNICALL OS_NATIVE(HIViewConvertPoint)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	CGPoint _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewConvertPoint_FUNC);
	if (arg0) lparg0 = getCGPointFields(env, arg0, &_arg0);
	rc = (jint)HIViewConvertPoint((HIPoint *)lparg0, (HIViewRef)arg1, (HIViewRef)arg2);
	if (arg0) setCGPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, HIViewConvertPoint_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewCreateOffscreenImage
JNIEXPORT jint JNICALL OS_NATIVE(HIViewCreateOffscreenImage)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jintArray arg3)
{
	CGRect _arg2, *lparg2=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewCreateOffscreenImage_FUNC);
	if (arg2) lparg2 = getCGRectFields(env, arg2, &_arg2);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)HIViewCreateOffscreenImage((HIViewRef)arg0, (OptionBits)arg1, (HIRect *)lparg2, (CGImageRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) setCGRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, HIViewCreateOffscreenImage_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewFindByID
JNIEXPORT jint JNICALL OS_NATIVE(HIViewFindByID)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewFindByID_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)HIViewFindByID((HIViewRef)arg0, *(HIViewID *)arg1, (HIViewRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, HIViewFindByID_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetFirstSubview
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetFirstSubview)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetFirstSubview_FUNC);
	rc = (jint)HIViewGetFirstSubview((HIViewRef)arg0);
	OS_NATIVE_EXIT(env, that, HIViewGetFirstSubview_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetFrame
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetFrame)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	CGRect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetFrame_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	rc = (jint)HIViewGetFrame((HIViewRef)arg0, (HIRect *)lparg1);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, HIViewGetFrame_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetLastSubview
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetLastSubview)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetLastSubview_FUNC);
	rc = (jint)HIViewGetLastSubview((HIViewRef)arg0);
	OS_NATIVE_EXIT(env, that, HIViewGetLastSubview_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetNextView
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetNextView)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetNextView_FUNC);
	rc = (jint)HIViewGetNextView((HIViewRef)arg0);
	OS_NATIVE_EXIT(env, that, HIViewGetNextView_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetRoot
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetRoot)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetRoot_FUNC);
	rc = (jint)HIViewGetRoot((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, HIViewGetRoot_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetSizeConstraints
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetSizeConstraints)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2)
{
	CGRect _arg1, *lparg1=NULL;
	CGRect _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetSizeConstraints_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getCGRectFields(env, arg2, &_arg2);
	rc = (jint)HIViewGetSizeConstraints((HIViewRef)arg0, (HISize *)lparg1, (HISize *)lparg2);
	if (arg2) setCGRectFields(env, arg2, lparg2);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, HIViewGetSizeConstraints_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetSubviewHit
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetSubviewHit)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jboolean arg2, jintArray arg3)
{
	CGPoint _arg1, *lparg1=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetSubviewHit_FUNC);
	if (arg1) lparg1 = getCGPointFields(env, arg1, &_arg1);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)HIViewGetSubviewHit((HIViewRef)arg0, (CGPoint *)lparg1, (Boolean)arg2, (HIViewRef *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg1) setCGPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, HIViewGetSubviewHit_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewGetViewForMouseEvent
JNIEXPORT jint JNICALL OS_NATIVE(HIViewGetViewForMouseEvent)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewGetViewForMouseEvent_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)HIViewGetViewForMouseEvent((HIViewRef)arg0, (EventRef)arg1, (HIViewRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, HIViewGetViewForMouseEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewIsVisible
JNIEXPORT jboolean JNICALL OS_NATIVE(HIViewIsVisible)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, HIViewIsVisible_FUNC);
	rc = (jboolean)HIViewIsVisible((HIViewRef)arg0);
	OS_NATIVE_EXIT(env, that, HIViewIsVisible_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewRemoveFromSuperview
JNIEXPORT jint JNICALL OS_NATIVE(HIViewRemoveFromSuperview)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewRemoveFromSuperview_FUNC);
	rc = (jint)HIViewRemoveFromSuperview((HIViewRef)arg0);
	OS_NATIVE_EXIT(env, that, HIViewRemoveFromSuperview_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetBoundsOrigin
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetBoundsOrigin)
	(JNIEnv *env, jclass that, jint arg0, jfloat arg1, jfloat arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetBoundsOrigin_FUNC);
	rc = (jint)HIViewSetBoundsOrigin((HIViewRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, HIViewSetBoundsOrigin_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetDrawingEnabled
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetDrawingEnabled)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetDrawingEnabled_FUNC);
	rc = (jint)HIViewSetDrawingEnabled((HIViewRef)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, HIViewSetDrawingEnabled_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetFrame
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetFrame)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	CGRect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetFrame_FUNC);
	if (arg1) lparg1 = getCGRectFields(env, arg1, &_arg1);
	rc = (jint)HIViewSetFrame((HIViewRef)arg0, (const HIRect *)lparg1);
	if (arg1) setCGRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, HIViewSetFrame_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetNeedsDisplay
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetNeedsDisplay)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetNeedsDisplay_FUNC);
	rc = (jint)HIViewSetNeedsDisplay((HIViewRef)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, HIViewSetNeedsDisplay_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetNeedsDisplayInRegion
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetNeedsDisplayInRegion)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetNeedsDisplayInRegion_FUNC);
	rc = (jint)HIViewSetNeedsDisplayInRegion((HIViewRef)arg0, (RgnHandle)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, HIViewSetNeedsDisplayInRegion_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetVisible
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetVisible)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetVisible_FUNC);
	rc = (jint)HIViewSetVisible((HIViewRef)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, HIViewSetVisible_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSetZOrder
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSetZOrder)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSetZOrder_FUNC);
	rc = (jint)HIViewSetZOrder((HIViewRef)arg0, (HIViewZOrderOp)arg1, (HIViewRef)arg2);
	OS_NATIVE_EXIT(env, that, HIViewSetZOrder_FUNC);
	return rc;
}
#endif

#ifndef NO_HIViewSimulateClick
JNIEXPORT jint JNICALL OS_NATIVE(HIViewSimulateClick)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2, jshortArray arg3)
{
	jshort *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HIViewSimulateClick_FUNC);
	if (arg3) lparg3 = (*env)->GetShortArrayElements(env, arg3, NULL);
	rc = (jint)HIViewSimulateClick((HIViewRef)arg0, (HIViewPartCode)arg1, (UInt32)arg2, (ControlPartCode *)lparg3);
	if (arg3) (*env)->ReleaseShortArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, HIViewSimulateClick_FUNC);
	return rc;
}
#endif

#ifndef NO_HLock
JNIEXPORT void JNICALL OS_NATIVE(HLock)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, HLock_FUNC);
	HLock((Handle)arg0);
	OS_NATIVE_EXIT(env, that, HLock_FUNC);
}
#endif

#ifndef NO_HMGetTagDelay
JNIEXPORT jint JNICALL OS_NATIVE(HMGetTagDelay)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HMGetTagDelay_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)HMGetTagDelay(lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, HMGetTagDelay_FUNC);
	return rc;
}
#endif

#ifndef NO_HMHideTag
JNIEXPORT jint JNICALL OS_NATIVE(HMHideTag)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HMHideTag_FUNC);
	rc = (jint)HMHideTag();
	OS_NATIVE_EXIT(env, that, HMHideTag_FUNC);
	return rc;
}
#endif

#ifndef NO_HMInstallControlContentCallback
JNIEXPORT void JNICALL OS_NATIVE(HMInstallControlContentCallback)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, HMInstallControlContentCallback_FUNC);
	HMInstallControlContentCallback((ControlRef)arg0, (HMControlContentUPP)arg1);
	OS_NATIVE_EXIT(env, that, HMInstallControlContentCallback_FUNC);
}
#endif

#ifndef NO_HMSetTagDelay
JNIEXPORT jint JNICALL OS_NATIVE(HMSetTagDelay)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, HMSetTagDelay_FUNC);
	rc = (jint)HMSetTagDelay(arg0);
	OS_NATIVE_EXIT(env, that, HMSetTagDelay_FUNC);
	return rc;
}
#endif

#ifndef NO_HUnlock
JNIEXPORT void JNICALL OS_NATIVE(HUnlock)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, HUnlock_FUNC);
	HUnlock((Handle)arg0);
	OS_NATIVE_EXIT(env, that, HUnlock_FUNC);
}
#endif

#ifndef NO_HandleControlClick
JNIEXPORT jshort JNICALL OS_NATIVE(HandleControlClick)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jint arg3)
{
	Point _arg1, *lparg1=NULL;
	jshort rc;
	OS_NATIVE_ENTER(env, that, HandleControlClick_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	rc = (jshort)HandleControlClick((ControlRef)arg0, *lparg1, (EventModifiers)arg2, (ControlActionUPP)arg3);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, HandleControlClick_FUNC);
	return rc;
}
#endif

#ifndef NO_HandleControlSetCursor
JNIEXPORT jint JNICALL OS_NATIVE(HandleControlSetCursor)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2, jbooleanArray arg3)
{
	Point _arg1, *lparg1=NULL;
	jboolean *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, HandleControlSetCursor_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	if (arg3) lparg3 = (*env)->GetBooleanArrayElements(env, arg3, NULL);
	rc = (jint)HandleControlSetCursor((ControlRef)arg0, *lparg1, (EventModifiers)arg2, (Boolean *)lparg3);
	if (arg3) (*env)->ReleaseBooleanArrayElements(env, arg3, lparg3, 0);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, HandleControlSetCursor_FUNC);
	return rc;
}
#endif

#ifndef NO_HiWord
JNIEXPORT jshort JNICALL OS_NATIVE(HiWord)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, HiWord_FUNC);
	rc = (jshort)HiWord(arg0);
	OS_NATIVE_EXIT(env, that, HiWord_FUNC);
	return rc;
}
#endif

#ifndef NO_HideWindow
JNIEXPORT void JNICALL OS_NATIVE(HideWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, HideWindow_FUNC);
	HideWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, HideWindow_FUNC);
}
#endif

#ifndef NO_HiliteMenu
JNIEXPORT void JNICALL OS_NATIVE(HiliteMenu)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, HiliteMenu_FUNC);
	HiliteMenu((MenuID)arg0);
	OS_NATIVE_EXIT(env, that, HiliteMenu_FUNC);
}
#endif

#ifndef NO_IconRefToIconFamily
JNIEXPORT jint JNICALL OS_NATIVE(IconRefToIconFamily)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, IconRefToIconFamily_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)IconRefToIconFamily((IconRef)arg0, (IconSelectorValue)arg1, (IconFamilyHandle *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, IconRefToIconFamily_FUNC);
	return rc;
}
#endif

#ifndef NO_InitContextualMenus
JNIEXPORT jint JNICALL OS_NATIVE(InitContextualMenus)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, InitContextualMenus_FUNC);
	rc = (jint)InitContextualMenus();
	OS_NATIVE_EXIT(env, that, InitContextualMenus_FUNC);
	return rc;
}
#endif

#ifndef NO_InitCursor
JNIEXPORT void JNICALL OS_NATIVE(InitCursor)
	(JNIEnv *env, jclass that)
{
	OS_NATIVE_ENTER(env, that, InitCursor_FUNC);
	InitCursor();
	OS_NATIVE_EXIT(env, that, InitCursor_FUNC);
}
#endif

#ifndef NO_InitDataBrowserCallbacks
JNIEXPORT jint JNICALL OS_NATIVE(InitDataBrowserCallbacks)
	(JNIEnv *env, jclass that, jobject arg0)
{
	DataBrowserCallbacks _arg0={0}, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, InitDataBrowserCallbacks_FUNC);
	if (arg0) lparg0 = getDataBrowserCallbacksFields(env, arg0, &_arg0);
	rc = (jint)InitDataBrowserCallbacks((DataBrowserCallbacks *)lparg0);
	if (arg0) setDataBrowserCallbacksFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, InitDataBrowserCallbacks_FUNC);
	return rc;
}
#endif

#ifndef NO_InitDataBrowserCustomCallbacks
JNIEXPORT jint JNICALL OS_NATIVE(InitDataBrowserCustomCallbacks)
	(JNIEnv *env, jclass that, jobject arg0)
{
	DataBrowserCustomCallbacks _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, InitDataBrowserCustomCallbacks_FUNC);
	if (arg0) lparg0 = getDataBrowserCustomCallbacksFields(env, arg0, &_arg0);
	rc = (jint)InitDataBrowserCustomCallbacks(lparg0);
	if (arg0) setDataBrowserCustomCallbacksFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, InitDataBrowserCustomCallbacks_FUNC);
	return rc;
}
#endif

#ifndef NO_InsertMenu
JNIEXPORT void JNICALL OS_NATIVE(InsertMenu)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, InsertMenu_FUNC);
	InsertMenu((MenuRef)arg0, (MenuID)arg1);
	OS_NATIVE_EXIT(env, that, InsertMenu_FUNC);
}
#endif

#ifndef NO_InsertMenuItemTextWithCFString
JNIEXPORT jint JNICALL OS_NATIVE(InsertMenuItemTextWithCFString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshort arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, InsertMenuItemTextWithCFString_FUNC);
	rc = (jint)InsertMenuItemTextWithCFString((MenuRef)arg0, (CFStringRef)arg1, (MenuItemIndex)arg2, (MenuItemAttributes)arg3, (MenuCommand)arg4);
	OS_NATIVE_EXIT(env, that, InsertMenuItemTextWithCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_InstallEventHandler
JNIEXPORT jint JNICALL OS_NATIVE(InstallEventHandler)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jintArray arg5)
{
	jint *lparg3=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, InstallEventHandler_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)InstallEventHandler((EventTargetRef)arg0, (EventHandlerUPP)arg1, (UInt32)arg2, (const EventTypeSpec *)lparg3, (void *)arg4, (EventHandlerRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, InstallEventHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_InstallEventLoopTimer
JNIEXPORT jint JNICALL OS_NATIVE(InstallEventLoopTimer)
	(JNIEnv *env, jclass that, jint arg0, jdouble arg1, jdouble arg2, jint arg3, jint arg4, jintArray arg5)
{
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, InstallEventLoopTimer_FUNC);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)InstallEventLoopTimer((EventLoopRef)arg0, (EventTimerInterval)arg1, (EventTimerInterval)arg2, (EventLoopTimerUPP)arg3, (void *)arg4, (EventLoopTimerRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	OS_NATIVE_EXIT(env, that, InstallEventLoopTimer_FUNC);
	return rc;
}
#endif

#ifndef NO_InstallReceiveHandler
JNIEXPORT jint JNICALL OS_NATIVE(InstallReceiveHandler)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, InstallReceiveHandler_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)InstallReceiveHandler((DragReceiveHandlerUPP)arg0, (WindowRef)arg1, (void *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, InstallReceiveHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_InstallTrackingHandler
JNIEXPORT jint JNICALL OS_NATIVE(InstallTrackingHandler)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, InstallTrackingHandler_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)InstallTrackingHandler((DragTrackingHandlerUPP)arg0, (WindowRef)arg1, (void *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, InstallTrackingHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_InvalWindowRect
JNIEXPORT void JNICALL OS_NATIVE(InvalWindowRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, InvalWindowRect_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	InvalWindowRect((WindowRef)arg0, (const Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, InvalWindowRect_FUNC);
}
#endif

#ifndef NO_InvalWindowRgn
JNIEXPORT void JNICALL OS_NATIVE(InvalWindowRgn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, InvalWindowRgn_FUNC);
	InvalWindowRgn((WindowRef)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, InvalWindowRgn_FUNC);
}
#endif

#ifndef NO_InvertRect
JNIEXPORT void JNICALL OS_NATIVE(InvertRect)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, InvertRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	InvertRect((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, InvertRect_FUNC);
}
#endif

#ifndef NO_InvertRgn
JNIEXPORT void JNICALL OS_NATIVE(InvertRgn)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, InvertRgn_FUNC);
	InvertRgn((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, InvertRgn_FUNC);
}
#endif

#ifndef NO_IsControlActive
JNIEXPORT jboolean JNICALL OS_NATIVE(IsControlActive)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsControlActive_FUNC);
	rc = (jboolean)IsControlActive((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, IsControlActive_FUNC);
	return rc;
}
#endif

#ifndef NO_IsControlEnabled
JNIEXPORT jboolean JNICALL OS_NATIVE(IsControlEnabled)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsControlEnabled_FUNC);
	rc = (jboolean)IsControlEnabled((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, IsControlEnabled_FUNC);
	return rc;
}
#endif

#ifndef NO_IsControlVisible
JNIEXPORT jboolean JNICALL OS_NATIVE(IsControlVisible)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsControlVisible_FUNC);
	rc = (jboolean)IsControlVisible((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, IsControlVisible_FUNC);
	return rc;
}
#endif

#ifndef NO_IsDataBrowserItemSelected
JNIEXPORT jboolean JNICALL OS_NATIVE(IsDataBrowserItemSelected)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsDataBrowserItemSelected_FUNC);
	rc = (jboolean)IsDataBrowserItemSelected((ControlRef)arg0, (DataBrowserItemID)arg1);
	OS_NATIVE_EXIT(env, that, IsDataBrowserItemSelected_FUNC);
	return rc;
}
#endif

#ifndef NO_IsMenuCommandEnabled
JNIEXPORT jboolean JNICALL OS_NATIVE(IsMenuCommandEnabled)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsMenuCommandEnabled_FUNC);
	rc = (jboolean)IsMenuCommandEnabled((MenuRef)arg0, (MenuCommand)arg1);
	OS_NATIVE_EXIT(env, that, IsMenuCommandEnabled_FUNC);
	return rc;
}
#endif

#ifndef NO_IsMenuItemEnabled
JNIEXPORT jboolean JNICALL OS_NATIVE(IsMenuItemEnabled)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsMenuItemEnabled_FUNC);
	rc = (jboolean)IsMenuItemEnabled((MenuRef)arg0, (MenuItemIndex)arg1);
	OS_NATIVE_EXIT(env, that, IsMenuItemEnabled_FUNC);
	return rc;
}
#endif

#ifndef NO_IsValidControlHandle
JNIEXPORT jboolean JNICALL OS_NATIVE(IsValidControlHandle)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsValidControlHandle_FUNC);
	rc = (jboolean)IsValidControlHandle((ControlRef)arg0);
	OS_NATIVE_EXIT(env, that, IsValidControlHandle_FUNC);
	return rc;
}
#endif

#ifndef NO_IsValidMenu
JNIEXPORT jboolean JNICALL OS_NATIVE(IsValidMenu)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsValidMenu_FUNC);
	rc = (jboolean)IsValidMenu((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, IsValidMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_IsValidWindowPtr
JNIEXPORT jboolean JNICALL OS_NATIVE(IsValidWindowPtr)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsValidWindowPtr_FUNC);
	rc = (jboolean)IsValidWindowPtr((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, IsValidWindowPtr_FUNC);
	return rc;
}
#endif

#ifndef NO_IsWindowActive
JNIEXPORT jboolean JNICALL OS_NATIVE(IsWindowActive)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsWindowActive_FUNC);
	rc = (jboolean)IsWindowActive((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, IsWindowActive_FUNC);
	return rc;
}
#endif

#ifndef NO_IsWindowCollapsed
JNIEXPORT jboolean JNICALL OS_NATIVE(IsWindowCollapsed)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsWindowCollapsed_FUNC);
	rc = (jboolean)IsWindowCollapsed((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, IsWindowCollapsed_FUNC);
	return rc;
}
#endif

#ifndef NO_IsWindowVisible
JNIEXPORT jboolean JNICALL OS_NATIVE(IsWindowVisible)
	(JNIEnv *env, jclass that, jint arg0)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, IsWindowVisible_FUNC);
	rc = (jboolean)IsWindowVisible((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, IsWindowVisible_FUNC);
	return rc;
}
#endif

#ifndef NO_KeyTranslate
JNIEXPORT jint JNICALL OS_NATIVE(KeyTranslate)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, KeyTranslate_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)KeyTranslate((const void *)arg0, arg1, (UInt32 *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, KeyTranslate_FUNC);
	return rc;
}
#endif

#ifndef NO_KillPoly
JNIEXPORT void JNICALL OS_NATIVE(KillPoly)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, KillPoly_FUNC);
	KillPoly((PolyHandle)arg0);
	OS_NATIVE_EXIT(env, that, KillPoly_FUNC);
}
#endif

#ifndef NO_LineTo
JNIEXPORT void JNICALL OS_NATIVE(LineTo)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, LineTo_FUNC);
	LineTo((short)arg0, (short)arg1);
	OS_NATIVE_EXIT(env, that, LineTo_FUNC);
}
#endif

#ifndef NO_LoWord
JNIEXPORT jshort JNICALL OS_NATIVE(LoWord)
	(JNIEnv *env, jclass that, jint arg0)
{
	jshort rc;
	OS_NATIVE_ENTER(env, that, LoWord_FUNC);
	rc = (jshort)LoWord(arg0);
	OS_NATIVE_EXIT(env, that, LoWord_FUNC);
	return rc;
}
#endif

#ifndef NO_LockPortBits
JNIEXPORT jint JNICALL OS_NATIVE(LockPortBits)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, LockPortBits_FUNC);
	rc = (jint)LockPortBits((GrafPtr)arg0);
	OS_NATIVE_EXIT(env, that, LockPortBits_FUNC);
	return rc;
}
#endif

#ifndef NO_Long2Fix
JNIEXPORT jint JNICALL OS_NATIVE(Long2Fix)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, Long2Fix_FUNC);
	rc = (jint)Long2Fix(arg0);
	OS_NATIVE_EXIT(env, that, Long2Fix_FUNC);
	return rc;
}
#endif

#ifndef NO_MenuSelect
JNIEXPORT jint JNICALL OS_NATIVE(MenuSelect)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Point _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, MenuSelect_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	rc = (jint)MenuSelect(*(Point *)lparg0);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, MenuSelect_FUNC);
	return rc;
}
#endif

#ifndef NO_MoveControl
JNIEXPORT void JNICALL OS_NATIVE(MoveControl)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2)
{
	OS_NATIVE_ENTER(env, that, MoveControl_FUNC);
	MoveControl((ControlRef)arg0, (SInt16)arg1, (SInt16)arg2);
	OS_NATIVE_EXIT(env, that, MoveControl_FUNC);
}
#endif

#ifndef NO_MoveTo
JNIEXPORT void JNICALL OS_NATIVE(MoveTo)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, MoveTo_FUNC);
	MoveTo((short)arg0, (short)arg1);
	OS_NATIVE_EXIT(env, that, MoveTo_FUNC);
}
#endif

#ifndef NO_MoveWindow
JNIEXPORT void JNICALL OS_NATIVE(MoveWindow)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2, jboolean arg3)
{
	OS_NATIVE_ENTER(env, that, MoveWindow_FUNC);
	MoveWindow((WindowRef)arg0, (short)arg1, (short)arg2, (Boolean)arg3);
	OS_NATIVE_EXIT(env, that, MoveWindow_FUNC);
}
#endif

#ifndef NO_NavCreateChooseFolderDialog
JNIEXPORT jint JNICALL OS_NATIVE(NavCreateChooseFolderDialog)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2, jint arg3, jintArray arg4)
{
	NavDialogCreationOptions _arg0, *lparg0=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NavCreateChooseFolderDialog_FUNC);
	if (arg0) lparg0 = getNavDialogCreationOptionsFields(env, arg0, &_arg0);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)NavCreateChooseFolderDialog((const NavDialogCreationOptions *)lparg0, (NavEventUPP)arg1, (NavObjectFilterUPP)arg2, (void *)arg3, (NavDialogRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg0) setNavDialogCreationOptionsFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, NavCreateChooseFolderDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_NavCreateGetFileDialog
JNIEXPORT jint JNICALL OS_NATIVE(NavCreateGetFileDialog)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5, jintArray arg6)
{
	NavDialogCreationOptions _arg0, *lparg0=NULL;
	jint *lparg6=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NavCreateGetFileDialog_FUNC);
	if (arg0) lparg0 = getNavDialogCreationOptionsFields(env, arg0, &_arg0);
	if (arg6) lparg6 = (*env)->GetIntArrayElements(env, arg6, NULL);
	rc = (jint)NavCreateGetFileDialog((const NavDialogCreationOptions *)lparg0, (NavTypeListHandle)arg1, (NavEventUPP)arg2, (NavPreviewUPP)arg3, (NavObjectFilterUPP)arg4, (void *)arg5, (NavDialogRef *)lparg6);
	if (arg6) (*env)->ReleaseIntArrayElements(env, arg6, lparg6, 0);
	if (arg0) setNavDialogCreationOptionsFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, NavCreateGetFileDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_NavCreatePutFileDialog
JNIEXPORT jint JNICALL OS_NATIVE(NavCreatePutFileDialog)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2, jint arg3, jint arg4, jintArray arg5)
{
	NavDialogCreationOptions _arg0, *lparg0=NULL;
	jint *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NavCreatePutFileDialog_FUNC);
	if (arg0) lparg0 = getNavDialogCreationOptionsFields(env, arg0, &_arg0);
	if (arg5) lparg5 = (*env)->GetIntArrayElements(env, arg5, NULL);
	rc = (jint)NavCreatePutFileDialog((const NavDialogCreationOptions *)lparg0, (OSType)arg1, (OSType)arg2, (NavEventUPP)arg3, (void *)arg4, (NavDialogRef *)lparg5);
	if (arg5) (*env)->ReleaseIntArrayElements(env, arg5, lparg5, 0);
	if (arg0) setNavDialogCreationOptionsFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, NavCreatePutFileDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_NavDialogDispose
JNIEXPORT void JNICALL OS_NATIVE(NavDialogDispose)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, NavDialogDispose_FUNC);
	NavDialogDispose((NavDialogRef)arg0);
	OS_NATIVE_EXIT(env, that, NavDialogDispose_FUNC);
}
#endif

#ifndef NO_NavDialogGetReply
JNIEXPORT jint JNICALL OS_NATIVE(NavDialogGetReply)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	NavReplyRecord _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NavDialogGetReply_FUNC);
	if (arg1) lparg1 = getNavReplyRecordFields(env, arg1, &_arg1);
	rc = (jint)NavDialogGetReply((NavDialogRef)arg0, (NavReplyRecord *)lparg1);
	if (arg1) setNavReplyRecordFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, NavDialogGetReply_FUNC);
	return rc;
}
#endif

#ifndef NO_NavDialogGetSaveFileName
JNIEXPORT jint JNICALL OS_NATIVE(NavDialogGetSaveFileName)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NavDialogGetSaveFileName_FUNC);
	rc = (jint)NavDialogGetSaveFileName((NavDialogRef)arg0);
	OS_NATIVE_EXIT(env, that, NavDialogGetSaveFileName_FUNC);
	return rc;
}
#endif

#ifndef NO_NavDialogGetUserAction
JNIEXPORT jint JNICALL OS_NATIVE(NavDialogGetUserAction)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NavDialogGetUserAction_FUNC);
	rc = (jint)NavDialogGetUserAction((NavDialogRef)arg0);
	OS_NATIVE_EXIT(env, that, NavDialogGetUserAction_FUNC);
	return rc;
}
#endif

#ifndef NO_NavDialogRun
JNIEXPORT jint JNICALL OS_NATIVE(NavDialogRun)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NavDialogRun_FUNC);
	rc = (jint)NavDialogRun((NavDialogRef)arg0);
	OS_NATIVE_EXIT(env, that, NavDialogRun_FUNC);
	return rc;
}
#endif

#ifndef NO_NavDialogSetSaveFileName
JNIEXPORT jint JNICALL OS_NATIVE(NavDialogSetSaveFileName)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NavDialogSetSaveFileName_FUNC);
	rc = (jint)NavDialogSetSaveFileName((NavDialogRef)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, NavDialogSetSaveFileName_FUNC);
	return rc;
}
#endif

#ifndef NO_NavGetDefaultDialogCreationOptions
JNIEXPORT jint JNICALL OS_NATIVE(NavGetDefaultDialogCreationOptions)
	(JNIEnv *env, jclass that, jobject arg0)
{
	NavDialogCreationOptions _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NavGetDefaultDialogCreationOptions_FUNC);
	if (arg0) lparg0 = getNavDialogCreationOptionsFields(env, arg0, &_arg0);
	rc = (jint)NavGetDefaultDialogCreationOptions((NavDialogCreationOptions *)lparg0);
	if (arg0) setNavDialogCreationOptionsFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, NavGetDefaultDialogCreationOptions_FUNC);
	return rc;
}
#endif

#ifndef NO_NewControl
JNIEXPORT jint JNICALL OS_NATIVE(NewControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jbyteArray arg2, jboolean arg3, jshort arg4, jshort arg5, jshort arg6, jshort arg7, jint arg8)
{
	Rect _arg1, *lparg1=NULL;
	jbyte *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NewControl_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = (*env)->GetByteArrayElements(env, arg2, NULL);
	rc = (jint)NewControl((WindowRef)arg0, (const Rect *)lparg1, (ConstStr255Param)lparg2, (Boolean)arg3, (SInt16)arg4, (SInt16)arg5, (SInt16)arg6, (SInt16)arg7, (SInt32)arg8);
	if (arg2) (*env)->ReleaseByteArrayElements(env, arg2, lparg2, 0);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, NewControl_FUNC);
	return rc;
}
#endif

#ifndef NO_NewDrag
JNIEXPORT jint JNICALL OS_NATIVE(NewDrag)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NewDrag_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)NewDrag((DragRef *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, NewDrag_FUNC);
	return rc;
}
#endif

#ifndef NO_NewGWorldFromPtr
JNIEXPORT jint JNICALL OS_NATIVE(NewGWorldFromPtr)
	(JNIEnv *env, jclass that, jintArray arg0, jint arg1, jobject arg2, jint arg3, jint arg4, jint arg5, jint arg6, jint arg7)
{
	jint *lparg0=NULL;
	Rect _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, NewGWorldFromPtr_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	if (arg2) lparg2 = getRectFields(env, arg2, &_arg2);
	rc = (jint)NewGWorldFromPtr((GWorldPtr *)lparg0, (unsigned long)arg1, (const Rect *)lparg2, (CTabHandle)arg3, (GDHandle)arg4, (GWorldFlags)arg5, (Ptr)arg6, (long)arg7);
	if (arg2) setRectFields(env, arg2, lparg2);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, NewGWorldFromPtr_FUNC);
	return rc;
}
#endif

#ifndef NO_NewHandle
JNIEXPORT jint JNICALL OS_NATIVE(NewHandle)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NewHandle_FUNC);
	rc = (jint)NewHandle((Size)arg0);
	OS_NATIVE_EXIT(env, that, NewHandle_FUNC);
	return rc;
}
#endif

#ifndef NO_NewHandleClear
JNIEXPORT jint JNICALL OS_NATIVE(NewHandleClear)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NewHandleClear_FUNC);
	rc = (jint)NewHandleClear((Size)arg0);
	OS_NATIVE_EXIT(env, that, NewHandleClear_FUNC);
	return rc;
}
#endif

#ifndef NO_NewPtr
JNIEXPORT jint JNICALL OS_NATIVE(NewPtr)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NewPtr_FUNC);
	rc = (jint)NewPtr((Size)arg0);
	OS_NATIVE_EXIT(env, that, NewPtr_FUNC);
	return rc;
}
#endif

#ifndef NO_NewPtrClear
JNIEXPORT jint JNICALL OS_NATIVE(NewPtrClear)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NewPtrClear_FUNC);
	rc = (jint)NewPtrClear((Size)arg0);
	OS_NATIVE_EXIT(env, that, NewPtrClear_FUNC);
	return rc;
}
#endif

#ifndef NO_NewRgn
JNIEXPORT jint JNICALL OS_NATIVE(NewRgn)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, NewRgn_FUNC);
	rc = (jint)NewRgn();
	OS_NATIVE_EXIT(env, that, NewRgn_FUNC);
	return rc;
}
#endif

#ifndef NO_OffsetRect
JNIEXPORT void JNICALL OS_NATIVE(OffsetRect)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, OffsetRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	OffsetRect(lparg0, arg1, arg2);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, OffsetRect_FUNC);
}
#endif

#ifndef NO_OffsetRgn
JNIEXPORT void JNICALL OS_NATIVE(OffsetRgn)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2)
{
	OS_NATIVE_ENTER(env, that, OffsetRgn_FUNC);
	OffsetRgn((RgnHandle)arg0, (short)arg1, (short)arg2);
	OS_NATIVE_EXIT(env, that, OffsetRgn_FUNC);
}
#endif

#ifndef NO_OpenDataBrowserContainer
JNIEXPORT jint JNICALL OS_NATIVE(OpenDataBrowserContainer)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, OpenDataBrowserContainer_FUNC);
	rc = (jint)OpenDataBrowserContainer((ControlRef)arg0, (DataBrowserItemID)arg1);
	OS_NATIVE_EXIT(env, that, OpenDataBrowserContainer_FUNC);
	return rc;
}
#endif

#ifndef NO_OpenPoly
JNIEXPORT jint JNICALL OS_NATIVE(OpenPoly)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, OpenPoly_FUNC);
	rc = (jint)OpenPoly();
	OS_NATIVE_EXIT(env, that, OpenPoly_FUNC);
	return rc;
}
#endif

#ifndef NO_OpenRgn
JNIEXPORT void JNICALL OS_NATIVE(OpenRgn)
	(JNIEnv *env, jclass that)
{
	OS_NATIVE_ENTER(env, that, OpenRgn_FUNC);
	OpenRgn();
	OS_NATIVE_EXIT(env, that, OpenRgn_FUNC);
}
#endif

#ifndef NO_PMCreatePageFormat
JNIEXPORT jint JNICALL OS_NATIVE(PMCreatePageFormat)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMCreatePageFormat_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)PMCreatePageFormat((PMPageFormat *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, PMCreatePageFormat_FUNC);
	return rc;
}
#endif

#ifndef NO_PMCreatePrintSettings
JNIEXPORT jint JNICALL OS_NATIVE(PMCreatePrintSettings)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMCreatePrintSettings_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)PMCreatePrintSettings((PMPrintSettings *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, PMCreatePrintSettings_FUNC);
	return rc;
}
#endif

#ifndef NO_PMCreateSession
JNIEXPORT jint JNICALL OS_NATIVE(PMCreateSession)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMCreateSession_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)PMCreateSession((PMPrintSession *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, PMCreateSession_FUNC);
	return rc;
}
#endif

#ifndef NO_PMFlattenPageFormat
JNIEXPORT jint JNICALL OS_NATIVE(PMFlattenPageFormat)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMFlattenPageFormat_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMFlattenPageFormat((PMPageFormat)arg0, (Handle *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMFlattenPageFormat_FUNC);
	return rc;
}
#endif

#ifndef NO_PMFlattenPrintSettings
JNIEXPORT jint JNICALL OS_NATIVE(PMFlattenPrintSettings)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMFlattenPrintSettings_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMFlattenPrintSettings((PMPrintSettings)arg0, (Handle *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMFlattenPrintSettings_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetAdjustedPageRect
JNIEXPORT jint JNICALL OS_NATIVE(PMGetAdjustedPageRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	PMRect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetAdjustedPageRect_FUNC);
	if (arg1) lparg1 = getPMRectFields(env, arg1, &_arg1);
	rc = (jint)PMGetAdjustedPageRect((PMPageFormat)arg0, (PMRect *)lparg1);
	if (arg1) setPMRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, PMGetAdjustedPageRect_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetAdjustedPaperRect
JNIEXPORT jint JNICALL OS_NATIVE(PMGetAdjustedPaperRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	PMRect _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetAdjustedPaperRect_FUNC);
	if (arg1) lparg1 = getPMRectFields(env, arg1, &_arg1);
	rc = (jint)PMGetAdjustedPaperRect((PMPageFormat)arg0, (PMRect *)lparg1);
	if (arg1) setPMRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, PMGetAdjustedPaperRect_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetCollate
JNIEXPORT jint JNICALL OS_NATIVE(PMGetCollate)
	(JNIEnv *env, jclass that, jint arg0, jbooleanArray arg1)
{
	jboolean *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetCollate_FUNC);
	if (arg1) lparg1 = (*env)->GetBooleanArrayElements(env, arg1, NULL);
	rc = (jint)PMGetCollate((PMPrintSettings)arg0, lparg1);
	if (arg1) (*env)->ReleaseBooleanArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMGetCollate_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetCopies
JNIEXPORT jint JNICALL OS_NATIVE(PMGetCopies)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetCopies_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMGetCopies((PMPrintSettings)arg0, (UInt32 *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMGetCopies_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetFirstPage
JNIEXPORT jint JNICALL OS_NATIVE(PMGetFirstPage)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetFirstPage_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMGetFirstPage((PMPrintSettings)arg0, (UInt32 *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMGetFirstPage_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetJobNameCFString
JNIEXPORT jint JNICALL OS_NATIVE(PMGetJobNameCFString)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetJobNameCFString_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMGetJobNameCFString((PMPrintSettings)arg0, (CFStringRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMGetJobNameCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetLastPage
JNIEXPORT jint JNICALL OS_NATIVE(PMGetLastPage)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetLastPage_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMGetLastPage((PMPrintSettings)arg0, (UInt32 *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMGetLastPage_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetPageRange
JNIEXPORT jint JNICALL OS_NATIVE(PMGetPageRange)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetPageRange_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)PMGetPageRange((PMPrintSettings)arg0, (UInt32 *)lparg1, (UInt32 *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMGetPageRange_FUNC);
	return rc;
}
#endif

#ifndef NO_PMGetResolution
JNIEXPORT jint JNICALL OS_NATIVE(PMGetResolution)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	PMResolution _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMGetResolution_FUNC);
	if (arg1) lparg1 = getPMResolutionFields(env, arg1, &_arg1);
	rc = (jint)PMGetResolution((PMPageFormat)arg0, (PMResolution *)lparg1);
	if (arg1) setPMResolutionFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, PMGetResolution_FUNC);
	return rc;
}
#endif

#ifndef NO_PMRelease
JNIEXPORT jint JNICALL OS_NATIVE(PMRelease)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMRelease_FUNC);
	rc = (jint)PMRelease((PMObject)arg0);
	OS_NATIVE_EXIT(env, that, PMRelease_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionBeginDocumentNoDialog
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionBeginDocumentNoDialog)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionBeginDocumentNoDialog_FUNC);
	rc = (jint)PMSessionBeginDocumentNoDialog((PMPrintSession)arg0, (PMPrintSettings)arg1, (PMPageFormat)arg2);
	OS_NATIVE_EXIT(env, that, PMSessionBeginDocumentNoDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionBeginPageNoDialog
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionBeginPageNoDialog)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	PMRect _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionBeginPageNoDialog_FUNC);
	if (arg2) lparg2 = getPMRectFields(env, arg2, &_arg2);
	rc = (jint)PMSessionBeginPageNoDialog((PMPrintSession)arg0, (PMPageFormat)arg1, (const PMRect *)lparg2);
	if (arg2) setPMRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, PMSessionBeginPageNoDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionCopyDestinationLocation
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionCopyDestinationLocation)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionCopyDestinationLocation_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)PMSessionCopyDestinationLocation((PMPrintSession)arg0, (PMPrintSettings)arg1, (CFURLRef *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, PMSessionCopyDestinationLocation_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionCreatePrinterList
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionCreatePrinterList)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2, jintArray arg3)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionCreatePrinterList_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)PMSessionCreatePrinterList((PMPrintSession)arg0, (CFArrayRef *)lparg1, (CFIndex *)lparg2, (PMPrinter *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMSessionCreatePrinterList_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionDefaultPageFormat
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionDefaultPageFormat)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionDefaultPageFormat_FUNC);
	rc = (jint)PMSessionDefaultPageFormat((PMPrintSession)arg0, (PMPageFormat)arg1);
	OS_NATIVE_EXIT(env, that, PMSessionDefaultPageFormat_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionDefaultPrintSettings
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionDefaultPrintSettings)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionDefaultPrintSettings_FUNC);
	rc = (jint)PMSessionDefaultPrintSettings((PMPrintSession)arg0, (PMPrintSettings)arg1);
	OS_NATIVE_EXIT(env, that, PMSessionDefaultPrintSettings_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionEndDocumentNoDialog
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionEndDocumentNoDialog)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionEndDocumentNoDialog_FUNC);
	rc = (jint)PMSessionEndDocumentNoDialog((PMPrintSession)arg0);
	OS_NATIVE_EXIT(env, that, PMSessionEndDocumentNoDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionEndPageNoDialog
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionEndPageNoDialog)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionEndPageNoDialog_FUNC);
	rc = (jint)PMSessionEndPageNoDialog((PMPrintSession)arg0);
	OS_NATIVE_EXIT(env, that, PMSessionEndPageNoDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionError
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionError)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionError_FUNC);
	rc = (jint)PMSessionError((PMPrintSession)arg0);
	OS_NATIVE_EXIT(env, that, PMSessionError_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionGetDestinationType
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionGetDestinationType)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshortArray arg2)
{
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionGetDestinationType_FUNC);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)PMSessionGetDestinationType((PMPrintSession)arg0, (PMPrintSettings)arg1, (PMDestinationType *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, PMSessionGetDestinationType_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionGetGraphicsContext
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionGetGraphicsContext)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionGetGraphicsContext_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)PMSessionGetGraphicsContext((PMPrintSession)arg0, (CFStringRef)arg1, (void **)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, PMSessionGetGraphicsContext_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionPageSetupDialog
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionPageSetupDialog)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jbooleanArray arg2)
{
	jboolean *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionPageSetupDialog_FUNC);
	if (arg2) lparg2 = (*env)->GetBooleanArrayElements(env, arg2, NULL);
	rc = (jint)PMSessionPageSetupDialog((PMPrintSession)arg0, (PMPageFormat)arg1, (Boolean *)lparg2);
	if (arg2) (*env)->ReleaseBooleanArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, PMSessionPageSetupDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionPrintDialog
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionPrintDialog)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jbooleanArray arg3)
{
	jboolean *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionPrintDialog_FUNC);
	if (arg3) lparg3 = (*env)->GetBooleanArrayElements(env, arg3, NULL);
	rc = (jint)PMSessionPrintDialog((PMPrintSession)arg0, (PMPrintSettings)arg1, (PMPageFormat)arg2, (Boolean *)lparg3);
	if (arg3) (*env)->ReleaseBooleanArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, PMSessionPrintDialog_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionSetCurrentPrinter
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionSetCurrentPrinter)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionSetCurrentPrinter_FUNC);
	rc = (jint)PMSessionSetCurrentPrinter((PMPrintSession)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, PMSessionSetCurrentPrinter_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionSetDestination
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionSetDestination)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshort arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionSetDestination_FUNC);
	rc = (jint)PMSessionSetDestination((PMPrintSession)arg0, (PMPrintSettings)arg1, (PMDestinationType)arg2, (CFStringRef)arg3, (CFURLRef)arg4);
	OS_NATIVE_EXIT(env, that, PMSessionSetDestination_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionSetDocumentFormatGeneration
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionSetDocumentFormatGeneration)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionSetDocumentFormatGeneration_FUNC);
	rc = (jint)PMSessionSetDocumentFormatGeneration((PMPrintSession)arg0, (CFStringRef)arg1, (CFArrayRef)arg2, (CFTypeRef)arg3);
	OS_NATIVE_EXIT(env, that, PMSessionSetDocumentFormatGeneration_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionSetError
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionSetError)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionSetError_FUNC);
	rc = (jint)PMSessionSetError((PMPrintSession)arg0, arg1);
	OS_NATIVE_EXIT(env, that, PMSessionSetError_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionUseSheets
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionUseSheets)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionUseSheets_FUNC);
	rc = (jint)PMSessionUseSheets((PMPrintSession)arg0, (WindowRef)arg1, (PMSheetDoneUPP)arg2);
	OS_NATIVE_EXIT(env, that, PMSessionUseSheets_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionValidatePageFormat
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionValidatePageFormat)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jbooleanArray arg2)
{
	jboolean *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionValidatePageFormat_FUNC);
	if (arg2) lparg2 = (*env)->GetBooleanArrayElements(env, arg2, NULL);
	rc = (jint)PMSessionValidatePageFormat((PMPrintSession)arg0, (PMPageFormat)arg1, (Boolean *)lparg2);
	if (arg2) (*env)->ReleaseBooleanArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, PMSessionValidatePageFormat_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSessionValidatePrintSettings
JNIEXPORT jint JNICALL OS_NATIVE(PMSessionValidatePrintSettings)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jbooleanArray arg2)
{
	jboolean *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSessionValidatePrintSettings_FUNC);
	if (arg2) lparg2 = (*env)->GetBooleanArrayElements(env, arg2, NULL);
	rc = (jint)PMSessionValidatePrintSettings((PMPrintSession)arg0, (PMPrintSettings)arg1, (Boolean *)lparg2);
	if (arg2) (*env)->ReleaseBooleanArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, PMSessionValidatePrintSettings_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSetCollate
JNIEXPORT jint JNICALL OS_NATIVE(PMSetCollate)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSetCollate_FUNC);
	rc = (jint)PMSetCollate((PMPrintSettings)arg0, arg1);
	OS_NATIVE_EXIT(env, that, PMSetCollate_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSetFirstPage
JNIEXPORT jint JNICALL OS_NATIVE(PMSetFirstPage)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSetFirstPage_FUNC);
	rc = (jint)PMSetFirstPage((PMPrintSettings)arg0, (UInt32)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, PMSetFirstPage_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSetJobNameCFString
JNIEXPORT jint JNICALL OS_NATIVE(PMSetJobNameCFString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSetJobNameCFString_FUNC);
	rc = (jint)PMSetJobNameCFString((PMPrintSettings)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, PMSetJobNameCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSetLastPage
JNIEXPORT jint JNICALL OS_NATIVE(PMSetLastPage)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSetLastPage_FUNC);
	rc = (jint)PMSetLastPage((PMPrintSettings)arg0, (UInt32)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, PMSetLastPage_FUNC);
	return rc;
}
#endif

#ifndef NO_PMSetPageRange
JNIEXPORT jint JNICALL OS_NATIVE(PMSetPageRange)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PMSetPageRange_FUNC);
	rc = (jint)PMSetPageRange((PMPrintSettings)arg0, (UInt32)arg1, (UInt32)arg2);
	OS_NATIVE_EXIT(env, that, PMSetPageRange_FUNC);
	return rc;
}
#endif

#ifndef NO_PMUnflattenPageFormat
JNIEXPORT jint JNICALL OS_NATIVE(PMUnflattenPageFormat)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMUnflattenPageFormat_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMUnflattenPageFormat((Handle)arg0, (PMPageFormat *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMUnflattenPageFormat_FUNC);
	return rc;
}
#endif

#ifndef NO_PMUnflattenPrintSettings
JNIEXPORT jint JNICALL OS_NATIVE(PMUnflattenPrintSettings)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PMUnflattenPrintSettings_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)PMUnflattenPrintSettings((Handle)arg0, (PMPrintSettings *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, PMUnflattenPrintSettings_FUNC);
	return rc;
}
#endif

#ifndef NO_PaintOval
JNIEXPORT void JNICALL OS_NATIVE(PaintOval)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, PaintOval_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	PaintOval((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, PaintOval_FUNC);
}
#endif

#ifndef NO_PaintPoly
JNIEXPORT void JNICALL OS_NATIVE(PaintPoly)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, PaintPoly_FUNC);
	PaintPoly((PolyHandle)arg0);
	OS_NATIVE_EXIT(env, that, PaintPoly_FUNC);
}
#endif

#ifndef NO_PaintRect
JNIEXPORT void JNICALL OS_NATIVE(PaintRect)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, PaintRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	PaintRect((const Rect *)lparg0);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, PaintRect_FUNC);
}
#endif

#ifndef NO_PaintRoundRect
JNIEXPORT void JNICALL OS_NATIVE(PaintRoundRect)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, PaintRoundRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	PaintRoundRect((const Rect *)lparg0, (short)arg1, (short)arg2);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, PaintRoundRect_FUNC);
}
#endif

#ifndef NO_PenSize
JNIEXPORT void JNICALL OS_NATIVE(PenSize)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, PenSize_FUNC);
	PenSize((short)arg0, (short)arg1);
	OS_NATIVE_EXIT(env, that, PenSize_FUNC);
}
#endif

#ifndef NO_PickColor
JNIEXPORT jint JNICALL OS_NATIVE(PickColor)
	(JNIEnv *env, jclass that, jobject arg0)
{
	ColorPickerInfo _arg0, *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PickColor_FUNC);
	if (arg0) lparg0 = getColorPickerInfoFields(env, arg0, &_arg0);
	rc = (jint)PickColor((ColorPickerInfo *)lparg0);
	if (arg0) setColorPickerInfoFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, PickColor_FUNC);
	return rc;
}
#endif

#ifndef NO_PopUpMenuSelect
JNIEXPORT jint JNICALL OS_NATIVE(PopUpMenuSelect)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2, jshort arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PopUpMenuSelect_FUNC);
	rc = (jint)PopUpMenuSelect((MenuRef)arg0, (short)arg1, (short)arg2, (short)arg3);
	OS_NATIVE_EXIT(env, that, PopUpMenuSelect_FUNC);
	return rc;
}
#endif

#ifndef NO_PostEvent
JNIEXPORT jint JNICALL OS_NATIVE(PostEvent)
	(JNIEnv *env, jclass that, jshort arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PostEvent_FUNC);
	rc = (jint)PostEvent((EventKind)arg0, (UInt32)arg1);
	OS_NATIVE_EXIT(env, that, PostEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_PostEventToQueue
JNIEXPORT jint JNICALL OS_NATIVE(PostEventToQueue)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshort arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, PostEventToQueue_FUNC);
	rc = (jint)PostEventToQueue((EventQueueRef)arg0, (EventRef)arg1, (EventPriority)arg2);
	OS_NATIVE_EXIT(env, that, PostEventToQueue_FUNC);
	return rc;
}
#endif

#ifndef NO_PtInRect
JNIEXPORT jboolean JNICALL OS_NATIVE(PtInRect)
	(JNIEnv *env, jclass that, jobject arg0, jobject arg1)
{
	Point _arg0, *lparg0=NULL;
	Rect _arg1, *lparg1=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, PtInRect_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	rc = (jboolean)PtInRect(*(Point *)lparg0, (const Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, PtInRect_FUNC);
	return rc;
}
#endif

#ifndef NO_PtInRgn
JNIEXPORT jboolean JNICALL OS_NATIVE(PtInRgn)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1)
{
	Point _arg0, *lparg0=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, PtInRgn_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	rc = (jboolean)PtInRgn(*(Point *)lparg0, (RgnHandle)arg1);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, PtInRgn_FUNC);
	return rc;
}
#endif

#ifndef NO_PutScrapFlavor
JNIEXPORT jint JNICALL OS_NATIVE(PutScrapFlavor)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jbyteArray arg4)
{
	jbyte *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, PutScrapFlavor_FUNC);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	rc = (jint)PutScrapFlavor((ScrapRef)arg0, (ScrapFlavorType)arg1, (ScrapFlavorFlags)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, PutScrapFlavor_FUNC);
	return rc;
}
#endif

#ifndef NO_QDBeginCGContext
JNIEXPORT jint JNICALL OS_NATIVE(QDBeginCGContext)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, QDBeginCGContext_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)QDBeginCGContext((CGrafPtr)arg0, (CGContextRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, QDBeginCGContext_FUNC);
	return rc;
}
#endif

#ifndef NO_QDEndCGContext
JNIEXPORT jint JNICALL OS_NATIVE(QDEndCGContext)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, QDEndCGContext_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)QDEndCGContext((CGrafPtr)arg0, (CGContextRef *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, QDEndCGContext_FUNC);
	return rc;
}
#endif

#ifndef NO_QDFlushPortBuffer
JNIEXPORT void JNICALL OS_NATIVE(QDFlushPortBuffer)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, QDFlushPortBuffer_FUNC);
	QDFlushPortBuffer((CGrafPtr)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, QDFlushPortBuffer_FUNC);
}
#endif

#ifndef NO_QDGlobalToLocalPoint
JNIEXPORT void JNICALL OS_NATIVE(QDGlobalToLocalPoint)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Point _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, QDGlobalToLocalPoint_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	QDGlobalToLocalPoint((CGrafPtr)arg0, (Point *)lparg1);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, QDGlobalToLocalPoint_FUNC);
}
#endif

#ifndef NO_QDLocalToGlobalPoint
JNIEXPORT void JNICALL OS_NATIVE(QDLocalToGlobalPoint)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Point _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, QDLocalToGlobalPoint_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	QDLocalToGlobalPoint((CGrafPtr)arg0, (Point *)lparg1);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, QDLocalToGlobalPoint_FUNC);
}
#endif

#ifndef NO_QDSetDirtyRegion
JNIEXPORT jint JNICALL OS_NATIVE(QDSetDirtyRegion)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, QDSetDirtyRegion_FUNC);
	rc = (jint)QDSetDirtyRegion((CGrafPtr)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, QDSetDirtyRegion_FUNC);
	return rc;
}
#endif

#ifndef NO_QDSetPatternOrigin
JNIEXPORT void JNICALL OS_NATIVE(QDSetPatternOrigin)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Point _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, QDSetPatternOrigin_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	QDSetPatternOrigin(*(Point *)lparg0);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, QDSetPatternOrigin_FUNC);
}
#endif

#ifndef NO_QDSwapTextFlags
JNIEXPORT jint JNICALL OS_NATIVE(QDSwapTextFlags)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, QDSwapTextFlags_FUNC);
	rc = (jint)QDSwapTextFlags((UInt32)arg0);
	OS_NATIVE_EXIT(env, that, QDSwapTextFlags_FUNC);
	return rc;
}
#endif

#ifndef NO_RGBBackColor
JNIEXPORT void JNICALL OS_NATIVE(RGBBackColor)
	(JNIEnv *env, jclass that, jobject arg0)
{
	RGBColor _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, RGBBackColor_FUNC);
	if (arg0) lparg0 = getRGBColorFields(env, arg0, &_arg0);
	RGBBackColor((const RGBColor *)lparg0);
	if (arg0) setRGBColorFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, RGBBackColor_FUNC);
}
#endif

#ifndef NO_RGBForeColor
JNIEXPORT void JNICALL OS_NATIVE(RGBForeColor)
	(JNIEnv *env, jclass that, jobject arg0)
{
	RGBColor _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, RGBForeColor_FUNC);
	if (arg0) lparg0 = getRGBColorFields(env, arg0, &_arg0);
	RGBForeColor((const RGBColor *)lparg0);
	if (arg0) setRGBColorFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, RGBForeColor_FUNC);
}
#endif

#ifndef NO_ReceiveNextEvent
JNIEXPORT jint JNICALL OS_NATIVE(ReceiveNextEvent)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jdouble arg2, jboolean arg3, jintArray arg4)
{
	jint *lparg1=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ReceiveNextEvent_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)ReceiveNextEvent((UInt32)arg0, (const EventTypeSpec *)lparg1, (EventTimeout)arg2, (Boolean)arg3, (EventRef *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, ReceiveNextEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_RectInRgn
JNIEXPORT jboolean JNICALL OS_NATIVE(RectInRgn)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1)
{
	Rect _arg0, *lparg0=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, RectInRgn_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	rc = (jboolean)RectInRgn((const Rect *)lparg0, (RgnHandle)arg1);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, RectInRgn_FUNC);
	return rc;
}
#endif

#ifndef NO_RectRgn
JNIEXPORT void JNICALL OS_NATIVE(RectRgn)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, RectRgn_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	RectRgn((RgnHandle)arg0, (const Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, RectRgn_FUNC);
}
#endif

#ifndef NO_RegisterAppearanceClient
JNIEXPORT jint JNICALL OS_NATIVE(RegisterAppearanceClient)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RegisterAppearanceClient_FUNC);
	rc = (jint)RegisterAppearanceClient();
	OS_NATIVE_EXIT(env, that, RegisterAppearanceClient_FUNC);
	return rc;
}
#endif

#ifndef NO_ReleaseEvent
JNIEXPORT void JNICALL OS_NATIVE(ReleaseEvent)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, ReleaseEvent_FUNC);
	ReleaseEvent((EventRef)arg0);
	OS_NATIVE_EXIT(env, that, ReleaseEvent_FUNC);
}
#endif

#ifndef NO_ReleaseIconRef
JNIEXPORT void JNICALL OS_NATIVE(ReleaseIconRef)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, ReleaseIconRef_FUNC);
	ReleaseIconRef((IconRef)arg0);
	OS_NATIVE_EXIT(env, that, ReleaseIconRef_FUNC);
}
#endif

#ifndef NO_ReleaseMenu
JNIEXPORT jint JNICALL OS_NATIVE(ReleaseMenu)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ReleaseMenu_FUNC);
	rc = (jint)ReleaseMenu((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, ReleaseMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_ReleaseWindow
JNIEXPORT jint JNICALL OS_NATIVE(ReleaseWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ReleaseWindow_FUNC);
	rc = (jint)ReleaseWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, ReleaseWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_ReleaseWindowGroup
JNIEXPORT jint JNICALL OS_NATIVE(ReleaseWindowGroup)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ReleaseWindowGroup_FUNC);
	rc = (jint)ReleaseWindowGroup((WindowGroupRef)arg0);
	OS_NATIVE_EXIT(env, that, ReleaseWindowGroup_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveControlProperty
JNIEXPORT jint JNICALL OS_NATIVE(RemoveControlProperty)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveControlProperty_FUNC);
	rc = (jint)RemoveControlProperty((ControlRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, RemoveControlProperty_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveDataBrowserItems
JNIEXPORT jint JNICALL OS_NATIVE(RemoveDataBrowserItems)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveDataBrowserItems_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)RemoveDataBrowserItems((ControlRef)arg0, (DataBrowserItemID)arg1, (UInt32)arg2, (const DataBrowserItemID *)lparg3, (DataBrowserPropertyID)arg4);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, RemoveDataBrowserItems_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveDataBrowserTableViewColumn
JNIEXPORT jint JNICALL OS_NATIVE(RemoveDataBrowserTableViewColumn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveDataBrowserTableViewColumn_FUNC);
	rc = (jint)RemoveDataBrowserTableViewColumn((ControlRef)arg0, (DataBrowserTableViewColumnID)arg1);
	OS_NATIVE_EXIT(env, that, RemoveDataBrowserTableViewColumn_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveEventHandler
JNIEXPORT jint JNICALL OS_NATIVE(RemoveEventHandler)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveEventHandler_FUNC);
	rc = (jint)RemoveEventHandler((EventHandlerRef)arg0);
	OS_NATIVE_EXIT(env, that, RemoveEventHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveEventLoopTimer
JNIEXPORT jint JNICALL OS_NATIVE(RemoveEventLoopTimer)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveEventLoopTimer_FUNC);
	rc = (jint)RemoveEventLoopTimer((EventLoopTimerRef)arg0);
	OS_NATIVE_EXIT(env, that, RemoveEventLoopTimer_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveReceiveHandler
JNIEXPORT jint JNICALL OS_NATIVE(RemoveReceiveHandler)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveReceiveHandler_FUNC);
	rc = (jint)RemoveReceiveHandler((DragReceiveHandlerUPP)arg0, (WindowRef)arg1);
	OS_NATIVE_EXIT(env, that, RemoveReceiveHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_RemoveTrackingHandler
JNIEXPORT jint JNICALL OS_NATIVE(RemoveTrackingHandler)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RemoveTrackingHandler_FUNC);
	rc = (jint)RemoveTrackingHandler((DragTrackingHandlerUPP)arg0, (WindowRef)arg1);
	OS_NATIVE_EXIT(env, that, RemoveTrackingHandler_FUNC);
	return rc;
}
#endif

#ifndef NO_RepositionWindow
JNIEXPORT jint JNICALL OS_NATIVE(RepositionWindow)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RepositionWindow_FUNC);
	rc = (jint)RepositionWindow((WindowRef)arg0, (WindowRef)arg1, arg2);
	OS_NATIVE_EXIT(env, that, RepositionWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_ReshapeCustomWindow
JNIEXPORT jint JNICALL OS_NATIVE(ReshapeCustomWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, ReshapeCustomWindow_FUNC);
	rc = (jint)ReshapeCustomWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, ReshapeCustomWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_RestoreApplicationDockTileImage
JNIEXPORT jint JNICALL OS_NATIVE(RestoreApplicationDockTileImage)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RestoreApplicationDockTileImage_FUNC);
	rc = (jint)RestoreApplicationDockTileImage();
	OS_NATIVE_EXIT(env, that, RestoreApplicationDockTileImage_FUNC);
	return rc;
}
#endif

#ifndef NO_RetainEvent
JNIEXPORT jint JNICALL OS_NATIVE(RetainEvent)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RetainEvent_FUNC);
	rc = (jint)RetainEvent((EventRef)arg0);
	OS_NATIVE_EXIT(env, that, RetainEvent_FUNC);
	return rc;
}
#endif

#ifndef NO_RetainMenu
JNIEXPORT jint JNICALL OS_NATIVE(RetainMenu)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RetainMenu_FUNC);
	rc = (jint)RetainMenu((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, RetainMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_RetainWindow
JNIEXPORT jint JNICALL OS_NATIVE(RetainWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RetainWindow_FUNC);
	rc = (jint)RetainWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, RetainWindow_FUNC);
	return rc;
}
#endif

#ifndef NO_RevealDataBrowserItem
JNIEXPORT jint JNICALL OS_NATIVE(RevealDataBrowserItem)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jbyte arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, RevealDataBrowserItem_FUNC);
	rc = (jint)RevealDataBrowserItem((ControlRef)arg0, (DataBrowserItemID)arg1, (DataBrowserPropertyID)arg2, (DataBrowserRevealOptions)arg3);
	OS_NATIVE_EXIT(env, that, RevealDataBrowserItem_FUNC);
	return rc;
}
#endif

#ifndef NO_RunStandardAlert
JNIEXPORT jint JNICALL OS_NATIVE(RunStandardAlert)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshortArray arg2)
{
	jshort *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, RunStandardAlert_FUNC);
	if (arg2) lparg2 = (*env)->GetShortArrayElements(env, arg2, NULL);
	rc = (jint)RunStandardAlert((DialogRef)arg0, (ModalFilterUPP)arg1, (DialogItemIndex *)lparg2);
	if (arg2) (*env)->ReleaseShortArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, RunStandardAlert_FUNC);
	return rc;
}
#endif

#ifndef NO_ScrollRect
JNIEXPORT void JNICALL OS_NATIVE(ScrollRect)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2, jint arg3)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, ScrollRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	ScrollRect((const Rect *)lparg0, (short)arg1, (short)arg2, (RgnHandle)arg3);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, ScrollRect_FUNC);
}
#endif

#ifndef NO_SectRect
JNIEXPORT jboolean JNICALL OS_NATIVE(SectRect)
	(JNIEnv *env, jclass that, jobject arg0, jobject arg1, jobject arg2)
{
	Rect _arg0, *lparg0=NULL;
	Rect _arg1, *lparg1=NULL;
	Rect _arg2, *lparg2=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, SectRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = &_arg2;
	rc = (jboolean)SectRect(lparg0, lparg1, lparg2);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, SectRect_FUNC);
	return rc;
}
#endif

#ifndef NO_SectRgn
JNIEXPORT void JNICALL OS_NATIVE(SectRgn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	OS_NATIVE_ENTER(env, that, SectRgn_FUNC);
	SectRgn((RgnHandle)arg0, (RgnHandle)arg1, (RgnHandle)arg2);
	OS_NATIVE_EXIT(env, that, SectRgn_FUNC);
}
#endif

#ifndef NO_SelectWindow
JNIEXPORT void JNICALL OS_NATIVE(SelectWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, SelectWindow_FUNC);
	SelectWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, SelectWindow_FUNC);
}
#endif

#ifndef NO_SendBehind
JNIEXPORT void JNICALL OS_NATIVE(SendBehind)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SendBehind_FUNC);
	SendBehind((WindowRef)arg0, (WindowRef)arg1);
	OS_NATIVE_EXIT(env, that, SendBehind_FUNC);
}
#endif

#ifndef NO_SendEventToEventTarget
JNIEXPORT jint JNICALL OS_NATIVE(SendEventToEventTarget)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SendEventToEventTarget_FUNC);
	rc = (jint)SendEventToEventTarget((EventRef)arg0, (EventTargetRef)arg1);
	OS_NATIVE_EXIT(env, that, SendEventToEventTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_SetApplicationDockTileImage
JNIEXPORT jint JNICALL OS_NATIVE(SetApplicationDockTileImage)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetApplicationDockTileImage_FUNC);
	rc = (jint)SetApplicationDockTileImage((CGImageRef)arg0);
	OS_NATIVE_EXIT(env, that, SetApplicationDockTileImage_FUNC);
	return rc;
}
#endif

#ifndef NO_SetBevelButtonContentInfo
JNIEXPORT jint JNICALL OS_NATIVE(SetBevelButtonContentInfo)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	ControlButtonContentInfo _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetBevelButtonContentInfo_FUNC);
	if (arg1) lparg1 = getControlButtonContentInfoFields(env, arg1, &_arg1);
	rc = (jint)SetBevelButtonContentInfo((ControlRef)arg0, (ControlButtonContentInfoPtr)lparg1);
	if (arg1) setControlButtonContentInfoFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetBevelButtonContentInfo_FUNC);
	return rc;
}
#endif

#ifndef NO_SetClip
JNIEXPORT void JNICALL OS_NATIVE(SetClip)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, SetClip_FUNC);
	SetClip((RgnHandle)arg0);
	OS_NATIVE_EXIT(env, that, SetClip_FUNC);
}
#endif

#ifndef NO_SetControl32BitMaximum
JNIEXPORT void JNICALL OS_NATIVE(SetControl32BitMaximum)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControl32BitMaximum_FUNC);
	SetControl32BitMaximum((ControlRef)arg0, (SInt32)arg1);
	OS_NATIVE_EXIT(env, that, SetControl32BitMaximum_FUNC);
}
#endif

#ifndef NO_SetControl32BitMinimum
JNIEXPORT void JNICALL OS_NATIVE(SetControl32BitMinimum)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControl32BitMinimum_FUNC);
	SetControl32BitMinimum((ControlRef)arg0, (SInt32)arg1);
	OS_NATIVE_EXIT(env, that, SetControl32BitMinimum_FUNC);
}
#endif

#ifndef NO_SetControl32BitValue
JNIEXPORT void JNICALL OS_NATIVE(SetControl32BitValue)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControl32BitValue_FUNC);
	SetControl32BitValue((ControlRef)arg0, (SInt32)arg1);
	OS_NATIVE_EXIT(env, that, SetControl32BitValue_FUNC);
}
#endif

#ifndef NO_SetControlAction
JNIEXPORT void JNICALL OS_NATIVE(SetControlAction)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControlAction_FUNC);
	SetControlAction((ControlRef)arg0, (ControlActionUPP)arg1);
	OS_NATIVE_EXIT(env, that, SetControlAction_FUNC);
}
#endif

#ifndef NO_SetControlBounds
JNIEXPORT void JNICALL OS_NATIVE(SetControlBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, SetControlBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	SetControlBounds((ControlRef)arg0, (const Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetControlBounds_FUNC);
}
#endif

#ifndef NO_SetControlColorProc
JNIEXPORT jint JNICALL OS_NATIVE(SetControlColorProc)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlColorProc_FUNC);
	rc = (jint)SetControlColorProc((ControlRef)arg0, (ControlColorUPP)arg1);
	OS_NATIVE_EXIT(env, that, SetControlColorProc_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIIII
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIIII)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIIII_FUNC);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)arg4);
	OS_NATIVE_EXIT(env, that, SetControlData__IIIII_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlButtonContentInfo_2
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlButtonContentInfo_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jobject arg4)
{
	ControlButtonContentInfo _arg4, *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlButtonContentInfo_2_FUNC);
	if (arg4) lparg4 = getControlButtonContentInfoFields(env, arg4, &_arg4);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) setControlButtonContentInfoFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlButtonContentInfo_2_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlTabInfoRecV1_2
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlTabInfoRecV1_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jobject arg4)
{
	ControlTabInfoRecV1 _arg4, *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlTabInfoRecV1_2_FUNC);
	if (arg4) lparg4 = getControlTabInfoRecV1Fields(env, arg4, &_arg4);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) setControlTabInfoRecV1Fields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, SetControlData__IIIILorg_eclipse_swt_internal_carbon_ControlTabInfoRecV1_2_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIIILorg_eclipse_swt_internal_carbon_Rect_2
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIIILorg_eclipse_swt_internal_carbon_Rect_2)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jobject arg4)
{
	Rect _arg4, *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIIILorg_eclipse_swt_internal_carbon_Rect_2_FUNC);
	if (arg4) lparg4 = getRectFields(env, arg4, &_arg4);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) setRectFields(env, arg4, lparg4);
	OS_NATIVE_EXIT(env, that, SetControlData__IIIILorg_eclipse_swt_internal_carbon_Rect_2_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIII_3B
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIII_3B)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jbyteArray arg4)
{
	jbyte *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIII_3B_FUNC);
	if (arg4) lparg4 = (*env)->GetByteArrayElements(env, arg4, NULL);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseByteArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, SetControlData__IIII_3B_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIII_3I
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIII_3I)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jintArray arg4)
{
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIII_3I_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, SetControlData__IIII_3I_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlData__IIII_3S
JNIEXPORT jint JNICALL OS_NATIVE(SetControlData__IIII_3S)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jshortArray arg4)
{
	jshort *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlData__IIII_3S_FUNC);
	if (arg4) lparg4 = (*env)->GetShortArrayElements(env, arg4, NULL);
	rc = (jint)SetControlData((ControlRef)arg0, (ControlPartCode)arg1, (ResType)arg2, (Size)arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseShortArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, SetControlData__IIII_3S_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlFontStyle
JNIEXPORT jint JNICALL OS_NATIVE(SetControlFontStyle)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	ControlFontStyleRec _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlFontStyle_FUNC);
	if (arg1) lparg1 = getControlFontStyleRecFields(env, arg1, &_arg1);
	rc = (jint)SetControlFontStyle((ControlRef)arg0, (const ControlFontStyleRec *)lparg1);
	if (arg1) setControlFontStyleRecFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetControlFontStyle_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlPopupMenuHandle
JNIEXPORT void JNICALL OS_NATIVE(SetControlPopupMenuHandle)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControlPopupMenuHandle_FUNC);
	SetControlPopupMenuHandle((ControlRef)arg0, (MenuRef)arg1);
	OS_NATIVE_EXIT(env, that, SetControlPopupMenuHandle_FUNC);
}
#endif

#ifndef NO_SetControlProperty
JNIEXPORT jint JNICALL OS_NATIVE(SetControlProperty)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jintArray arg4)
{
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlProperty_FUNC);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)SetControlProperty((ControlRef)arg0, arg1, arg2, arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, SetControlProperty_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlReference
JNIEXPORT void JNICALL OS_NATIVE(SetControlReference)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControlReference_FUNC);
	SetControlReference((ControlRef)arg0, (SInt32)arg1);
	OS_NATIVE_EXIT(env, that, SetControlReference_FUNC);
}
#endif

#ifndef NO_SetControlTitleWithCFString
JNIEXPORT jint JNICALL OS_NATIVE(SetControlTitleWithCFString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlTitleWithCFString_FUNC);
	rc = (jint)SetControlTitleWithCFString((ControlRef)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, SetControlTitleWithCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_SetControlViewSize
JNIEXPORT void JNICALL OS_NATIVE(SetControlViewSize)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetControlViewSize_FUNC);
	SetControlViewSize((ControlRef)arg0, (SInt32)arg1);
	OS_NATIVE_EXIT(env, that, SetControlViewSize_FUNC);
}
#endif

#ifndef NO_SetControlVisibility
JNIEXPORT jint JNICALL OS_NATIVE(SetControlVisibility)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetControlVisibility_FUNC);
	rc = (jint)SetControlVisibility((ControlRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, SetControlVisibility_FUNC);
	return rc;
}
#endif

#ifndef NO_SetCursor
JNIEXPORT void JNICALL OS_NATIVE(SetCursor)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, SetCursor_FUNC);
	SetCursor((const Cursor *)arg0);
	OS_NATIVE_EXIT(env, that, SetCursor_FUNC);
}
#endif

#ifndef NO_SetDataBrowserCallbacks
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserCallbacks)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	DataBrowserCallbacks _arg1={0}, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserCallbacks_FUNC);
	if (arg1) lparg1 = getDataBrowserCallbacksFields(env, arg1, &_arg1);
	rc = (jint)SetDataBrowserCallbacks((ControlRef)arg0, (const DataBrowserCallbacks *)lparg1);
	if (arg1) setDataBrowserCallbacksFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserCallbacks_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserCustomCallbacks
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserCustomCallbacks)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	DataBrowserCustomCallbacks _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserCustomCallbacks_FUNC);
	if (arg1) lparg1 = getDataBrowserCustomCallbacksFields(env, arg1, &_arg1);
	rc = (jint)SetDataBrowserCustomCallbacks((ControlRef)arg0, lparg1);
	if (arg1) setDataBrowserCustomCallbacksFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserCustomCallbacks_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserHasScrollBars
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserHasScrollBars)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserHasScrollBars_FUNC);
	rc = (jint)SetDataBrowserHasScrollBars((ControlRef)arg0, (Boolean)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserHasScrollBars_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserItemDataBooleanValue
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserItemDataBooleanValue)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserItemDataBooleanValue_FUNC);
	rc = (jint)SetDataBrowserItemDataBooleanValue((DataBrowserItemDataRef)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserItemDataBooleanValue_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserItemDataButtonValue
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserItemDataButtonValue)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserItemDataButtonValue_FUNC);
	rc = (jint)SetDataBrowserItemDataButtonValue((DataBrowserItemDataRef)arg0, (ThemeButtonValue)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserItemDataButtonValue_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserItemDataIcon
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserItemDataIcon)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserItemDataIcon_FUNC);
	rc = (jint)SetDataBrowserItemDataIcon((DataBrowserItemDataRef)arg0, (IconRef)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserItemDataIcon_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserItemDataItemID
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserItemDataItemID)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserItemDataItemID_FUNC);
	rc = (jint)SetDataBrowserItemDataItemID((DataBrowserItemDataRef)arg0, (DataBrowserItemID)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserItemDataItemID_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserItemDataText
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserItemDataText)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserItemDataText_FUNC);
	rc = (jint)SetDataBrowserItemDataText((DataBrowserItemDataRef)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserItemDataText_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserListViewDisclosureColumn
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserListViewDisclosureColumn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserListViewDisclosureColumn_FUNC);
	rc = (jint)SetDataBrowserListViewDisclosureColumn((ControlRef)arg0, (DataBrowserTableViewColumnID)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserListViewDisclosureColumn_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserListViewHeaderBtnHeight
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserListViewHeaderBtnHeight)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserListViewHeaderBtnHeight_FUNC);
	rc = (jint)SetDataBrowserListViewHeaderBtnHeight((ControlRef)arg0, (UInt16)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserListViewHeaderBtnHeight_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserListViewHeaderDesc
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserListViewHeaderDesc)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	DataBrowserListViewHeaderDesc _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserListViewHeaderDesc_FUNC);
	if (arg2) lparg2 = getDataBrowserListViewHeaderDescFields(env, arg2, &_arg2);
	rc = (jint)SetDataBrowserListViewHeaderDesc((ControlRef)arg0, arg1, lparg2);
	if (arg2) setDataBrowserListViewHeaderDescFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserListViewHeaderDesc_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserScrollPosition
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserScrollPosition)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserScrollPosition_FUNC);
	rc = (jint)SetDataBrowserScrollPosition((ControlRef)arg0, (UInt32)arg1, (UInt32)arg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserScrollPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserSelectedItems
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserSelectedItems)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jint arg3)
{
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserSelectedItems_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)SetDataBrowserSelectedItems((ControlRef)arg0, (UInt32)arg1, (const DataBrowserItemID *)lparg2, (DataBrowserSetOption)arg3);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, SetDataBrowserSelectedItems_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserSelectionFlags
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserSelectionFlags)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserSelectionFlags_FUNC);
	rc = (jint)SetDataBrowserSelectionFlags((ControlRef)arg0, (DataBrowserSelectionFlags)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserSelectionFlags_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserSortOrder
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserSortOrder)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserSortOrder_FUNC);
	rc = (jint)SetDataBrowserSortOrder((ControlRef)arg0, arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserSortOrder_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserTableViewColumnPosition
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserTableViewColumnPosition)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserTableViewColumnPosition_FUNC);
	rc = (jint)SetDataBrowserTableViewColumnPosition((ControlRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserTableViewColumnPosition_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserTableViewHiliteStyle
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserTableViewHiliteStyle)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserTableViewHiliteStyle_FUNC);
	rc = (jint)SetDataBrowserTableViewHiliteStyle((ControlRef)arg0, arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserTableViewHiliteStyle_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserTableViewItemRow
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserTableViewItemRow)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserTableViewItemRow_FUNC);
	rc = (jint)SetDataBrowserTableViewItemRow((ControlRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserTableViewItemRow_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserTableViewNamedColumnWidth
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserTableViewNamedColumnWidth)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshort arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserTableViewNamedColumnWidth_FUNC);
	rc = (jint)SetDataBrowserTableViewNamedColumnWidth((ControlRef)arg0, (DataBrowserTableViewColumnID)arg1, (UInt16)arg2);
	OS_NATIVE_EXIT(env, that, SetDataBrowserTableViewNamedColumnWidth_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDataBrowserTarget
JNIEXPORT jint JNICALL OS_NATIVE(SetDataBrowserTarget)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDataBrowserTarget_FUNC);
	rc = (jint)SetDataBrowserTarget((ControlRef)arg0, (DataBrowserItemID)arg1);
	OS_NATIVE_EXIT(env, that, SetDataBrowserTarget_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDragAllowableActions
JNIEXPORT jint JNICALL OS_NATIVE(SetDragAllowableActions)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDragAllowableActions_FUNC);
	rc = (jint)SetDragAllowableActions((DragRef)arg0, (DragActions)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, SetDragAllowableActions_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDragDropAction
JNIEXPORT jint JNICALL OS_NATIVE(SetDragDropAction)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDragDropAction_FUNC);
	rc = (jint)SetDragDropAction((DragRef)arg0, (DragActions)arg1);
	OS_NATIVE_EXIT(env, that, SetDragDropAction_FUNC);
	return rc;
}
#endif

#ifndef NO_SetDragInputProc
JNIEXPORT jint JNICALL OS_NATIVE(SetDragInputProc)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetDragInputProc_FUNC);
	rc = (jint)SetDragInputProc((DragRef)arg0, (DragInputUPP)arg1, (void *)arg2);
	OS_NATIVE_EXIT(env, that, SetDragInputProc_FUNC);
	return rc;
}
#endif

#ifndef NO_SetEventLoopTimerNextFireTime
JNIEXPORT jint JNICALL OS_NATIVE(SetEventLoopTimerNextFireTime)
	(JNIEnv *env, jclass that, jint arg0, jdouble arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetEventLoopTimerNextFireTime_FUNC);
	rc = (jint)SetEventLoopTimerNextFireTime((EventLoopTimerRef)arg0, (EventTimerInterval)arg1);
	OS_NATIVE_EXIT(env, that, SetEventLoopTimerNextFireTime_FUNC);
	return rc;
}
#endif

#ifndef NO_SetEventParameter__IIII_3C
JNIEXPORT jint JNICALL OS_NATIVE(SetEventParameter__IIII_3C)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jcharArray arg4)
{
	jchar *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetEventParameter__IIII_3C_FUNC);
	if (arg4) lparg4 = (*env)->GetCharArrayElements(env, arg4, NULL);
	rc = (jint)SetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (UInt32)arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseCharArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, SetEventParameter__IIII_3C_FUNC);
	return rc;
}
#endif

#ifndef NO_SetEventParameter__IIII_3S
JNIEXPORT jint JNICALL OS_NATIVE(SetEventParameter__IIII_3S)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jshortArray arg4)
{
	jshort *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetEventParameter__IIII_3S_FUNC);
	if (arg4) lparg4 = (*env)->GetShortArrayElements(env, arg4, NULL);
	rc = (jint)SetEventParameter((EventRef)arg0, (EventParamName)arg1, (EventParamType)arg2, (UInt32)arg3, (const void *)lparg4);
	if (arg4) (*env)->ReleaseShortArrayElements(env, arg4, lparg4, 0);
	OS_NATIVE_EXIT(env, that, SetEventParameter__IIII_3S_FUNC);
	return rc;
}
#endif

#ifndef NO_SetFontInfoForSelection
JNIEXPORT jint JNICALL OS_NATIVE(SetFontInfoForSelection)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetFontInfoForSelection_FUNC);
	rc = (jint)SetFontInfoForSelection((OSType)arg0, (UInt32)arg1, (void *)arg2, (HIObjectRef)arg3);
	OS_NATIVE_EXIT(env, that, SetFontInfoForSelection_FUNC);
	return rc;
}
#endif

#ifndef NO_SetFrontProcess
JNIEXPORT jint JNICALL OS_NATIVE(SetFrontProcess)
	(JNIEnv *env, jclass that, jintArray arg0)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetFrontProcess_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)SetFrontProcess((const ProcessSerialNumber *)lparg0);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, SetFrontProcess_FUNC);
	return rc;
}
#endif

#ifndef NO_SetFrontProcessWithOptions
JNIEXPORT jint JNICALL OS_NATIVE(SetFrontProcessWithOptions)
	(JNIEnv *env, jclass that, jintArray arg0, jint arg1)
{
	jint *lparg0=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetFrontProcessWithOptions_FUNC);
	if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	rc = (jint)SetFrontProcessWithOptions((const ProcessSerialNumber *)lparg0, arg1);
	if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, SetFrontProcessWithOptions_FUNC);
	return rc;
}
#endif

#ifndef NO_SetGWorld
JNIEXPORT void JNICALL OS_NATIVE(SetGWorld)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetGWorld_FUNC);
	SetGWorld((CGrafPtr)arg0, (GDHandle)arg1);
	OS_NATIVE_EXIT(env, that, SetGWorld_FUNC);
}
#endif

#ifndef NO_SetItemMark
JNIEXPORT void JNICALL OS_NATIVE(SetItemMark)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2)
{
	OS_NATIVE_ENTER(env, that, SetItemMark_FUNC);
	SetItemMark((MenuRef)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, SetItemMark_FUNC);
}
#endif

#ifndef NO_SetKeyboardFocus
JNIEXPORT jint JNICALL OS_NATIVE(SetKeyboardFocus)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jshort arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetKeyboardFocus_FUNC);
	rc = (jint)SetKeyboardFocus((WindowRef)arg0, (ControlRef)arg1, (ControlFocusPart)arg2);
	OS_NATIVE_EXIT(env, that, SetKeyboardFocus_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuCommandMark
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuCommandMark)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jchar arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuCommandMark_FUNC);
	rc = (jint)SetMenuCommandMark((MenuRef)arg0, (MenuCommand)arg1, (UniChar)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuCommandMark_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuFont
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuFont)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuFont_FUNC);
	rc = (jint)SetMenuFont((MenuRef)arg0, (SInt16)arg1, (UInt16)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuFont_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemCommandKey
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemCommandKey)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jboolean arg2, jchar arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemCommandKey_FUNC);
	rc = (jint)SetMenuItemCommandKey((MenuRef)arg0, (MenuItemIndex)arg1, (Boolean)arg2, (UInt16)arg3);
	OS_NATIVE_EXIT(env, that, SetMenuItemCommandKey_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemHierarchicalMenu
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemHierarchicalMenu)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemHierarchicalMenu_FUNC);
	rc = (jint)SetMenuItemHierarchicalMenu((MenuRef)arg0, (MenuItemIndex)arg1, (MenuRef)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuItemHierarchicalMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemIconHandle
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemIconHandle)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jbyte arg2, jint arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemIconHandle_FUNC);
	rc = (jint)SetMenuItemIconHandle((MenuRef)arg0, (SInt16)arg1, (UInt8)arg2, (Handle)arg3);
	OS_NATIVE_EXIT(env, that, SetMenuItemIconHandle_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemKeyGlyph
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemKeyGlyph)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemKeyGlyph_FUNC);
	rc = (jint)SetMenuItemKeyGlyph((MenuRef)arg0, (SInt16)arg1, (SInt16)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuItemKeyGlyph_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemModifiers
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemModifiers)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jbyte arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemModifiers_FUNC);
	rc = (jint)SetMenuItemModifiers((MenuRef)arg0, (SInt16)arg1, (UInt8)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuItemModifiers_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemRefCon
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemRefCon)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemRefCon_FUNC);
	rc = (jint)SetMenuItemRefCon((MenuRef)arg0, (SInt16)arg1, (UInt32)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuItemRefCon_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuItemTextWithCFString
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuItemTextWithCFString)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuItemTextWithCFString_FUNC);
	rc = (jint)SetMenuItemTextWithCFString((MenuRef)arg0, (MenuItemIndex)arg1, (CFStringRef)arg2);
	OS_NATIVE_EXIT(env, that, SetMenuItemTextWithCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_SetMenuTitleWithCFString
JNIEXPORT jint JNICALL OS_NATIVE(SetMenuTitleWithCFString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetMenuTitleWithCFString_FUNC);
	rc = (jint)SetMenuTitleWithCFString((MenuRef)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, SetMenuTitleWithCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_SetOrigin
JNIEXPORT void JNICALL OS_NATIVE(SetOrigin)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1)
{
	OS_NATIVE_ENTER(env, that, SetOrigin_FUNC);
	SetOrigin((short)arg0, (short)arg1);
	OS_NATIVE_EXIT(env, that, SetOrigin_FUNC);
}
#endif

#ifndef NO_SetPort
JNIEXPORT void JNICALL OS_NATIVE(SetPort)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, SetPort_FUNC);
	SetPort((GrafPtr)arg0);
	OS_NATIVE_EXIT(env, that, SetPort_FUNC);
}
#endif

#ifndef NO_SetPortBounds
JNIEXPORT void JNICALL OS_NATIVE(SetPortBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, SetPortBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	SetPortBounds((CGrafPtr)arg0, (const Rect *)lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetPortBounds_FUNC);
}
#endif

#ifndef NO_SetPortWindowPort
JNIEXPORT void JNICALL OS_NATIVE(SetPortWindowPort)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, SetPortWindowPort_FUNC);
	SetPortWindowPort((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, SetPortWindowPort_FUNC);
}
#endif

#ifndef NO_SetPt
JNIEXPORT void JNICALL OS_NATIVE(SetPt)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2)
{
	Point _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, SetPt_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	SetPt((Point *)lparg0, (short)arg1, (short)arg2);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, SetPt_FUNC);
}
#endif

#ifndef NO_SetRect
JNIEXPORT void JNICALL OS_NATIVE(SetRect)
	(JNIEnv *env, jclass that, jobject arg0, jshort arg1, jshort arg2, jshort arg3, jshort arg4)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, SetRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	SetRect((Rect *)lparg0, (short)arg1, (short)arg2, (short)arg3, (short)arg4);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, SetRect_FUNC);
}
#endif

#ifndef NO_SetRectRgn
JNIEXPORT void JNICALL OS_NATIVE(SetRectRgn)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2, jshort arg3, jshort arg4)
{
	OS_NATIVE_ENTER(env, that, SetRectRgn_FUNC);
	SetRectRgn((RgnHandle)arg0, (short)arg1, (short)arg2, (short)arg3, (short)arg4);
	OS_NATIVE_EXIT(env, that, SetRectRgn_FUNC);
}
#endif

#ifndef NO_SetRootMenu
JNIEXPORT jint JNICALL OS_NATIVE(SetRootMenu)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetRootMenu_FUNC);
	rc = (jint)SetRootMenu((MenuRef)arg0);
	OS_NATIVE_EXIT(env, that, SetRootMenu_FUNC);
	return rc;
}
#endif

#ifndef NO_SetThemeBackground
JNIEXPORT jint JNICALL OS_NATIVE(SetThemeBackground)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetThemeBackground_FUNC);
	rc = (jint)SetThemeBackground((ThemeBrush)arg0, (SInt16)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, SetThemeBackground_FUNC);
	return rc;
}
#endif

#ifndef NO_SetThemeCursor
JNIEXPORT jint JNICALL OS_NATIVE(SetThemeCursor)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetThemeCursor_FUNC);
	rc = (jint)SetThemeCursor((ThemeCursor)arg0);
	OS_NATIVE_EXIT(env, that, SetThemeCursor_FUNC);
	return rc;
}
#endif

#ifndef NO_SetThemeDrawingState
JNIEXPORT jint JNICALL OS_NATIVE(SetThemeDrawingState)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetThemeDrawingState_FUNC);
	rc = (jint)SetThemeDrawingState((ThemeDrawingState)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, SetThemeDrawingState_FUNC);
	return rc;
}
#endif

#ifndef NO_SetThemeTextColor
JNIEXPORT jint JNICALL OS_NATIVE(SetThemeTextColor)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetThemeTextColor_FUNC);
	rc = (jint)SetThemeTextColor(arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, SetThemeTextColor_FUNC);
	return rc;
}
#endif

#ifndef NO_SetThemeWindowBackground
JNIEXPORT jint JNICALL OS_NATIVE(SetThemeWindowBackground)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetThemeWindowBackground_FUNC);
	rc = (jint)SetThemeWindowBackground((WindowRef)arg0, (ThemeBrush)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, SetThemeWindowBackground_FUNC);
	return rc;
}
#endif

#ifndef NO_SetUpControlBackground
JNIEXPORT jint JNICALL OS_NATIVE(SetUpControlBackground)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetUpControlBackground_FUNC);
	rc = (jint)SetUpControlBackground((ControlRef)arg0, (SInt16)arg1, (Boolean)arg2);
	OS_NATIVE_EXIT(env, that, SetUpControlBackground_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWRefCon
JNIEXPORT void JNICALL OS_NATIVE(SetWRefCon)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, SetWRefCon_FUNC);
	SetWRefCon((WindowRef)arg0, (long)arg1);
	OS_NATIVE_EXIT(env, that, SetWRefCon_FUNC);
}
#endif

#ifndef NO_SetWindowActivationScope
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowActivationScope)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowActivationScope_FUNC);
	rc = (jint)SetWindowActivationScope((WindowRef)arg0, (WindowActivationScope)arg1);
	OS_NATIVE_EXIT(env, that, SetWindowActivationScope_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowBounds
JNIEXPORT void JNICALL OS_NATIVE(SetWindowBounds)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	Rect _arg2, *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, SetWindowBounds_FUNC);
	if (arg2) lparg2 = getRectFields(env, arg2, &_arg2);
	SetWindowBounds((WindowRef)arg0, (WindowRegionCode)arg1, (Rect *)lparg2);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, SetWindowBounds_FUNC);
}
#endif

#ifndef NO_SetWindowDefaultButton
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowDefaultButton)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowDefaultButton_FUNC);
	rc = (jint)SetWindowDefaultButton((WindowRef)arg0, (ControlRef)arg1);
	OS_NATIVE_EXIT(env, that, SetWindowDefaultButton_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowGroup
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowGroup)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowGroup_FUNC);
	rc = (jint)SetWindowGroup((WindowRef)arg0, (WindowGroupRef)arg1);
	OS_NATIVE_EXIT(env, that, SetWindowGroup_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowGroupOwner
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowGroupOwner)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowGroupOwner_FUNC);
	rc = (jint)SetWindowGroupOwner((WindowGroupRef)arg0, (WindowRef)arg1);
	OS_NATIVE_EXIT(env, that, SetWindowGroupOwner_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowGroupParent
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowGroupParent)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowGroupParent_FUNC);
	rc = (jint)SetWindowGroupParent((WindowGroupRef)arg0, (WindowGroupRef)arg1);
	OS_NATIVE_EXIT(env, that, SetWindowGroupParent_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowModality
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowModality)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowModality_FUNC);
	rc = (jint)SetWindowModality((WindowRef)arg0, (WindowModality)arg1, (WindowRef)arg2);
	OS_NATIVE_EXIT(env, that, SetWindowModality_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowResizeLimits
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowResizeLimits)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2)
{
	CGPoint _arg1, *lparg1=NULL;
	CGPoint _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowResizeLimits_FUNC);
	if (arg1) lparg1 = getCGPointFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getCGPointFields(env, arg2, &_arg2);
	rc = (jint)SetWindowResizeLimits((WindowRef)arg0, (HISize *)lparg1, (HISize *)lparg2);
	if (arg2) setCGPointFields(env, arg2, lparg2);
	if (arg1) setCGPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, SetWindowResizeLimits_FUNC);
	return rc;
}
#endif

#ifndef NO_SetWindowTitleWithCFString
JNIEXPORT jint JNICALL OS_NATIVE(SetWindowTitleWithCFString)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SetWindowTitleWithCFString_FUNC);
	rc = (jint)SetWindowTitleWithCFString((WindowRef)arg0, (CFStringRef)arg1);
	OS_NATIVE_EXIT(env, that, SetWindowTitleWithCFString_FUNC);
	return rc;
}
#endif

#ifndef NO_ShowWindow
JNIEXPORT void JNICALL OS_NATIVE(ShowWindow)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, ShowWindow_FUNC);
	ShowWindow((WindowRef)arg0);
	OS_NATIVE_EXIT(env, that, ShowWindow_FUNC);
}
#endif

#ifndef NO_SizeControl
JNIEXPORT void JNICALL OS_NATIVE(SizeControl)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2)
{
	OS_NATIVE_ENTER(env, that, SizeControl_FUNC);
	SizeControl((ControlRef)arg0, (SInt16)arg1, (SInt16)arg2);
	OS_NATIVE_EXIT(env, that, SizeControl_FUNC);
}
#endif

#ifndef NO_SizeWindow
JNIEXPORT void JNICALL OS_NATIVE(SizeWindow)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jshort arg2, jboolean arg3)
{
	OS_NATIVE_ENTER(env, that, SizeWindow_FUNC);
	SizeWindow((WindowRef)arg0, (short)arg1, (short)arg2, (Boolean)arg3);
	OS_NATIVE_EXIT(env, that, SizeWindow_FUNC);
}
#endif

#ifndef NO_StillDown
JNIEXPORT jboolean JNICALL OS_NATIVE(StillDown)
	(JNIEnv *env, jclass that)
{
	jboolean rc;
	OS_NATIVE_ENTER(env, that, StillDown_FUNC);
	rc = (jboolean)StillDown();
	OS_NATIVE_EXIT(env, that, StillDown_FUNC);
	return rc;
}
#endif

#ifndef NO_SyncCGContextOriginWithPort
JNIEXPORT jint JNICALL OS_NATIVE(SyncCGContextOriginWithPort)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, SyncCGContextOriginWithPort_FUNC);
	rc = (jint)SyncCGContextOriginWithPort((CGContextRef)arg0, (CGrafPtr)arg1);
	OS_NATIVE_EXIT(env, that, SyncCGContextOriginWithPort_FUNC);
	return rc;
}
#endif

#ifndef NO_SysBeep
JNIEXPORT void JNICALL OS_NATIVE(SysBeep)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, SysBeep_FUNC);
	SysBeep((short)arg0);
	OS_NATIVE_EXIT(env, that, SysBeep_FUNC);
}
#endif

#ifndef NO_TXNActivate
JNIEXPORT jint JNICALL OS_NATIVE(TXNActivate)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jboolean arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNActivate_FUNC);
	rc = (jint)TXNActivate((TXNObject)arg0, (TXNFrameID)arg1, (TXNScrollBarState)arg2);
	OS_NATIVE_EXIT(env, that, TXNActivate_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNAdjustCursor
JNIEXPORT void JNICALL OS_NATIVE(TXNAdjustCursor)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, TXNAdjustCursor_FUNC);
	TXNAdjustCursor((TXNObject)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, TXNAdjustCursor_FUNC);
}
#endif

#ifndef NO_TXNClick
JNIEXPORT void JNICALL OS_NATIVE(TXNClick)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	EventRecord _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, TXNClick_FUNC);
	if (arg1) lparg1 = getEventRecordFields(env, arg1, &_arg1);
	TXNClick((TXNObject)arg0, (const EventRecord *)lparg1);
	if (arg1) setEventRecordFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TXNClick_FUNC);
}
#endif

#ifndef NO_TXNCopy
JNIEXPORT jint JNICALL OS_NATIVE(TXNCopy)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNCopy_FUNC);
	rc = (jint)TXNCopy((TXNObject)arg0);
	OS_NATIVE_EXIT(env, that, TXNCopy_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNCut
JNIEXPORT jint JNICALL OS_NATIVE(TXNCut)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNCut_FUNC);
	rc = (jint)TXNCut((TXNObject)arg0);
	OS_NATIVE_EXIT(env, that, TXNCut_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNDataSize
JNIEXPORT jint JNICALL OS_NATIVE(TXNDataSize)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNDataSize_FUNC);
	rc = (jint)TXNDataSize((TXNObject)arg0);
	OS_NATIVE_EXIT(env, that, TXNDataSize_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNDeleteObject
JNIEXPORT void JNICALL OS_NATIVE(TXNDeleteObject)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, TXNDeleteObject_FUNC);
	TXNDeleteObject((TXNObject)arg0);
	OS_NATIVE_EXIT(env, that, TXNDeleteObject_FUNC);
}
#endif

#ifndef NO_TXNDraw
JNIEXPORT void JNICALL OS_NATIVE(TXNDraw)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, TXNDraw_FUNC);
	TXNDraw((TXNObject)arg0, (GWorldPtr)arg1);
	OS_NATIVE_EXIT(env, that, TXNDraw_FUNC);
}
#endif

#ifndef NO_TXNEchoMode
JNIEXPORT jint JNICALL OS_NATIVE(TXNEchoMode)
	(JNIEnv *env, jclass that, jint arg0, jchar arg1, jint arg2, jboolean arg3)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNEchoMode_FUNC);
	rc = (jint)TXNEchoMode((TXNObject)arg0, (UniChar)arg1, (TextEncoding)arg2, (Boolean)arg3);
	OS_NATIVE_EXIT(env, that, TXNEchoMode_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNFocus
JNIEXPORT void JNICALL OS_NATIVE(TXNFocus)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	OS_NATIVE_ENTER(env, that, TXNFocus_FUNC);
	TXNFocus((TXNObject)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, TXNFocus_FUNC);
}
#endif

#ifndef NO_TXNGetData
JNIEXPORT jint JNICALL OS_NATIVE(TXNGetData)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNGetData_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)TXNGetData((TXNObject)arg0, (TXNOffset)arg1, (TXNOffset)arg2, (Handle *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, TXNGetData_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNGetLineCount
JNIEXPORT jint JNICALL OS_NATIVE(TXNGetLineCount)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1)
{
	jint *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNGetLineCount_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	rc = (jint)TXNGetLineCount((TXNObject)arg0, (ItemCount *)lparg1);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, TXNGetLineCount_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNGetLineMetrics
JNIEXPORT jint JNICALL OS_NATIVE(TXNGetLineMetrics)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jintArray arg3)
{
	jint *lparg2=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNGetLineMetrics_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)TXNGetLineMetrics((TXNObject)arg0, (UInt32)arg1, (Fixed *)lparg2, (Fixed *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, TXNGetLineMetrics_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNGetRectBounds
JNIEXPORT jint JNICALL OS_NATIVE(TXNGetRectBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2, jobject arg3)
{
	Rect _arg1, *lparg1=NULL;
	TXNLongRect _arg2, *lparg2=NULL;
	TXNLongRect _arg3, *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNGetRectBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getTXNLongRectFields(env, arg2, &_arg2);
	if (arg3) lparg3 = getTXNLongRectFields(env, arg3, &_arg3);
	rc = (jint)TXNGetRectBounds((TXNObject)arg0, (Rect *)lparg1, (TXNLongRect *)lparg2, (TXNLongRect *)lparg3);
	if (arg3) setTXNLongRectFields(env, arg3, lparg3);
	if (arg2) setTXNLongRectFields(env, arg2, lparg2);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TXNGetRectBounds_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNGetSelection
JNIEXPORT void JNICALL OS_NATIVE(TXNGetSelection)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jintArray arg2)
{
	jint *lparg1=NULL;
	jint *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, TXNGetSelection_FUNC);
	if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	TXNGetSelection((TXNObject)arg0, (TXNOffset *)lparg1, (TXNOffset *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, 0);
	OS_NATIVE_EXIT(env, that, TXNGetSelection_FUNC);
}
#endif

#ifndef NO_TXNGetTXNObjectControls
JNIEXPORT jint JNICALL OS_NATIVE(TXNGetTXNObjectControls)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jintArray arg2, jintArray arg3)
{
	jint *lparg2=NULL;
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNGetTXNObjectControls_FUNC);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)TXNGetTXNObjectControls((TXNObject)arg0, (ItemCount)arg1, (const TXNControlTag *)lparg2, (TXNControlData *)lparg3);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, TXNGetTXNObjectControls_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNGetViewRect
JNIEXPORT void JNICALL OS_NATIVE(TXNGetViewRect)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, TXNGetViewRect_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	TXNGetViewRect((TXNObject)arg0, lparg1);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TXNGetViewRect_FUNC);
}
#endif

#ifndef NO_TXNInitTextension
JNIEXPORT jint JNICALL OS_NATIVE(TXNInitTextension)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNInitTextension_FUNC);
	rc = (jint)TXNInitTextension((const TXNMacOSPreferredFontDescription *)arg0, (ItemCount)arg1, (TXNInitOptions)arg2);
	OS_NATIVE_EXIT(env, that, TXNInitTextension_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNNewObject
JNIEXPORT jint JNICALL OS_NATIVE(TXNNewObject)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2, jint arg3, jint arg4, jint arg5, jint arg6, jintArray arg7, jintArray arg8, jint arg9)
{
	Rect _arg2, *lparg2=NULL;
	jint *lparg7=NULL;
	jint *lparg8=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNNewObject_FUNC);
	if (arg2) lparg2 = getRectFields(env, arg2, &_arg2);
	if (arg7) lparg7 = (*env)->GetIntArrayElements(env, arg7, NULL);
	if (arg8) lparg8 = (*env)->GetIntArrayElements(env, arg8, NULL);
	rc = (jint)TXNNewObject((const FSSpec *)arg0, (WindowRef)arg1, (const Rect *)lparg2, (TXNFrameOptions)arg3, (TXNFrameType)arg4, (TXNFileType)arg5, (TXNPermanentTextEncodingType)arg6, (TXNObject *)lparg7, (TXNFrameID *)lparg8, (TXNObjectRefcon)arg9);
	if (arg8) (*env)->ReleaseIntArrayElements(env, arg8, lparg8, 0);
	if (arg7) (*env)->ReleaseIntArrayElements(env, arg7, lparg7, 0);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, TXNNewObject_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNOffsetToPoint
JNIEXPORT jint JNICALL OS_NATIVE(TXNOffsetToPoint)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jobject arg2)
{
	Point _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNOffsetToPoint_FUNC);
	if (arg2) lparg2 = getPointFields(env, arg2, &_arg2);
	rc = (jint)TXNOffsetToPoint((TXNObject)arg0, (TXNOffset)arg1, (Point *)lparg2);
	if (arg2) setPointFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, TXNOffsetToPoint_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNPaste
JNIEXPORT jint JNICALL OS_NATIVE(TXNPaste)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNPaste_FUNC);
	rc = (jint)TXNPaste((TXNObject)arg0);
	OS_NATIVE_EXIT(env, that, TXNPaste_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNPointToOffset
JNIEXPORT jint JNICALL OS_NATIVE(TXNPointToOffset)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jintArray arg2)
{
	Point _arg1, *lparg1=NULL;
	jint *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNPointToOffset_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	if (arg2) lparg2 = (*env)->GetIntArrayElements(env, arg2, NULL);
	rc = (jint)TXNPointToOffset((TXNObject)arg0, *lparg1, (TXNOffset *)lparg2);
	if (arg2) (*env)->ReleaseIntArrayElements(env, arg2, lparg2, 0);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TXNPointToOffset_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNSelectAll
JNIEXPORT void JNICALL OS_NATIVE(TXNSelectAll)
	(JNIEnv *env, jclass that, jint arg0)
{
	OS_NATIVE_ENTER(env, that, TXNSelectAll_FUNC);
	TXNSelectAll((TXNObject)arg0);
	OS_NATIVE_EXIT(env, that, TXNSelectAll_FUNC);
}
#endif

#ifndef NO_TXNSetBackground
JNIEXPORT jint JNICALL OS_NATIVE(TXNSetBackground)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	TXNBackground _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNSetBackground_FUNC);
	if (arg1) lparg1 = getTXNBackgroundFields(env, arg1, &_arg1);
	rc = (jint)TXNSetBackground((TXNObject)arg0, (const TXNBackground *)lparg1);
	if (arg1) setTXNBackgroundFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TXNSetBackground_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNSetData
JNIEXPORT jint JNICALL OS_NATIVE(TXNSetData)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jcharArray arg2, jint arg3, jint arg4, jint arg5)
{
	jchar *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNSetData_FUNC);
	if (arg2) lparg2 = (*env)->GetCharArrayElements(env, arg2, NULL);
	rc = (jint)TXNSetData((TXNObject)arg0, (TXNDataType)arg1, (const void *)lparg2, (ByteCount)arg3, (TXNOffset)arg4, (TXNOffset)arg5);
	if (arg2) (*env)->ReleaseCharArrayElements(env, arg2, lparg2, 0);
	OS_NATIVE_EXIT(env, that, TXNSetData_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNSetFrameBounds
JNIEXPORT void JNICALL OS_NATIVE(TXNSetFrameBounds)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4, jint arg5)
{
	OS_NATIVE_ENTER(env, that, TXNSetFrameBounds_FUNC);
	TXNSetFrameBounds((TXNObject)arg0, (SInt32)arg1, (SInt32)arg2, (SInt32)arg3, (SInt32)arg4, (TXNFrameID)arg5);
	OS_NATIVE_EXIT(env, that, TXNSetFrameBounds_FUNC);
}
#endif

#ifndef NO_TXNSetRectBounds
JNIEXPORT void JNICALL OS_NATIVE(TXNSetRectBounds)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jobject arg2, jboolean arg3)
{
	Rect _arg1, *lparg1=NULL;
	TXNLongRect _arg2, *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, TXNSetRectBounds_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = getTXNLongRectFields(env, arg2, &_arg2);
	TXNSetRectBounds((TXNObject)arg0, (Rect *)lparg1, (TXNLongRect *)lparg2, (Boolean)arg3);
	if (arg2) setTXNLongRectFields(env, arg2, lparg2);
	if (arg1) setRectFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TXNSetRectBounds_FUNC);
}
#endif

#ifndef NO_TXNSetSelection
JNIEXPORT jint JNICALL OS_NATIVE(TXNSetSelection)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNSetSelection_FUNC);
	rc = (jint)TXNSetSelection((TXNObject)arg0, (TXNOffset)arg1, (TXNOffset)arg2);
	OS_NATIVE_EXIT(env, that, TXNSetSelection_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNSetTXNObjectControls
JNIEXPORT jint JNICALL OS_NATIVE(TXNSetTXNObjectControls)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1, jint arg2, jintArray arg3, jintArray arg4)
{
	jint *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNSetTXNObjectControls_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)TXNSetTXNObjectControls((TXNObject)arg0, (Boolean)arg1, (ItemCount)arg2, (const TXNControlTag *)lparg3, (const TXNControlData *)lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, TXNSetTXNObjectControls_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNSetTypeAttributes
JNIEXPORT jint JNICALL OS_NATIVE(TXNSetTypeAttributes)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jint arg3, jint arg4)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, TXNSetTypeAttributes_FUNC);
	rc = (jint)TXNSetTypeAttributes((TXNObject)arg0, (ItemCount)arg1, (const TXNTypeAttributes *)arg2, (TXNOffset)arg3, (TXNOffset)arg4);
	OS_NATIVE_EXIT(env, that, TXNSetTypeAttributes_FUNC);
	return rc;
}
#endif

#ifndef NO_TXNShowSelection
JNIEXPORT void JNICALL OS_NATIVE(TXNShowSelection)
	(JNIEnv *env, jclass that, jint arg0, jboolean arg1)
{
	OS_NATIVE_ENTER(env, that, TXNShowSelection_FUNC);
	TXNShowSelection((TXNObject)arg0, (Boolean)arg1);
	OS_NATIVE_EXIT(env, that, TXNShowSelection_FUNC);
}
#endif

#ifndef NO_TestControl
JNIEXPORT jshort JNICALL OS_NATIVE(TestControl)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1)
{
	Point _arg1, *lparg1=NULL;
	jshort rc;
	OS_NATIVE_ENTER(env, that, TestControl_FUNC);
	if (arg1) lparg1 = getPointFields(env, arg1, &_arg1);
	rc = (jshort)TestControl((ControlRef)arg0, *(Point *)lparg1);
	if (arg1) setPointFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TestControl_FUNC);
	return rc;
}
#endif

#ifndef NO_TextFace
JNIEXPORT void JNICALL OS_NATIVE(TextFace)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, TextFace_FUNC);
	TextFace((StyleParameter)arg0);
	OS_NATIVE_EXIT(env, that, TextFace_FUNC);
}
#endif

#ifndef NO_TextFont
JNIEXPORT void JNICALL OS_NATIVE(TextFont)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, TextFont_FUNC);
	TextFont((short)arg0);
	OS_NATIVE_EXIT(env, that, TextFont_FUNC);
}
#endif

#ifndef NO_TextMode
JNIEXPORT void JNICALL OS_NATIVE(TextMode)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, TextMode_FUNC);
	TextMode((short)arg0);
	OS_NATIVE_EXIT(env, that, TextMode_FUNC);
}
#endif

#ifndef NO_TextSize
JNIEXPORT void JNICALL OS_NATIVE(TextSize)
	(JNIEnv *env, jclass that, jshort arg0)
{
	OS_NATIVE_ENTER(env, that, TextSize_FUNC);
	TextSize((short)arg0);
	OS_NATIVE_EXIT(env, that, TextSize_FUNC);
}
#endif

#ifndef NO_TextWidth
JNIEXPORT jshort JNICALL OS_NATIVE(TextWidth)
	(JNIEnv *env, jclass that, jbyteArray arg0, jshort arg1, jshort arg2)
{
	jbyte *lparg0=NULL;
	jshort rc;
	OS_NATIVE_ENTER(env, that, TextWidth_FUNC);
	if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	rc = (jshort)TextWidth((const void *)lparg0, (short)arg1, (short)arg2);
	if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	OS_NATIVE_EXIT(env, that, TextWidth_FUNC);
	return rc;
}
#endif

#ifndef NO_TrackDrag
JNIEXPORT jint JNICALL OS_NATIVE(TrackDrag)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	EventRecord _arg1, *lparg1=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TrackDrag_FUNC);
	if (arg1) lparg1 = getEventRecordFields(env, arg1, &_arg1);
	rc = (jint)TrackDrag((DragRef)arg0, (const EventRecord *)lparg1, (RgnHandle)arg2);
	if (arg1) setEventRecordFields(env, arg1, lparg1);
	OS_NATIVE_EXIT(env, that, TrackDrag_FUNC);
	return rc;
}
#endif

#ifndef NO_TrackMouseLocationWithOptions
JNIEXPORT jint JNICALL OS_NATIVE(TrackMouseLocationWithOptions)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jdouble arg2, jobject arg3, jintArray arg4, jshortArray arg5)
{
	Point _arg3, *lparg3=NULL;
	jint *lparg4=NULL;
	jshort *lparg5=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, TrackMouseLocationWithOptions_FUNC);
	if (arg3) lparg3 = getPointFields(env, arg3, &_arg3);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	if (arg5) lparg5 = (*env)->GetShortArrayElements(env, arg5, NULL);
	rc = (jint)TrackMouseLocationWithOptions((GrafPtr)arg0, (OptionBits)arg1, (EventTimeout)arg2, (Point *)lparg3, (UInt32 *)lparg4, (MouseTrackingResult *)lparg5);
	if (arg5) (*env)->ReleaseShortArrayElements(env, arg5, lparg5, 0);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) setPointFields(env, arg3, lparg3);
	OS_NATIVE_EXIT(env, that, TrackMouseLocationWithOptions_FUNC);
	return rc;
}
#endif

#ifndef NO_UnionRect
JNIEXPORT void JNICALL OS_NATIVE(UnionRect)
	(JNIEnv *env, jclass that, jobject arg0, jobject arg1, jobject arg2)
{
	Rect _arg0, *lparg0=NULL;
	Rect _arg1, *lparg1=NULL;
	Rect _arg2, *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, UnionRect_FUNC);
	if (arg0) lparg0 = getRectFields(env, arg0, &_arg0);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	if (arg2) lparg2 = &_arg2;
	UnionRect(lparg0, lparg1, lparg2);
	if (arg2) setRectFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, UnionRect_FUNC);
}
#endif

#ifndef NO_UnionRgn
JNIEXPORT void JNICALL OS_NATIVE(UnionRgn)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	OS_NATIVE_ENTER(env, that, UnionRgn_FUNC);
	UnionRgn((RgnHandle)arg0, (RgnHandle)arg1, (RgnHandle)arg2);
	OS_NATIVE_EXIT(env, that, UnionRgn_FUNC);
}
#endif

#ifndef NO_UnlockPortBits
JNIEXPORT jint JNICALL OS_NATIVE(UnlockPortBits)
	(JNIEnv *env, jclass that, jint arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, UnlockPortBits_FUNC);
	rc = (jint)UnlockPortBits((GrafPtr)arg0);
	OS_NATIVE_EXIT(env, that, UnlockPortBits_FUNC);
	return rc;
}
#endif

#ifndef NO_UpdateControls
JNIEXPORT void JNICALL OS_NATIVE(UpdateControls)
	(JNIEnv *env, jclass that, jint arg0, jint arg1)
{
	OS_NATIVE_ENTER(env, that, UpdateControls_FUNC);
	UpdateControls((WindowRef)arg0, (RgnHandle)arg1);
	OS_NATIVE_EXIT(env, that, UpdateControls_FUNC);
}
#endif

#ifndef NO_UpdateDataBrowserItems
JNIEXPORT jint JNICALL OS_NATIVE(UpdateDataBrowserItems)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2, jintArray arg3, jint arg4, jint arg5)
{
	jint *lparg3=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, UpdateDataBrowserItems_FUNC);
	if (arg3) lparg3 = (*env)->GetIntArrayElements(env, arg3, NULL);
	rc = (jint)UpdateDataBrowserItems((ControlRef)arg0, (DataBrowserItemID)arg1, (UInt32)arg2, (const DataBrowserItemID *)lparg3, (DataBrowserPropertyID)arg4, (DataBrowserPropertyID)arg5);
	if (arg3) (*env)->ReleaseIntArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, UpdateDataBrowserItems_FUNC);
	return rc;
}
#endif

#ifndef NO_UpgradeScriptInfoToTextEncoding
JNIEXPORT jint JNICALL OS_NATIVE(UpgradeScriptInfoToTextEncoding)
	(JNIEnv *env, jclass that, jshort arg0, jshort arg1, jshort arg2, jbyteArray arg3, jintArray arg4)
{
	jbyte *lparg3=NULL;
	jint *lparg4=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, UpgradeScriptInfoToTextEncoding_FUNC);
	if (arg3) lparg3 = (*env)->GetByteArrayElements(env, arg3, NULL);
	if (arg4) lparg4 = (*env)->GetIntArrayElements(env, arg4, NULL);
	rc = (jint)UpgradeScriptInfoToTextEncoding(arg0, arg1, arg2, lparg3, lparg4);
	if (arg4) (*env)->ReleaseIntArrayElements(env, arg4, lparg4, 0);
	if (arg3) (*env)->ReleaseByteArrayElements(env, arg3, lparg3, 0);
	OS_NATIVE_EXIT(env, that, UpgradeScriptInfoToTextEncoding_FUNC);
	return rc;
}
#endif

#ifndef NO_WaitMouseMoved
JNIEXPORT jboolean JNICALL OS_NATIVE(WaitMouseMoved)
	(JNIEnv *env, jclass that, jobject arg0)
{
	Point _arg0, *lparg0=NULL;
	jboolean rc;
	OS_NATIVE_ENTER(env, that, WaitMouseMoved_FUNC);
	if (arg0) lparg0 = getPointFields(env, arg0, &_arg0);
	rc = (jboolean)WaitMouseMoved(*lparg0);
	if (arg0) setPointFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, WaitMouseMoved_FUNC);
	return rc;
}
#endif

#ifndef NO_X2Fix
JNIEXPORT jint JNICALL OS_NATIVE(X2Fix)
	(JNIEnv *env, jclass that, jdouble arg0)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, X2Fix_FUNC);
	rc = (jint)X2Fix(arg0);
	OS_NATIVE_EXIT(env, that, X2Fix_FUNC);
	return rc;
}
#endif

#ifndef NO_ZoomWindowIdeal
JNIEXPORT jint JNICALL OS_NATIVE(ZoomWindowIdeal)
	(JNIEnv *env, jclass that, jint arg0, jshort arg1, jobject arg2)
{
	Point _arg2, *lparg2=NULL;
	jint rc;
	OS_NATIVE_ENTER(env, that, ZoomWindowIdeal_FUNC);
	if (arg2) lparg2 = getPointFields(env, arg2, &_arg2);
	rc = (jint)ZoomWindowIdeal((WindowRef)arg0, (WindowPartCode)arg1, (Point *)lparg2);
	if (arg2) setPointFields(env, arg2, lparg2);
	OS_NATIVE_EXIT(env, that, ZoomWindowIdeal_FUNC);
	return rc;
}
#endif

#ifndef NO_kHIViewWindowContentID
JNIEXPORT jint JNICALL OS_NATIVE(kHIViewWindowContentID)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, kHIViewWindowContentID_FUNC);
	rc = (jint)&kHIViewWindowContentID;
	OS_NATIVE_EXIT(env, that, kHIViewWindowContentID_FUNC);
	return rc;
}
#endif

#ifndef NO_kPMDocumentFormatPDF
JNIEXPORT jint JNICALL OS_NATIVE(kPMDocumentFormatPDF)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, kPMDocumentFormatPDF_FUNC);
	rc = (jint)kPMDocumentFormatPDF;
	OS_NATIVE_EXIT(env, that, kPMDocumentFormatPDF_FUNC);
	return rc;
}
#endif

#ifndef NO_kPMGraphicsContextCoreGraphics
JNIEXPORT jint JNICALL OS_NATIVE(kPMGraphicsContextCoreGraphics)
	(JNIEnv *env, jclass that)
{
	jint rc;
	OS_NATIVE_ENTER(env, that, kPMGraphicsContextCoreGraphics_FUNC);
	rc = (jint)kPMGraphicsContextCoreGraphics;
	OS_NATIVE_EXIT(env, that, kPMGraphicsContextCoreGraphics_FUNC);
	return rc;
}
#endif

#ifndef NO_memcpy__III
JNIEXPORT void JNICALL OS_NATIVE(memcpy__III)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	OS_NATIVE_ENTER(env, that, memcpy__III_FUNC);
	memcpy((void *)arg0, (const void *)arg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__III_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_ATSUTab_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_ATSUTab_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	ATSUTab _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_ATSUTab_2I_FUNC);
	if (arg1) lparg1 = getATSUTabFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_ATSUTab_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_BitMap_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_BitMap_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	BitMap _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_BitMap_2I_FUNC);
	if (arg1) lparg1 = getBitMapFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_BitMap_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_Cursor_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_Cursor_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	Cursor _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_Cursor_2I_FUNC);
	if (arg1) lparg1 = getCursorFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_Cursor_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_EventRecord_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_EventRecord_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	EventRecord _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_EventRecord_2I_FUNC);
	if (arg1) lparg1 = getEventRecordFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_EventRecord_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	FontSelectionQDStyle _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2I_FUNC);
	if (arg1) lparg1 = getFontSelectionQDStyleFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_HMHelpContentRec_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_HMHelpContentRec_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	HMHelpContentRec _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_HMHelpContentRec_2I_FUNC);
	if (arg1) lparg1 = getHMHelpContentRecFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_HMHelpContentRec_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_PixMap_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_PixMap_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	PixMap _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_PixMap_2I_FUNC);
	if (arg1) lparg1 = getPixMapFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_PixMap_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_RGBColor_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_RGBColor_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	RGBColor _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_RGBColor_2I_FUNC);
	if (arg1) lparg1 = getRGBColorFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_RGBColor_2I_FUNC);
}
#endif

#ifndef NO_memcpy__ILorg_eclipse_swt_internal_carbon_Rect_2I
JNIEXPORT void JNICALL OS_NATIVE(memcpy__ILorg_eclipse_swt_internal_carbon_Rect_2I)
	(JNIEnv *env, jclass that, jint arg0, jobject arg1, jint arg2)
{
	Rect _arg1, *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_Rect_2I_FUNC);
	if (arg1) lparg1 = getRectFields(env, arg1, &_arg1);
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
	OS_NATIVE_EXIT(env, that, memcpy__ILorg_eclipse_swt_internal_carbon_Rect_2I_FUNC);
}
#endif

#ifndef NO_memcpy__I_3BI
JNIEXPORT void JNICALL OS_NATIVE(memcpy__I_3BI)
	(JNIEnv *env, jclass that, jint arg0, jbyteArray arg1, jint arg2)
{
	jbyte *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__I_3BI_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) lparg1 = (*env)->GetPrimitiveArrayCritical(env, arg1, NULL);
	} else
#endif
	{
		if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	}
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) (*env)->ReleasePrimitiveArrayCritical(env, arg1, lparg1, JNI_ABORT);
	} else
#endif
	{
		if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, JNI_ABORT);
	}
	OS_NATIVE_EXIT(env, that, memcpy__I_3BI_FUNC);
}
#endif

#ifndef NO_memcpy__I_3CI
JNIEXPORT void JNICALL OS_NATIVE(memcpy__I_3CI)
	(JNIEnv *env, jclass that, jint arg0, jcharArray arg1, jint arg2)
{
	jchar *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__I_3CI_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) lparg1 = (*env)->GetPrimitiveArrayCritical(env, arg1, NULL);
	} else
#endif
	{
		if (arg1) lparg1 = (*env)->GetCharArrayElements(env, arg1, NULL);
	}
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) (*env)->ReleasePrimitiveArrayCritical(env, arg1, lparg1, JNI_ABORT);
	} else
#endif
	{
		if (arg1) (*env)->ReleaseCharArrayElements(env, arg1, lparg1, JNI_ABORT);
	}
	OS_NATIVE_EXIT(env, that, memcpy__I_3CI_FUNC);
}
#endif

#ifndef NO_memcpy__I_3II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__I_3II)
	(JNIEnv *env, jclass that, jint arg0, jintArray arg1, jint arg2)
{
	jint *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__I_3II_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) lparg1 = (*env)->GetPrimitiveArrayCritical(env, arg1, NULL);
	} else
#endif
	{
		if (arg1) lparg1 = (*env)->GetIntArrayElements(env, arg1, NULL);
	}
	memcpy((void *)arg0, (const void *)lparg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) (*env)->ReleasePrimitiveArrayCritical(env, arg1, lparg1, JNI_ABORT);
	} else
#endif
	{
		if (arg1) (*env)->ReleaseIntArrayElements(env, arg1, lparg1, JNI_ABORT);
	}
	OS_NATIVE_EXIT(env, that, memcpy__I_3II_FUNC);
}
#endif

#ifndef NO_memcpy__Lorg_eclipse_swt_internal_carbon_ATSTrapezoid_2II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__Lorg_eclipse_swt_internal_carbon_ATSTrapezoid_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	ATSTrapezoid _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_ATSTrapezoid_2II_FUNC);
	if (arg0) lparg0 = &_arg0;
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
	if (arg0) setATSTrapezoidFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_ATSTrapezoid_2II_FUNC);
}
#endif

#ifndef NO_memcpy__Lorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__Lorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	FontSelectionQDStyle _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2II_FUNC);
	if (arg0) lparg0 = &_arg0;
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
	if (arg0) setFontSelectionQDStyleFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_FontSelectionQDStyle_2II_FUNC);
}
#endif

#ifndef NO_memcpy__Lorg_eclipse_swt_internal_carbon_GDevice_2II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__Lorg_eclipse_swt_internal_carbon_GDevice_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	GDevice _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_GDevice_2II_FUNC);
	if (arg0) lparg0 = &_arg0;
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
	if (arg0) setGDeviceFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_GDevice_2II_FUNC);
}
#endif

#ifndef NO_memcpy__Lorg_eclipse_swt_internal_carbon_HMHelpContentRec_2II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__Lorg_eclipse_swt_internal_carbon_HMHelpContentRec_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	HMHelpContentRec _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_HMHelpContentRec_2II_FUNC);
	if (arg0) lparg0 = &_arg0;
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
	if (arg0) setHMHelpContentRecFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_HMHelpContentRec_2II_FUNC);
}
#endif

#ifndef NO_memcpy__Lorg_eclipse_swt_internal_carbon_PixMap_2II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__Lorg_eclipse_swt_internal_carbon_PixMap_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	PixMap _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_PixMap_2II_FUNC);
	if (arg0) lparg0 = &_arg0;
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
	if (arg0) setPixMapFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_PixMap_2II_FUNC);
}
#endif

#ifndef NO_memcpy__Lorg_eclipse_swt_internal_carbon_Rect_2II
JNIEXPORT void JNICALL OS_NATIVE(memcpy__Lorg_eclipse_swt_internal_carbon_Rect_2II)
	(JNIEnv *env, jclass that, jobject arg0, jint arg1, jint arg2)
{
	Rect _arg0, *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_Rect_2II_FUNC);
	if (arg0) lparg0 = &_arg0;
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
	if (arg0) setRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, memcpy__Lorg_eclipse_swt_internal_carbon_Rect_2II_FUNC);
}
#endif

#ifndef NO_memcpy___3BII
JNIEXPORT void JNICALL OS_NATIVE(memcpy___3BII)
	(JNIEnv *env, jclass that, jbyteArray arg0, jint arg1, jint arg2)
{
	jbyte *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy___3BII_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL);
	} else
#endif
	{
		if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
	}
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	}
	OS_NATIVE_EXIT(env, that, memcpy___3BII_FUNC);
}
#endif

#ifndef NO_memcpy___3B_3CI
JNIEXPORT void JNICALL OS_NATIVE(memcpy___3B_3CI)
	(JNIEnv *env, jclass that, jbyteArray arg0, jcharArray arg1, jint arg2)
{
	jbyte *lparg0=NULL;
	jchar *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy___3B_3CI_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL);
		if (arg1) lparg1 = (*env)->GetPrimitiveArrayCritical(env, arg1, NULL);
	} else
#endif
	{
		if (arg0) lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL);
		if (arg1) lparg1 = (*env)->GetCharArrayElements(env, arg1, NULL);
	}
	memcpy((void *)lparg0, (const void *)lparg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) (*env)->ReleasePrimitiveArrayCritical(env, arg1, lparg1, JNI_ABORT);
		if (arg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg1) (*env)->ReleaseCharArrayElements(env, arg1, lparg1, JNI_ABORT);
		if (arg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
	}
	OS_NATIVE_EXIT(env, that, memcpy___3B_3CI_FUNC);
}
#endif

#ifndef NO_memcpy___3CII
JNIEXPORT void JNICALL OS_NATIVE(memcpy___3CII)
	(JNIEnv *env, jclass that, jcharArray arg0, jint arg1, jint arg2)
{
	jchar *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy___3CII_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL);
	} else
#endif
	{
		if (arg0) lparg0 = (*env)->GetCharArrayElements(env, arg0, NULL);
	}
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg0) (*env)->ReleaseCharArrayElements(env, arg0, lparg0, 0);
	}
	OS_NATIVE_EXIT(env, that, memcpy___3CII_FUNC);
}
#endif

#ifndef NO_memcpy___3C_3BI
JNIEXPORT void JNICALL OS_NATIVE(memcpy___3C_3BI)
	(JNIEnv *env, jclass that, jcharArray arg0, jbyteArray arg1, jint arg2)
{
	jchar *lparg0=NULL;
	jbyte *lparg1=NULL;
	OS_NATIVE_ENTER(env, that, memcpy___3C_3BI_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL);
		if (arg1) lparg1 = (*env)->GetPrimitiveArrayCritical(env, arg1, NULL);
	} else
#endif
	{
		if (arg0) lparg0 = (*env)->GetCharArrayElements(env, arg0, NULL);
		if (arg1) lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL);
	}
	memcpy((void *)lparg0, (const void *)lparg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg1) (*env)->ReleasePrimitiveArrayCritical(env, arg1, lparg1, JNI_ABORT);
		if (arg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, JNI_ABORT);
		if (arg0) (*env)->ReleaseCharArrayElements(env, arg0, lparg0, 0);
	}
	OS_NATIVE_EXIT(env, that, memcpy___3C_3BI_FUNC);
}
#endif

#ifndef NO_memcpy___3FII
JNIEXPORT void JNICALL OS_NATIVE(memcpy___3FII)
	(JNIEnv *env, jclass that, jfloatArray arg0, jint arg1, jint arg2)
{
	jfloat *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy___3FII_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL);
	} else
#endif
	{
		if (arg0) lparg0 = (*env)->GetFloatArrayElements(env, arg0, NULL);
	}
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg0) (*env)->ReleaseFloatArrayElements(env, arg0, lparg0, 0);
	}
	OS_NATIVE_EXIT(env, that, memcpy___3FII_FUNC);
}
#endif

#ifndef NO_memcpy___3III
JNIEXPORT void JNICALL OS_NATIVE(memcpy___3III)
	(JNIEnv *env, jclass that, jintArray arg0, jint arg1, jint arg2)
{
	jint *lparg0=NULL;
	OS_NATIVE_ENTER(env, that, memcpy___3III_FUNC);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) lparg0 = (*env)->GetPrimitiveArrayCritical(env, arg0, NULL);
	} else
#endif
	{
		if (arg0) lparg0 = (*env)->GetIntArrayElements(env, arg0, NULL);
	}
	memcpy((void *)lparg0, (const void *)arg1, (size_t)arg2);
#ifdef JNI_VERSION_1_2
	if (IS_JNI_1_2) {
		if (arg0) (*env)->ReleasePrimitiveArrayCritical(env, arg0, lparg0, 0);
	} else
#endif
	{
		if (arg0) (*env)->ReleaseIntArrayElements(env, arg0, lparg0, 0);
	}
	OS_NATIVE_EXIT(env, that, memcpy___3III_FUNC);
}
#endif

#ifndef NO_memset
JNIEXPORT void JNICALL OS_NATIVE(memset)
	(JNIEnv *env, jclass that, jint arg0, jint arg1, jint arg2)
{
	OS_NATIVE_ENTER(env, that, memset_FUNC);
	memset((void *)arg0, arg1, arg2);
	OS_NATIVE_EXIT(env, that, memset_FUNC);
}
#endif

