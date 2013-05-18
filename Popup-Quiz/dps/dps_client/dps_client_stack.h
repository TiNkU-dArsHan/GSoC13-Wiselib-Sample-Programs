/*
 * File: dps_client_stack.h
 * 
 */

#ifndef __ALGORITHMS_DPS_DPS_CLIENT_DPS_CLIENT_STACK_H__
#define __ALGORITHMS_DPS_DPS_CLIENT_DPS_CLIENT_STACK_H__

/**
* all the configuration files required by the DPSClient Stack
*
*/



/**
*
* the header files of the each -layer in the stack
*			       -managers of the stack 
*/
#include "algorithms/dps/dps_client/clientdps.h"
#include "algorithms/dps/dps_client/client_stub.h"
#include "algorithms/dps/dps_client/uart_radio.h"

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
		typedef wiselib::UartRadio<OsModel, Radio, Debug, Timer, Uart> UartRadio_t;
		
		typedef wiselib::ClientDPS<OsModel, Radio, Debug, Timer, UartRadio_t> ClientDPS_t;
		
		typedef wiselib::Clientstub<OsModel, ClientDPS_t, Radio, Debug , Timer> Clientstub_t;
		
		//typedef wiselib::UDP<OsModel, Clientstub_t, Radio, Debug> UDP_t;
		//typedef wiselib::ICMPv6<OsModel, Clientstub_t, Radio, Debug, Timer> ICMPv6_t;
		
		
		
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
			*Initialize all the -layers of Client stack in the order : DPS,Clientstub/virtual-ipv6, ICMPv6,UDP.
			*		    -mangers of the stack: PacketPoolManager etc..
			*The parameter of recieve function in each layer is defined by its lower layer.	
			*	
			*	+---------------+
			*	|UDP	|ICMPv6	|
			* +-----+---------------+
			* |	 virtual-IPv6/	| 
			* |	 Client-stub	|
			* |---------------------|
			* |	|		|
			* |Client		|
			* |DPS	|		|
			* |	|		|
			* |	|---------------|
			* |	|		|
			* |	|  OSradio	|
			* +-----+---------------+
			*[the parameter of the function call can be extended]
			*/
			
		/**
		*clientdps.init();
		*On init ClientDPS  all the modules required by the ClientDPS are initialized
		*
		*
		* 
		* fragmentation/unfragmentation of data
		* RPC-packet formation
		* checksum
		* AES security
		* 	 are the main functions
		* once the rpc-message packets is formed it is sent to OSradio layer for forwarding.
		*during the process the IPv6 addr is converted into MAC-addr
		*
	* [FOR FEW OF THE FUNCTIONS AND TEMPLETES IN THE FILE THE PARAMETER LIST MUST BE EXTENDED UPON ADDING OTHER FUNCTIONS AND CLASS]
		*/	
		
			clientdps.init( *radio_,*debug_,*timer_);	
		
		
		/**
		*clientstub.init();
		* On init clientstub will initialize all the required
		* modules for marsheling and unmarsheling of the arguments
		*routing table is initialised.
		*RPC broadcast[DISCOVER] message is send to find potential server
		*
		*interfaces provided to the upper layer UDP and lower layer dll are
		*remotesend( destinationaddr-IPv6,size,[UDP/icmpv6]packet);
		*remotereceive( destinationaddr-MAC,size,RPC-packet) );
		*
		*
		*/
			clientstub.init( *radio_, *debug_, *timer_ );
		
		
		
		/**
		* After data is packed into the UDP/ICMPv6 packets it is send to remote IPv6 layer 
		* by call Clientstub interface remotesend(destinationaddr,size,UDP/icmpv6packet);
		*similarly the UDP callback recives packets from destination node through the client stub 
		*after RPC-packet is unmarshelled .
		*
		*/
		
		/*	udp.init( ipv6, *debug_, &packet_pool_mgr);
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
		
		//ICMPv6_t icmpv6; 
		//UDP_t udp;
		
		
	private:
		typename Radio::self_pointer_t radio_;
		typename Debug::self_pointer_t debug_;
		typename Timer::self_pointer_t timer_;
		typename Uart::self_pointer_t uart_;
		
		Clientstub_t clientstub;
		ClientDPS_t clientdps;
		UartRadio_t uart_radio;
		
	
		
	};
}
#endif
