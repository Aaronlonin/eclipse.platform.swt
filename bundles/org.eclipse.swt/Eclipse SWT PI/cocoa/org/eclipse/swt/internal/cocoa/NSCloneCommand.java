package org.eclipse.swt.internal.cocoa;

public class NSCloneCommand extends NSScriptCommand {

public NSCloneCommand() {
	super();
}

public NSCloneCommand(int id) {
	super(id);
}

public NSScriptObjectSpecifier keySpecifier() {
	int result = OS.objc_msgSend(this.id, OS.sel_keySpecifier);
	return result != 0 ? new NSScriptObjectSpecifier(result) : null;
}

public void setReceiversSpecifier(NSScriptObjectSpecifier receiversRef) {
	OS.objc_msgSend(this.id, OS.sel_setReceiversSpecifier_1, receiversRef != null ? receiversRef.id : 0);
}

}
