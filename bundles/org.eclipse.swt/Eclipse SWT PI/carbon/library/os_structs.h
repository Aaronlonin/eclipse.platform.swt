/*******************************************************************************
* Copyright (c) 2000, 2003 IBM Corporation and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Common Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/cpl-v10.html
* 
* Contributors:
*     IBM Corporation - initial API and implementation
*******************************************************************************/

#include "os.h"

#ifndef NO_AEDesc
AEDesc *getAEDescFields(JNIEnv *env, jobject lpObject, AEDesc *lpStruct);
void setAEDescFields(JNIEnv *env, jobject lpObject, AEDesc *lpStruct);
#else
#define getAEDescFields(a,b,c) NULL
#define setAEDescFields(a,b,c)
#endif

#ifndef NO_ATSTrapezoid
ATSTrapezoid *getATSTrapezoidFields(JNIEnv *env, jobject lpObject, ATSTrapezoid *lpStruct);
void setATSTrapezoidFields(JNIEnv *env, jobject lpObject, ATSTrapezoid *lpStruct);
#else
#define getATSTrapezoidFields(a,b,c) NULL
#define setATSTrapezoidFields(a,b,c)
#endif

#ifndef NO_ATSUTab
ATSUTab *getATSUTabFields(JNIEnv *env, jobject lpObject, ATSUTab *lpStruct);
void setATSUTabFields(JNIEnv *env, jobject lpObject, ATSUTab *lpStruct);
#else
#define getATSUTabFields(a,b,c) NULL
#define setATSUTabFields(a,b,c)
#endif

#ifndef NO_AlertStdCFStringAlertParamRec
AlertStdCFStringAlertParamRec *getAlertStdCFStringAlertParamRecFields(JNIEnv *env, jobject lpObject, AlertStdCFStringAlertParamRec *lpStruct);
void setAlertStdCFStringAlertParamRecFields(JNIEnv *env, jobject lpObject, AlertStdCFStringAlertParamRec *lpStruct);
#else
#define getAlertStdCFStringAlertParamRecFields(a,b,c) NULL
#define setAlertStdCFStringAlertParamRecFields(a,b,c)
#endif

#ifndef NO_BitMap
BitMap *getBitMapFields(JNIEnv *env, jobject lpObject, BitMap *lpStruct);
void setBitMapFields(JNIEnv *env, jobject lpObject, BitMap *lpStruct);
#else
#define getBitMapFields(a,b,c) NULL
#define setBitMapFields(a,b,c)
#endif

#ifndef NO_CFRange
CFRange *getCFRangeFields(JNIEnv *env, jobject lpObject, CFRange *lpStruct);
void setCFRangeFields(JNIEnv *env, jobject lpObject, CFRange *lpStruct);
#else
#define getCFRangeFields(a,b,c) NULL
#define setCFRangeFields(a,b,c)
#endif

#ifndef NO_CGPoint
CGPoint *getCGPointFields(JNIEnv *env, jobject lpObject, CGPoint *lpStruct);
void setCGPointFields(JNIEnv *env, jobject lpObject, CGPoint *lpStruct);
#else
#define getCGPointFields(a,b,c) NULL
#define setCGPointFields(a,b,c)
#endif

#ifndef NO_CGRect
CGRect *getCGRectFields(JNIEnv *env, jobject lpObject, CGRect *lpStruct);
void setCGRectFields(JNIEnv *env, jobject lpObject, CGRect *lpStruct);
#else
#define getCGRectFields(a,b,c) NULL
#define setCGRectFields(a,b,c)
#endif

#ifndef NO_ColorPickerInfo
ColorPickerInfo *getColorPickerInfoFields(JNIEnv *env, jobject lpObject, ColorPickerInfo *lpStruct);
void setColorPickerInfoFields(JNIEnv *env, jobject lpObject, ColorPickerInfo *lpStruct);
#else
#define getColorPickerInfoFields(a,b,c) NULL
#define setColorPickerInfoFields(a,b,c)
#endif

#ifndef NO_ControlButtonContentInfo
ControlButtonContentInfo *getControlButtonContentInfoFields(JNIEnv *env, jobject lpObject, ControlButtonContentInfo *lpStruct);
void setControlButtonContentInfoFields(JNIEnv *env, jobject lpObject, ControlButtonContentInfo *lpStruct);
#else
#define getControlButtonContentInfoFields(a,b,c) NULL
#define setControlButtonContentInfoFields(a,b,c)
#endif

#ifndef NO_ControlFontStyleRec
ControlFontStyleRec *getControlFontStyleRecFields(JNIEnv *env, jobject lpObject, ControlFontStyleRec *lpStruct);
void setControlFontStyleRecFields(JNIEnv *env, jobject lpObject, ControlFontStyleRec *lpStruct);
#else
#define getControlFontStyleRecFields(a,b,c) NULL
#define setControlFontStyleRecFields(a,b,c)
#endif

#ifndef NO_ControlTabEntry
ControlTabEntry *getControlTabEntryFields(JNIEnv *env, jobject lpObject, ControlTabEntry *lpStruct);
void setControlTabEntryFields(JNIEnv *env, jobject lpObject, ControlTabEntry *lpStruct);
#else
#define getControlTabEntryFields(a,b,c) NULL
#define setControlTabEntryFields(a,b,c)
#endif

