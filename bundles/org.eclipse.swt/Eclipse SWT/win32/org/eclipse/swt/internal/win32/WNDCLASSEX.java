package org.eclipse.swt.internal.win32;

/*
 * Licensed Materials - Property of IBM,
 * WebSphere Studio Workbench
 * (c) Copyright IBM Corp 2000
 */
public class WNDCLASSEX {
	public int cbSize; 
	public int style; 
	public int lpfnWndProc; 
	public int cbClsExtra; 
	public int cbWndExtra; 
	public int hInstance; 
	public int hIcon; 
	public int hCursor; 
	public int hbrBackground; 
	public int lpszMenuName; 
	public int lpszClassName; 
	public int hIconSm;
	public static final int sizeof = 48;
}
