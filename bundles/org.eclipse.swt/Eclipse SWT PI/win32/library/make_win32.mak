#*******************************************************************************
# Copyright (c) 2000, 2005 IBM Corporation and others.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v10.html
# 
# Contributors:
#     IBM Corporation - initial API and implementation
#*******************************************************************************

# Makefile for SWT libraries on Windows

# assumes JAVA_HOME is set in the environment from which nmake is run

APPVER=5.0
!include <make_common.mak>
!include <win32.mak>

pgm_ver_str="SWT $(maj_ver).$(min_ver) for Windows"
timestamp_str=__DATE__\" \"__TIME__\" (EST)\"
copyright = "Copyright (C) 1999, 2004 IBM Corp.  All rights reserved."

SWT_PREFIX  = swt
WS_PREFIX   = win32
SWT_VERSION = $(maj_ver)$(min_ver)
SWT_LIB     = $(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).dll
SWT_LIBS    = ole32.lib comctl32.lib user32.lib gdi32.lib comdlg32.lib kernel32.lib shell32.lib oleaut32.lib advapi32.lib imm32.lib winspool.lib oleacc.lib usp10.lib wininet.lib
SWT_OBJS    = swt.obj callback.obj c.obj c_stats.obj os.obj os_structs.obj os_custom.obj os_stats.obj com_structs.obj com.obj com_stats.obj com_custom.obj

GDIP_PREFIX  = swt-gdip
GDIP_LIB     = $(GDIP_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).dll
GDIP_LIBS    = gdi32.lib gdiplus.lib
GDIP_OBJS    = gdip.obj gdip_structs.obj gdip_stats.obj gdip_custom.obj

AWT_PREFIX = swt-awt
AWT_LIB    = $(AWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).dll
AWT_LIBS   = $(JAVA_HOME)\jre\bin\jawt.lib
AWT_OBJS   = swt_awt.obj

WGL_PREFIX = swt-wgl
WGL_LIB    = $(WGL_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).dll
WGL_LIBS   = opengl32.lib gdi32.lib
WGL_OBJS   = wgl.obj wgl_structs.obj wgl_stats.obj

# Uncomment for Native Stats tool
#NATIVE_STATS = -DNATIVE_STATS

# Uncomment for debug flags
#SWT_CDEBUG = -Zi -Odi
#SWT_LDEBUG = /DEBUG /DEBUGTYPE:both

XULRUNNER_PREFIX = swt-xulrunner
XULRUNNER_LIB = $(XULRUNNER_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).dll
XULRUNNER_LIBS = Advapi32.lib $(XULRUNNER_SDK)\lib\xpcomglue.lib
XULRUNNER_OBJS = xpcom.obj xpcom_custom.obj xpcom_structs.obj xpcom_stats.obj xpcomglue.obj xpcomglue_stats.obj

XPCOMINIT_PREFIX = swt-xpcominit
XPCOMINIT_LIB = $(XPCOMINIT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).dll
XPCOMINIT_OBJS = xpcominit.obj xpcominit_structs.obj xpcominit_stats.obj

MOZILLACFLAGS = -c \
	-O1 \
	$(SWT_CDEBUG) \
	-DSWT_VERSION=$(SWT_VERSION) \
	$(NATIVE_STATS) \
	-MD \
	-DMOZILLA_STRICT_API=1 \
	-W3 \
	-I. \
	-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/win32 \
	/I$(XULRUNNER_SDK)\include\mozilla-config.h /I$(XULRUNNER_SDK)\include

# note: thoroughly test all examples after changing any optimization flags
SWT_WINDOWS_SDK = -DWINVER=0x0500 -D_WIN32_WINDOWS=0x0400 -D_WIN32_WINNT=0x501 -D_WIN32_IE=0x0500
CFLAGS = -c -W3 -G6 -GD -O1 $(SWT_CDEBUG) -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DUSE_ASSEMBLER $(SWT_WINDOWS_SDK) -DVC_EXTRALEAN -nologo -MT -D_X86_=1 -DWIN32 -D_WIN32 -D_WIN32_DCOM /I$(JAVA_HOME)\include /I$(JAVA_HOME)\include\win32 /I.
RCFLAGS = -DSWT_FILE_VERSION=\"$(maj_ver).$(min_ver)\" -DSWT_COMMA_VERSION=$(comma_ver)
LFLAGS = /INCREMENTAL:NO /PDB:NONE /RELEASE /NOLOGO $(SWT_LDEBUG) -entry:_DllMainCRTStartup@12 -dll /BASE:0x10000000 /comment:$(pgm_ver_str) /comment:$(copyright) /DLL

all: $(SWT_LIB) $(AWT_LIB) $(GDIP_LIB) $(WGL_LIB) $(XULRUNNER_LIB) $(XPCOMINIT_LIB)

xpcom_custom.obj: xpcom_custom.cpp
	cl $(MOZILLACFLAGS) xpcom_custom.cpp
