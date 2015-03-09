/*******************************************************************************
 * Copyright (c) 2015 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.graphics;

import java.io.*;

/**
 * This class hold common constants and utility functions w.r.t. to SWT high DPI
 * functionality.
 * 
 * @since 3.104
 */
public class DPIUtil {
	public static final char FILE_EXTENSION_SEPARATOR = '.';
	public static final String FILE_ONE_HALF_IDENTIFIER = "@1.5x";
	public static final String FILE_DOUBLE_IDENTIFIER = "@2x";
	public static final int SIZE = 3;

	/* DPI Constants */
	public static final int DPI_ZOOM_200 = 192;
	public static final int DPI_ZOOM_150 = 144;
	/**
	 * Prepare an array of Image filenames for various DPI levels.
	 * 
	 * @return String[] image filenames
	 */
	public static String[] getImageNames (String fileName) {
		if (fileName == null || fileName.trim().length() == 0)
			return new String[0];

		String[] fileNames = new String[SIZE];
		/* Adding the default fileName as-is */
		fileNames[0] = fileName;
		
		/* Creating high DPI fileNames as per pattern */
		int separatorLoc = fileName.lastIndexOf (FILE_EXTENSION_SEPARATOR);
		String name = (separatorLoc != -1) ? fileName.substring (0, separatorLoc) : fileName;
		String ext = (separatorLoc != -1) ? FILE_EXTENSION_SEPARATOR + fileName.substring (separatorLoc + 1) : "";
		fileNames[1] = name + FILE_ONE_HALF_IDENTIFIER + ext;
		fileNames[2] = name + FILE_DOUBLE_IDENTIFIER + ext;
		return fileNames;
	}

	/**
	 * Compute the imageSelector index based on the DPI value.
	 * 
	 * @return imageSelector index
	 */
	public static int mapDPIToImageSelectorIndex (int dpi) {
		int imageSelectorIndex;
		if (dpi >= DPI_ZOOM_200) {
			imageSelectorIndex = 2;
		} else if (dpi >= DPI_ZOOM_150) {
			imageSelectorIndex = 1;
		} else {
			imageSelectorIndex = 0;
		}
		return imageSelectorIndex;
	}

	/**
	 * Compute the imageSelector index based on the zoom value.
	 * 
	 * @return imageSelector index
	 */
	public static int mapZoomToImageSelectorIndex (int zoom) {
		int imageSelectorIndex = 0;
		if (zoom >= 200) {
			imageSelectorIndex = 2;
		}
		else if (zoom >= 150) {
			imageSelectorIndex = 1;
		}
		else {
			imageSelectorIndex = 0;
		}
		return imageSelectorIndex;
	}
	
	/**
	 * Checks if filename is a valid file.
	 * 
	 * @param filename String name of the file
	 * @return true if file exits
	 */
	public static boolean fileExists (String filename) {
		if (filename == null) {
			return false;
		}
		File file = new File (filename);
		if (( file.exists() ) && (!file.isDirectory())) {
			return true;
		}
		return false;
	}
}
