#!/bin/sh
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

if [ "${OS}" = "" ]; then
	OS=`uname -s`
fi

case $OS in
	"Linux")
		JAVA_HOME = /bluebird/teamswt/swt-builddir/ive/bin
		makefile="make_linux.mak"
		echo "Building Linux GTK version of SWT OpenGL"
		;;
	*)
		echo "*** Unknown OS <${OS}>"
		;;
esac

export JAVA_HOME

make -f $makefile ${1+"$@"}
