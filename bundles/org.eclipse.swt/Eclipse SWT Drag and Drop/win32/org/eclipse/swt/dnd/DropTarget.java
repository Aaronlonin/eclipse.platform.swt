package org.eclipse.swt.dnd;

/*
 * Licensed Materials - Property of IBM,
 * WebSphere Studio Workbench
 * (c) Copyright IBM Corp 2000
 */
import org.eclipse.swt.*;
import org.eclipse.swt.ole.win32.*;
import org.eclipse.swt.internal.ole.win32.*;
import org.eclipse.swt.graphics.*;
import org.eclipse.swt.widgets.*;
import org.eclipse.swt.internal.win32.*;

/**
 *
 * Class <code>DropTarget</code> defines the target object for a drag and drop transfer.
 *
 * IMPORTANT: This class is <em>not</em> intended to be subclassed.
 *
 * <p>This class identifies the <code>Control</code> over which the user must position the cursor
 * in order to drop the data being transferred.  It also specifies what data types can be dropped on 
 * this control and what operations can be performed.  You may have several DropTragets in an 
 * application but there can only be a one to one mapping between a <code>Control</code> and a <code>DropTarget</code>.
 * The DropTarget can receive data from within the same application or from other applications 
 * (such as text dragged from a text editor like Word).</p>
 *
 * <code><pre>
 *	int operations = DND.DROP_MOVE | DND.DROP_COPY | DND.DROP_LINK;
 *	Transfer[] types = new Transfer[] {TextTransfer.getInstance()};
 *	DropTarget target = new DropTarget(label, operations);
 *	target.setTransfer(types);
 * </code></pre>
 *
 * <p>The application is notified of data being dragged over this control and of when a drop occurs by 
 * implementing the interface <code>DropTargetListener</code> which uses the class 
 * <code>DropTargetEvent</code>.  The application can modify the type of drag being performed 
 * on this Control at any stage of the drag by modifying the <code>event.detail</code> field or the 
 * <code>event.currentDataType</code> field.  When the data is dropped, it is the responsibility of 
 * the application to copy this data for its own purposes.
 *
 * <code><pre>
 *	target.addDropListener (new DropTargetListener() {
 *		public void dragEnter(DropTargetEvent event) {};
 *		public void dragOver(DropTargetEvent event) {};
 *		public void dragLeave(DropTargetEvent event) {};
 *		public void dragOperationChanged(DropTargetEvent event) {};
 *		public void dropAccept(DropTargetEvent event) {}
 *		public void drop(DropTargetEvent event) {
 *			// A drop has occurred, copy over the data
 *			if (event.data == null) { // no data to copy, indicate failure in event.detail
 *				event.detail = DND.DROP_NONE;
 *				return;
 *			}
 *			label.setText ((String) event.data); // data copied to label text
 *		}
 * 	});
 * </pre></code>
 *
 * <dl>
 *	<dt><b>Styles</b> <dd>DND.DROP_NONE, DND.DROP_COPY, DND.DROP_MOVE, DND.DROP_LINK 
 *	<dt><b>Events</b> <dd>DND.DragEnter, DND.DragLeave, DND.DragOver, DND.DragOperationChanged, 
 *                        DND.Drop, DND.DropAccept
 * </dl>
 */

public class DropTarget extends Widget {

	
	// interfaces
	private COMObject iUnknown;
	private COMObject iDropTarget;

	// info for registering as a droptarget	
	private Control control;
	private Listener controlListener;

	private Transfer[] transferAgents = new Transfer[0];;

	private int refCount;

	// info about data being dragged over site
	private TransferData selectedDataType;
	private TransferData[] dataTypes;
	private int lastOperation;
	private int keyState;

	private DragUnderEffect effect;
	