xpcom_stats.obj: xpcom_stats.cpp
	cl $(MOZILLACFLAGS) xpcom_stats.cpp
xpcom_structs.obj: xpcom_structs.cpp
	cl $(MOZILLACFLAGS) xpcom_structs.cpp
xpcom.obj: xpcom.cpp
	cl $(MOZILLACFLAGS) xpcom.cpp
xpcomglue.obj: xpcomglue.cpp
	cl $(MOZILLACFLAGS) xpcomglue.cpp
xpcomglue_stats.obj: xpcomglue_stats.cpp
	cl $(MOZILLACFLAGS) xpcomglue_stats.cpp
xpcominit_stats.obj: xpcominit_stats.cpp
	cl $(MOZILLACFLAGS) xpcominit_stats.cpp
xpcominit_structs.obj: xpcominit_structs.cpp
	cl $(MOZILLACFLAGS) xpcominit_structs.cpp
xpcominit.obj: xpcominit.cpp
	cl $(MOZILLACFLAGS) xpcominit.cpp

.c.obj:
	cl $(CFLAGS) $*.c

.cpp.obj:
	cl $(CFLAGS) $*.cpp

$(SWT_LIB): $(SWT_OBJS) swt.res
	echo $(LFLAGS) >templrf
	echo $(SWT_LIBS) >>templrf
	echo -machine:IX86 >>templrf
	echo -subsystem:windows >>templrf
	echo -out:$(SWT_LIB) >>templrf
	echo $(SWT_OBJS) >>templrf
	echo swt.res >>templrf
	link @templrf
	del templrf

$(GDIP_LIB): $(GDIP_OBJS) swt_gdip.res
	echo $(LFLAGS) >templrf
	echo $(GDIP_LIBS) >>templrf
	echo -machine:IX86 >>templrf
	echo -subsystem:windows >>templrf
	echo -out:$(GDIP_LIB) >>templrf
	echo $(GDIP_OBJS) >>templrf
	echo swt_gdip.res >>templrf
	link @templrf
	del templrf

$(AWT_LIB): $(AWT_OBJS) swt_awt.res
	echo $(LFLAGS) >templrf
	echo $(AWT_LIBS) >>templrf
	echo -machine:IX86 >>templrf
	echo -subsystem:windows >>templrf
	echo -out:$(AWT_LIB) >>templrf
	echo $(AWT_OBJS) >>templrf
	echo swt_awt.res >>templrf
	link @templrf
	del templrf

$(WGL_LIB): $(WGL_OBJS) swt_wgl.res
	echo $(LFLAGS) >templrf
	echo $(WGL_LIBS) >>templrf
	echo -machine:IX86 >>templrf
	echo -subsystem:windows >>templrf
	echo -out:$(WGL_LIB) >>templrf
	echo $(WGL_OBJS) >>templrf
	echo swt_wgl.res >>templrf
	link @templrf
	del templrf
	
$(XULRUNNER_LIB): $(XULRUNNER_OBJS) swt_xpcom.res
	echo $(LFLAGS) >templrf
	echo $(XULRUNNER_LIBS) >>templrf
	echo -machine:IX86 >>templrf
	echo -subsystem:windows >>templrf
	echo -out:$(XULRUNNER_LIB) >>templrf
	echo $(XULRUNNER_OBJS) >>templrf
	link @templrf
	
$(XPCOMINIT_LIB): $(XPCOMINIT_OBJS) swt_xpcominit.res
	echo $(LFLAGS) >templrf
	echo $(XULRUNNER_LIBS) >>templrf
	echo -machine:IX86 >>templrf
	echo -subsystem:windows >>templrf
	echo -out:$(XPCOMINIT_LIB) >>templrf
	echo $(XPCOMINIT_OBJS) >>templrf
	link @templrf

swt.res:
	rc $(RCFLAGS) -DSWT_ORG_FILENAME=\"$(SWT_LIB)\" -r -fo swt.res swt.rc

swt_gdip.res:
	rc $(RCFLAGS) -DSWT_ORG_FILENAME=\"$(GDIP_LIB)\" -r -fo swt_gdip.res swt_gdip.rc

swt_awt.res:
	rc $(RCFLAGS) -DSWT_ORG_FILENAME=\"$(AWT_LIB)\" -r -fo swt_awt.res swt_awt.rc

swt_wgl.res:
	rc $(RCFLAGS) -DSWT_ORG_FILENAME=\"$(WGL_LIB)\" -r -fo swt_wgl.res swt_wgl.rc

swt_xpcom.res:
	rc $(RCFLAGS) -DSWT_ORG_FILENAME=\"$(XULRUNNER_LIB)\" -r -fo swt_xpcom.res swt_xpcom.rc

swt_xpcominit.res:
	rc $(RCFLAGS) -DSWT_ORG_FILENAME=\"$(XPCOMINIT_LIB)\" -r -fo swt_xpcom.res swt_xpcom.rc

install: all
	copy *.dll $(OUTPUT_DIR)

clean:
    del *.obj *.res *.dll *.lib *.exp
