package org.eclipse.swt.dnd;

/*
 * Copyright (c) 2000, 2002 IBM Corp.  All rights reserved.
 * This file is made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 */

import org.eclipse.swt.widgets.*;

class DNDEvent extends Event {

	public TransferData dataType;
	public TransferData[] dataTypes;
	public int operations;
	public int feedback;
	
}
