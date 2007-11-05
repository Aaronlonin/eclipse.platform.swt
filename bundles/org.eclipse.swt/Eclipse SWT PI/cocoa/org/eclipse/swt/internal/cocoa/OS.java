package org.eclipse.swt.internal.cocoa;

import org.eclipse.swt.internal.*;

public class OS extends C {
	static {
		Library.loadLibrary("swt-pi"); //$NON-NLS-1$
	}

	/** Constants */
	public static final int NSBackingStoreRetained     = 0;
	public static final int NSBackingStoreNonretained  = 1;
	public static final int NSBackingStoreBuffered     = 2;	
	public static final int NSBorderlessWindowMask = 0;
	public static final int NSTitledWindowMask = 1 << 0;
	public static final int NSClosableWindowMask = 1 << 1;
	public static final int NSMiniaturizableWindowMask = 1 << 2;
	public static final int NSResizableWindowMask = 1 << 3;
	public static final int NSTexturedBackgroundWindowMask = 1 << 8;
	public static final int kProcessTransformToForegroundApplication = 1;
	public static final int noErr = 0;
	
	public static final int NSMomentaryLightButton   = 0;
	public static final int NSPushOnPushOffButton    = 1;
	public static final int NSToggleButton           = 2;
	public static final int NSSwitchButton           = 3;
	public static final int NSRadioButton            = 4;
	public static final int NSMomentaryChangeButton  = 5;
	public static final int NSOnOffButton            = 6;
	public static final int NSMomentaryPushInButton  = 7;
	public static final int NSMomentaryPushButton    = 0;
	public static final int NSMomentaryLight         = 7;
	
	public static final int NSRoundedBezelStyle           = 1;
	public static final int NSRegularSquareBezelStyle     = 2;
	public static final int NSThickSquareBezelStyle       = 3;
	public static final int NSThickerSquareBezelStyle     = 4;
	public static final int NSDisclosureBezelStyle        = 5;
	public static final int NSShadowlessSquareBezelStyle  = 6;
	public static final int NSCircularBezelStyle          = 7;
	public static final int NSTexturedSquareBezelStyle    = 8;
	public static final int NSHelpButtonBezelStyle        = 9;
	public static final int NSSmallSquareBezelStyle       = 10;
	public static final int NSTexturedRoundedBezelStyle   = 11;
	public static final int NSRoundRectBezelStyle         = 12;
	public static final int NSRecessedBezelStyle          = 13;
	public static final int NSRoundedDisclosureBezelStyle = 14;
	
	public static final int NSAlphaFirstBitmapFormat            = 1 << 0;
	public static final int NSAlphaNonpremultipliedBitmapFormat = 1 << 1;
	public static final int NSFloatingPointSamplesBitmapFormat  = 1 << 2;
	
	public static final int NSNoImage       = 0;
	public static final int NSImageOnly     = 1;
	public static final int NSImageLeft     = 2;
	public static final int NSImageRight    = 3;
	public static final int NSImageBelow    = 4;
	public static final int NSImageAbove    = 5;
	public static final int NSImageOverlaps = 6;
	
	public static final int NSMixedState = -1;
	public static final int NSOffState   = 0;
	public static final int NSOnState    = 1;

	public static final int NSImageInterpolationDefault = 0;
	public static final int NSImageInterpolationNone = 1;
	public static final int NSImageInterpolationLow = 2;
	public static final int NSImageInterpolationHigh = 3;
	
	public static final int NSCompositeClear           = 0;
	public static final int NSCompositeCopy            = 1;
	public static final int NSCompositeSourceOver      = 2;
	public static final int NSCompositeSourceIn        = 3;
	public static final int NSCompositeSourceOut       = 4;
	public static final int NSCompositeSourceAtop      = 5;
	public static final int NSCompositeDestinationOver = 6;
	public static final int NSCompositeDestinationIn   = 7;
	public static final int NSCompositeDestinationOut  = 8;
	public static final int NSCompositeDestinationAtop = 9;
	public static final int NSCompositeXOR             = 10;
	public static final int NSCompositePlusDarker      = 11;
	public static final int NSCompositeHighlight       = 12;
	public static final int NSCompositePlusLighter     = 13;
	
