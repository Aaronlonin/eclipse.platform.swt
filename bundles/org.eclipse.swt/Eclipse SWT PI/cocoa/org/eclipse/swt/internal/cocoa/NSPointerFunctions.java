package org.eclipse.swt.internal.cocoa;

public class NSPointerFunctions extends NSObject {

public NSPointerFunctions() {
	super();
}

public NSPointerFunctions(int id) {
	super(id);
}

public id initWithOptions(int options) {
	int result = OS.objc_msgSend(this.id, OS.sel_initWithOptions_1, options);
	return result != 0 ? new id(result) : null;
}

public static id pointerFunctionsWithOptions(int options) {
	int result = OS.objc_msgSend(OS.class_NSPointerFunctions, OS.sel_pointerFunctionsWithOptions_1, options);
	return result != 0 ? new id(result) : null;
}

//public void setUsesStrongWriteBarrier(boolean ) {
//	OS.objc_msgSend(this.id, OS.sel_setUsesStrongWriteBarrier_1, );
//}
//
//public void setUsesWeakReadAndWriteBarriers(boolean ) {
//	OS.objc_msgSend(this.id, OS.sel_setUsesWeakReadAndWriteBarriers_1, );
//}

public boolean usesStrongWriteBarrier() {
	return OS.objc_msgSend(this.id, OS.sel_usesStrongWriteBarrier) != 0;
}

public boolean usesWeakReadAndWriteBarriers() {
	return OS.objc_msgSend(this.id, OS.sel_usesWeakReadAndWriteBarriers) != 0;
}

}
