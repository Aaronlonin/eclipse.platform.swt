/*
 * Copyright (c) IBM Corp. 2000, 2002.  All rights reserved.
 *
 * The contents of this file are made available under the terms
 * of the GNU Lesser General Public License (LGPL) Version 2.1 that
 * accompanies this distribution (lgpl-v21.txt).  The LGPL is also
 * available at http://www.gnu.org/licenses/lgpl.html.  If the version
 * of the LGPL at http://www.gnu.org is different to the version of
 * the LGPL accompanying this distribution and there is any conflict
 * between the two license versions, the terms of the LGPL accompanying
 * this distribution shall govern.
 */

/**
 * SWT OS natives implementation: gtk_window_* functions.
 * This file also contains all dialog functions (e.g.,
 * gtk_color_selection_*).
 */ 

#include "swt.h"
#include "structs.h"

#include <stdio.h>
#include <assert.h>


/*
 * gtk_window_*
 */

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1new
  (JNIEnv *env, jclass that, jint type)
{
	return (jint)gtk_window_new((GtkWindowType)type);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1title
  (JNIEnv *env, jclass that, jint window, jbyteArray title)
{
	jbyte *title1 = NULL;
	if (title) {
		title1 = (*env)->GetByteArrayElements(env, title, NULL);
	}
	gtk_window_set_title((GtkWindow*)window, (gchar*)title1);
	if (title) {
		(*env)->ReleaseByteArrayElements(env, title, title1, 0);
	}
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1policy
  (JNIEnv *env, jclass that, jint window, jint allow_shrink, jint allow_grow, jint auto_shrink)
{
	gtk_window_set_policy((GtkWindow*)window, (gint)allow_shrink, (gint)allow_grow, (gint)auto_shrink);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1resizable
  (JNIEnv *env, jclass that, jint window, jboolean resizable)
{
	gtk_window_set_resizable((GtkWindow*)window, (gboolean)resizable);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1get_1position
  (JNIEnv *env, jclass that, jint window, jintArray px, jintArray py)
{
  jint *px1 = NULL;
  jint *py1 = NULL;
  if (px) px1 = (*env)->GetIntArrayElements(env, px, NULL);
  if (py) py1 = (*env)->GetIntArrayElements(env, py, NULL);
  gtk_window_get_position((GtkWindow*)window, (gint*)px1, (gint*)py1);
  if (px) (*env)->ReleaseIntArrayElements(env, px, px1, 0);
  if (py) (*env)->ReleaseIntArrayElements(env, py, py1, 0);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1get_1size
  (JNIEnv *env, jclass that, jint window, jintArray px, jintArray py)
{
  jint *px1 = NULL;
  jint *py1 = NULL;
  if (px) px1 = (*env)->GetIntArrayElements(env, px, NULL);
  if (py) py1 = (*env)->GetIntArrayElements(env, py, NULL);
  gtk_window_get_size((GtkWindow*)window, (gint*)px1, (gint*)py1);
  if (px) (*env)->ReleaseIntArrayElements(env, px, px1, 0);
  if (py) (*env)->ReleaseIntArrayElements(env, py, py1, 0);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1move
  (JNIEnv *env, jclass that, jint window, jint x, jint y)
{
	gtk_window_move((GtkWindow*)window, x, y);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1resize
  (JNIEnv *env, jclass that, jint window, jint width, jint height)
{
	gtk_window_resize((GtkWindow*)window, width, height);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1transient_1for
  (JNIEnv *env, jclass that, jint window, jint parent)
{
	gtk_window_set_transient_for((GtkWindow*)window, (GtkWindow*)parent);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1modal
  (JNIEnv *env, jclass that, jint window, jboolean modal)
{
	gtk_window_set_modal((GtkWindow*)window, modal);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1add_1accel_1group
  (JNIEnv *env, jclass that, jint window, jint accel_group)
{
	gtk_window_add_accel_group((GtkWindow*)window, (GtkAccelGroup*)accel_group);
}






/*
 *  DIALOGS
 */

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1message_1dialog_1new
  (JNIEnv *env, jclass that, jint parent, jint flags, jint type, jint buttons, jstring message_format)
{
  const gchar *message_format1 = NULL;
  GtkWidget *result = NULL;
  if (message_format != NULL) {
    message_format1 = (*env)->GetStringUTFChars(env, message_format, NULL);
    if (message_format1 == NULL) return 0; /* OutOfMemory */
  }
  result = gtk_message_dialog_new((GtkWindow*)parent,
	                              (GtkDialogFlags) flags,
	                              (GtkMessageType) type,
	                              (GtkButtonsType) buttons,
	                              message_format1);
  (*env)->ReleaseStringUTFChars(env, message_format, message_format1);
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1dialog_1add_1button
  (JNIEnv *env, jclass that, jint dialog, jstring text, jint response_id)
{
  const gchar *text1 = NULL;
  GtkWidget *result;
  if (text != NULL) {
    text1 = (*env)->GetStringUTFChars(env, text, NULL);
    if (text1 == NULL) return 0; /* OutOfMemory */
  }
  result = gtk_dialog_add_button ((GtkDialog*)dialog , (const gchar*)text1, (gint)response_id);
  (*env)->ReleaseStringUTFChars(env, text, text1);
  return (jint) result;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1MESSAGE_1INFO
  (JNIEnv *env, jclass that)
{
  return (jint) GTK_MESSAGE_INFO;
}
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1MESSAGE_1WARNING
  (JNIEnv *env, jclass that)
{
  return (jint) GTK_MESSAGE_WARNING;
}
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1MESSAGE_1QUESTION
  (JNIEnv *env, jclass that)
{
  return (jint) GTK_MESSAGE_QUESTION;
}
JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1MESSAGE_1ERROR
  (JNIEnv *env, jclass that)
{
  return (jint) GTK_MESSAGE_ERROR;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1dialog_1run
  (JNIEnv *env, jclass that, jint dialog)
{
	return (jint)gtk_dialog_run((GtkDialog*)dialog);
}


/*
 *  Color selection
 */

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1color_1selection_1set_1color
  (JNIEnv *env, jclass that, jint colorsel, jdoubleArray color)
{
	jdouble *color1 = NULL;
	if (color) {
		color1 = (*env)->GetDoubleArrayElements(env, color, NULL);
	}
	gtk_color_selection_set_color((GtkColorSelection*)colorsel, (gdouble*)color1);
	if (color) {
		(*env)->ReleaseDoubleArrayElements(env, color, color1, 0);
	}
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1color_1selection_1get_1color
  (JNIEnv *env, jclass that, jint colorsel, jdoubleArray color)
{
	jdouble *color1 = NULL;
	if (color) {
		color1 = (*env)->GetDoubleArrayElements(env, color, NULL);
	}
	gtk_color_selection_get_color((GtkColorSelection*)colorsel, (gdouble*)color1);
	if (color) {
		(*env)->ReleaseDoubleArrayElements(env, color, color1, 0);
	}
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1color_1selection_1dialog_1new
  (JNIEnv *env, jclass that, jbyteArray title)
{
	jint rc;
	jbyte *title1 = NULL;
	if (title) {
		title1 = (*env)->GetByteArrayElements(env, title, NULL);
	}
	rc = (jint)gtk_color_selection_dialog_new((gchar*)title1);
	if (title) {
		(*env)->ReleaseByteArrayElements(env, title, title1, 0);
	}
	return rc;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1COLOR_1SELECTION_1DIALOG_1OK_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bug 70745
     */
    return (jint) (((GtkColorSelectionDialog*)fsd)->ok_button);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1COLOR_1SELECTION_1DIALOG_1CANCEL_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bug 70745
     */
    return (jint) (((GtkColorSelectionDialog*)fsd)->cancel_button);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1COLOR_1SELECTION_1DIALOG_1HELP_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bug 70745
     */
    return (jint) (((GtkColorSelectionDialog*)fsd)->help_button);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1COLOR_1SELECTION_1DIALOG_1COLORSEL
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bug 70745
     */
    return (jint) (((GtkColorSelectionDialog*)fsd)->colorsel);
}


/*
 * gtk_dialog_*
 */

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1dialog_1new
  (JNIEnv *env, jclass that)
{
	return (jint)gtk_dialog_new();
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1DIALOG_1VBOX
  (JNIEnv *env, jclass that, jint fsd)
{
    return (jint) (((GtkDialog*)fsd)->vbox);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1DIALOG_1ACTION_1AREA
  (JNIEnv *env, jclass that, jint fsd)
{
    return (jint) (((GtkDialog*)fsd)->action_area);
}


/*
 * gtk_file_selection_*
 */

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1file_1selection_1new
  (JNIEnv *env, jclass that, jbyteArray title)
{
	jint rc;
	jbyte *title1 = NULL;
	if (title) {
		title1 = (*env)->GetByteArrayElements(env, title, NULL);
	}
	rc = (jint)gtk_file_selection_new((gchar*)title1);
	if (title) {
		(*env)->ReleaseByteArrayElements(env, title, title1, 0);
	}
	return rc;
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1file_1selection_1set_1filename
  (JNIEnv *env, jclass that, jint filesel, jbyteArray filename)
{
	jbyte *filename1 = NULL;
	if (filename) {
		filename1 = (*env)->GetByteArrayElements(env, filename, NULL);
	}
	gtk_file_selection_set_filename((GtkFileSelection*)filesel, (gchar*)filename1);
	if (filename) {
		(*env)->ReleaseByteArrayElements(env, filename, filename1, 0);
	}
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1file_1selection_1get_1filename
  (JNIEnv *env, jclass that, jint filesel)
{
	return (jint)gtk_file_selection_get_filename((GtkFileSelection*)filesel);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1file_1selection_1get_1selections
  (JNIEnv *env, jclass that, jint filesel)
{
    return (jint)gtk_file_selection_get_selections((GtkFileSelection*)filesel);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1file_1selection_1complete
  (JNIEnv *env, jclass that, jint filesel, jbyteArray pattern)
{
	jbyte *pattern1 = NULL;
	if (pattern) {
		pattern1 = (*env)->GetByteArrayElements(env, pattern, NULL);
	}
	gtk_file_selection_complete((GtkFileSelection*)filesel, (gchar*)pattern1);
	if (pattern) {
		(*env)->ReleaseByteArrayElements(env, pattern, pattern1, 0);
	}
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1FILE_1SELECTION_1OK_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bug 70745
     */
    return (jint) (((GtkFileSelection*)fsd)->ok_button);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1FILE_1SELECTION_1CANCEL_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bug 70745
     */
    return (jint) (((GtkFileSelection*)fsd)->cancel_button);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1file_1selection_1set_1select_1multiple
  (JNIEnv *env, jclass that, jint filesel, jboolean select_multiple)
{
	gtk_file_selection_set_select_multiple((GtkFileSelection*)filesel, (gboolean)select_multiple);
}


/*
 * gtk_font_selection_*
 */

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1font_1selection_1dialog_1new
  (JNIEnv *env, jclass that, jbyteArray title)
{
	jint rc;
	jbyte *title1 = NULL;
	if (title) {
		title1 = (*env)->GetByteArrayElements(env, title, NULL);
	}
	rc = (jint)gtk_font_selection_dialog_new((gchar*)title1);
	if (title) {
		(*env)->ReleaseByteArrayElements(env, title, title1, 0);
	}
	return rc;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1font_1selection_1dialog_1get_1font_1name
  (JNIEnv *env, jclass that, jint fsd)
{
	return (jint)gtk_font_selection_dialog_get_font_name((GtkFontSelectionDialog*)fsd);
}

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1font_1selection_1dialog_1set_1font_1name
  (JNIEnv *env, jclass that, jint fsd, jbyteArray fontname)
{
	jboolean rc;
	jbyte *fontname1 = NULL;
	if (fontname) {
		fontname1 = (*env)->GetByteArrayElements(env, fontname, NULL);
	}
	rc = (jboolean)gtk_font_selection_dialog_set_font_name((GtkFontSelectionDialog*)fsd, (gchar*)fontname1);
	if (fontname) {
		(*env)->ReleaseByteArrayElements(env, fontname, fontname1, 0);
	}
	return rc;
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1FONT_1SELECTION_1DIALOG_1OK_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bugs 70742, 70745
     */
    return (jint) (((GtkFontSelectionDialog*)fsd)->ok_button);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_GTK_1FONT_1SELECTION_1DIALOG_1CANCEL_1BUTTON
  (JNIEnv *env, jclass that, jint fsd)
{
    /*
     * GTK bugs 70742, 70745
     */
    return (jint) (((GtkFontSelectionDialog*)fsd)->cancel_button);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1default
  (JNIEnv *env, jclass that, jint window, jint widget)
{
    gtk_window_set_default((GtkWindow*)window, (GtkWidget*)widget);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1get_1default
  (JNIEnv *env, jclass that, jint window)
{
    return (jint)(((GtkWindow*)window)->default_widget);
}

JNIEXPORT jboolean JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1activate_1default
  (JNIEnv *env, jclass that, jint window)
{
    return (jboolean)gtk_window_activate_default((GtkWindow*)window);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1iconify
  (JNIEnv *env, jclass that, jint window)
{
    gtk_window_iconify((GtkWindow*)window);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1deiconify
  (JNIEnv *env, jclass that, jint window)
{
    gtk_window_deiconify((GtkWindow*)window);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1maximize
  (JNIEnv *env, jclass that, jint window)
{
    gtk_window_maximize((GtkWindow*)window);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1unmaximize
  (JNIEnv *env, jclass that, jint window)
{
    gtk_window_unmaximize((GtkWindow*)window);
}

JNIEXPORT jint JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1get_1focus
  (JNIEnv *env, jclass that, jint window)
{
    return (jint)gtk_window_get_focus((GtkWindow*)window);
}

JNIEXPORT void JNICALL Java_org_eclipse_swt_internal_gtk_OS_gtk_1window_1set_1destroy_1with_1parent
  (JNIEnv *env, jclass that, jint window, jboolean setting)
{
    gtk_window_set_destroy_with_parent((GtkWindow*)window, (gboolean)setting);
}
