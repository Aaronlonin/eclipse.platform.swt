#*******************************************************************************
# Copyright (c) 2000, 2003 IBM Corporation and others.
# All rights reserved. This program and the accompanying materials 
# are made available under the terms of the Common Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/cpl-v10.html
# 
# Contributors:
#     IBM Corporation - initial API and implementation
#*******************************************************************************

# Makefile for SWT libraries on Carbon/Mac

include make_common.mak

SWT_PREFIX=swt
SWTPI_PREFIX=swt-pi
SWTWEBKIT_PREFIX=swt-webkit
WS_PREFIX=carbon
SWT_VERSION=$(maj_ver)$(min_ver)
SWT_LIB=lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).jnilib
SWTPI_LIB=lib$(SWTPI_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).jnilib
WEBKIT_LIB=lib$(SWTWEBKIT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).jnilib

DEBUG =  
CFLAGS = -c -DSWT_VERSION=$(SWT_VERSION) $(DEBUG) -DCARBON -I /System/Library/Frameworks/JavaVM.framework/Versions/1.3.1/Headers
LFLAGS = -bundle -framework JavaVM -framework Carbon 
WEBKITCFLAGS = -c -xobjective-c -I /System/Library/Frameworks/JavaVM.framework/Versions/1.3.1/Headers -I /System/Library/Frameworks/Cocoa.framework/Headers -I /System/Library/Frameworks/WebKit.framework/Headers
WEBKITLFLAGS = $(LFLAGS) -framework WebKit -framework Cocoa
SWT_OBJECTS = callback.o
SWTPI_OBJECTS = os.o os_custom.o os_structs.o os_stats.o
WEBKIT_OBJECTS = webkit.o

all: $(SWT_LIB) $(SWTPI_LIB) $(WEBKIT_LIB)

.c.o:
	cc $(CFLAGS) $*.c

$(SWT_LIB): $(SWT_OBJECTS)
	cc -o $(SWT_LIB) $(LFLAGS) $(SWT_OBJECTS)

$(SWTPI_LIB): $(SWTPI_OBJECTS)
	cc -o $(SWTPI_LIB) $(LFLAGS) $(SWTPI_OBJECTS)
	
webkit.o: webkit.c
	cc $(WEBKITCFLAGS) webkit.c
	
$(WEBKIT_LIB): $(WEBKIT_OBJECTS)
	cc -o $(WEBKIT_LIB) $(WEBKITLFLAGS) $(WEBKIT_OBJECTS)

clean:
	rm -f *.jnilib *.o