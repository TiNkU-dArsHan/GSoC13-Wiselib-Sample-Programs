/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#ifndef __SHAWN_LEGACYAPPS_TESTQ_PRO_HELLOWORLD_MESSAGE_H
#define __SHAWN_LEGACYAPPS_TESTQ_PRO_HELLOWORLD_MESSAGE_H
#include "_legacyapps_enable_cmake.h"
#ifdef ENABLE_TESTQ_PRO

#include "sys/message.h"

namespace testq_pro
{

   class TestqProMessage
       : public shawn::Message
   {
   public:
	   TestqProMessage();
	   TestqProMessage(int);
	   virtual ~TestqProMessage();
   };

}

#endif
#endif
/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/testq_pro/testq_pro_message.h,v $
 * Version $Revision: 197 $
 * Date    $Date: 2008-04-29 21:10:51 +0530 (Tue, 29 Apr 2008) $
 *-----------------------------------------------------------------------
 * $Log: testq_pro_message.h,v $
 *-----------------------------------------------------------------------*/
