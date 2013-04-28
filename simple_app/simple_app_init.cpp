/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "legacyapps/simple_app/simple_app_init.h"
#ifdef ENABLE_SIMPLE_APP

#include "legacyapps/simple_app/simple_app_processor_factory.h"

extern "C" void init_simple_app( shawn::SimulationController& sc )
{
   simple_app::SimpleAppProcessorFactory::register_factory( sc );
}

#endif
