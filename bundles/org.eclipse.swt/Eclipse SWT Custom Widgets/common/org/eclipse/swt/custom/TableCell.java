package org.eclipse.swt.custom;

/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */
 
import org.eclipse.swt.widgets.*;
import org.eclipse.swt.graphics.*;
import org.eclipse.swt.layout.*;
import org.eclipse.swt.*;

public class TableCell extends Composite {

	Table table;
	TableItem row;
	int column;
	Listener scrollListener;
	Listener tableListener;
	Listener columnListener;
	Image image;
	String text;
	boolean ctrlset = false;

public TableCell (Table table, int style) {
	super(table, style);
	this.table = table;
	
	setFont(table.getFont());
	setForeground(table.getForeground());
	setBackground(table.getBackground());
	
	scrollListener = new Listener() {
		public void handleEvent(Event e) {
			switch (e.type) {
				case SWT.Selection: {
					onScrollSelection(e); 
					break;
				}
			}
		}
	};
	ScrollBar hBar = table.getHorizontalBar ();
	if (hBar != null) hBar.addListener(SWT.Selection, scrollListener);
	ScrollBar vBar = table.getVerticalBar ();
	if (vBar != null) vBar.addListener(SWT.Selection, scrollListener);
	
	tableListener = new Listener() {
		public void handleEvent(Event e) {
			switch (e.type) {
				case SWT.Selection: onTableSelection(e); break;
				case SWT.MouseDown: onTableMouseDown(e); break;
				case SWT.FocusIn:   onTableFocusIn(e); break;
				case SWT.KeyUp:   onTableKeyUp(e); break;
			}
		}
	};
	table.addListener(SWT.Selection, tableListener);
	table.addListener(SWT.MouseDown, tableListener);
	table.addListener(SWT.FocusIn,   tableListener);
	table.addListener(SWT.KeyUp,   tableListener);
	
	columnListener = new Listener() {
		public void handleEvent(Event e) {
			resize();
		}
	};
	
	Listener listener = new Listener() {
		public void handleEvent(Event e) {
			switch (e.type) {
				case SWT.Traverse:  onTraverse(e); break;
				case SWT.Paint:     paint(e.gc); break;
				case SWT.FocusIn:   
				case SWT.FocusOut:  onFocusChange(e); break;
				case SWT.MouseDoubleClick: onDoubleClick(e); break;
				case SWT.KeyDown:    onKeyDown(e); break;
			}
		}
	};
	addListener(SWT.Traverse, listener);
	addListener(SWT.Paint, listener);
	addListener(SWT.FocusIn, listener);
	addListener(SWT.FocusOut, listener);
	addListener(SWT.MouseDoubleClick, listener);
	addListener(SWT.KeyDown, listener);
}
public void dispose () {
	setColumn(-1);
	row = null;
	
	table.removeListener(SWT.KeyDown, tableListener);
	table.removeListener(SWT.Resize, tableListener);
	table.removeListener(SWT.Selection, tableListener);
	table.removeListener(SWT.MouseUp, tableListener);
	
	ScrollBar hBar = table.getHorizontalBar ();
	if (hBar != null) hBar.removeListener (SWT.Selection, scrollListener);
	ScrollBar vBar = table.getVerticalBar ();
	if (vBar != null) vBar.removeListener (SWT.Selection, scrollListener);
}
public int getColumn () {
	return column;
}
public TableItem getRow() {
	return row;
}

private void onTraverse(Event e) {
	if (row == null) return;
	
	int index = table.indexOf(row);
	int newIndex = index;
	int newColumn = column;
	if (e.detail == SWT.TRAVERSE_ARROW_PREVIOUS && e.keyCode == SWT.ARROW_UP) {
		newIndex = Math.max(index - 1, 0);
	}
	if (e.detail == SWT.TRAVERSE_ARROW_NEXT && e.keyCode == SWT.ARROW_DOWN) {
		newIndex = Math.min(index + 1, table.getItemCount() - 1);
	}
	if (e.detail == SWT.TRAVERSE_ARROW_PREVIOUS && e.keyCode == SWT.ARROW_LEFT) {
		newColumn = Math.max(column - 1, 0);
	}
	if (e.detail == SWT.TRAVERSE_ARROW_NEXT && e.keyCode == SWT.ARROW_RIGHT) {
		newColumn = Math.min(column + 1, table.getColumnCount() - 1);
	}
	
	if (index == newIndex && column == newColumn) return;
	row = table.getItem(newIndex);
	table.showItem(row);
	setColumn(newColumn);
	updateCell();
	table.setSelection(new TableItem[] {row});
	notifyListeners(SWT.Selection, new Event());
	e.doit = false;
}

private void onTableFocusIn(Event e) {
	if (ctrlset) return;
	getDisplay().asyncExec(new Runnable () {
		public void run() {
			if (!isDisposed() && table.isFocusControl()) {
				setVisible(true);
				setFocus();
			}
		}
	});
}
private void onTableKeyUp(Event e) {
	if ((e.stateMask & SWT.CTRL) != 0) return;
	ctrlset = false;
	getDisplay().asyncExec(new Runnable () {
		public void run() {
			if (!isDisposed() && table.isFocusControl()) {
				setVisible(true);
				setFocus();
			}
		}
	});
}
private void onDoubleClick(Event e) {
	notifyListeners(SWT.DefaultSelection, new Event());
}
private void onFocusChange(Event e) {
	this.setVisible(e.type == SWT.FocusIn);
}
private void onKeyDown(Event e) {
	if (e.character == SWT.CR) {
		notifyListeners(SWT.DefaultSelection, new Event());
	}
	if ((e.stateMask & SWT.CTRL) != 0) {
		ctrlset = true;
		table.forceFocus();
	}
}
private void onTableMouseDown(Event e) {
	// find column at coordinates
	Point pt = new Point(e.x, e.y);
	TableItem item = table.getItem(pt);
	int index = -1;
	if (item != null) {
		int length = table.getColumnCount();
		for (int i = 0; i < length; i++) {
			Rectangle rect = item.getBounds(i);
			if (rect.contains(pt)) {
				index = i;
				break;
			}
		}
	}
	if (index == column && item == row) return;
	row = item;
	setColumn(index);
	notifyListeners(SWT.Selection, new Event());
	updateCell();
}
private void onScrollSelection(Event e) {
	if (column == -1 || row == null || row.isDisposed()) return;
	
	boolean hadFocus = false;
	if (getVisible ()) {
		hadFocus = isFocusControl();
	}
	boolean visible = e.detail != SWT.DRAG;
	if (visible) {
		setBounds (row.getBounds(column));
	}
	setVisible (visible);
	if (visible && hadFocus) setFocus ();
}
private void onTableSelection(Event e) {
	getDisplay().asyncExec(new Runnable () {
		public void run() {
			if (isDisposed()) return;
			TableItem selection = table.getSelection()[0];
			if (selection == row) return;
			if (column == -1) setColumn(0);
			notifyListeners(SWT.Selection, new Event());
			updateCell();
		}
	});
}
private void paint(GC gc) {
	if (row == null || column == -1) return;
	Color foreground;
	Color background;
	Display display = getDisplay();
	foreground = display.getSystemColor(SWT.COLOR_LIST_SELECTION_TEXT);
	background = display.getSystemColor(SWT.COLOR_LIST_SELECTION);
	Rectangle rect = getClientArea();
	int x = rect.x, y = rect.y;
	int width = rect.width; int height = rect.height;
	gc.setBackground(background);
	gc.fillRectangle(x, y, width, height);
	
	gc.setBackground(getDisplay().getSystemColor(SWT.COLOR_BLACK));
	gc.setForeground(getDisplay().getSystemColor(SWT.COLOR_WHITE));
	gc.drawFocus(x, y, width, height);
	
	if (image != null) {
		Rectangle imageRect = image.getBounds();
		x += 2; y += 2;
		width = Math.max(0, width - 4); height = Math.max(0, height - 4);
		gc.drawImage(image, 0, 0, imageRect.width, imageRect.height, x, y, height, height);
		x += height; width = Math.max(0, width - height);
	}
	if (text != null) {
		x += 2;
		gc.setForeground(foreground);
		Point extent = gc.textExtent(text);
		gc.drawText(text, x, y + Math.max(0, (height - extent.y)/2), true);
	}
}

private void updateCell() {
	if (row != null && column != -1) {
		text = row.getText(column);
		image = row.getImage(column);
	}
	resize();
	GC gc = new GC(this);
	paint(gc);
	gc.dispose();
}
private void resize() {
	if (row != null && column != -1) {
		setBounds (row.getBounds(column));
	} else {
		setBounds (-200, -200, 0, 0);
	}
}
private void setColumn(int column) {
	if (column == this.column) return;
	if (this.column != -1) {
		TableColumn tableColumn = table.getColumn(this.column);
		if (tableColumn != null && !tableColumn.isDisposed()) {
			tableColumn.removeListener(SWT.Resize, columnListener);
			tableColumn.removeListener(SWT.Move, columnListener);
		}
		this.column = -1;
	}
	if (column != -1) {
		TableColumn tableColumn = table.getColumn(column);
		if (tableColumn != null && !tableColumn.isDisposed()) {
			tableColumn.addListener(SWT.Resize, columnListener);
			tableColumn.addListener(SWT.Move, columnListener);
			this.column = column;
		}
	}
}

public void setImage(Image image) {
	this.image = image;
	redraw();
}
public void setText(String text) {
	this.text = text;
	redraw();
}
public Image getImage() {
	return image;
}
public String getText() {
	return (text == null) ? "" : text;
}
}
