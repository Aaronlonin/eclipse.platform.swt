package org.eclipse.swt.tests.junit;
/*
 * (c) Copyright IBM Corp. 2000, 2002. All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import junit.framework.*;
import junit.textui.*;

/**
 * Suite for testing all of the graphics test cases.
 */
public class AllGraphicsTests {
public static void main(String[] args) {
	TestRunner.run (suite());
}
public static Test suite() {
	TestSuite suite = new TestSuite();

	suite.addTest(Test_org_eclipse_swt_graphics_Color.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_Cursor.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_DeviceData.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_Font.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_FontData.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_FontMetrics.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_GC.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_GCData.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_Image.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_ImageData.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_PaletteData.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_Point.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_Rectangle.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_Region.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_RGB.suite());
	
	
	suite.addTest(Test_org_eclipse_swt_graphics_ImageLoader.suite());
	suite.addTest(Test_org_eclipse_swt_graphics_ImageLoaderEvent.suite());

	return suite;
}
}
