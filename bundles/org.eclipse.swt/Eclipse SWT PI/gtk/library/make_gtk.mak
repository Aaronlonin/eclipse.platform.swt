# Copyright (c) IBM Corp. 2000, 2001.  All rights reserved.
#
# The contents of this file are made available under the terms
# of the GNU Lesser General Public License (LGPL) Version 2.1 that
# accompanies this distribution (lgpl-v21.txt).  The LGPL is also
# available at http://www.gnu.org/licenses/lgpl.html.  If the version
# of the LGPL at http://www.gnu.org is different to the version of
# the LGPL accompanying this distribution and there is any conflict
# between the two license versions, the terms of the LGPL accompanying
# this distribution shall govern.
#
# Makefile for creating SWT libraries on Linux

include make_common.mak

SWT_VERSION=$(maj_ver)$(min_ver)

# Define the installation directories for various products.
# Your system may have these in a different place.

# Define the installation directories for various products.
# Your system may have these in a different place.
#    IVE_HOME   - IBM's version of Java (J9)
IVE_HOME   = /bluebird/teamswt/swt-builddir/ive
#IVE_HOME   = /opt/IBMvame1.4/ive

JAVA_JNI=$(IVE_HOME)/bin/include
JAVAH=$(IVE_HOME)/bin/javah
LD_LIBRARY_PATH=$(IVE_HOME)/bin

# Whether we want GTK over X or FB
GTKTARGET = gtk+-2.0
#GTKTARGET = gtk+-linux-fb-2.0

CC = gcc
LD = ld

# Define the various DLL (shared) libraries to be made.

SWT_PREFIX   = swt
WS_PREFIX    = gtk
SWT_DLL      = lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
SWTPI_DLL    = lib$(SWT_PREFIX)-pi-$(WS_PREFIX)-$(SWT_VERSION).so

#GNOME_PREFIX = swt-gnome
#GNOME_DLL    = lib$(GNOME_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
#GNOME_LIB    = -x -shared \
#    -L/usr/lib \
#    -lgnome -lglib \
#    -lm -ldl


# Compile and link options from pkg-config
GTKCFLAGS = `pkg-config --cflags $(GTKTARGET)` `pkg-config --cflags pango`
GTKLIBS = `pkg-config --libs $(GTKTARGET)`


#
#  Target Rules
#

all: make_swt  # make_gnome

make_swt: $(SWT_DLL) $(SWTPI_DLL)

#make_gnome: $(GNOME_DLL)


# All about Linking

PI_OBJECTS = swt.o structs.o

$(SWT_DLL): callback.o
	$(LD) -x -shared \
	    -o $(SWT_DLL) callback.o
	    
$(SWTPI_DLL): $(PI_OBJECTS) structs.o
	$(LD) -x -shared \
	    $(GTKLIBS) \
	    -o $(SWTPI_DLL) $(PI_OBJECTS)

#$(GNOME_DLL): gnome.o
#	$(LD) -o $@ gnome.o $(GNOME_LIB)


# All about Compiling

CFLAGS = -c -O -s \
	    -DSWT_VERSION=$(SWT_VERSION) \
	    -DLINUX -DGTK \
	    -fpic -fPIC \
	    $(GTKCFLAGS) \
	    -I$(JAVA_JNI)

callback.o: callback.c
	$(CC) $(CFLAGS) callback.c

swt.o: swt.c swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) swt.c

structs.o: structs.c
	$(CC) $(CFLAGS) $(GTKCFLAGS) structs.c

clean:
	rm -f *.o *.so
