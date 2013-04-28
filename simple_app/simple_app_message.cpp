/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "legacyapps/simple_app/simple_app_message.h"
#ifdef ENABLE_SIMPLE_APP

namespace simple_app
{

	// ----------------------------------------------------------------------
	SimpleAppMessage::
		SimpleAppMessage()
	{}
   
	// ----------------------------------------------------------------------
	SimpleAppMessage::
		SimpleAppMessage(int size)
	{
		setSize(size);
	}

	// ----------------------------------------------------------------------
	SimpleAppMessage::
		~SimpleAppMessage()
	{}

}
#endif

/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/simple_app/simple_app_message.cpp,v $
 * Version $Revision: 126 $
 * Date    $Date: 2008-02-21 21:03:02 +0530 (Thu, 21 Feb 2008) $
 *-----------------------------------------------------------------------
 * $Log: simple_app_message.cpp,v $
 *-----------------------------------------------------------------------*/
