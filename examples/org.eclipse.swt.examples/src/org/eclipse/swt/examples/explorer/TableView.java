package org.eclipse.swt.examples.explorer;/*
 * (c) Copyright IBM Corp. 2000, 2001.
 * All Rights Reserved
 */

import org.eclipse.swt.*;import org.eclipse.swt.dnd.*;import org.eclipse.swt.events.*;import org.eclipse.swt.graphics.*;import org.eclipse.swt.layout.*;import org.eclipse.swt.program.*;import org.eclipse.swt.widgets.*;import java.io.*;import java.text.*;import java.util.*;

public class TableView {
	private static final String TABLEITEMDATA_FILE = "TableItem.file";
		// File: File associated with table row

	private final Table table;
	private final Label contentsOfLabel;
	private final Shell shell;
	private final Display display;
	private final FileViewer viewer;
	
	private File activeDir = null;
	
	/* Worker thread control */
	private UpdateWorker tableUpdateWorker = null;

	final String[] titles = new String [] {
		FileViewer.getResourceString("Name"),
		FileViewer.getResourceString("Size"),
		FileViewer.getResourceString("Type"),
		FileViewer.getResourceString("Modified")
	};
	final int[] widths = new int[] {150, 60, 75, 150};

	/**
	 * Creates the file details table.
	 * 
	 * @param theViewer the viewer to attach to
	 * @param parent the parent control
	 * @param layoutData the layout data
	 */
	public TableView(FileViewer theViewer, Composite parent, Object layoutData) {
		this.viewer = theViewer;
		shell = parent.getShell();
		display = shell.getDisplay();

		Composite composite = new Composite(parent, SWT.NONE);
		composite.setLayoutData(layoutData);
		GridLayout gridLayout = new GridLayout();
		gridLayout.numColumns = 1;
		gridLayout.marginHeight = gridLayout.marginWidth = 2;
		gridLayout.horizontalSpacing = gridLayout.verticalSpacing = 0;
		composite.setLayout(gridLayout);
		contentsOfLabel = new Label(composite, SWT.BORDER);
		contentsOfLabel.setLayoutData(new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL));

		table = new Table(composite, SWT.BORDER | SWT.V_SCROLL | SWT.H_SCROLL | SWT.MULTI);
		table.setLayoutData(new GridData(GridData.FILL_HORIZONTAL | GridData.FILL_VERTICAL));

