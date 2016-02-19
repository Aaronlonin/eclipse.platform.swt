/*******************************************************************************
 * Copyright (c) 2016 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.graphics;

import org.eclipse.swt.*;

/**
 * This class hold common constants and utility functions w.r.t. to SWT high DPI
 * functionality.
 *
 * @since 3.105
 */
public class DPIUtil {
	public static int DEVICE_ZOOM = 100;

	/* DPI Constants */
	static final int DPI_ZOOM_200 = 192;
	static final int DPI_ZOOM_150 = 144;

	private static boolean autoScale = true;

/**
 * Auto-scale down ImageData
 */
public static ImageData autoScaleDown (ImageData imageData) {
	if (!getAutoScale () || imageData == null) return imageData;
	float scaleFactor = getScalingFactor ();
	return scaleFactor == 1 ? imageData
			: imageData.scaledTo (Math.round ((float)imageData.width / scaleFactor), Math.round ((float)imageData.height / scaleFactor));
}

/**
 * Auto-scale down int dimensions.
 */
public static int autoScaleDown (int size) {
	if (!getAutoScale ()) return size;
	float scaleFactor = getScalingFactor ();
	return Math.round (size / scaleFactor);
}

/**
 * Auto-scale down float dimensions.
 */
public static float autoScaleDown (float size) {
	if (!getAutoScale ()) return size;
	float scaleFactor = getScalingFactor ();
	return size / scaleFactor;
}

/**
 * Auto-scale up float array dimensions.
 */
public static float[] autoScaleDown (float size[]) {
	if (!getAutoScale () || size == null) return size;
	float scaleFactor = getScalingFactor ();
	float scaledSize[] = new float[size.length];
	for (int i = 0; i < scaledSize.length; i++) {
		scaledSize[i] = size[i] / scaleFactor;
	}
	return scaledSize;
}

/**
 * Returns a new scaled down Point.
 */
public static Point autoScaleDown (Point point) {
	if (!getAutoScale () || point == null) return point;
	float scaleFactor = getScalingFactor ();
	if (scaleFactor == 1) return point;
	Point scaledPoint = new Point (0,0);
	scaledPoint.x = Math.round (point.x / scaleFactor);
	scaledPoint.y = Math.round (point.y / scaleFactor);
	return scaledPoint;
}

/**
 * Returns a new scaled down Rectangle.
 */
public static Rectangle autoScaleDown (Rectangle rect) {
	if (!getAutoScale () || rect == null) return rect;
	float scaleFactor = getScalingFactor ();
	if (scaleFactor == 1) return rect;
	Rectangle scaledRect = new Rectangle (0,0,0,0);
	scaledRect.x = Math.round (rect.x / scaleFactor);
	scaledRect.y = Math.round (rect.y / scaleFactor);
	scaledRect.width = Math.round (rect.width / scaleFactor);
	scaledRect.height = Math.round (rect.height / scaleFactor);
	return scaledRect;
}

/**
 * Auto-scale image with ImageData
 */
static ImageData autoScaleImageData (ImageData imageData, int targetZoom, int currentZoom) {
	if (!getAutoScale () || imageData == null || targetZoom == currentZoom) return imageData;
	float scaleFactor = ((float) targetZoom)/((float) currentZoom);
	return imageData.scaledTo (Math.round ((float)imageData.width * scaleFactor), Math.round ((float)imageData.height * scaleFactor));
}

/**
 * Auto-scale up ImageData
 */
public static ImageData autoScaleUp (ImageData imageData) {
	if (!getAutoScale () || imageData == null) return imageData;
	float scaleFactor = getScalingFactor ();
	return scaleFactor == 1 ? imageData
			: imageData.scaledTo (Math.round ((float)imageData.width * scaleFactor), Math.round ((float)imageData.height * scaleFactor));
}

/**
 * Auto-scale up int dimensions.
 */
public static int autoScaleUp (int size) {
	if (!getAutoScale ()) return size;
	float scaleFactor = getScalingFactor ();
	return Math.round (size * scaleFactor);
}

/**
 * Auto-scale up float dimensions.
 */
public static float autoScaleUp (float size) {
	if (!getAutoScale ()) return size;
	float scaleFactor = getScalingFactor ();
	return size * scaleFactor;
}

/**
 * Auto-scale up int array dimensions.
 */
public static int[] autoScaleUp (int size[]) {
	if (!getAutoScale () || size == null) return size;
	float scaleFactor = getScalingFactor ();
	int scaledSize[] = new int[size.length];
	for (int i = 0; i < scaledSize.length; i++) {
		scaledSize[i] = Math.round (size[i] * scaleFactor);
	}
	return scaledSize;
}

/**
 * Returns a new scaled up Point.
 */
public static Point autoScaleUp (Point point) {
	if (!getAutoScale () || point == null) return point;
	float scaleFactor = getScalingFactor ();
	if (scaleFactor == 1) return point;
	Point scaledPoint = new Point (0,0);
	scaledPoint.x = Math.round (point.x * scaleFactor);
	scaledPoint.y = Math.round (point.y * scaleFactor);
	return scaledPoint;
}

/**
 * Returns a new scaled up Rectangle.
 */
public static Rectangle autoScaleUp (Rectangle rect) {
	if (!getAutoScale () || rect == null) return rect;
	float scaleFactor = getScalingFactor ();
	if (scaleFactor == 1) return rect;
	Rectangle scaledRect = new Rectangle (0,0,0,0);
	scaledRect.x = Math.round (rect.x * scaleFactor);
	scaledRect.y = Math.round (rect.y * scaleFactor);
	scaledRect.width = Math.round (rect.width * scaleFactor);
	scaledRect.height = Math.round (rect.height * scaleFactor);
	return scaledRect;
}
public static boolean getAutoScale () {
	return autoScale;
}

/**
 * Returns an <code>ImageData</code> for specified zoom.
 */
static ImageData getImageData (Image image, int source_zoom, int target_zoom) {
	if (source_zoom == target_zoom) return image.getImageDataInPixels ();
	ImageData imageData = null;
	if (image.imageDataProvider != null) {
		boolean[] found = new boolean[1];
		imageData = DPIUtil.validateAndGetImageDataAtZoom (image.imageDataProvider, target_zoom, found);
		if (!found[0]) {
			imageData = DPIUtil.autoScaleImageData (imageData, target_zoom, 100);
		}
	} else if (image.imageFileNameProvider != null) {
		boolean[] found = new boolean[1];
		String filename = DPIUtil.validateAndGetImagePathAtZoom (image.imageFileNameProvider, target_zoom, found);
		if (!found[0]) {
			imageData = DPIUtil.autoScaleImageData (new ImageData(filename), target_zoom, 100);
		} else {
			imageData = new ImageData (filename);
		}
	} else {
		/* Get ImageData at currentZoom and scale it to specified zoom. */
		imageData = image.getImageDataInPixels ();
		imageData = DPIUtil.autoScaleImageData (imageData, target_zoom, source_zoom);
	}
	return imageData;
}

public static int getDeviceZoom() {
	return DEVICE_ZOOM;
}
public static void setDeviceZoom(int deviceZoom) {
	DEVICE_ZOOM = deviceZoom;
}

/**
 * Gets scaling factor for the current Image
 */
public static float getscalingFactor (Image image) {
	return ((float)DEVICE_ZOOM) / 100f;
}

/**
 * Returns Scaling factor from the display
 * @return float scaling factor
 */
public static float getScalingFactor () {
	float scalingFactor = 1;
	if (getAutoScale ()) {
		scalingFactor = ((float)DEVICE_ZOOM/100f);
	}
	return scalingFactor;
}

/**
 * Compute the zoom value based on the DPI value.
 *
 * @return zoom
 */
static int mapDPIToZoom (int dpi) {
	int zoom;
	if (dpi >= DPI_ZOOM_200) {
		zoom = 200;
	} else if (dpi >= DPI_ZOOM_150) {
		zoom = 150;
	} else {
		zoom = 100;
	}
	return zoom;
}
/**
 * Returns a new rectangle as per the scaleFactor.
 */
static Rectangle scale (Rectangle rect, int targetZoom, int currentZoom) {
	if (rect == null || targetZoom == currentZoom) return rect;
	float scaleFactor = ((float)targetZoom) / (float)currentZoom;
	Rectangle returnRect = new Rectangle (0,0,0,0);
	returnRect.x = Math.round (rect.x * scaleFactor);
	returnRect.y = Math.round (rect.y * scaleFactor);
	returnRect.width = Math.round (rect.width * scaleFactor);
	returnRect.height = Math.round (rect.height * scaleFactor);
	return returnRect;
}

/**
 * Gets Image data at specified zoom level, if image is missing then
 * fall-back to 100% image. If provider or fall-back image is not available,
 * throw error.
 */
static ImageData validateAndGetImageDataAtZoom (ImageDataProvider provider, int zoom, boolean[] found) {
	if (provider == null) SWT.error (SWT.ERROR_NULL_ARGUMENT);
	ImageData data = provider.getImageData (zoom);
	found [0] = (data != null);
	/* If image is null when (zoom != 100%), fall-back to image at 100% zoom */
	if (zoom != 100 && !found [0]) data = provider.getImageData (100);
	if (data == null) SWT.error (SWT.ERROR_INVALID_ARGUMENT);
	return data;
}

/**
 * Gets Image file path at specified zoom level, if image is missing then
 * fall-back to 100% image. If provider or fall-back image is not available,
 * throw error.
 */
static String validateAndGetImagePathAtZoom (ImageFileNameProvider provider, int zoom, boolean[] found) {
	if (provider == null) SWT.error (SWT.ERROR_NULL_ARGUMENT);
	String filename = provider.getImagePath (zoom);
	found [0] = (filename != null);
	/* If image is null when (zoom != 100%), fall-back to image at 100% zoom */
	if (zoom != 100 && !found [0]) filename = provider.getImagePath (100);
	if (filename == null) SWT.error (SWT.ERROR_INVALID_ARGUMENT);
	return filename;
}

/**
 * Auto-scale image with ImageFileName
 */
static ImageData autoScaleImageFileName (String filename, int targetZoom, int currentZoom) {
	if (filename == null) return null;
	ImageData imageData = new ImageData (filename);
	return autoScaleImageData (imageData, targetZoom, currentZoom);
}

}
