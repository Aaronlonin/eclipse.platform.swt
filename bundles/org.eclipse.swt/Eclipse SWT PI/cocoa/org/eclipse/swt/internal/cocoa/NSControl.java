package org.eclipse.swt.internal.cocoa;

public class NSControl extends NSView {
	
public NSControl(int id) {
	super(id);
}

public NSFont font() {
	int id = OS.objc_msgSend(this.id, OS.sel_font);
	return id != 0 ? new NSFont(id) : null;
}

public void setFont(NSFont font) {
	OS.objc_msgSend(id, OS.sel_setFont_1, font != null ? font.id : 0);
}
}