	/** Classes */
	public static final int class_NSObject = OS.objc_getClass("NSObject");
	public static final int class_NSString = OS.objc_getClass("NSString");
	public static final int class_NSToolbarView = OS.objc_getClass("NSToolbarView");
	public static final int class_NSGradient = OS.objc_getClass("NSGradient");
	public static final int class_NSView = OS.objc_getClass("NSView");
	public static final int class_NSImage = OS.objc_getClass("NSImage");
	public static final int class_NSBezierPath = OS.objc_getClass("NSBezierPath");
	public static final int class_NSAffineTransform = OS.objc_getClass("NSAffineTransform");
	public static final int class_NSBitmapImageRep = OS.objc_getClass("NSBitmapImageRep");
	public static final int class_NSImageRep = OS.objc_getClass("NSImageRep");
	public static final int class_NSScrollView = OS.objc_getClass("NSScrollView");
	public static final int class_NSButton = OS.objc_getClass("NSButton");
	public static final int class_NSArray = OS.objc_getClass("NSArray");
	public static final int class_NSColor = OS.objc_getClass("NSColor");
	public static final int class_NSFont = OS.objc_getClass("NSFont");
	public static final int class_NSCursor = OS.objc_getClass("NSCursor");
	public static final int class_NSApplication = OS.objc_getClass("NSApplication");
	public static final int class_NSWindow = OS.objc_getClass("NSWindow");
	public static final int class_NSScreen = OS.objc_getClass("NSScreen");
	public static final int class_NSAutoreleasePool = OS.objc_getClass("NSAutoreleasePool");
	public static final int class_NSProgressIndicator = OS.objc_getClass("NSProgressIndicator");
	public static final int class_NSGraphicsContext = OS.objc_getClass("NSGraphicsContext");
	
