/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#ifndef __SHAWN_APPS_LEGACYAPPS_TESTQ_PRO_PROCESSOR_FACTORY_H
#define __SHAWN_APPS_LEGACYAPPS_TESTQ_PRO_PROCESSOR_FACTORY_H
#include "_legacyapps_enable_cmake.h"
#ifdef ENABLE_TESTQ_PRO

#include "sys/processors/processor_factory.h"

namespace shawn 
{ 
    class SimulationController; 
    class Processor;
}

namespace testq_pro
{

   class TestqProProcessorFactory
      : public shawn::ProcessorFactory
   {
   public:
      TestqProProcessorFactory();
      virtual ~TestqProProcessorFactory();

      virtual std::string name( void ) const throw();
      virtual std::string description( void ) const throw();
      virtual shawn::Processor* create( void ) throw();

      static void register_factory( shawn::SimulationController& ) throw();
   };

}

#endif
#endif
/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/testq_pro/testq_pro_processor_factory.h,v $
 * Version $Revision: 419 $
 * Date    $Date: 2010-05-26 21:59:40 +0530 (Wed, 26 May 2010) $
 *-----------------------------------------------------------------------
 * $Log: testq_pro_processor_factory.h,v $
 *-----------------------------------------------------------------------*/
