# Makefile for module 'swt'

# (c) Copyright IBM Corp., 2000, 2001
# All Rights Reserved.

maj_ver=2
min_ver=006
revision=0

#assumes IVE_HOME is set in the environment

DLLPREFIX=swt
OS_PREFIX=qnx
DLLNAME=lib$(DLLPREFIX)-$(OS_PREFIX)-$(maj_ver)$(min_ver).so
#DLLNAME=lib$(DLLPREFIX)$(maj_ver)$(min_ver)r$(revision).so

DEBUG =  
CFLAGS = -c -shared -DSWT_LIBRARY_MAJOR_VERSION=$(maj_ver) -DSWT_LIBRARY_MINOR_VERSION=$(min_ver) -w8 $(DEBUG) -DPHOTON -I$(IVE_HOME)/include
LFLAGS = -shared -lph -lphrender

SWTOBJS = swt.o structs.o callback.o globals.o library.o

all: \
	 $(DLLNAME)

BUILDLIB: $(DLLNAME)

.c.o:
	cc $(CFLAGS) $*.c

$(DLLNAME):\
    $(SWTOBJS)
	cc $(LFLAGS) -o $(DLLNAME) \
	    $(SWTOBJS)
	
clean:
	rm -f *.o
	rm -f $(DLLNAME)