package org.eclipse.swt.internal;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

public class Library {

	/* SWT Version - Mmmm (M=major, mmm=minor) */
	
	/**
	 * SWT Major version number (must be >= 0)
	 */
	static int MAJOR_VERSION = 2;
	
	/**
	 * SWT Minor version number (must be in the range 0..999)
	 */
	static int MINOR_VERSION = 35;
	
	/**
	 * SWT revision number (must be >= 0)
	 */
	static int REVISION = 0;

/**
 * Returns the SWT version as an integer in the standard format
 * <em>Mmmm</em> where <em>M</em> is the major version number
 * and <em>mmm</em> is the minor version number.
 *
 * @return the version of the currently running SWT
 */
public static int getVersion () {
	return MAJOR_VERSION * 1000 + MINOR_VERSION;
}

/**
 * Returns the SWT revision number as an integer. Revision changes
 * occur as a result of non-API breaking bug fixes.
 *
 * @return the revision number of the currently running SWT
 */
public static int getRevision () {
	return REVISION;
}

/**
 * Loads the shared library that matches the version of the
 * Java code which is currently running.  SWT shared libraries
 * follow an encoding scheme where the major, minor and revision
 * numbers are embedded in the library name and this along with
 * <code>name</code> is used to load the library.  If this fails,
 * <code>name</code> is used in another attempt to load the library,
 * this time ignoring the SWT version encoding scheme.
 *
 * @param name the name of the library to load
 */
public static void loadLibrary (String name) {
}

}

