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

/**
 * Interface to provide a callback mechanism to get information about images
 * when the application is moved from low dpi monitor to high dpi. This 
 * information will be used to render the higher resolution images
 * 
 * This interface needs to be implemented by client code and provide the image
 * information on demand. This interface provides a callback mechanism to the
 * client code to provide ImageData based on the OS as per the zoom
 * level. Client can have their own naming convention for various zoom levels
 * 
 * @since 3.104
 */
public interface ImageDataProvider {

	/**
	 * Method to retrieve ImageData for a particular zoom level this needs to
	 * be implemented on the client side
	 * 	
	 * This method should return an object of ImageData. If not available please
	 * fallback to image of 100% level and send its ImageData
	 * 
	 * @param zoom
	 *            value will be 100, 150 and 200.
	 * @return the ImageData of the image 
	 * @since 3.104
	 */
	public ImageData getImageData (int zoom);

}
