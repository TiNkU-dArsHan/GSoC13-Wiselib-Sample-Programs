/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#ifndef __SHAWN_APPS_LEGACYAPPS_SIMPLE_APP_PROCESSOR_H
#define __SHAWN_APPS_LEGACYAPPS_SIMPLE_APP_PROCESSOR_H
#include "_legacyapps_enable_cmake.h"
#ifdef ENABLE_SIMPLE_APP

#include "sys/processor.h"
#include <set>

namespace simple_app
{

   class SimpleAppProcessor
       : public shawn::Processor
   {
   public:
      SimpleAppProcessor();
      virtual ~SimpleAppProcessor();

      virtual void boot( void ) throw();
      virtual bool process_message( const shawn::ConstMessageHandle& ) throw();
      virtual void work( void ) throw();

   protected:
      int last_time_of_receive_;
      std::set<const shawn::Node*> neighbours_;
   };


}

#endif
#endif
/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/simple_app/simple_app_processor.h,v $
 * Version $Revision: 419 $
 * Date    $Date: 2010-05-26 21:59:40 +0530 (Wed, 26 May 2010) $
 *-----------------------------------------------------------------------
 * $Log: simple_app_processor.h,v $
 *-----------------------------------------------------------------------*/
