#*******************************************************************************
# Copyright (c) 2000, 2004 IBM Corporation and others.
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

SWT_VERSION=$(maj_ver)$(min_ver)

# Define the various shared libraries to be build.
WS_PREFIX = gtk
SWT_PREFIX = swt
AWT_PREFIX = swt-awt
SWTPI_PREFIX = swt-pi
ATK_PREFIX = swt-atk
KDE_PREFIX = swt-kde
GNOME_PREFIX = swt-gnome
MOZILLA_PREFIX = swt-mozilla
SWT_LIB = lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
AWT_LIB = lib$(AWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
SWTPI_LIB = lib$(SWTPI_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
ATK_LIB = lib$(ATK_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
GNOME_LIB = lib$(GNOME_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
KDE_LIB = lib$(KDE_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
MOZILLA_LIB = lib$(MOZILLA_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so

GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
GTKLIBS = `pkg-config --libs gtk+-2.0` -L$(XTEST_LIB_PATH) -lXtst

AWT_LIBS = -L$(AWT_LIB_PATH) -ljawt -shared

ATKCFLAGS = `pkg-config --cflags atk gtk+-2.0`
ATKLIBS = `pkg-config --libs atk gtk+-2.0`

GNOMECFLAGS = `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
GNOMELIBS = `pkg-config --libs gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`

KDE_LIBS = -L/usr/lib  -L$(QT_HOME)/lib -shared  -lkdecore -lqt -lkparts
KDE_CFLAGS = -fno-rtti -c -O -I/usr/include/kde -I$(QT_HOME)/include -I$(JAVA_HOME)/include

MOZILLACFLAGS = -O \
	-DXPCOM_GLUE=1 \
	-DMOZILLA_STRICT_API=1 \
	-fno-rtti \
	-fno-exceptions \
	-Wall \
	-Wno-non-virtual-dtor \
	-fPIC \
	-I./ \
	-I$(GECKO_SDK)	\
	-include $(GECKO_SDK)/mozilla-config.h \
	-I$(GECKO_SDK)/nspr/include \
	-I$(GECKO_SDK)/xpcom/include \
	-I$(GECKO_SDK)/string/include \
	-I$(GECKO_SDK)/embed_base/include \
	-I$(GECKO_SDK)/embedstring/include
MOZILLALIBS = -shared -Wl,--version-script=mozilla_exports -Bsymbolic \
	-L$(GECKO_SDK)/embedstring/bin -lembedstring \
	-L$(GECKO_SDK)/embed_base/bin -lembed_base_s \
	-L$(GECKO_SDK)/xpcom/bin -lxpcomglue_s -lxpcom \
	-L$(GECKO_SDK)/nspr/bin -lnspr4 -lplds4 -lplc4

SWT_OBJECTS = swt.o callback.o
AWT_OBJECTS = swt_awt.o
SWTPI_OBJECTS = swt.o os.o os_structs.o os_custom.o os_stats.o
ATK_OBJECTS = swt.o atk.o atk_structs.o atk_custom.o atk_stats.o
GNOME_OBJECTS = swt.o gnome.o gnome_structs.o gnome_stats.o
KDE_OBJS = swt.o kde.o kde_stats.o
MOZILLA_OBJECTS = swt.o xpcom.o xpcom_custom.o xpcom_structs.o xpcom_stats.o
 
CFLAGS = -O -Wall \
		-DSWT_VERSION=$(SWT_VERSION) \
		-DLINUX -DGTK \
		-I$(JAVA_HOME)/include \
		-fpic \
		${SWT_PTR_CFLAGS}
LIBS = -shared -fpic


all: make_swt make_atk make_gnome make_awt make_kde

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

swt.o: swt.c swt.h
	$(CC) $(CFLAGS) -c swt.c
os.o: os.c os.h swt.h os_custom.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os.c
os_structs.o: os_structs.c os_structs.h os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_structs.c 
os_custom.o: os_custom.c os_structs.h os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_custom.c
os_stats.o: os_stats.c os_structs.h os.h os_stats.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_stats.c

#
# AWT lib
#
make_awt:$(AWT_LIB)

$(AWT_LIB): $(AWT_OBJECTS)
	$(LD) $(AWT_LIBS) -o $(AWT_LIB) $(AWT_OBJECTS)

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
atk_stats.o: atk_stats.c atk_structs.h atk_stats.h atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk_stats.c

#
# Gnome lib
#
make_gnome: $(GNOME_LIB)

$(GNOME_LIB): $(GNOME_OBJECTS)
	$(LD) $(LIBS) $(GNOMELIBS) -o $(GNOME_LIB) $(GNOME_OBJECTS)

gnome.o: gnome.c 
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome.c

gnome_structs.o: gnome_structs.c 
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome_structs.c
	
gnome_stats.o: gnome_stats.c gnome_stats.h
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome_stats.c

#
# KDE lib
#
make_kde: $(KDE_LIB)

$(KDE_LIB): $(KDE_OBJS)
	$(LD) -o $@ $(KDE_OBJS) $(KDE_LIBS)

kde.o: kde.cpp
	$(CXX) $(CFLAGS) $(KDE_CFLAGS) -o kde.o kde.cpp

kde_stats.o: kde_stats.cpp
	$(CXX) $(CFLAGS) $(KDE_CFLAGS) -o kde_stats.o kde_stats.cpp
	
#
# Mozilla lib
#
make_mozilla:$(MOZILLA_LIB)

$(MOZILLA_LIB): $(MOZILLA_OBJECTS)
	$(CXX) -o $(MOZILLA_LIB) $(MOZILLA_OBJECTS) $(MOZILLALIBS)

xpcom.o: xpcom.cpp
	$(CXX) $(MOZILLACFLAGS) -c xpcom.cpp

xpcom_structs.o: xpcom_structs.cpp
	$(CXX) $(MOZILLACFLAGS) -c xpcom_structs.cpp
	
xpcom_custom.o: xpcom_custom.cpp
	$(CXX) $(MOZILLACFLAGS) -c xpcom_custom.cpp

xpcom_stats.o: xpcom_stats.cpp
	$(CXX) $(MOZILLACFLAGS) -c xpcom_stats.cpp	

#
# Install
#
install: all
	cp *.so $(OUTPUT_DIR)

#
# Clean
#
clean:
	rm -f *.o *.so
