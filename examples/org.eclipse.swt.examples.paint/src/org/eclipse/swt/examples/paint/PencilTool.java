package org.eclipse.swt.examples.paint;

/*
 * (c) Copyright IBM Corp. 2000, 2002.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.graphics.*;

/**
 * A pencil tool.
 */
public class PencilTool extends ContinuousPaintSession implements PaintTool {
	private ToolSettings settings;
	
	/**
	 * Constructs a pencil tool.
	 * 
	 * @param toolSettings the new tool settings
	 * @param getPaintSurface() the PaintSurface we will render on.
	 */
	public PencilTool(ToolSettings toolSettings, PaintSurface paintSurface) {
		super(paintSurface);
		set(toolSettings);
	}
	
	/**
	 * Sets the tool's settings.
	 * 
	 * @param toolSettings the new tool settings
	 */
	public void set(ToolSettings toolSettings) {
		settings = toolSettings;
	}

	/**
	 * Returns the name associated with this tool.
	 * 
	 * @return the localized name of this tool
	 */
	public String getDisplayName() {
		return PaintPlugin.getResourceString("tool.Pencil.label");
	}

	/*
	 * Template method for drawing
	 */
	public void render(final Point point) {
		final PaintSurface ps = getPaintSurface();
		ps.drawFigure(new PointFigure(settings.commonForegroundColor, point.x, point.y));
	}
}
