/*
 * File: dps_stack.h
 * 
 */

#ifndef __ALGORITHMS_DPS_DPS_SERVER_DPS_SERVER_STACK_H__
#define __ALGORITHMS_DPS_DPS_SERVER_DPS_SERVER_STACK_H__

/**
* all the configuration files required by the DPSServer Stack
*
*/



/**
*
* the header files of the each -layer in the stack
*			       -managers of the stack 
*/


#include "algorithms/dps/dps_server/serverdps.h"
#include "algorithms/dps/dps_server/server_stub.h"
#include "algorithms/dps/dps_server/uart_radio.h"

/**
*server stack receives packets from the other nodes through
*2 different side i,e through normal protocol stack
*and also through DPS protocol stack
*The functions of each are defined in there repective layers
*/

namespace wiselib
{
	
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_P>
	
	class DPSServerStack
	{
	
	public:
		
		typedef OsModel_P OsModel;
		typedef Radio_P Radio;
		typedef Debug_P Debug;
		typedef Timer_P Timer;
		typedef Uart_P Uart;
		
		typedef DPSServerStack<OsModel, Radio, Debug, Timer, Uart> self_type;
		
		/**
		
		
		*/
		
		typedef wiselib::UartRadio<OsModel, Radio, Debug, Timer, Uart> UartRadio_t;
		
		typedef wiselib::ServerDPS<OsModel, Radio, Debug, Timer, UartRadio_t> ServerDPS_t;
		
		typedef wiselib::Serverstub<OsModel, ServerDPS_t, Radio, Debug , Timer> Serverstub_t;
		
		//typedef wiselib::UDP<OsModel, IPv6_t, Radio, Debug> UDP_t;
		
		
		
		enum ErrorCodes
		{
			SUCCESS = OsModel::SUCCESS,
			ERR_UNSPEC = OsModel::ERR_UNSPEC,
			ERR_NOTIMPL = OsModel::ERR_NOTIMPL,
			ERR_HOSTUNREACH = OsModel::ERR_HOSTUNREACH
		};
		
		
		void init( Radio& radio, Debug& debug, Timer& timer, Uart& uart)
		{
			radio_ = &radio;
			debug_ = &debug;
			timer_ = &timer;
			uart_ = &uart;
			
			debug_->debug( "DPS Server stack init: %x", radio_->id());
			
	
		
			/**
			*
			*Initialize all the 
					-layers of Server stack in the order :
			*			6lowpan , uart_radio , ServerDPS , Serverstub ,IPv6 ,ICMPv6 ,UDP.
			*	[Always the parameter of receive function in each layer is defined by its lower layer]
				
			*		 -mangers of the stack required for both side i,e. RPC and normal side:
							 PacketPoolManager,Interface_manager etc..
			*	init all the required managers in there respective order between the layers 
			*	
			*
			*
			* 
			*
			*
			*	+---------------+
			*	|UDP	|ICMPv6	|
			* +-----+---------------+
			* |Server     IPv6 	| 
			* |STUB	|		|
			* |-----|---------------|
			* |	|		|
			* |Server		|
			* |DPS	|    6LOWPAN	|
			* |	|---------------|
			* |	|      		|
			* |	|		|
			* |	|    OSradio	|
			* +-----+---------------+
			*
			*
[FOR FEW OF THE FUNCTIONS AND TEMPLETES IN THE FILE THE PARAMETER LIST MUST BE EXTENDED UPON ADDING OTHER FUNCTIONS AND CLASS]
			*/
	
		/*Init LoWPAN
		lowpan.init(*radio_, *debug_, &packet_pool_mgr, *timer_ );			
		*/
			
		/*uart radio
		*/
			
		/**
		*serverdps.init();
		* briefly initialzes all the modules required for RPC functioning
		*
		* fragmentation/unfragmentation of data
		* RPC-packet formation
		* checksum
		* AES security
		* 	 are the main functions
		* once the rpc-message packets is formed it is sent to OSradio layer for forwarding.
		*during the process the IPv6 addr is converted into MAC-addr
		*
		*/	
		
			serverdps.init(*radio_,*debug_,*timer_);	
		
		
		
		/**
		*serverstub.init();
		* On init Serverstub will initialize all the required
		* modules for marsheling and unmarsheling of the arguments
		*
		*routing table is initialised.
		* the server starts listening to the client 
		*
		*interfaces provided to the upper layer UDP and lower layer dll are
		*remotesend( destinationaddr-IPv6,size,[UDP/icmpv6]packet);
		*remotereceive( destinationaddr-MAC,size,RPC-packet) );
		*
		*
		*/
			serverstub.init( *radio_, *debug_, *timer_);
		
			
		
			
		/*Init IPv6
		ipv6.init( *radio_, *debug_, &packet_pool_mgr, *timer_, &interface_manager );
		*/
		
			
		/*Init UDP
			udp.init( ipv6, *debug_, &packet_pool_mgr);
			//Just register callback, not enable IP radio
			if( SUCCESS != udp.enable_radio() )
				debug_->debug( "Fatal error: UDP layer enabling failed! " );
		*/
		
		/*Init ICMPv6
			icmpv6.init( ipv6, *debug_, &packet_pool_mgr);
			//Just register callback, not enable IP radio
			if( SUCCESS != icmpv6.enable_radio() )
				debug_->debug( "Fatal error: icmpv6 layer enabling failed! " );
		*/
		
		
		}
		

		
		
	private:
		typename Radio::self_pointer_t radio_;
		typename Debug::self_pointer_t debug_;
		typename Timer::self_pointer_t timer_;
		typename Uart::self_pointer_t uart_;
		UartRadio_t uart_radio;
		
		Serverstub_t serverstub;
		ServerDPS_t serverdps;
	
		
	};
}
#endif
