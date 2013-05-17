/*
 * File: dps_client_stack.h
 * 
 */

#ifndef __ALGORITHMS_DPS_DPSCLIENT_DPS_CLIENT_STACK_H__
#define __ALGORITHMS_DPS_DPSCLIENT_DPS_CLIENT_STACK_H__

/**
* all the configuration files required by the DPSClient Stack
*
*/



/**
*
* the header files of the each -layer in the stack
*			       -managers of the stack 
*/

//#include "algorithms/dps/dps_client/udp.h"

namespace wiselib
{
	
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_P>
	
	class DPSClientStack
	{
	
	public:
		
		typedef OsModel_P OsModel;
		typedef Radio_P Radio;
		typedef Debug_P Debug;
		typedef Timer_P Timer;
		typedef Uart_P Uart;
		
		typedef DPSClientStack<OsModel, Radio, Debug, Timer, Uart> self_type;
		
		/**
		
		
		*/
		//typedef wiselib::UDP<OsModel, IPv6_t, Radio, Debug> UDP_t;
		//typedef wiselib::ICMPv6<>
		//typedef wiselib::Clientstub<>
		//typedef wiselib::ClientDPS<>
		
		
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
			
			debug_->debug( "DPS Client stack init: %x", radio_->id());
			
	
		
			/**
			*
			*Initialize all the -layers of Client stack: DPS , Clientstub/virtual-ipv6 ,UDP, ICMPv6.
			*		    -mangers of the stack: PacketPoolManager etc..		
			*+--------------+
			*|UDP	|ICMPv6	|
			*+--------------+
			*|virtual	| 
			*|IPv6	|	|
			*|------|	|
			*|	|	|
			*|	|	|
			*|Client|	|
			*|DPS	|	|
			*|      |	|
			*+------+-------+
			*|  OSradio	|
			*+--------------+
			*/
			
		/**
		*On init ClientDPS a RPC broadcast[DISCOVER] message is send ,to find potential server
		*this module uses RPClibrary [wiselib compatable] for establishing communication between
		*distant node 
		* 
		*/	
		/*
		*	ClientDPS.init(*radio_,*debug_,*timer_,&packet_pool_mgr);	
		*/
		
		/**
		* On init clientstub will initialize all the required
		* modules for marsheling and unmarsheling and interfaces provided to the upper layer
		*/
		//	Clientstub.init( *radio_, *debug_, *timer_, &packet_pool_mgr);
		
		
		
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
		
	
		
	};
}
#endif