	private int iDataObject;
	
/**
 * Creates a new <code>DropTarget</code> to handle dropping on the specified <code>Control</code>.
 * 
 * @param control the <code>Control</code> over which the user positions the cursor to drop data
 *
 * @param style the bitwise OR'ing of allowed operations; this may be a combination of any of 
 *					DND.DROP_NONE, DND.DROP_COPY, DND.DROP_MOVE, DND.DROP_LINK
 *
 */
public DropTarget(Control control, int style) {

	super (control, checkStyle(style));
	
	this.control = control;
	
	createCOMInterfaces();

	int result = 0;
	if ((result = COM.CoLockObjectExternal(iDropTarget.getAddress(), true, true)) != COM.S_OK)
		DND.error(DND.ERROR_CANNOT_INIT_DROP, result);
	if ((result = COM.RegisterDragDrop( control.handle, iDropTarget.getAddress() )) != COM.S_OK)
		DND.error(DND.ERROR_CANNOT_INIT_DROP, result);

	controlListener = new Listener () {
		public void handleEvent (Event event) {
			DropTarget.this.dispose();
		}
	};
	
	control.addListener (SWT.Dispose, controlListener);
	
	this.addListener (SWT.Dispose, new Listener () {
		public void handleEvent (Event event) {
			onDispose();
		}
	});

	if (control instanceof Tree) {
		effect = new TreeDragUnderEffect((Tree)control);
	} else if (control instanceof Table) {
		effect = new TableDragUnderEffect((Table)control);
	} else {
		effect = new NoDragUnderEffect(control);
	}
}
/**	 
 * Adds the listener to receive events.
 *
 * @param listener the listener
 *
 * @exception SWTError 
 *	<ul><li>ERROR_THREAD_INVALID_ACCESS when called from the wrong thread</li>
 * 		<li>ERROR_WIDGET_DISPOSED  when the widget has been disposed</li>
 * 		<li>ERROR_NULL_ARGUMENT when listener is null</li></ul>
 */
public void addDropListener(DropTargetListener listener) {	
	if (listener == null) DND.error (SWT.ERROR_NULL_ARGUMENT);
	DNDListener typedListener = new DNDListener (listener);
	addListener (DND.DragEnter, typedListener);
	addListener (DND.DragLeave, typedListener);
	addListener (DND.DragOver, typedListener);
	addListener (DND.DragOperationChanged, typedListener);
	addListener (DND.Drop, typedListener);
	addListener (DND.DropAccept, typedListener);

}
private int AddRef() {
	refCount++;
	return refCount;
}
static int checkStyle (int style) {
	if (style == SWT.NONE) return DND.DROP_MOVE;
	return style;
}
private void createCOMInterfaces() {
	// register each of the interfaces that this object implements
	iUnknown    = new COMObject(new int[]{2, 0, 0}){
		public int method0(int[] args) {return QueryInterface(args[0], args[1]);}
		public int method1(int[] args) {return AddRef();}
		public int method2(int[] args) {return Release();}
	};
	
	iDropTarget = new COMObject(new int[]{2, 0, 0, 5, 4, 0, 5}){
		public int method0(int[] args) {return QueryInterface(args[0], args[1]);}
		public int method1(int[] args) {return AddRef();}
		public int method2(int[] args) {return Release();}
		public int method3(int[] args) {return DragEnter(args[0], args[1], args[2], args[3], args[4]);}
		public int method4(int[] args) {return DragOver(args[0], args[1], args[2], args[3]);}
		public int method5(int[] args) {return DragLeave();}
		public int method6(int[] args) {return Drop(args[0], args[1], args[2], args[3], args[4]);}
	};

}
private void onDispose () {	
	if (control == null) return;

	COM.RevokeDragDrop(control.handle);
	
	if (controlListener != null)
		control.removeListener(SWT.Dispose, controlListener);
	controlListener = null;
	transferAgents = null;
	control = null;
	
	COM.CoLockObjectExternal(iDropTarget.getAddress(), false, true);
	
	this.Release();
	
	COM.CoFreeUnusedLibraries();
}
private void disposeCOMInterfaces() {
	
	if (iUnknown != null)
		iUnknown.dispose();
	iUnknown = null;
	
	if (iDropTarget != null)
		iDropTarget.dispose();
	iDropTarget = null;
}
private int DragEnter(  
	int pDataObject, //Pointer to the interface of the source data object
	int grfKeyState, //Current state of keyboard modifier keys
	int pt_x,        //Current cursor coordinates
	int pt_y,        //Current cursor coordinates
	int pdwEffect    //Pointer to the effect of the drag-and-drop operation
){
	
	selectedDataType = null;
	dataTypes = new TransferData[0];
	iDataObject = 0;
	lastOperation = DND.DROP_NONE;
	
	// Are any types being dragged for which we have a matching transfer object?
	// Get enumerator of dragged types
	IDataObject dataObject = new IDataObject(pDataObject);
	dataObject.AddRef();
	int[] address = new int[1];
	if (dataObject.EnumFormatEtc(COM.DATADIR_GET, address) != COM.S_OK){
		OS.MoveMemory(pdwEffect, new int[] {COM.DROPEFFECT_NONE}, 4);
		dataObject.Release();
		return COM.S_OK;
	}
	IEnumFORMATETC enum = new IEnumFORMATETC(address[0]);
	dataObject.Release();
	iDataObject = pDataObject;
	
	// Loop over enumerator and save any types that match what we are looking for
	int rgelt = OS.GlobalAlloc(OS.GMEM_FIXED | OS.GMEM_ZEROINIT, FORMATETC.sizeof);
	int[] pceltFetched = new int[1];
	enum.Reset();
	while (enum.Next(1, rgelt, pceltFetched) == COM.S_OK && pceltFetched[0] == 1) {
		TransferData transferData = new TransferData();
		transferData.formatetc = new FORMATETC();
		COM.MoveMemory(transferData.formatetc, rgelt, FORMATETC.sizeof);
		transferData.type = transferData.formatetc.cfFormat;
		
		for (int i = 0; i < transferAgents.length; i++){
			if (transferAgents[i].isSupportedType(transferData)){
				TransferData[] newDataTypes = new TransferData[dataTypes.length + 1];
				System.arraycopy(dataTypes, 0, newDataTypes, 0, dataTypes.length);
				newDataTypes[dataTypes.length] = transferData;
				dataTypes = newDataTypes;
				break;
			}
		}
	}
	OS.GlobalFree(rgelt);
	enum.Release();
	
	// give listeners a chance to have input
	DNDEvent event = new DNDEvent();
	event.widget = this;
	event.time = OS.GetMessageTime();
	event.x = pt_x;
	event.y = pt_y;
	event.dataTypes = dataTypes;
	event.feedback = DND.FEEDBACK_SELECT;
	int[] allowedEffects = new int[1];
	OS.MoveMemory(allowedEffects, pdwEffect, 4);
	allowedEffects[0] = osToOp(allowedEffects[0]);
	event.operations = allowedEffects[0];
	if (dataTypes.length > 0) {
		event.dataType = dataTypes[0];
		event.dataType.pIDataObject = pDataObject;
	}
	event.detail = DND.DROP_NONE;
	// assign operation if it is allowed
	keyState = osToOp(getOperationFromKeyState(grfKeyState));
	if ((keyState & getStyle()) == keyState){
		event.detail = keyState;
	}
	
	try {
		notifyListeners(DND.DragEnter,event);
	} catch (Throwable e) {
		OS.MoveMemory(pdwEffect, new int[] {COM.DROPEFFECT_NONE}, 4);
		return COM.S_OK;
	}
	
	for (int i = 0; i < dataTypes.length; i++) {
		if (dataTypes[i].equals(event.dataType)){
			selectedDataType = event.dataType;
			break;
		}
	}
	if (selectedDataType != null && ((allowedEffects[0] & event.detail) == event.detail)) {
		lastOperation = event.detail;
	}

	effect.show(event.feedback, event.x, event.y);
	
	OS.MoveMemory(pdwEffect, new int[] {opToOs(lastOperation)}, 4);
	return COM.S_OK;
}
private int DragLeave()
{
	effect.show(DND.FEEDBACK_NONE, 0, 0);
	keyState = DND.DROP_NONE;
	
	// give listeners a chance to react
	DNDEvent event = new DNDEvent();
	event.widget = this;
	event.time = OS.GetMessageTime();
	event.detail = DND.DROP_NONE;
	try {
		notifyListeners(DND.DragLeave, event);
	} catch (Throwable e) {}

	return COM.S_OK;
}
private int DragOver(  
	int grfKeyState, //Current state of keyboard modifier keys
	int pt_x,        //Current cursor coordinates
	int pt_y,
	int pdwEffect    //Pointer to the effect of the drag-and-drop operation
){
	DNDEvent event = new DNDEvent();
	event.widget = this;
	event.time = OS.GetMessageTime();
	event.x = pt_x;
	event.y = pt_y;
	event.dataTypes = dataTypes;
	event.feedback = DND.FEEDBACK_SELECT;
	int[] allowedEffects = new int[1];
	OS.MoveMemory(allowedEffects, pdwEffect, 4);
	allowedEffects[0] = osToOp(allowedEffects[0]);
	event.operations = allowedEffects[0];
	event.dataType = selectedDataType;
	if (event.dataType != null) {
		event.dataType.pIDataObject = iDataObject;
	}

	try {	
		int oldKeyState = keyState;
		keyState = osToOp(getOperationFromKeyState(grfKeyState));
		if (keyState == oldKeyState) {
			event.detail = lastOperation;
			// update with new drag over info
			notifyListeners(DND.DragOver,event);
		} else {
			event.detail = keyState;
			// operation has changed
			notifyListeners(DND.DragOperationChanged, event);
		}
	} catch (Throwable e) {
		OS.MoveMemory(pdwEffect, new int[] {COM.DROPEFFECT_NONE}, 4);
		return COM.S_OK;
	}

	// update drop data and drag under effect based on response from event	
	selectedDataType = null;
	for (int i = 0; i < dataTypes.length; i++) {
		if (dataTypes[i].equals(event.dataType)){
			selectedDataType = event.dataType;
			break;
		}
	}

	lastOperation = DND.DROP_NONE;
	if (selectedDataType != null && ((allowedEffects[0] & event.detail) == event.detail)) {
		lastOperation = event.detail;
	}
	
	effect.show(event.feedback, event.x, event.y);
	
	OS.MoveMemory(pdwEffect, new int[] {opToOs(lastOperation)}, 4);
	return COM.S_OK;
}
private int Drop(
	int pDataObject, //Pointer to the interface for the source data
	int grfKeyState, //Current state of keyboard modifier keys
	int pt_x,        //Current cursor coordinates
	int pt_y,
	int pdwEffect    //Pointer to the effect of the drag-and-drop operation
){
		
	effect.show(DND.FEEDBACK_NONE, 0, 0);
	keyState = DND.DROP_NONE;
	
	// Send a DragLeave event to be consistant with Motif
	DNDEvent event = new DNDEvent();
	event.widget = this;
	event.time = OS.GetMessageTime();
	event.detail = DND.DROP_NONE;
	try {
		notifyListeners(DND.DragLeave, event);
	} catch (Throwable e) {}

	// Send a DropAccept event to be consistant with Motif
	event = new DNDEvent();
	event.widget = this;
	event.time = OS.GetMessageTime();
	event.x = pt_x;
	event.y = pt_y;
	event.dataTypes = dataTypes;
	int[] allowedEffects = new int[1];
	OS.MoveMemory(allowedEffects, pdwEffect, 4);
	allowedEffects[0] = osToOp(allowedEffects[0]);
	event.operations = allowedEffects[0];		
	event.dataType = selectedDataType;
	if (event.dataType != null) {
		event.dataType.pIDataObject = iDataObject;
	}
	event.detail = lastOperation;

	try {
		notifyListeners(DND.DropAccept,event);
	} catch (Throwable e) {
		event.dataType = null;
		event.detail = DND.DROP_NONE;
	}

	selectedDataType = null;
	for (int i = 0; i < dataTypes.length; i++) {
		if (dataTypes[i].equals(event.dataType)){
			selectedDataType = event.dataType;
			break;
		}
	}
	lastOperation = DND.DROP_NONE;
	if (selectedDataType != null && (allowedEffects[0] & event.detail) == event.detail) {
		lastOperation = event.detail;
	}

	if (lastOperation != DND.DROP_NONE){
		// find the matching converter
		Transfer matchingTransfer = null;
		for (int i = 0; i < transferAgents.length; i++){
			if (transferAgents[i].isSupportedType(event.dataType)){
				matchingTransfer = transferAgents[i];
				break;
			}
		}
		if (matchingTransfer == null){
			lastOperation = DND.DROP_NONE;
		} else {
			event.dataType.pIDataObject = pDataObject;
			Object data = matchingTransfer.nativeToJava(event.dataType);
			event.data = data;
			try {
				notifyListeners(DND.Drop,event);
				lastOperation = DND.DROP_NONE;
				if ((allowedEffects[0] & event.detail) == event.detail) {
					lastOperation = event.detail;
				}
			} catch (Throwable e) {
				lastOperation = DND.DROP_NONE;
			}

		}
	}			
	
	OS.MoveMemory(pdwEffect, new int[] {osToOp(lastOperation)}, 4);	
	return COM.S_OK;
}
/**
 * Returns the Control which is registered for this DropTarget.  This is the control over which the 
 * user positions the cursor to drop the data.
 *
 * @return the Control which is registered for this DropTarget
 *
 */
public Control getControl () {
	return control;
}
public Display getDisplay () {

	if (control == null) DND.error(SWT.ERROR_WIDGET_DISPOSED);
	return control.getDisplay ();
}
private int getOperationFromKeyState(int grfKeyState) {
	boolean ctrl = (grfKeyState & OS.MK_CONTROL) != 0;
	boolean shift = (grfKeyState & OS.MK_SHIFT) != 0;
	if (ctrl && shift) { 
		// CTRL + SHIFT == Link
		return COM.DROPEFFECT_LINK;
	}
	if (ctrl){
		//CTRL == COPY
		return COM.DROPEFFECT_COPY;
	}

	return COM.DROPEFFECT_MOVE; // default operation
}
/**
 * Returns the list of data types that can be transferred to this DropTarget.
 *
 * @return the list of data types that can be transferred to this DropTarget
 *
 */ 
public Transfer[] getTransfer(){
	return transferAgents;
}
public void notifyListeners (int eventType, Event event) {
	Point coordinates = new Point(event.x, event.y);
	coordinates = control.toControl(coordinates);
	if (this.control instanceof Tree) {
		event.item = ((Tree)control).getItem(coordinates);
	}
	if (this.control instanceof Table) {
		event.item = ((Table)control).getItem(coordinates);
	}
	super.notifyListeners(eventType, event);
}
private int opToOs(int operation) {
	int osOperation = 0;
	if ((operation & DND.DROP_COPY) != 0){
		osOperation |= COM.DROPEFFECT_COPY;
	}
	if ((operation & DND.DROP_LINK) != 0) {
		osOperation |= COM.DROPEFFECT_LINK;
	}
	if ((operation & DND.DROP_MOVE) != 0) {
		osOperation |= COM.DROPEFFECT_MOVE;
	}
	return osOperation;
}
private int osToOp(int osOperation){
	int operation = 0;
	if ((osOperation & COM.DROPEFFECT_COPY) != 0){
		operation |= DND.DROP_COPY;
	}
	if ((osOperation & COM.DROPEFFECT_LINK) != 0) {
		operation |= DND.DROP_LINK;
	}
	if ((osOperation & COM.DROPEFFECT_MOVE) != 0) {
		operation |= DND.DROP_MOVE;
	}
	return operation;

}
private int QueryInterface(int riid, int ppvObject) {
	
	if (riid == 0 || ppvObject == 0)
		return COM.E_INVALIDARG;
	GUID guid = new GUID();
	COM.MoveMemory(guid, riid, GUID.sizeof);
	if (COM.IsEqualGUID(guid, COM.IIDIUnknown)) {
		COM.MoveMemory(ppvObject, new int[] {iUnknown.getAddress()}, 4);
		AddRef();
		return COM.S_OK;
	}
	if (COM.IsEqualGUID(guid, COM.IIDIDropTarget)) {
		COM.MoveMemory(ppvObject, new int[] {iDropTarget.getAddress()}, 4);
		AddRef();
		return COM.S_OK;
	}

	COM.MoveMemory(ppvObject, new int[] {0}, 4);
	return COM.E_NOINTERFACE;
}
private int Release() {
	refCount--;
	
	if (refCount == 0) {
		disposeCOMInterfaces();
		COM.CoFreeUnusedLibraries();
	}
	
	return refCount;
}
/**	 
 * Removes the listener.
 *
 * @param listener the listener
 *
 * @exception SWTError
 *	<ul><li>ERROR_THREAD_INVALID_ACCESS	when called from the wrong thread</li>
 * 		<li>ERROR_WIDGET_DISPOSED when the widget has been disposed</li>
 * 		<li>ERROR_NULL_ARGUMENT when listener is null</li></ul>
 */
public void removeDropListener(DropTargetListener listener) {	
	if (listener == null) DND.error (SWT.ERROR_NULL_ARGUMENT);
	removeListener (DND.DragEnter, listener);
	removeListener (DND.DragLeave, listener);
	removeListener (DND.DragOver, listener);
	removeListener (DND.DragOperationChanged, listener);
	removeListener (DND.Drop, listener);
	removeListener (DND.DropAccept, listener);
}
/**
 * Specifies the list of data types that can be transferred to this DropTarget.
 *
 * @param transferAgents a list of Transfer objects which define the types of data that can be
 *						 dropped on this target
 */
public void setTransfer(Transfer[] transferAgents){
	this.transferAgents = transferAgents;
}

protected void checkSubclass () {
	String name = getClass().getName ();
	String validName = DropTarget.class.getName();
	if (!validName.equals(name)) {
		DND.error (SWT.ERROR_INVALID_SUBCLASS);
	}
}
}
