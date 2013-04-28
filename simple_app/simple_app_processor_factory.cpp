/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "_legacyapps_enable_cmake.h"
#ifdef ENABLE_SIMPLE_APP

#include "legacyapps/simple_app/simple_app_processor_factory.h"
#include "legacyapps/simple_app/simple_app_processor.h"
#include "sys/processors/processor_keeper.h"
#include "sys/simulation/simulation_controller.h"
#include <iostream>

using namespace std;
using namespace shawn;

namespace simple_app
{

   // ----------------------------------------------------------------------
   void
   SimpleAppProcessorFactory::
   register_factory( SimulationController& sc )
      throw()
   {
      sc.processor_keeper_w().add( new SimpleAppProcessorFactory );
   }
   
   // ----------------------------------------------------------------------
   SimpleAppProcessorFactory::
   SimpleAppProcessorFactory()
   {
      //cout << "SimpleAppProcessorFactory ctor" << &auto_reg_ << endl;
   }
   
   // ----------------------------------------------------------------------
   SimpleAppProcessorFactory::
   ~SimpleAppProcessorFactory()
   {
      //cout << "SimpleAppProcessorFactory dtor" << endl;
   }
   
   // ----------------------------------------------------------------------
   std::string
   SimpleAppProcessorFactory::
   name( void )
      const throw()
   { 
	   return "simple_app"; 
   }
   
   // ----------------------------------------------------------------------
   std::string 
   SimpleAppProcessorFactory::
   description( void )
      const throw()
   {
      return "simple HelloWorld demo processor";
   }
   
   // ----------------------------------------------------------------------
   shawn::Processor*
   SimpleAppProcessorFactory::
   create( void )
      throw()
   {
      return new SimpleAppProcessor;
   }

}

#endif

/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/simple_app/simple_app_processor_factory.cpp,v $
 * Version $Revision: 197 $
 * Date    $Date: 2008-04-29 21:10:51 +0530 (Tue, 29 Apr 2008) $
 *-----------------------------------------------------------------------
 * $Log: simple_app_processor_factory.cpp,v $
 *-----------------------------------------------------------------------*/
