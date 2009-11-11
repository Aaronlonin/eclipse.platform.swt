package org.eclipse.swt.accessibility;

import org.eclipse.swt.internal.win32.*;
import org.eclipse.swt.internal.ole.win32.*;

class Relation {
	Accessible accessible;
	COMObject objIAccessibleRelation = null;
	int refCount;
	int type;
	Accessible[] targets;
	static final String[] relationTypeString = {
		"controlledBy",		//$NON-NLS-1$
		"controllerFor",	//$NON-NLS-1$
		"describedBy",		//$NON-NLS-1$
		"descriptionFor",	//$NON-NLS-1$
		"embeddedBy",		//$NON-NLS-1$
		"embeds",			//$NON-NLS-1$
		"flowsFrom",		//$NON-NLS-1$
		"flowsTo",			//$NON-NLS-1$
		"labelFor",			//$NON-NLS-1$
		"labelledBy",		//$NON-NLS-1$
		"memberOf",			//$NON-NLS-1$
		"nodeChildOf",		//$NON-NLS-1$
		"parentWindowOf",	//$NON-NLS-1$
		"popupFor",			//$NON-NLS-1$
		"subwindowOf",		//$NON-NLS-1$
	};
	static final String[] localizedRelationTypeString = {
		"controlled by",
		"controller for",
		"described by",
		"description for",
		"embedded by",
		"embeds",
		"flows from",
		"flows to",
		"label for",
		"labelled by",
		"member of",
		"node child of",
		"parent window of",
		"popup for",
		"subwindow of",
	};

	Relation(Accessible accessible, int type) {
		this.accessible = accessible;
		this.type = type;
		this.targets = new Accessible[0];
	}
	
	/* QueryInterface([in] iid, [out] ppvObject)
	 * Ownership of ppvObject transfers from callee to caller so reference count on ppvObject 
	 * must be incremented before returning.  Caller is responsible for releasing ppvObject.
	 */
	int QueryInterface(COMObject comObject, int /*long*/ iid, int /*long*/ ppvObject) {
		GUID guid = new GUID();
		COM.MoveMemory(guid, iid, GUID.sizeof);

		if (COM.IsEqualGUID(guid, COM.IIDIUnknown)) {
			COM.MoveMemory(ppvObject, new int /*long*/[] { comObject.getAddress() }, OS.PTR_SIZEOF);
			AddRef();
			return COM.S_OK;
		}

		if (COM.IsEqualGUID(guid, COM.IIDIAccessibleRelation)) {
			COM.MoveMemory(ppvObject, new int /*long*/[] { objIAccessibleRelation.getAddress() }, OS.PTR_SIZEOF);
			AddRef();
			return COM.S_OK;
		}

		return COM.E_NOINTERFACE;
	}

	int AddRef() {
		if (refCount == 0) {
			/* Create the COMObject on the first AddRef. */
			objIAccessibleRelation = new COMObject(new int[] {2,0,0,1,1,1,2,3}) {
				public int /*long*/ method0(int /*long*/[] args) {return QueryInterface(objIAccessibleRelation, args[0], args[1]);}
				public int /*long*/ method1(int /*long*/[] args) {return AddRef();}
				public int /*long*/ method2(int /*long*/[] args) {return Release();}
				public int /*long*/ method3(int /*long*/[] args) {return get_relationType(args[0]);}
				public int /*long*/ method4(int /*long*/[] args) {return get_localizedRelationType(args[0]);}
				public int /*long*/ method5(int /*long*/[] args) {return get_nTargets(args[0]);}
				public int /*long*/ method6(int /*long*/[] args) {return get_target((int)/*64*/args[0], args[1]);}
				public int /*long*/ method7(int /*long*/[] args) {return get_targets((int)/*64*/args[0], args[1], args[2]);}
			};
		}
		refCount++;
		return refCount;
	}

	int Release() {
		refCount--;

		if (refCount == 0) {
			if (objIAccessibleRelation != null)
				objIAccessibleRelation.dispose();
			objIAccessibleRelation = null;
		}
		return refCount;
	}

	/* get_relationType([out] pbstrRelationType) */
	int get_relationType(int /*long*/ pbstrRelationType) {
		String relationType = relationTypeString[type];
		setString(pbstrRelationType, relationType);
		return COM.S_OK;
	}

	/* get_localizedRelationType([out] pbstrLocalizedRelationType) */
	int get_localizedRelationType(int /*long*/ pbstrLocalizedRelationType) {
		String localizedRelationType = localizedRelationTypeString[type]; // TODO: no.... set this at creation time
		setString(pbstrLocalizedRelationType, localizedRelationType);
		return COM.S_OK;
	}

	/* get_nTargets([out] pNTargets) */
	int get_nTargets(int /*long*/ pNTargets) {
		COM.MoveMemory(pNTargets, new int [] { targets.length }, 4);
		return COM.S_OK;
	}

	/* get_target([in] targetIndex, [out] ppTarget) */
	int get_target(int targetIndex, int /*long*/ ppTarget) {
		if (targetIndex < 0 || targetIndex > targets.length - 1) return COM.E_INVALIDARG;
		Accessible target = targets[targetIndex];
		if (target != null) {
			target.AddRef();
			setPtrVARIANT(ppTarget, COM.VT_DISPATCH, target.objIAccessible.getAddress());
		}
		return COM.S_OK;
	}

	/* get_targets([in] maxTargets, [out] ppTargets, [out] pNTargets) */
	int get_targets(int maxTargets, int /*long*/ ppTargets, int /*long*/ pNTargets) {
		// TODO: Fix this
//		AccessibleRelationEvent event = new AccessibleRelationEvent(this);
//		event.maxTargets = maxTargets;
//		for (int i = 0; i < accessibleRelationListeners.size(); i++) {
//			AccessibleRelationListener listener = (AccessibleRelationListener) accessibleRelationListeners.elementAt(i);
//			listener.getTargets(event);
//		}
//		Accessible accessible = event.targets;
//		if (accessible != null) {
//			accessible.AddRef();
//			setPtrVARIANT(ppTargets, COM.VT_DISPATCH, accessible.objIAccessible.getAddress());
//		}
//		COM.MoveMemory(pNTargets, new int [] { event.targetCount }, 4);
		return COM.S_OK;
		// TODO: @retval S_FALSE if there is nothing to return, nTargets is set to 0
	}

	void setString(int psz, String string) {
		char[] data = (string + "\0").toCharArray();
		int /*long*/ ptr = COM.SysAllocString(data);
		COM.MoveMemory(psz, new int /*long*/ [] { ptr }, OS.PTR_SIZEOF);
	}

	void setPtrVARIANT(int /*long*/ variant, short vt, int /*long*/ lVal) {
		if (vt == COM.VT_DISPATCH || vt == COM.VT_UNKNOWN) {
			COM.MoveMemory(variant, new short[] { vt }, 2);
			COM.MoveMemory(variant + 8, new int /*long*/[] { lVal }, OS.PTR_SIZEOF);
		}
	}

	void addTarget(Accessible target) {
		Accessible[] newTargets = new Accessible[targets.length + 1];
		System.arraycopy(targets, 0, newTargets, 0, targets.length);
		newTargets[targets.length] = target;
		targets = newTargets;
	}
}
