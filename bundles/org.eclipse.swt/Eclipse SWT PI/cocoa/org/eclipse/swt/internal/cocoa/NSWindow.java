package org.eclipse.swt.internal.cocoa;

public class NSWindow extends NSObject {

public NSWindow() {
	super(0);
}

public NSWindow(int id) {
	super(id);
}

public int get_class() {
	return OS.class_NSWindow;
}

public NSWindow initWithContentRect(NSRect rect, int styleMask, int backing, boolean defer) {
	id = OS.objc_msgSend(id, OS.sel_initWithContentRect_1styleMask_1backing_1defer_1, rect, styleMask, backing, defer);
	return this;
}

public void makeKeyAndOrderFront(NSObject sender) {
	OS.objc_msgSend(id, OS.sel_makeKeyAndOrderFront_1, sender != null ? sender.id : 0);
}

public void setDelegate(NSObject delegate) {
	OS.objc_msgSend(id, OS.sel_setDelegate_1, delegate != null ? delegate.id : 0);	
}

public NSObject contentView() {
	int id = OS.objc_msgSend(this.id, OS.sel_contentView);
	if (id == 0) return null;
	return new NSObject(id);
}
}
