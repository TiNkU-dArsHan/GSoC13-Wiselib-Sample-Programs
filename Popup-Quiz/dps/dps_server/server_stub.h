#ifndef __ALGORITHMS_DPS_DPS_SERVER_SERVERSTUB_H__
#define __ALGORITHMS_DPS_DPS_SERVER_SERVERSTUB_H__

/**
* all the configuration files required by the Serverstub layer
*
*/



/*
#include "RPC/marshelling.h"
#include "RPC/unmarshelling"

#include "dps/dps/serverdps.h"
#include "dps/dps_server/interface_mgr.h"
#include "dps/dps_server/Ipv6.h"
*/

/**
*this layer completely defines the functions of the ServerSkeleton
*the functionality of this layer are 
*1).On initialization the server start listenting to the Client
*	on the through DPS side of the stack.
*	
*	
*2).On reciving of the data from ServerDPS unmarshell it 
*	call the required procesdure referring to the protocol-num
*	
*3).On Reciving packets from upper layer marshell it and send to the ServerDPS
*	
*4) On Reciving of the packets 
*
**/

#include "util/base_classes/radio_base.h"


namespace wiselib
{
	
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	class Serverstub
	:public RadioBase<OsModel_P, typename Radio_P::node_id_t, typename Radio_P::size_t, typename Radio_P::block_data_t>
	{
	
	public:
		
		typedef OsModel_P OsModel;
		typedef Radio_ServerDPS_P Radio_ServerDPS;
		typedef Radio_P Radio;
		typedef Debug_P Debug;
		typedef Timer_P Timer;
		
		typedef Serverstub<OsModel,Radio_ServerDPS,Radio, Debug, Timer> self_type;
		
		
		// The MAC address is called link_layer_node_id_t
		typedef typename Radio::node_id_t link_layer_node_id_t;
		typedef typename Radio::size_t size_t;
		typedef typename Radio::block_data_t block_data_t;
		typedef typename Radio::message_id_t message_id_t;
		
		enum ErrorCodes
		{
			SUCCESS = OsModel::SUCCESS,
			ERR_UNSPEC = OsModel::ERR_UNSPEC,
			ERR_NOTIMPL = OsModel::ERR_NOTIMPL,
			ERR_HOSTUNREACH = OsModel::ERR_HOSTUNREACH
		};
		
		///@name Construction / Destruction
		///@{
		Serverstub();
		~Serverstub();
		///@}
		
		
		void init( Radio& radio,Debug& debug, Timer& timer)
		{
			radio_ = &radio;
			debug_ = &debug;
			timer_ = &timer;
			
			
			listen_to_client();
			
			//init serialization modules required for marshelling
		}
		
		
		inline int init();
		inline int destruct();
		
		///@name Routing Control
		///@{
		int enable_radio( void );
		int disable_radio( void );
		///@}
		
		/**
		*interface offered to transport layer by the server_stub
		*/
		//int remotesend (IPv6address reciver,size_t packet_size,block_data_t *data);
		int remotesend();
		
		
		/**
		* Callback function of the layer. This is called by the ServerDPS Radio.
		*/
		//void remotereceive( node_id from, size_t len, block_data_t *data );
		void remotereceive();
		
	
		
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
		
		/**
		*
		*/	
		int listen_to_client();
		
		/**
		*
		*/
		
		int call_required_procedure();
		
		int routing_poll( void* p_number );
		
		//all the other required functions .
		
	};	


	//----------------------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------------------
	//
	//---------------------------------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	Serverstub()
	: radio_ ( 0 ),
	debug_ ( 0 )
	{}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	~Serverstub()
	{
		disable_radio();
		
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	init( void )
	{
		return 1;
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	destruct( void )
	{
		return disable_radio();
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	enable_radio( void )
	{
		return 1;
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	disable_radio( void )
	{
	return 1;
		
	}
	//------------------------------------------------------------------------------------------
	
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P, Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	
	listen_to_client()
	{
		/**
		*listen to client 
		*if RPC DISCOVERY packet
		*	send RPC ADVITISE message to client
		*	
		*
		*if CONNECT packet
		*	if resource avilable 
		*	then
		*		send ALLOW		
		*	else
		*		send ABORT
		* 
		if FINISH packet
		*  set client ipv6 addr 
		*  store client ipv6 and mac addr in route-over routing table
		*
		*if RPC REQUEST packet
		* 	unmarshall the data and call the requires procedure
		
		*/
		
		return 1;
		
	}

	//------------------------------------------------------------------------------------
	//Call the required procedure
	//-------------------------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P,Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	call_required_procedure( )
	{
	
	
	return 1;
	
	}
	

	//-----------------------------------------------------------------------------------
	//SEND [interface to upper layer]
	//-----------------------------------------------------------------------------------	
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P,Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	remotesend( )
	{	
		/*data (marshelling)
		 of data
		 converting ipv6 address to mac address
		 forwarding to ServerDPS 
		*/
		return 1;
	}
	
	
	
	//---------------------------------------------------------------------------------------
	//RECIEVE PACKETS []
	//---------------------------------------------------------------------------------------
	
	template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	void 
	Serverstub<OsModel_P,Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	remotereceive( )
	{
		/*reciving data from ServerDPS
		and 
		unmarshelling it
		*/
		
	}
	
	
	 //--------------------------------------------------------------------------------------------
	 //set addr of destination in Routing table .
	//-------------------------------------------------------------------------------------------		
		
		template<typename OsModel_P,
		typename Radio_ServerDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Serverstub<OsModel_P,Radio_ServerDPS_P, Radio_P, Debug_P, Timer_P>::
	routing_poll( void* p_number )
	{
		return 1;
	
	}
	
	
	
}
	

#endif
		

