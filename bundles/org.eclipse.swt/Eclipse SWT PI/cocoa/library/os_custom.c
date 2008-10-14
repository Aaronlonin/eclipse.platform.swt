/*******************************************************************************
 * Copyright (c) 2000, 2007 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/

#include "swt.h"
#include "os_structs.h"
#include "os_stats.h"

#define OS_NATIVE(func) Java_org_eclipse_swt_internal_cocoa_OS_##func

#ifndef NO_JNIGetObject
JNIEXPORT jobject JNICALL OS_NATIVE(JNIGetObject)
	(JNIEnv *env, jclass that, jintLong arg0)
{
	jobject rc = 0;
	OS_NATIVE_ENTER(env, that, JNIGetObject_FUNC);
	rc = (jobject)arg0;
	OS_NATIVE_EXIT(env, that, JNIGetObject_FUNC);
	return rc;
}
#endif

#ifndef NO_NSIntersectionRect
JNIEXPORT void JNICALL OS_NATIVE(NSIntersectionRect)
	(JNIEnv *env, jclass that, jobject arg0, jobject arg1, jobject arg2)
{
	NSRect _arg0, *lparg0=NULL;
	NSRect _arg1, *lparg1=NULL;
	NSRect _arg2, *lparg2=NULL;
	OS_NATIVE_ENTER(env, that, NSIntersectionRect_FUNC);
	if (arg0) if ((lparg0 = getNSRectFields(env, arg0, &_arg0)) == NULL) goto fail;
	if (arg1) if ((lparg1 = getNSRectFields(env, arg1, &_arg1)) == NULL) goto fail;
	if (arg2) if ((lparg2 = getNSRectFields(env, arg2, &_arg2)) == NULL) goto fail;
	*lparg0 = NSIntersectionRect(*lparg1, *lparg2);
fail:
	if (arg2 && lparg2) setNSRectFields(env, arg2, lparg2);
	if (arg1 && lparg1) setNSRectFields(env, arg1, lparg1);
	if (arg0 && lparg0) setNSRectFields(env, arg0, lparg0);
	OS_NATIVE_EXIT(env, that, NSIntersectionRect_FUNC);
}
#endif

#ifndef NO_drawRect_1CALLBACK
static jintLong drawRect_1CALLBACK;
static void drawRect(id obj, SEL sel, NSRect rect)
{
	return ((void (*)(id, SEL, NSRect*))drawRect_1CALLBACK)(obj, sel, &rect);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(drawRect_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	drawRect_1CALLBACK = func;
	return (jintLong)drawRect;
}
#endif

#ifndef NO_draggedImage_1endedAt_1operation_1CALLBACK
static jintLong draggedImage_1endedAt_1operation_1CALLBACK;
static void draggedImage_1endedAt_1operation(id obj, SEL sel, NSImage *image, NSPoint point, NSDragOperation op)
{
	return ((void (*)(id, SEL, NSImage *, NSPoint *, NSDragOperation))draggedImage_1endedAt_1operation_1CALLBACK)(obj, sel, image, &point, op);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(draggedImage_1endedAt_1operation_1CALLBACK)
(JNIEnv *env, jclass that, jintLong func)
{
	draggedImage_1endedAt_1operation_1CALLBACK = func;
	return (jintLong)draggedImage_1endedAt_1operation;
}
#endif

#ifndef NO_drawInteriorWithFrame_1inView_1CALLBACK
static jintLong drawInteriorWithFrame_1inView_1CALLBACK;
static void drawInteriorWithFrame_1inView(id obj, SEL sel, NSRect rect, NSView* view)
{
	return ((void (*)(id, SEL, NSRect*, NSView*))drawInteriorWithFrame_1inView_1CALLBACK)(obj, sel, &rect, view);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(drawInteriorWithFrame_1inView_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	drawInteriorWithFrame_1inView_1CALLBACK = func;
	return (jintLong)drawInteriorWithFrame_1inView;
}
#endif

#ifndef NO_setFrame_1CALLBACK
static jintLong setFrame_1CALLBACK;
static void setFrame(id obj, SEL sel, NSRect rect)
{
	return ((void (*)(id, SEL, NSRect*))setFrame_1CALLBACK)(obj, sel, &rect);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(setFrame_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	setFrame_1CALLBACK = func;
	return (jintLong)setFrame;
}
#endif

#ifndef NO_setFrameOrigin_1CALLBACK
static jintLong setFrameOrigin_1CALLBACK;
static void setFrameOrigin(id obj, SEL sel, NSPoint point)
{
	return ((void (*)(id, SEL, NSPoint*))setFrameOrigin_1CALLBACK)(obj, sel, &point);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(setFrameOrigin_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	setFrameOrigin_1CALLBACK = func;
	return (jintLong)setFrameOrigin;
}
#endif

#ifndef NO_setFrameSize_1CALLBACK
static jintLong setFrameSize_1CALLBACK;
static void setFrameSize(id obj, SEL sel, NSSize size)
{
	return ((void (*)(id, SEL, NSSize*))setFrameSize_1CALLBACK)(obj, sel, &size);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(setFrameSize_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	setFrameSize_1CALLBACK = func;
	return (jintLong)setFrameSize;
}
#endif

#ifndef NO_hitTest_1CALLBACK
static jintLong hitTest_1CALLBACK;
static void hitTest(id obj, SEL sel, NSPoint point)
{
	return ((void (*)(id, SEL, NSPoint*))hitTest_1CALLBACK)(obj, sel, &point);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(hitTest_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	hitTest_1CALLBACK = func;
	return (jintLong)hitTest;
}
#endif

#ifndef NO_highlightSelectionInClipRect_1CALLBACK
static jintLong highlightSelectionInClipRect_1CALLBACK;
static void highlightSelectionInClipRect(id obj, SEL sel, NSRect rect)
{
	return ((void (*)(id, SEL, NSRect*))highlightSelectionInClipRect_1CALLBACK)(obj, sel, &rect);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(highlightSelectionInClipRect_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	highlightSelectionInClipRect_1CALLBACK = func;
	return (jintLong)highlightSelectionInClipRect;
}
#endif

#ifndef NO_webView_1setFrame_1CALLBACK
static jintLong webView_1setFrame_1CALLBACK;
static void webView_1setFrame(id obj, SEL sel, WebView *sender, NSRect rect)
{
	return ((void (*)(id, SEL, WebView*, NSRect*))webView_1setFrame_1CALLBACK)(obj, sel, sender, &rect);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(webView_1setFrame_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	webView_1setFrame_1CALLBACK = func;
	return (jintLong)webView_1setFrame;
}
#endif

#ifndef NO_setMarkedText_1selectedRange_1CALLBACK
static jintLong setMarkedText_1selectedRange_1CALLBACK;
static void setMarkedText_1selectedRange(id obj, SEL sel, id *arg0, NSRange arg1)
{
	((void (*)(id, SEL, id*, NSRange*))setMarkedText_1selectedRange_1CALLBACK)(obj, sel, arg0, &arg1);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(setMarkedText_1selectedRange_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	setMarkedText_1selectedRange_1CALLBACK = func;
	return (jintLong)setMarkedText_1selectedRange;
}
#endif

#ifndef NO_selectedRange_1CALLBACK
static jintLong selectedRange_1CALLBACK;
static NSRange selectedRangeProc(id obj, SEL sel)
{
	NSRange* ptr = ((NSRange* (*)(id, SEL))selectedRange_1CALLBACK)(obj, sel);
	NSRange range = *ptr;
	free(ptr);
	return range;
}
JNIEXPORT jintLong JNICALL OS_NATIVE(selectedRange_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	selectedRange_1CALLBACK = func;
	return (jintLong)selectedRangeProc;
}
#endif

#ifndef NO_markedRange_1CALLBACK
static jintLong markedRange_1CALLBACK;
static NSRange markedRangeProc(id obj, SEL sel)
{
	NSRange* ptr = ((NSRange* (*)(id, SEL))markedRange_1CALLBACK)(obj, sel);
	NSRange range = *ptr;
	free(ptr);
	return range;
}
JNIEXPORT jintLong JNICALL OS_NATIVE(markedRange_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	markedRange_1CALLBACK = func;
	return (jintLong)markedRangeProc;
}
#endif

#ifndef NO_characterIndexForPoint_1CALLBACK
static jintLong characterIndexForPoint_1CALLBACK;
static int characterIndexForPoint(id obj, SEL sel, NSPoint point)
{
	return ((int (*)(id, SEL, NSPoint*))characterIndexForPoint_1CALLBACK)(obj, sel, &point);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(characterIndexForPoint_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	characterIndexForPoint_1CALLBACK = func;
	return (jintLong)characterIndexForPoint;
}
#endif

#ifndef NO_firstRectForCharacterRange_1CALLBACK
static jintLong firstRectForCharacterRange_1CALLBACK;
static NSRect firstRectForCharacterRangeProc(id obj, SEL sel, NSRange arg0)
{
	NSRect* ptr = ((NSRect* (*)(id, SEL, NSRange*))firstRectForCharacterRange_1CALLBACK)(obj, sel, &arg0);
	NSRect result = *ptr;
	free(ptr);
	return result;
}
JNIEXPORT jintLong JNICALL OS_NATIVE(firstRectForCharacterRange_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	firstRectForCharacterRange_1CALLBACK = func;
	return (jintLong)firstRectForCharacterRangeProc;
}
#endif

#ifndef NO_attributedSubstringFromRange_1CALLBACK
static jintLong attributedSubstringFromRange_1CALLBACK;
static id attributedSubstringFromRangeProc(id obj, SEL sel, NSRange arg0)
{
	return ((id (*)(id, SEL, NSRange*))attributedSubstringFromRange_1CALLBACK)(obj, sel, &arg0);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(attributedSubstringFromRange_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	attributedSubstringFromRange_1CALLBACK = func;
	return (jintLong)attributedSubstringFromRangeProc;
}
#endif

#ifndef NO_textView_1willChangeSelectionFromCharacterRange_1toCharacterRange_1CALLBACK
static jintLong textView_1willChangeSelectionFromCharacterRange_1toCharacterRange_1CALLBACK;
static NSRange textView_1willChangeSelectionFromCharacterRange_1toCharacterRange(id obj, SEL sel, NSTextView *aTextView, NSRange oldSelectedCharRange, NSRange newSelectedCharRange)
{
	NSRange* ptr = ((NSRange* (*)(id, SEL, NSTextView*, NSRange*, NSRange*))textView_1willChangeSelectionFromCharacterRange_1toCharacterRange_1CALLBACK)(obj, sel, aTextView, &oldSelectedCharRange, &newSelectedCharRange);
	NSRange result = *ptr;
	free(ptr);
	return result;
}
JNIEXPORT jintLong JNICALL OS_NATIVE(textView_1willChangeSelectionFromCharacterRange_1toCharacterRange_1CALLBACK)
	(JNIEnv *env, jclass that, jintLong func)
{
	textView_1willChangeSelectionFromCharacterRange_1toCharacterRange_1CALLBACK = func;
	return (jintLong)textView_1willChangeSelectionFromCharacterRange_1toCharacterRange;
}
#endif

#ifndef NO_NSZeroRect
JNIEXPORT jint JNICALL OS_NATIVE(NSZeroRect)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	OS_NATIVE_ENTER(env, that, NSZeroRect_FUNC);
	rc = (jint)&NSZeroRect;
	OS_NATIVE_EXIT(env, that, NSZeroRect_FUNC);
	return rc;
}
#endif

#ifndef NO_accessibilityHitTest_1CALLBACK
static jintLong accessibilityHitTest_1CALLBACK;
static void accessibilityHitTest(id obj, SEL sel, NSPoint point)
{
	return ((void (*)(id, SEL, NSPoint *))accessibilityHitTest_1CALLBACK)(obj, sel, &point);
}
JNIEXPORT jintLong JNICALL OS_NATIVE(accessibilityHitTest_1CALLBACK)
(JNIEnv *env, jclass that, jintLong func)
{
	accessibilityHitTest_1CALLBACK = func;
	return (jintLong)accessibilityHitTest;
}
#endif
