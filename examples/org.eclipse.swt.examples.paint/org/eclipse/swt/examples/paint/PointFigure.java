package org.eclipse.swt.examples.paint;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.graphics.*;

/**
 * 2D Point object
 */
public class PointFigure extends Figure {
	private Color color;
	private int x, y;
	/**
	 * Constructs a Point
	 * 
	 * @param color the color for this object
	 * @param x the virtual X coordinate of the first end-point
	 * @param y the virtual Y coordinate of the first end-point
	 */
	public PointFigure(Color color, int x, int y) {
		this.color = color; this.x = x; this.y = y;
	}
	public void draw(FigureDrawContext fdc) {
		Point p = fdc.toClientPoint(x, y);
		fdc.gc.setBackground(color);
		fdc.gc.fillRectangle(p.x, p.y, 1, 1);
	}
	public void addDamagedRegion(FigureDrawContext fdc, Region region) {
		region.add(fdc.toClientRectangle(x, y, x, y));
	}
}