	/** Selectors */	
	public static final int sel_drawInRect_1fromRect_1operation_1fraction_1 = OS.sel_registerName("drawInRect:fromRect:operation:fraction:");
	public static final int sel_addCursorRect_1cursor_1 = OS.sel_registerName("addCursorRect:cursor:");
	public static final int sel_addSubview_1 = OS.sel_registerName("addSubview:");
	public static final int sel_addRepresentation_1 = OS.sel_registerName("addRepresentation:");
	public static final int sel_alloc = OS.sel_registerName("alloc");
	public static final int sel_alphaValue = OS.sel_registerName("alphaValue");
	public static final int sel_appendBezierPath_1 = OS.sel_registerName("appendBezierPath:");
	public static final int sel_appendBezierPathWithOvalInRect_1= OS.sel_registerName("appendBezierPathWithOvalInRect:");
	public static final int sel_appendBezierPathWithRect_1 = OS.sel_registerName("appendBezierPathWithRect:");
	public static final int sel_appendBezierPathWithRoundedRect_1xRadius_1yRadius_1 = OS.sel_registerName("appendBezierPathWithRoundedRect:xRadius:yRadius:");
	public static final int sel_arrowCursor = OS.sel_registerName("arrowCursor");
	public static final int sel_bestRepresentationForDevice_1 = OS.sel_registerName("bestRepresentationForDevice:");
	public static final int sel_bezierPath = OS.sel_registerName("bezierPath");
	public static final int sel_bezierPathWithOvalInRect_1 = OS.sel_registerName("bezierPathWithOvalInRect:");
	public static final int sel_bitmapData = OS.sel_registerName("bitmapData");
	public static final int sel_cascadeTopLeftFromPoint_1 = OS.sel_registerName("cascadeTopLeftFromPoint:");
	public static final int sel_close = OS.sel_registerName("close");
	public static final int sel_closePath = OS.sel_registerName("closePath");
	public static final int sel_colorWithDeviceRed_1green_1blue_1alpha_1 = OS.sel_registerName("colorWithDeviceRed:green:blue:alpha:");	
	public static final int sel_concat = OS.sel_registerName("concat");
	public static final int sel_contentView = OS.sel_registerName("contentView");
	public static final int sel_controlPointBounds = OS.sel_registerName("controlPointBounds");
	public static final int sel_copy = OS.sel_registerName("copy");
	public static final int sel_count = OS.sel_registerName("count");
	public static final int sel_crosshairCursor = OS.sel_registerName("crosshairCursor");
	public static final int sel_currentPoint = OS.sel_registerName("currentPoint");
	public static final int sel_curveToPoint_1controlPoint1_1controlPoint2_1 = OS.sel_registerName("curveToPoint:controlPoint1:controlPoint2:");
	public static final int sel_depth = OS.sel_registerName("depth");
	public static final int sel_doubleValue = OS.sel_registerName("doubleValue");
	public static final int sel_drawAtPoint_1withAttributes_1 = OS.sel_registerName("drawAtPoint:withAttributes:");
	public static final int sel_drawInRect_1angle_1 = OS.sel_registerName("drawInRect:angle:");
	public static final int sel_familyName = OS.sel_registerName("familyName");
	public static final int sel_fill = OS.sel_registerName("fill");
	public static final int sel_fontName = OS.sel_registerName("fontName");
	public static final int sel_fontWithName_1size_1 = OS.sel_registerName("fontWithName:size:");
	public static final int sel_font = OS.sel_registerName("font");
	public static final int sel_frame = OS.sel_registerName("frame");
	public static final int sel_graphicsContextWithBitmapImageRep_1 = OS.sel_registerName("graphicsContextWithBitmapImageRep:");
	public static final int sel_getCharacters_1 = OS.sel_registerName("getCharacters:");
	public static final int sel_IBeamCursor = OS.sel_registerName("IBeamCursor");
	public static final int sel_imageInterpolation = OS.sel_registerName("imageInterpolation");
	public static final int sel_init = OS.sel_registerName("init");
	public static final int sel_initWithBitmapDataPlanes_1pixelsWide_1pixelsHigh_1bitsPerSample_1samplesPerPixel_1hasAlpha_1isPlanar_1colorSpaceName_1bitmapFormat_1bytesPerRow_1bitsPerPixel_1 = OS.sel_registerName("initWithBitmapDataPlanes:pixelsWide:pixelsHigh:bitsPerSample:samplesPerPixel:hasAlpha:isPlanar:colorSpaceName:bitmapFormat:bytesPerRow:bitsPerPixel:");
	public static final int sel_initWithFrame_1 = OS.sel_registerName("initWithFrame:");
	public static final int sel_initWithContentRect_1styleMask_1backing_1defer_1 = OS.sel_registerName("initWithContentRect:styleMask:backing:defer:");
	public static final int sel_initWithImage_1hotSpot_1 = OS.sel_registerName("initWithImage:hotSpot:");
	public static final int sel_initWithSize_1 = OS.sel_registerName("initWithSize:");
	public static final int sel_initWithTransform_1 = OS.sel_registerName("initWithTransform:");
	public static final int sel_initWithStartingColor_endingColor_1 = OS.sel_registerName("initWithStartingColor:endingColor:");
	public static final int sel_invert = OS.sel_registerName("invert");
	public static final int sel_isFlipped = OS.sel_registerName("isFlipped");
	public static final int sel_isVisible = OS.sel_registerName("isVisible");
	public static final int sel_keyDown_1 = OS.sel_registerName("keyDown:");
	public static final int sel_length = OS.sel_registerName("length");
	public static final int sel_lineToPoint_1 = OS.sel_registerName("lineToPoint:");
	public static final int sel_mainScreen = OS.sel_registerName("mainScreen");
	public static final int sel_makeKeyAndOrderFront_1 = OS.sel_registerName("makeKeyAndOrderFront:");
	public static final int sel_maxValue = OS.sel_registerName("maxValue");
	public static final int sel_minValue = OS.sel_registerName("minValue");
	public static final int sel_mouseDown_1 = OS.sel_registerName("mouseDown:");
	public static final int sel_moveToPoint_1 = OS.sel_registerName("moveToPoint:");
	public static final int sel_new = OS.sel_registerName("new");
	public static final int sel_objectAtIndex_1 = OS.sel_registerName("objectAtIndex:");	
	public static final int sel_orderFront_1 = OS.sel_registerName("orderFront:");
	public static final int sel_orderOut_1 = OS.sel_registerName("orderOut:");
	public static final int sel_prependTransform_1 = OS.sel_registerName("prependTransform:");
	public static final int sel_pointingHandCursor = OS.sel_registerName("pointingHandCursor");
	public static final int sel_pointSize = OS.sel_registerName("pointSize");
	public static final int sel_release = OS.sel_registerName("release");
	public static final int sel_removeAllPoints = OS.sel_registerName("removeAllPoints");
	public static final int sel_resizeLeftRightCursor = OS.sel_registerName("resizeLeftRightCursor");
	public static final int sel_resizeRightCursor = OS.sel_registerName("resizeRightCursor");
	public static final int sel_resizeLeftCursor = OS.sel_registerName("resizeLeftCursor");
	public static final int sel_resizeDownCursor = OS.sel_registerName("resizeDownCursor");
	public static final int sel_resizeUpCursor = OS.sel_registerName("resizeUpCursor");
	public static final int sel_resizeUpDownCursor = OS.sel_registerName("resizeUpDownCursor");
	public static final int sel_respondsToSelector_1 = OS.sel_registerName("respondsToSelector:");
	public static final int sel_restoreGraphicsState = OS.sel_registerName("restoreGraphicsState");
	public static final int sel_rotateByDegrees_1 = OS.sel_registerName("rotateByDegrees_1");
	public static final int sel_run = OS.sel_registerName("run");
	public static final int sel_saveGraphicsState = OS.sel_registerName("saveGraphicsState");
	public static final int sel_scaleXBy_1yBy_1 = OS.sel_registerName("scaleXBy:yBy:");
	public static final int sel_screens = OS.sel_registerName("screens");
	public static final int sel_set = OS.sel_registerName("set");
	public static final int sel_setAction_1 = OS.sel_registerName("setAction:");
	public static final int sel_setAlphaValue_1 = OS.sel_registerName("setAlphaValue:");
	public static final int sel_setImagePosition_1 = OS.sel_registerName("setImagePosition:");
	public static final int sel_setBackgroundColor_1 = OS.sel_registerName("setBackgroundColor:");	
	public static final int sel_setBezelStyle_1 = OS.sel_registerName("setBezelStyle:");
	public static final int sel_setButtonType_1 = OS.sel_registerName("setButtonType:");
	public static final int sel_setContentView_1 = OS.sel_registerName("setContentView:");
	public static final int sel_setCurrentContext_1 = OS.sel_registerName("setCurrentContext:");
	public static final int sel_setDoubleValue_1 = OS.sel_registerName("setDoubleValue:");
	public static final int sel_setDelegate_1 = OS.sel_registerName("setDelegate:");
	public static final int sel_setFont_1 = OS.sel_registerName("setFont:");
	public static final int sel_setFrame_1 = OS.sel_registerName("setFrame:");
	public static final int sel_setFrameOrigin_1 = OS.sel_registerName("setFrameOrigin:");
	public static final int sel_setFrameSize_1 = OS.sel_registerName("setFrameSize:");
	public static final int sel_setHidden_1 = OS.sel_registerName("setHidden:");
	public static final int sel_setImage_1 = OS.sel_registerName("setImage:");
	public static final int sel_setImageInterpolation_1 = OS.sel_registerName("setImageInterpolation:");
	public static final int sel_setIndeterminate_1 = OS.sel_registerName("setIndeterminate:");
	public static final int sel_setLineWidth_1 = OS.sel_registerName("setLineWidth:");
	public static final int sel_setMinValue_1 = OS.sel_registerName("setMinValue:");
	public static final int sel_setMaxValue_1 = OS.sel_registerName("setMaxValue:");
	public static final int sel_setOnMouseEntered_1 = OS.sel_registerName("setOnMouseEntered:");
	public static final int sel_setState_1 = OS.sel_registerName("setState:");
	public static final int sel_setShouldAntialias_1 = OS.sel_registerName("setShouldAntialias:");
	public static final int sel_setTag_1 = OS.sel_registerName("setTag:");
	public static final int sel_setTarget_1 = OS.sel_registerName("setTarget:");
	public static final int sel_setTitle_1 = OS.sel_registerName("setTitle:");
	public static final int sel_setTransformStruct_1 = OS.sel_registerName("setTransformStruct:");
	public static final int sel_setFrameTopLeftPoint_1 = OS.sel_registerName("setFrameTopLeftPoint:");
	public static final int sel_sharedApplication = OS.sel_registerName("sharedApplication");
	public static final int sel_size = OS.sel_registerName("size");
	public static final int sel_sizeWithAttributes_1 = OS.sel_registerName("sizeWithAttributes:");
	public static final int sel_startAnimation_1 = OS.sel_registerName("startAnimation:");
	public static final int sel_state = OS.sel_registerName("state");
	public static final int sel_stop_1 = OS.sel_registerName("stop:");
	public static final int sel_stringWithCharacters_1length_1 = OS.sel_registerName("stringWithCharacters:length:");
	public static final int sel_stringWithUTF8String_1 = OS.sel_registerName("stringWithUTF8String:");	
	public static final int sel_stroke = OS.sel_registerName("stroke");
	public static final int sel_tag = OS.sel_registerName("tag");
	public static final int sel_transform = OS.sel_registerName("transform");
	public static final int sel_transformPoint_1 = OS.sel_registerName("transformPoint:");
	public static final int sel_transformStruct = OS.sel_registerName("transformStruct");
	public static final int sel_translateXBy_1yBy_1 = OS.sel_registerName("translateXBy:yBy:");
	public static final int sel_visibleFrame = OS.sel_registerName("visibleFrame");
	public static final int sel_windowWillClose_1 = OS.sel_registerName("windowWillClose:");
	public static final int sel_windowShouldClose_1 = OS.sel_registerName("windowShouldClose:");
	
	

