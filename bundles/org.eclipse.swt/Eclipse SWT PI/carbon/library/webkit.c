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

#include <Carbon/Carbon.h>
#include <WebKit/WebKit.h>
#include <WebKit/HIWebView.h>

#include "jni.h"

JNIEXPORT void JNICALL Java_org_eclipse_swt_browser_WebKit_WebInitForCarbon(JNIEnv *env, jclass zz) {
	WebInitForCarbon();
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_HIWebViewCreate(JNIEnv *env, jclass zz, jintArray outView) {
	jint *a = (*env)->GetIntArrayElements(env, outView, NULL);
	jint status = (jint) HIWebViewCreate((HIViewRef *)a);
	(*env)->ReleaseIntArrayElements(env, outView, a, 0);
	return status;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_HIWebViewGetWebView(JNIEnv *env, jclass zz, jint viewRef) {
	return (jint) HIWebViewGetWebView((HIViewRef)viewRef);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_objc_1msgSend__II(JNIEnv *env, jclass zz, jint obj, jint sel) {
	return (jint) objc_msgSend((void *)obj, (void *)sel);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_objc_1msgSend__III(JNIEnv *env, jclass zz, jint obj, jint sel, jint arg0) {
	return (jint) objc_msgSend((void *)obj, (void *)sel, (void *)arg0);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_objc_1msgSend__IIII(JNIEnv *env, jclass zz, jint obj, jint sel, jint arg0, jint arg1) {
	return (jint) objc_msgSend((void *)obj, (void *)sel, (void *)arg0, (void *)arg1);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_objc_1msgSend__IIIII(JNIEnv *env, jclass zz, jint obj, jint sel, jint arg0, jint arg1, jint arg2) {
	return (jint) objc_msgSend((void *)obj, (void *)sel, (void *)arg0, (void *)arg1, (void *)arg2);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_objc_1msgSend__IIIIII(JNIEnv *env, jclass zz, jint obj, jint sel, jint arg0, jint arg1, jint arg2, jint arg3) {
	return (jint) objc_msgSend((void *)obj, (void *)sel, (void *)arg0, (void *)arg1, (void *)arg2, (void *)arg3);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_objc_1getClass(JNIEnv *env, jclass zz, jbyteArray name) {
	jbyte *a = (*env)->GetByteArrayElements(env, name, NULL);
	jint id = (jint) objc_getClass((const char *)a);
	(*env)->ReleaseByteArrayElements(env, name, a, 0);
	return id;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_browser_WebKit_sel_1registerName(JNIEnv *env, jclass zz, jbyteArray name) {
	jbyte *a= (*env)->GetByteArrayElements(env, name, NULL);
	jint sel= (jint) sel_registerName((const char *)a);
	(*env)->ReleaseByteArrayElements(env, name, a, 0);
	return sel;
}

@interface WebKitDelegate : NSObject
{
	int (*proc) (int sender, int selector, int arg0, int arg1, int arg2, int arg3);
}
@end

@implementation WebKitDelegate

- (id)initWithProc:(id)prc
{
    [super init];
    proc= (void *) prc;
    return self;
}

/* WebFrameLoadDelegate */

- (void)webView:(WebView *)sender didFailProvisionalLoadWithError:(NSError *)error forFrame:(WebFrame *)frame
{
	proc((int)sender, 1, (int)error, (int)frame, 0, 0);
}

- (void)webView:(WebView *)sender didFinishLoadForFrame:(WebFrame *)frame
{
	proc((int)sender, 2, (int)frame, 0, 0, 0);
}

- (void)webView:(WebView *)sender didReceiveTitle:(NSString *)title forFrame:(WebFrame *)frame
{
	proc((int)sender, 3, (int)title, (int)frame, 0, 0);
}

- (void)webView:(WebView *)sender didStartProvisionalLoadForFrame:(WebFrame *)frame
{
	proc((int)sender, 4, (int)frame, 0, 0, 0);
}

- (void)webView:(WebView *)sender didCommitLoadForFrame:(WebFrame *)frame
{
	proc((int)sender, 10, (int)frame, 0, 0, 0);
}

/* WebResourceLoadDelegate */

- (void)webView:(WebView *)sender resource:(id)identifier didFinishLoadingFromDataSource:(WebDataSource *)dataSource
{
	proc((int)sender, 5, (int)identifier, (int)dataSource, 0, 0);
}

- (void)webView:(WebView *)sender resource:(id)identifier didFailLoadingWithError:(NSError *)error fromDataSource:(WebDataSource *)dataSource
{
	proc((int)sender, 6, (int)identifier, (int)error, (int)dataSource, 0);
}

- (id)webView:(WebView *)sender identifierForInitialRequest:(NSURLRequest *)request fromDataSource:(WebDataSource *)dataSource
{
    return (id) proc((int)sender, 7, (int)request, (int)dataSource, 0, 0);    
}

- (NSURLRequest *)webView:(WebView *)sender resource:(id)identifier willSendRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirectResponse fromDataSource:(WebDataSource *)dataSource
{
	return (NSURLRequest *) proc((int)sender, 8, (int)identifier, (int)request, (int)redirectResponse, (int)dataSource);
}

/* handleNotification */

- (void)handleNotification:(NSNotification *)notification
{
	proc((int)[notification object], 9, (int)notification, 0, 0, 0);
}

/* UIDelegate */

- (WebView *)webView:(WebView *)sender createWebViewWithRequest:(NSURLRequest *)request
{
	return (WebView *) proc((int)sender, 11, (int)request, 0, 0, 0);
}

- (void)webViewShow:(WebView *)sender
{
	proc((int)sender, 12, 0, 0, 0, 0);
}

- (void)webView:(WebView *)sender setFrame:(NSRect)frame
{
	proc((int)sender, 13, (int)&frame, 0, 0, 0);
}

- (void)webViewClose:(WebView *)sender
{
	proc((int)sender, 14, 0, 0, 0, 0);
}

- (NSArray *)webView:(WebView *)sender contextMenuItemsForElement:(NSDictionary *)element defaultMenuItems:(NSArray *)defaultMenuItems
{
	return (NSArray *)proc((int)sender, 15, (int)element, (int)defaultMenuItems, 0, 0);
}

@end

