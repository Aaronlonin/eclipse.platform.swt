package org.eclipse.swt.internal.ole.win32;

/*
 * Copyright (c) 2000, 2003 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */
 
import org.eclipse.swt.internal.win32.RECT;
 
public class IOleDocumentView extends IUnknown
{
public IOleDocumentView(int address) {
	super(address);
}

public int SetInPlaceSite(int pIPSite) {
	return COM.VtblCall(3, address, pIPSite);
}
public int SetRect(RECT prcView){
	return COM.VtblCall(6, address, prcView);
}
public int Show(int fShow ){
	return COM.VtblCall(9, address, fShow);
}
public int UIActivate(int fUIActivate){
	return COM.VtblCall(10, address, fUIActivate);
}
}