	public static final int sel_sendSelection = OS.sel_registerName("sendSelection");	
	

	//TODO - don't hard code
	public static final int VERSION = 0x1040;
	public static final int PTR_SIZEOF = 4;

/** JNI natives */
public static final native int NewGlobalRef(Object object);
public static final native void DeleteGlobalRef(int globalRef);
public static final native Object JNIGetObject(int globalRef);
	
public static final native boolean class_addIvar(int cls, String name, int size, byte alignment, String types);
public static final native boolean class_addMethod(int cls, int name, int imp, String types);
public static final native int objc_allocateClassPair(int superclass, String name, int extraBytes);
public static final native int objc_getClass(String className);
public static final native int objc_lookUpClass(String className);
public static final native void objc_msgSend_stret(NSPoint result, int object, int selector);
public static final native void objc_msgSend_stret(NSPoint result, int object, int selector, NSPoint arg0);
public static final native void objc_msgSend_stret(float[] result, int object, int selector);
public static final native void objc_msgSend_stret(NSRect result, int object, int selector);
public static final native void objc_msgSend_stret(NSSize result, int object, int selector);
public static final native double objc_msgSend_fpret(int object, int selector);
public static final native int objc_msgSend(int object, int selector);
public static final native int objc_msgSend(int object, int selector, int arg0);
public static final native int objc_msgSend(int object, int selector, String arg0);
public static final native int objc_msgSend(int object, int selector, float arg0);
public static final native int objc_msgSend(int object, int selector, double arg0);
public static final native int objc_msgSend(int object, int selector, float[] arg0);
public static final native int objc_msgSend(int object, int selector, float arg0, float arg1);
public static final native int objc_msgSend(int object, int selector, int arg0, float arg1);
public static final native int objc_msgSend(int object, int selector, float arg0, float arg1, float arg2, float arg3);
public static final native int objc_msgSend(int object, int selector, NSSize arg0);
public static final native int objc_msgSend(int object, int selector, NSRect arg0);
public static final native int objc_msgSend(int object, int selector, NSRect arg0, int arg1, int arg2, boolean arg3);
public static final native int objc_msgSend(int object, int selector, NSRect arg0, float arg1, float arg2);
public static final native int objc_msgSend(int object, int selector, NSRect arg0, float arg1);
public static final native int objc_msgSend(int object, int selector, int arg0, NSRect arg1, int arg2);
public static final native int objc_msgSend(int object, int selector, NSRect arg0, int arg1);
public static final native int objc_msgSend(int object, int selector, NSRect arg0, NSRect arg1, int arg2, float arg3);
public static final native int objc_msgSend(int object, int selector, char[] arg0);
public static final native int objc_msgSend(int object, int selector, char[] arg0, int arg1);
public static final native int objc_msgSend(int object, int selector, NSPoint arg0, int arg1);
public static final native int objc_msgSend(int object, int selector, NSPoint arg0, NSPoint arg1, NSPoint arg2);
public static final native int objc_msgSend(int object, int selector, int arg0, NSPoint arg1);
public static final native int objc_msgSend(int object, int selector, NSPoint arg0);
public static final native int objc_msgSend(int object, int selector, int arg0, int arg1);
public static final native int objc_msgSend(int object, int selector, int arg0, int arg1, int arg2);
public static final native int objc_msgSend(int object, int selector, int arg0, int arg1, int arg2, int arg3);
public static final native int objc_msgSend(int object, int selector, int[] arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10);
public static final native void objc_registerClassPair(int cls);
public static final native int object_getClassName(int obj);
public static final native int object_getInstanceVariable(int obj, String name, int[] outValue);
public static final native int object_setInstanceVariable(int obj, String name, int value);
public static final native int sel_registerName(String selectorName);

public static final native int NSBitsPerPixelFromDepth(int depth);
public static final native int NSDeviceRGBColorSpace();

public static final native int NSFontAttributeName();
public static final native int NSParagraphStyleAttributeName();
public static final native int NSForegroundColorAttributeName();
public static final native int NSUnderlineStyleAttributeName();
public static final native int NSSuperscriptAttributeName();
public static final native int NSBackgroundColorAttributeName();
public static final native int NSAttachmentAttributeName();
public static final native int NSLigatureAttributeName();
public static final native int NSBaselineOffsetAttributeName();
public static final native int NSKernAttributeName();
public static final native int NSLinkAttributeName();
public static final native int NSStrokeWidthAttributeName();
public static final native int NSStrokeColorAttributeName();
public static final native int NSUnderlineColorAttributeName();
public static final native int NSStrikethroughStyleAttributeName();
public static final native int NSStrikethroughColorAttributeName();
public static final native int NSShadowAttributeName();
public static final native int NSObliquenessAttributeName();
public static final native int NSExpansionAttributeName();
public static final native int NSCursorAttributeName();
public static final native int NSToolTipAttributeName();
public static final native int NSMarkedClauseSegmentAttributeName();

public static final native int GetCurrentProcess(int[] psn);
public static final native int SetFrontProcess(int[] psn);
public static final native int TransformProcessType(int[] psn, int transformState);  
}
