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

# Define the installation directories for various products.
JAVA_HOME   = /bluebird/teamswt/swt-builddir/ive/bin

# Define the various shared libraries to be made.
SWT_PREFIX   = gl
WS_PREFIX    = gtk
SWT_DLL      = lib$(SWT_PREFIX)-$(WS_PREFIX).so
SWT_OBJ      = gl.c glu.c gtkglext.c

GTKLIBS = `pkg-config --libs gthread-2.0 gtk+-2.0 gdkglext-1.0 gtkglext-1.0` -L/usr/X11R6/lib -lGL -lGLU -lm 
GTKCFLAGS = `pkg-config --cflags gtk+-2.0 gdkglext-1.0 gtkglext-1.0`

#
# The following CFLAGS are for compiling the SWT OpenGL library.
#
CFLAGS = -O -s -shared \
	-I./ \
	-I$(JAVA_HOME)/include \
	$(GTKCFLAGS) \
	-Wall

all: make_swt

make_swt: $(SWT_DLL)

$(SWT_DLL): $(SWT_OBJ)
	gcc  $(CFLAGS) $(GTKLIBS) -o $(SWT_DLL) $(SWT_OBJ)
	
clean:
	rm -f *.so *.o
