/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "legacyapps/testq_pro/testq_pro_message.h"
#ifdef ENABLE_TESTQ_PRO

namespace testq_pro
{

	// ----------------------------------------------------------------------
	TestqProMessage::
		TestqProMessage()
	{}
   
	// ----------------------------------------------------------------------
	TestqProMessage::
		TestqProMessage(int size)
	{
		setSize(size);
	}

	// ----------------------------------------------------------------------
	TestqProMessage::
		~TestqProMessage()
	{}

}
#endif

/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/testq_pro/testq_pro_message.cpp,v $
 * Version $Revision: 126 $
 * Date    $Date: 2008-02-21 21:03:02 +0530 (Thu, 21 Feb 2008) $
 *-----------------------------------------------------------------------
 * $Log: testq_pro_message.cpp,v $
 *-----------------------------------------------------------------------*/
