package org.eclipse.swt.custom;
/*
 * Licensed Materials - Property of IBM,
 * (c) Copyright IBM Corp 2000, 2001
 */

/* Imports */
import org.eclipse.swt.events.*;
import org.eclipse.swt.graphics.*;

/**
 * This event is sent when a line is about to be drawn.
 */
public class LineBackgroundEvent extends TypedEvent {
	public int lineOffset;			// line start offset 
	public String lineText;			// line text
	public Color lineBackground;	// line background color
	
public LineBackgroundEvent(StyledTextEvent e) {
	super(e);
	lineOffset = e.detail;
	lineText = e.text;
}
}


