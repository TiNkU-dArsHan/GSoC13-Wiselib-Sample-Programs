/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "_legacyapps_enable_cmake.h"
#ifdef ENABLE_TESTQ_PRO

#include "legacyapps/testq_pro/testq_pro_processor_factory.h"
#include "legacyapps/testq_pro/testq_pro_processor.h"
#include "sys/processors/processor_keeper.h"
#include "sys/simulation/simulation_controller.h"
#include <iostream>

using namespace std;
using namespace shawn;

namespace testq_pro
{

   // ----------------------------------------------------------------------
   void
   TestqProProcessorFactory::
   register_factory( SimulationController& sc )
      throw()
   {
      sc.processor_keeper_w().add( new TestqProProcessorFactory );
   }
   
   // ----------------------------------------------------------------------
   TestqProProcessorFactory::
   TestqProProcessorFactory()
   {
      //cout << "TestqProProcessorFactory ctor" << &auto_reg_ << endl;
   }
   
   // ----------------------------------------------------------------------
   TestqProProcessorFactory::
   ~TestqProProcessorFactory()
   {
      //cout << "TestqProProcessorFactory dtor" << endl;
   }
   
   // ----------------------------------------------------------------------
   std::string
   TestqProProcessorFactory::
   name( void )
      const throw()
   { 
	   return "testq_pro"; 
   }
   
   // ----------------------------------------------------------------------
   std::string 
   TestqProProcessorFactory::
   description( void )
      const throw()
   {
      return "simple HelloWorld demo processor";
   }
   
   // ----------------------------------------------------------------------
   shawn::Processor*
   TestqProProcessorFactory::
   create( void )
      throw()
   {
      return new TestqProProcessor;
   }

}

#endif

/*-----------------------------------------------------------------------
 * Source  $Source: /cvs/shawn/shawn/apps/testq_pro/testq_pro_processor_factory.cpp,v $
 * Version $Revision: 197 $
 * Date    $Date: 2008-04-29 21:10:51 +0530 (Tue, 29 Apr 2008) $
 *-----------------------------------------------------------------------
 * $Log: testq_pro_processor_factory.cpp,v $
 *-----------------------------------------------------------------------*/