#ifndef NO_ControlTabInfoRecV1
ControlTabInfoRecV1 *getControlTabInfoRecV1Fields(JNIEnv *env, jobject lpObject, ControlTabInfoRecV1 *lpStruct);
void setControlTabInfoRecV1Fields(JNIEnv *env, jobject lpObject, ControlTabInfoRecV1 *lpStruct);
#else
#define getControlTabInfoRecV1Fields(a,b,c) NULL
#define setControlTabInfoRecV1Fields(a,b,c)
#endif

#ifndef NO_Cursor
Cursor *getCursorFields(JNIEnv *env, jobject lpObject, Cursor *lpStruct);
void setCursorFields(JNIEnv *env, jobject lpObject, Cursor *lpStruct);
#else
#define getCursorFields(a,b,c) NULL
#define setCursorFields(a,b,c)
#endif

#ifndef NO_DataBrowserCallbacks
DataBrowserCallbacks *getDataBrowserCallbacksFields(JNIEnv *env, jobject lpObject, DataBrowserCallbacks *lpStruct);
void setDataBrowserCallbacksFields(JNIEnv *env, jobject lpObject, DataBrowserCallbacks *lpStruct);
#else
#define getDataBrowserCallbacksFields(a,b,c) NULL
#define setDataBrowserCallbacksFields(a,b,c)
#endif

#ifndef NO_DataBrowserCustomCallbacks
DataBrowserCustomCallbacks *getDataBrowserCustomCallbacksFields(JNIEnv *env, jobject lpObject, DataBrowserCustomCallbacks *lpStruct);
void setDataBrowserCustomCallbacksFields(JNIEnv *env, jobject lpObject, DataBrowserCustomCallbacks *lpStruct);
#else
#define getDataBrowserCustomCallbacksFields(a,b,c) NULL
#define setDataBrowserCustomCallbacksFields(a,b,c)
#endif

#ifndef NO_DataBrowserListViewColumnDesc
DataBrowserListViewColumnDesc *getDataBrowserListViewColumnDescFields(JNIEnv *env, jobject lpObject, DataBrowserListViewColumnDesc *lpStruct);
void setDataBrowserListViewColumnDescFields(JNIEnv *env, jobject lpObject, DataBrowserListViewColumnDesc *lpStruct);
#else
#define getDataBrowserListViewColumnDescFields(a,b,c) NULL
#define setDataBrowserListViewColumnDescFields(a,b,c)
#endif

#ifndef NO_DataBrowserListViewHeaderDesc
DataBrowserListViewHeaderDesc *getDataBrowserListViewHeaderDescFields(JNIEnv *env, jobject lpObject, DataBrowserListViewHeaderDesc *lpStruct);
void setDataBrowserListViewHeaderDescFields(JNIEnv *env, jobject lpObject, DataBrowserListViewHeaderDesc *lpStruct);
#else
#define getDataBrowserListViewHeaderDescFields(a,b,c) NULL
#define setDataBrowserListViewHeaderDescFields(a,b,c)
#endif

#ifndef NO_EventRecord
EventRecord *getEventRecordFields(JNIEnv *env, jobject lpObject, EventRecord *lpStruct);
void setEventRecordFields(JNIEnv *env, jobject lpObject, EventRecord *lpStruct);
#else
#define getEventRecordFields(a,b,c) NULL
#define setEventRecordFields(a,b,c)
#endif

#ifndef NO_FontInfo
FontInfo *getFontInfoFields(JNIEnv *env, jobject lpObject, FontInfo *lpStruct);
void setFontInfoFields(JNIEnv *env, jobject lpObject, FontInfo *lpStruct);
#else
#define getFontInfoFields(a,b,c) NULL
#define setFontInfoFields(a,b,c)
#endif

#ifndef NO_FontSelectionQDStyle
FontSelectionQDStyle *getFontSelectionQDStyleFields(JNIEnv *env, jobject lpObject, FontSelectionQDStyle *lpStruct);
void setFontSelectionQDStyleFields(JNIEnv *env, jobject lpObject, FontSelectionQDStyle *lpStruct);
#else
#define getFontSelectionQDStyleFields(a,b,c) NULL
#define setFontSelectionQDStyleFields(a,b,c)
#endif

#ifndef NO_GDevice
GDevice *getGDeviceFields(JNIEnv *env, jobject lpObject, GDevice *lpStruct);
void setGDeviceFields(JNIEnv *env, jobject lpObject, GDevice *lpStruct);
#else
#define getGDeviceFields(a,b,c) NULL
#define setGDeviceFields(a,b,c)
#endif

#ifndef NO_HICommand
HICommand *getHICommandFields(JNIEnv *env, jobject lpObject, HICommand *lpStruct);
void setHICommandFields(JNIEnv *env, jobject lpObject, HICommand *lpStruct);
#else
#define getHICommandFields(a,b,c) NULL
#define setHICommandFields(a,b,c)
#endif

