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

# Makefile for creating SWT libraries for Linux GTK

include make_common.mak

CC=gcc
LD=gcc

SWT_VERSION=$(maj_ver)$(min_ver)

# Define the installation directories for various products.
# Your system may have these in a different place.
#    JAVA_HOME   - IBM's version of Java (J9)
JAVA_HOME   = /bluebird/teamswt/swt-builddir/ive/bin

# Define the various shared libraries to be build.
WS_PREFIX    		= gtk
SWT_PREFIX   		= swt
SWTPI_PREFIX   	= swt-pi
ATK_PREFIX   		= swt-atk
GNOME_PREFIX	= swt-gnome
SWT_LIB			= lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
SWTPI_LIB		= lib$(SWTPI_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
ATK_LIB				= lib$(ATK_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
GNOME_LIB		= lib$(GNOME_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so

GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
GTKLIBS = `pkg-config --libs gtk+-2.0 gthread-2.0`

ATKCFLAGS = `pkg-config --cflags atk gtk+-2.0`
ATKLIBS = `pkg-config --libs atk gtk+-2.0`

GNOMECFLAGS = `pkg-config --cflags gnome-vfs-module-2.0`
GNOMELIBS = `pkg-config --libs gnome-vfs-module-2.0`

SWT_OBJECTS		= callback.o
SWTPI_OBJECTS	= os.o os_structs.o os_custom.o
ATK_OBJECTS			= atk.o atk_structs.o atk_custom.o
GNOME_OBJECTS	= gnome.o

CFLAGS = -O -Wall												\
		-DSWT_VERSION=$(SWT_VERSION)		\
		-DLINUX -DGTK 											\
		-I$(JAVA_HOME)/include
		
LIBS = -shared -fpic -fPIC

#
#  Target Rules
#

all: make_swt make_atk make_gnome

#
# SWT libs
#
make_swt: $(SWT_LIB) $(SWTPI_LIB)

$(SWT_LIB): $(SWT_OBJECTS)
	$(LD) $(LIBS) -o $(SWT_LIB) $(SWT_OBJECTS)

callback.o: callback.c callback.h
	$(CC) $(CFLAGS) -c callback.c

$(SWTPI_LIB): $(SWTPI_OBJECTS)
	$(LD) $(LIBS) $(GTKLIBS) -o $(SWTPI_LIB) $(SWTPI_OBJECTS)

os.o: os.c os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os.c
os_structs.o: os_structs.c os_structs.h os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_structs.c 
os_custom.o: os_custom.c os_structs.h os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_custom.c

#
# Atk lib
#
make_atk: $(ATK_LIB)

$(ATK_LIB): $(ATK_OBJECTS)
	$(LD) $(LIBS) $(ATKLIBS) -o $(ATK_LIB) $(ATK_OBJECTS)

atk.o: atk.c atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk.c
atk_structs.o: atk_structs.c atk_structs.h atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk_structs.c
atk_custom.o: atk_custom.c atk_structs.h atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk_custom.c

#
# Gnome lib
#
make_gnome: $(GNOME_LIB)

$(GNOME_LIB): $(GNOME_OBJECTS)
	$(LD) $(LIBS) $(GNOMELIBS) -o $(GNOME_LIB) $(GNOME_OBJECTS)

gnome.o: gnome.c 
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome.c

#
# Clean
#
clean:
	rm -f *.o *.so
