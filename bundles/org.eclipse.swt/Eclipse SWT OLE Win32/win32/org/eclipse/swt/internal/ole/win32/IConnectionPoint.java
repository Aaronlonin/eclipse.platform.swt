package org.eclipse.swt.internal.ole.win32;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */
public class IConnectionPoint extends IUnknown
{
public IConnectionPoint(int address) {
	super(address);
}
public int Advise(int pUnk, int[] pdwCookie) {
	return COM.VtblCall(5, address, pUnk, pdwCookie);
}
public int Unadvise(int dwCookie) {
	return COM.VtblCall(6, address, dwCookie);
}
}
