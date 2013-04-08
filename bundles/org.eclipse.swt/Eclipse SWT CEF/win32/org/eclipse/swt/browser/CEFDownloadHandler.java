/*******************************************************************************
 * Copyright (c) 2013 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.browser;


import org.eclipse.swt.graphics.Device;
import org.eclipse.swt.internal.cef3.*;

public class CEFDownloadHandler {
	CEF3Object object;
	int refCount = 1;
	CEF host;

public CEFDownloadHandler(CEF host) {
	super();
	this.host = host;
	object = new CEF3Object (new int[] {0, 0, 0, 4, 3}) {
		public long /*int*/ method0(long /*int*/[] args) {return add_ref();}
		public long /*int*/ method1(long /*int*/[] args) {return CEFDownloadHandler.this.release();}
		public long /*int*/ method2(long /*int*/[] args) {return get_refct();}
		public long /*int*/ method3(long /*int*/[] args) {return on_before_download(args[0], args[1], args[2], args[3]);}
		public long /*int*/ method4(long /*int*/[] args) {return on_download_updated(args[0], args[1], args[2]);}
	};
}

long /*int*/ getAddress () {
	return object.getAddress ();
}

/* cef_base_t */

synchronized int add_ref() {
	refCount++;
	return refCount;
}

synchronized int get_refct() {
	return refCount;
}

synchronized int release() {
	if (--refCount == 0) {
		if (Device.DEBUG) System.out.println("release: CEFDownloadHandler");
		if (object != null) {
			object.dispose ();
		}
		object = null;
	}
	return refCount;
}

/* cef_download_handler_t */


long /*int*/ on_before_download(long /*int*/ browser, long /*int*/ download_item, long /*int*/ suggested_name, long /*int*/ callback) {
	if (Device.DEBUG) System.out.println("on_before_download (impl)");
	CEFDownloadItem downloadItem = new CEFDownloadItem(download_item);
	final int id = downloadItem.getId();
	long /*int*/ pUrl = downloadItem.getUrl();
	final String url = CEF.ExtractCEFString(pUrl);
	CEF3.cef_string_userfree_free(pUrl);
	final String suggestedName = CEF.ExtractCEFString(suggested_name);
	final CEFBeforeDownloadCallback beforeDownloadCallback = new CEFBeforeDownloadCallback(callback);
	host.browser.getDisplay().asyncExec(new Runnable() {
		public void run() {
			if (host.browser.isDisposed()) return;
			host.createDownloadWindow(suggestedName, url, id);
			beforeDownloadCallback.cont(CEF.CEFSTRING_EMPTY, 1);
			beforeDownloadCallback.release();
		}
	});
	new CEFBase(browser).release();
	downloadItem.release();
	return 0;
}

long /*int*/ on_download_updated(long /*int*/ browser, long /*int*/ download_item, final long /*int*/ callback) {
	if (Device.DEBUG) System.out.println("on_download_updated (impl)");
	CEFDownloadItem downloadItem = new CEFDownloadItem(download_item);
	final long totalBytes = downloadItem.getTotalBytes();
	final long receivedBytes = downloadItem.getReceivedBytes();
	final boolean completed = downloadItem.isComplete() == 1;
	final boolean inProgress = downloadItem.isInProgress() == 1;
	final boolean cancelled = downloadItem.isCancelled() == 1;
	final CEFDownloadItemCallback downloadItemCallback = new CEFDownloadItemCallback(callback);
	final int id = downloadItem.getId();
	host.browser.getDisplay().asyncExec(new Runnable() {
		public void run() {
			if (host.browser.isDisposed()) return;
			host.onDownloadProgress(receivedBytes, totalBytes, completed, inProgress, cancelled, downloadItemCallback, id);
			downloadItemCallback.release();
		}
	});
	new CEFBase(browser).release();
	downloadItem.release();
	return 0;
}

}
