package org.eclipse.swt.internal.image;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.*;

class PngIdatChunk extends PngChunk {

PngIdatChunk(byte[] reference){
	super(reference);
}

/**
 * Answer whether the chunk is a valid IDAT chunk.
 */
void validate(PngFileReadState readState, PngIhdrChunk headerChunk) {
	if (!readState.readIHDR
		|| (headerChunk.getMustHavePalette() && !readState.readPLTE)
		|| readState.readIEND) 
	{
		SWT.error(SWT.ERROR_INVALID_IMAGE);
	} else {
		readState.readIDAT = true;
	}
	
	super.validate(readState, headerChunk);
}

byte getDataByteAtOffset(int offset) {
	return reference[DATA_OFFSET + offset];
}

}
