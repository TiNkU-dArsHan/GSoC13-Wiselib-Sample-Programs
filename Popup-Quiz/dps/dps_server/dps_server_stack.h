/*
 * File: dps_stack.h
 * 
 */

#ifndef __ALGORITHMS_DPS_DPSCLIENT_DPS_SERVER_STACK_H__
#define __ALGORITHMS_DPS_DPSCLIENT_DPS_SERVER_STACK_H__

/**
* all the configuration files required by the DPSServer Stack
*
*/



/**
*
* the header files of the each -layer in the stack
*			       -managers of the stack 
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
		//typedef wiselib::UDP<OsModel, IPv6_t, Radio, Debug> UDP_t;
		//
		
		
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
			
			//debug_->debug( "DPS Client stack init: %x", radio_->id());
			
	
		
			/**
			*
			*Initialize all the -layers of Server stack: 6lowpan,ServerDPS,Serverstub,IPv6,UDP,ICMPv6
			*		    -mangers of the stack: PacketPoolManager etc..		
			*+--------------+
			*|UDP	|ICMPv6	|
			*+--------------+
			*|     IPv6	|
			*+--------------+
			*|Server|	|
			*|stub	|	|
			*|------|6lowpan|
			*|Server|	|
			*|DPS	|	|
			*+------+-------+
			*|  OSradio	|
			*+--------------+
			*
			*/
			
	
		/*Init LoWPAN
		lowpan.init(*radio_, *debug_, &packet_pool_mgr, *timer_ );			
		*/
			
			
			/**
		*On init ServerDPS will listen for RPC broadcast message i,e DISCOVER mgs send from client nodes.
		*
		*this module uses RPC for establishing communication between Client node 
		*
		*/	
		
			ServerDPS.init(*radio_,*debug_,*timer_,&packet_pool_mgr);	
		
		
		
		/**
		* On init Serverstub 
		*/
			Serverstub.init( *radio_, *debug_, *timer_, &packet_pool_mgr);
		
			
		
			
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
	};
}
#endif
