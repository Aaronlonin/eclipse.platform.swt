package org.eclipse.swt.examples.explorer;import org.eclipse.swt.graphics.*;
/** * Stores detailed formatted display information about a file entry. */
/* package */ class FileDisplayInfo {
	public String nameString;
	public String typeString;
	public String sizeString;
	public String dateString;
	public Image  iconImage;
		/**	 * Creates a formatted display block.	 * 	 * @param name the file name string	 * @param type the file type string	 * @param size the file size string	 * @param date the file data string	 * @param icon the file icon	 */	public FileDisplayInfo(String name, String type, String size, String date, Image icon) {
		this.nameString = name;
		this.typeString = type;
		this.sizeString = size;
		this.dateString = date;
		this.iconImage = icon;
	}
}
