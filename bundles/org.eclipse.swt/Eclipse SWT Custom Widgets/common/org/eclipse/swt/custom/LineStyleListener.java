package org.eclipse.swt.custom;
/*
 * Licensed Materials - Property of IBM,
 * (c) Copyright IBM Corp 2000, 2001
 */

/* Imports */
import java.util.*;

public interface LineStyleListener extends EventListener {
/**
 * This method is called when a line is about to be drawn in order to get the
 * line's style information.
 * <p>
 *
 * @param event.lineOffset line start offset (input)	
 * @param event.lineText line text (input)
 * @param event.styles array of StyleRanges, need to be in order (output)
 */
public void lineGetStyle(LineStyleEvent event);
}