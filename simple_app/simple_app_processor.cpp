/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "legacyapps/simple_app/simple_app_processor.h"
#ifdef ENABLE_SIMPLE_APP

#include "legacyapps/simple_app/simple_app_message.h"
#include "sys/simulation/simulation_controller.h"
#include "sys/node.h"
#include <iostream>


namespace simple_app
{
   SimpleAppProcessor::
   SimpleAppProcessor()
   {}
   // ----------------------------------------------------------------------
   SimpleAppProcessor::
   ~SimpleAppProcessor()
   {}
   // ----------------------------------------------------------------------
   void
   SimpleAppProcessor::
   boot( void )
      throw()
   {}
   // ----------------------------------------------------------------------
   bool
   SimpleAppProcessor::
   process_message( const shawn::ConstMessageHandle& mh ) 
      throw()
   {
      const SimpleAppMessage* msg = 
          dynamic_cast<const SimpleAppMessage*>( mh.get() );

      if( msg != NULL )
      { 
         if( owner() != msg->source() )
         { 
            neighbours_.insert( &msg->source() );
            INFO( logger(), "Received message from '" 
                            << msg->source().label() 
                            << "'" );
        
         }
         return true;
      }

      return Processor::process_message( mh );
   }
   // ----------------------------------------------------------------------
   void
   SimpleAppProcessor::
   work( void )
      throw()
   {
      // send message only in the first simulation round
      if ( simulation_round() == 0 )
      { 
         send( new SimpleAppMessage );
      }
   }
}
#endif
