#ifndef __ALGORITHMS_DPS_DPS_CLIENT_CLIENTDPS_H__
#define __ALGORITHMS_DPS_DPS_CLIENT_CLIENTDPS_H__

/**
*This files defines all the class and it function required by the 
*DPS  
* the main fuctions in cliendps are :
* send() 
* receive()
*
* 
*	the upperlayer uses send() to send marshelled IPv6 paccket with the to remote destination
* once the data is received by the upperlayer depending on the TYPE of data the RPC-packet is constructed 
* if required the packet is fragmented and the checksum is calculauted for each of them.
* with the required protocol-number , destination addr the RPC-packet is sent to the radiolayer .
*
* 	
*	Client stub uses recive() function to receive the RPC-packet from the Radio layer.
*once the packets are recived it is unfragemented and checksum is check for each of the packets 
*once full data is received and unfragmented . the upper layer is informed for further processing
*
*	
*
*[FOR FEW OF THE FUNCTIONS AND TEMPLETES IN THE FILE THE PARAMETER LIST MUST BE EXTENDED UPON ADDING OTHER FUNCTIONS AND CLASS]
*/

/*

#include "RPC/config.h"
#include "RPC/messagepkt.h"

#include "RPC/packet_pool_manager.h"
#include "client_stub.h"


etc...
*/
#include "util/base_classes/radio_base.h"
#include "uart_radio.h"

/**
*the 
*
*
*/

namespace wiselib
{
	
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_P>
	class ClientDPS
	{
	
	public:
		
		typedef OsModel_P OsModel;
		typedef Radio_P Radio;
		typedef Debug_P Debug;
		typedef Timer_P Timer;
		typedef Uart_P Uart;
		
		//---------------
		//parameters of the OSRadio
		//---------------
		typedef typename Radio::node_id_t node_id_t;
		typedef typename Radio::size_t size_t;
		typedef typename Radio::block_data_t block_data_t;
		typedef typename Radio::message_id_t message_id_t;
		
		/*
		*typedef and create variable instance of packet_pool_manager 
		* and RPCpacket etc..
		*/
		
		
		/*
		*typedef and create instance of the routingtable
		*/
		
		typedef ClientDPS<OsModel, Radio, Debug, Timer, Uart> self_type;
		
		
		
		enum ErrorCodes
		{
			SUCCESS = OsModel::SUCCESS,
			ERR_UNSPEC = OsModel::ERR_UNSPEC,
			ERR_NOTIMPL = OsModel::ERR_NOTIMPL,
			ERR_HOSTUNREACH = OsModel::ERR_HOSTUNREACH
		};
		
		// --------------------------------------------------------------------
		///@name Construction / Destruction
		///@{
		ClientDPS();
		~ClientDPS();
		///@}
		
		void init( Radio& radio, Debug& debug, Timer& timer)
		{
			radio_ = &radio;
			debug_ = &debug;
			timer_ = &timer;
			
		        
		      //init the required managers and routing 
		      //and all the required modules by this layer.
		       
		}
		
		 
		inline int init();
		inline int destruct();
		int enable_radio();
		
		int disable_radio();
		
		
		//int send (IPv6address reciver,size_t packet_size,block_data_t *data);
		int send();
		
		
		/**
		* Callback function of the layer. This is called by the OSRadio.
		*/
		//void receive( node_id from, size_t len, block_data_t *data );
		void receive();
		
		
		
		/**
		*all the function required by the dps
		*/
		
	private:
		
		Radio& radio()
		{ return *radio_; }
		
		Debug& debug()
		{ return *debug_; }
		
		Timer& timer()
		{ return *timer_; }
		
		typename Radio::self_pointer_t radio_;
		typename Debug::self_pointer_t debug_;
		typename Timer::self_pointer_t timer_;
		typename Uart::self_pointer_t uart_;
		
		/**
		* Callback ID
		*/
		int callback_id_;
		
		
		
		
	};
	//------------------------------------------------------------------------------------
	//
	//------------------------------------------------------------------------------------	
	//
	//-------------------------------------------------------------------------------------
	
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
	ClientDPS()
	: radio_ ( 0 ),
	debug_ ( 0 )
	{}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
	~ClientDPS()
	{
		disable_radio();
		
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	int
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
	init( void )
	{
		return enable_radio();
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	int
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
	destruct( void )
	{
		return disable_radio();
	}
	
	//---------------------------------------------------------------------------------------
	
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	int
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
	enable_radio( void )
	{

		if ( radio().enable_radio() != SUCCESS )
			return ERR_UNSPEC;
		
		callback_id_ = radio().template reg_recv_callback<self_type, &self_type::receive>( this );
		
		//
		//initialize the required parameters
		//		
		return SUCCESS;
	}
	
	//---------------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	int
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
	disable_radio( void )
	{

		if( radio().disable_radio() != SUCCESS )
			return ERR_UNSPEC;
			
		radio().template unreg_recv_callback(callback_id_);
		
		return SUCCESS;
	}
	
	//--------------------------------------------------------------------------------------
	//SENDING RPC PACKET  
	//--------------------------------------------------------------------------------------
		template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	int
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
		//send (IPv6address reciver,size_t packet_size,block_data_t *data);
		 send()
		{
			/**
			*for the marshelled arguments from client stub the rpc packet is constructed and sent to the remote node.
			*
			*/
			
			/*
			*CONSTRUCTION OF RPC HEADER
			*MAC addr of the remote node is used 
			*/
			
			
			/*FRAGMENTATION
			*
			*/
			
			/*
			*CHECKSUM
			*/
			
			/*
			*AES SECURITY
			*/
			
			
			//radio().send( mac_next_hop, fragment_size, fragemnted_data );
			
			return 1;
		}
		
	//---------------------------------------------------------------------------------------
	//RECEIVING RPC PACKET 
	//---------------------------------------------------------------------------------------
		template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_Radio_P>
	void
	ClientDPS<OsModel_P, Radio_P, Debug_P, Timer_P, Uart_Radio_P>::
		//void receive( node_id from, size_t len, block_data_t *data );
		receive()
		{
			/**
			*
			*the recived RPC packet is processed and the data is send to the client stub
			*/
		
			//FRAGMENTATION PROCESSING
			
			
			//CHECKSUM VERIFICATION
			
			//AES VERIFICATION
			
			//notify the clientstub or its packet_manager
		

		}
		
	
}
#endif