		for (int i = 0; i < titles.length; i++) {
			TableColumn column = new TableColumn(table, SWT.NONE);
			column.setText(titles [i]);
			column.setWidth(widths [i]);
		}
		table.setHeaderVisible(true);
		table.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent event) {
				viewer.notifySelectedFiles(getSelectedFiles());
			}
			public void widgetDefaultSelected(SelectionEvent event) {
				viewer.doDefaultFileAction(getSelectedFiles());
			}
			private File[] getSelectedFiles() {
				final TableItem[] items = table.getSelection();
				final File[] files = new File[items.length];
				
				for (int i = 0; i < items.length; ++i) {
					files[i] = (File) items[i].getData(TABLEITEMDATA_FILE);
				}
				return files;
			}
		});

		createTableDragSource(table);
		createTableDropTarget(table);
		
		tableUpdateWorker = new TableUpdateWorker();
	}

	/**
	 * Dispose of allocated resources and shut down.
	 */
	public void dispose() {
		tableUpdateWorker.syncStop();
	}

	/**
	 * Updates the table with file information in the background.
	 * <p>
	 * It is designed such that it can be interrupted cleanly.  Rather than put all the code
	 * to manage this here, the balance has been pushed out to UpdateWorker so it can be re-used.
	 * </p>
	 */
	private class TableUpdateWorker extends UpdateWorker {
		private File   currentDir = null;
		private File[] currentFiles = null;
		private File[] currentDirList = null;

		public TableUpdateWorker() {
			super(TableView.this.display);
		}
		
		/**
		 * Updates the table's contents
		 * 
		 * @param data arguments in an Object[]
		 * <ul>
		 * <li>File data[0] dir the current directory, null does nothing
		 * <li>File[] data[1] the list of files to select, null does nothing
		 * <li>Boolean data[2] if true, forces a refresh
		 * </ul>
		 */
		protected void execute(Object data) {
			// Get arguments
			final Object[] args = (Object[]) data;
			final File    argDir = (File) args[0];
			final File[]  argFiles = (File[]) args[1];
			final boolean argForce = ((Boolean) args[2]).booleanValue();

			// Update current state
			if (argDir != null) currentDir = argDir;
			if (argFiles != null) currentFiles = argFiles;
			else if (argDir != null) currentFiles = new File[0];

			// Perform necessary refreshing
			if (argDir != null) updateDirectoryListing();
			else if (argFiles != null) updateFileSelection();
			
			if (isCancelled()) {
				currentFiles = null;
				currentDir = null;
				currentDirList = null;
			}
		}

		/*
		 * Note the use of asyncExec() in some places to ensure that SWT Widgets are manipulated in the
		 * right thread.  Exclusive use of syncExec() would be inappropriate as it would require a pair
		 * of context switches between each table update operation.
		 */

		/**
		 * Updates directory list
		 */
		private void updateDirectoryListing() {
			// Clear existing information
			display.syncExec(new Runnable() {
				public void run() {
					viewer.clearDetails();
					contentsOfLabel.setText(FileViewer.getResourceString("Content_of",
						new Object[] { currentDir.getPath() }));
					table.removeAll();
					table.setRedraw(false);
					TableView.this.activeDir = currentDir; // synchronize this
				}
			});
			currentDirList = FileViewer.getDirectoryList(currentDir);
			updateDetails();

			for (int i = 0; (! isCancelled()) && (i < currentDirList.length); i++) {
				final File theFile = currentDirList[i];
				addFileDetails(currentDirList[i]);

				final boolean doIncrementalRefresh = ((i & 127) == 127);
				if (doIncrementalRefresh) display.syncExec(new Runnable() {
					public void run () {
						table.setRedraw(true);
						table.setRedraw(false);
					}
				});
			}

			// Allow the table to refresh itself
			display.asyncExec(new Runnable() {
				public void run() {
					table.setRedraw(true);
				}
			});
		}
			
		/**
		 * Adds a file's detail information to the directory list
		 */
		private void addFileDetails(final File file) {
			final FileDisplayInfo displayInfo = viewer.getFileDisplayInfo(file);
			final String[] strings = new String[] {
				displayInfo.nameString,
				displayInfo.sizeString,
				displayInfo.typeString,
				displayInfo.dateString };
			final Image image = displayInfo.iconImage;

			display.asyncExec(new Runnable() {
				public void run () {
					TableItem tableItem = new TableItem(table, 0);
					tableItem.setText(strings);
					tableItem.setImage(image);
					tableItem.setData(TABLEITEMDATA_FILE, file);
				}
			});
		}
		
		/**
		 * Updates the current file selection
		 */
		private void updateFileSelection() {
			updateDetails();
		}
		
		/**
		 * Updates the detail information
		 */
		private void updateDetails() {
			if (currentFiles.length == 0) {
				if (currentDir == null) return;
				final File folder = currentDir;
				final File[] files = currentDirList;

				// show directory information
				display.asyncExec(new Runnable() {
					public void run() {
						viewer.setFolderDetails(folder, files);
					}
				});
			} else if (currentFiles.length == 1) {
				final File file = currentFiles[0];

				// show individual file information
				display.asyncExec(new Runnable() {
					public void run() {
						viewer.setFileDetails(file);
					}
				});
			} else {
				// show multi-selection file information
				final File[] files = currentFiles;
				
				display.asyncExec(new Runnable() {
					public void run() {
						viewer.setSelectionDetails(files);
					}
				});
			}				
		}
	}

	/**
	 * Creates the Drag & Drop DropTarget for items being dropped onto the table.
	 * 
	 * @return the DropTarget for the table
	 */
	private DropTarget createTableDropTarget(final Table table){
		DropTarget dropTarget = new DropTarget(table, DND.DROP_MOVE | DND.DROP_COPY);
		dropTarget.setTransfer(new Transfer[] { FileTransfer.getInstance() });
		dropTarget.addDropListener(new DropTargetAdapter() {
			public void dragOver(DropTargetEvent event) {
				viewer.validateDrop(event, getTargetFile(event));
			}
			public void drop(DropTargetEvent event) {
				viewer.performDrop(event, getTargetFile(event));
			}				
			private File getTargetFile(DropTargetEvent event) {
				// Determine the target File for the drop 
				final TableItem item = table.getItem(table.toControl(new Point(event.x, event.y)));
				final File targetFile;
				if (item == null) {
					// We dropped on an unoccupied area of the table, use the table's root file
					targetFile = activeDir;
				} else {
					// We dropped on a particular item in the table, use the item's file
					targetFile = (File) item.getData(TABLEITEMDATA_FILE);
				}
				return targetFile;
			}
		});
		return dropTarget;
	}
	
	/**
	 * Creates the Drag & Drop DragSource for items being dragged from the table.
	 * 
	 * @return the DragSource for the table
	 */
	private DragSource createTableDragSource(final Table table) {
		DragSource dragSource = new DragSource(table, DND.DROP_MOVE | DND.DROP_COPY);
		dragSource.setTransfer(new Transfer[] { FileTransfer.getInstance() });
		dragSource.addDragListener(new DragSourceListener() {
			public void dragStart(DragSourceEvent e) {
				e.doit = table.getSelectionCount() > 0;
			}
			public void dragSetData(DragSourceEvent event){
				if (! FileTransfer.getInstance().isSupportedType(event.dataType)) return;
				
				final TableItem[] tableDragItems = table.getSelection();
				if (tableDragItems == null || tableDragItems.length == 0) return;
				
				final String[] data = new String[tableDragItems.length];
				for (int i = 0; i < tableDragItems.length; i++) {
					File file = (File) tableDragItems[i].getData(TABLEITEMDATA_FILE);
					data[i] = file.getAbsolutePath();
				}
				event.data = data;
			}
			public void dragFinished(DragSourceEvent event) {
			}
		});
		return dragSource;
	}

	/**
	 * Listens to selectedDirectory events.
	 * <p>
	 * Displays the contents in the selected directory.
	 * </p>
	 * 
	 * @param dir the directory that was selected, null is not permitted
	 */
	/* package */ void selectedDirectory(File dir) {
		tableUpdateWorker.asyncUpdate(new Object[] { dir, null, new Boolean(false) });
	}

	/**
	 * Listens to selectedFiles events.
	 * <p>
	 * Updates the details to match the specified selection.
	 * </p>
	 * 
	 * @param files the array of selected files, null is not permitted
	 */
	/* package */ void selectedFiles(File[] files) {
		tableUpdateWorker.asyncUpdate(new Object[] { null, files, new Boolean(false) });
	}
	
	/**
	 * Listens to refreshFiles events.
	 * <p>
	 * Refreshes information about any files in the list and their children.
	 * </p>
	 * 
	 * @param files the list of files to be refreshed, null refreshes everything
	 */
	/* package */ void refreshFiles(File[] files) {
		tableUpdateWorker.asyncUpdate(new Object[] { null, null, new Boolean(true) });
	}	
}