#ifndef NO_HMHelpContentRec
HMHelpContentRec *getHMHelpContentRecFields(JNIEnv *env, jobject lpObject, HMHelpContentRec *lpStruct);
void setHMHelpContentRecFields(JNIEnv *env, jobject lpObject, HMHelpContentRec *lpStruct);
#else
#define getHMHelpContentRecFields(a,b,c) NULL
#define setHMHelpContentRecFields(a,b,c)
#endif

#ifndef NO_MenuTrackingData
MenuTrackingData *getMenuTrackingDataFields(JNIEnv *env, jobject lpObject, MenuTrackingData *lpStruct);
void setMenuTrackingDataFields(JNIEnv *env, jobject lpObject, MenuTrackingData *lpStruct);
#else
#define getMenuTrackingDataFields(a,b,c) NULL
#define setMenuTrackingDataFields(a,b,c)
#endif

#ifndef NO_NavDialogCreationOptions
NavDialogCreationOptions *getNavDialogCreationOptionsFields(JNIEnv *env, jobject lpObject, NavDialogCreationOptions *lpStruct);
void setNavDialogCreationOptionsFields(JNIEnv *env, jobject lpObject, NavDialogCreationOptions *lpStruct);
#else
#define getNavDialogCreationOptionsFields(a,b,c) NULL
#define setNavDialogCreationOptionsFields(a,b,c)
#endif

#ifndef NO_NavReplyRecord
NavReplyRecord *getNavReplyRecordFields(JNIEnv *env, jobject lpObject, NavReplyRecord *lpStruct);
void setNavReplyRecordFields(JNIEnv *env, jobject lpObject, NavReplyRecord *lpStruct);
#else
#define getNavReplyRecordFields(a,b,c) NULL
#define setNavReplyRecordFields(a,b,c)
#endif

#ifndef NO_PMRect
PMRect *getPMRectFields(JNIEnv *env, jobject lpObject, PMRect *lpStruct);
void setPMRectFields(JNIEnv *env, jobject lpObject, PMRect *lpStruct);
#else
#define getPMRectFields(a,b,c) NULL
#define setPMRectFields(a,b,c)
#endif

#ifndef NO_PMResolution
PMResolution *getPMResolutionFields(JNIEnv *env, jobject lpObject, PMResolution *lpStruct);
void setPMResolutionFields(JNIEnv *env, jobject lpObject, PMResolution *lpStruct);
#else
#define getPMResolutionFields(a,b,c) NULL
#define setPMResolutionFields(a,b,c)
#endif

#ifndef NO_PixMap
PixMap *getPixMapFields(JNIEnv *env, jobject lpObject, PixMap *lpStruct);
void setPixMapFields(JNIEnv *env, jobject lpObject, PixMap *lpStruct);
#else
#define getPixMapFields(a,b,c) NULL
#define setPixMapFields(a,b,c)
#endif

#ifndef NO_Point
Point *getPointFields(JNIEnv *env, jobject lpObject, Point *lpStruct);
void setPointFields(JNIEnv *env, jobject lpObject, Point *lpStruct);
#else
#define getPointFields(a,b,c) NULL
#define setPointFields(a,b,c)
#endif

#ifndef NO_RGBColor
RGBColor *getRGBColorFields(JNIEnv *env, jobject lpObject, RGBColor *lpStruct);
void setRGBColorFields(JNIEnv *env, jobject lpObject, RGBColor *lpStruct);
#else
#define getRGBColorFields(a,b,c) NULL
#define setRGBColorFields(a,b,c)
#endif

#ifndef NO_Rect
Rect *getRectFields(JNIEnv *env, jobject lpObject, Rect *lpStruct);
void setRectFields(JNIEnv *env, jobject lpObject, Rect *lpStruct);
#else
#define getRectFields(a,b,c) NULL
#define setRectFields(a,b,c)
#endif

#ifndef NO_TXNBackground
TXNBackground *getTXNBackgroundFields(JNIEnv *env, jobject lpObject, TXNBackground *lpStruct);
void setTXNBackgroundFields(JNIEnv *env, jobject lpObject, TXNBackground *lpStruct);
#else
#define getTXNBackgroundFields(a,b,c) NULL
#define setTXNBackgroundFields(a,b,c)
#endif

#ifndef NO_TXNLongRect
TXNLongRect *getTXNLongRectFields(JNIEnv *env, jobject lpObject, TXNLongRect *lpStruct);
void setTXNLongRectFields(JNIEnv *env, jobject lpObject, TXNLongRect *lpStruct);
#else
#define getTXNLongRectFields(a,b,c) NULL
#define setTXNLongRectFields(a,b,c)
#endif

#ifndef NO_ThemeButtonDrawInfo
ThemeButtonDrawInfo *getThemeButtonDrawInfoFields(JNIEnv *env, jobject lpObject, ThemeButtonDrawInfo *lpStruct);
void setThemeButtonDrawInfoFields(JNIEnv *env, jobject lpObject, ThemeButtonDrawInfo *lpStruct);
#else
#define getThemeButtonDrawInfoFields(a,b,c) NULL
#define setThemeButtonDrawInfoFields(a,b,c)
#endif

