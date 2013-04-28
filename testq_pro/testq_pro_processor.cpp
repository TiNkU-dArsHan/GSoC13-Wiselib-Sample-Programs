/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "legacyapps/testq_pro/testq_pro_processor.h"
#ifdef ENABLE_TESTQ_PRO

#include "legacyapps/testq_pro/testq_pro_message.h"
#include "sys/simulation/simulation_controller.h"
#include "sys/node.h"
#include <iostream>


namespace testq_pro
{
   TestqProProcessor::
   TestqProProcessor()
   {}
   // ----------------------------------------------------------------------
   TestqProProcessor::
   ~TestqProProcessor()
   {}
   // ----------------------------------------------------------------------
   void
   TestqProProcessor::
   boot( void )
      throw()
   {}
   // ----------------------------------------------------------------------
   bool
   TestqProProcessor::
   process_message( const shawn::ConstMessageHandle& mh ) 
      throw()
   {
      const TestqProMessage* msg = 
          dynamic_cast<const TestqProMessage*>( mh.get() );

      if( msg != NULL )
      { 
         if( owner() != msg->source() )
         { 
            neighbours_.insert( &msg->source() );
            INFO( logger(), "Received message from '" 
                            << msg->source().label() 
                            << "'" );
        
         }
	       
	 if ( msg->source().label() < owner().label() )
	 { 
		std::cout << owner().label() << ": shutdown" ;
		set_state( Inactive ); 	
	 }
      
         return true;
      }

      return Processor::process_message( mh );
   }
   // ----------------------------------------------------------------------
   void
   TestqProProcessor::
   work( void )
      throw()
   {
      
         send( new TestqProMessage );
      
   }
}
#endif
