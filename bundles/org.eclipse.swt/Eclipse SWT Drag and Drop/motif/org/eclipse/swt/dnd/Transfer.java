package org.eclipse.swt.dnd;

/*
 * (c) Copyright IBM Corp. 2000, 2001, 2002.
 * All Rights Reserved
 */
 
import org.eclipse.swt.internal.Converter;
import org.eclipse.swt.internal.motif.OS;
import org.eclipse.swt.widgets.Display;

/**
 * <code>Transfer</code> provides a mechanism for converting between a java 
 * representation of data and a platform specific representation of data and 
 * vice versa.  It is used in data transfer operations such as drag and drop and 
 * clipboard copy/paste.
 *
 * <p>You should only need to become familiar with this class if you are 
 * implementing a Transfer subclass and you are unable to subclass the 
 * ByteArrayTransfer class.</p>
 * 
 * @see ByteArrayTransfer
 */
public abstract class Transfer {
/**
 * Returns a list of the platform specific data types that can be converted using 
 * this transfer agent.
 *
 * <p>Only the data type fields of the <code>TransferData</code> objects are filled 
 * in.</p>
 *
 * @return a list of the data types that can be converted using this transfer agent
 */
abstract public TransferData[] getSupportedTypes();
/**
 * Returns true if the <code>TransferData</code> data type can be converted 
 * using this transfer agent.
 *
 * @param transferData a platform specific description of a data type; only the data
 *  type fields of the <code>TransferData</code> object need to be filled in
 *
 * @return true if the transferData data type can be converted using this transfer 
 * agent
 */
abstract public boolean isSupportedType(TransferData transferData);
abstract protected String[] getTypeNames();
abstract protected int[] getTypeIds();
abstract protected void javaToNative (Object object, TransferData transferData);
abstract protected Object nativeToJava(TransferData transferData);
/**
 * Registers a name for a data type and returns the associated unique identifier.
 *
 * <p>You may register the same type more than once, the same unique identifier 
 * will be returned if the type has been previously registered.</p>
 *
 * <p>Note: On windows, do <b>not</b> call this method with pre-defined 
 * Clipboard Format types such as CF_TEXT or CF_BITMAP because the 
 * pre-defined identifier will not be returned</p>
 *
 * @param formatName the name of a data type
 *
 * @return the unique identifier associated with htis data type
 */
public static int registerType(String formatName){
	// Use default display because we don't have a particular widget
	int xDisplay = Display.getDefault().xDisplay;
	// Use the character encoding for the default locale
	byte[] buffer = Converter.wcsToMbcs (null, formatName, true);
	return OS.XmInternAtom (xDisplay, buffer, false); 
}
}
