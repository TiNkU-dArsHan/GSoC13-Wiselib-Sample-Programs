/************************************************************************
 ** This file is part of the network simulator Shawn.                  **
 ** Copyright (C) 2004-2007 by the SwarmNet (www.swarmnet.de) project  **
 ** Shawn is free software; you can redistribute it and/or modify it   **
 ** under the terms of the BSD License. Refer to the shawn-licence.txt **
 ** file in the root of the Shawn source tree for further details.     **
 ************************************************************************/
#include "legacyapps/testq_pro/testq_pro_init.h"
#ifdef ENABLE_TESTQ_PRO

#include "legacyapps/testq_pro/testq_pro_processor_factory.h"

extern "C" void init_testq_pro( shawn::SimulationController& sc )
{
   testq_pro::TestqProProcessorFactory::register_factory( sc );
}

#endif
