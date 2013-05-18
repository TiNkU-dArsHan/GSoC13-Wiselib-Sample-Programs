/*
*File:client_stub.h
*
*/


#ifndef __ALGORITHMS_DPS_DPS_CLIENT_CLIENTSTUB_H__
#define __ALGORITHMS_DPS_DPS_CLIENT_CLIENTSTUB_H__

/**
* all the configuration files required by the Clientstub
*
*/
/*

#include "RPC/marshelling.h"
#include "RPC/unmarshelling"

#include "dps/dps/clientdps.h"
#include "dps/dps_client/udp.h"
#include "dps/dps_client/ICMPv6.h"


*/
/**
*This files defines all the class and it function required by the 
*ClientStub layer
* the main fuctions offered by the client stub are
* bind_client_to_server();
* remotesend() ;
* remoterecive();
* getipaddr();
*
*       On init of this layer the client bind to the server by a 3 way hand shake the Client stub uses bind_client_to_server()
*function to perform this binding
*
*	The upperlayer uses remotesend() to send IPv6 paccket to remote destination
* once the data is received by the upperlayer it has to be marshelled the IPv6 addr is converted 
*to MAC addr and sent to ClientDPS
* 	
*	Client stub uses remoterecive() function to receive the packet and its type by the ClientDPS
*once the full data is received the data is unmarshelled and made avialable  to the upperlayer
*
*	getipaddr() is the fuction used by the client-stub to get ipv6 addr and networkprefix from the server
*
*[FOR FEW OF THE FUNCTIONS AND TEMPLETES IN THE FILE THE PARAMETER LIST MUST BE EXTENDED UPON ADDING OTHER FUNCTIONS AND CLASS]
*/
#include "util/base_classes/radio_base.h"


namespace wiselib
{
	
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	class Clientstub
	:public RadioBase<OsModel_P, typename Radio_P::node_id_t, typename Radio_P::size_t, typename Radio_P::block_data_t>
	{
	
	public:
		
		typedef OsModel_P OsModel;
		typedef Radio_ClientDPS_P Radio_ClientDPS;
		typedef Radio_P Radio;
		typedef Debug_P Debug;
		typedef Timer_P Timer;
		
		typedef Clientstub<OsModel,Radio_ClientDPS,Radio, Debug, Timer> self_type;
		
		
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
		Clientstub();
		~Clientstub();
		///@}
		
		
		void init( Radio& radio,Debug& debug, Timer& timer)
		{
			radio_ = &radio;
			debug_ = &debug;
			timer_ = &timer;
			
			
			
			bind_client_to_server();
			
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
		*interface offered to transport layer by the client_stub
		*/
		//int remotesend (IPv6address reciver,size_t packet_size,block_data_t *data);
		int remotesend();
		
		
		/**
		* Callback function of the layer. This is called by the ClientDPS Radio.
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
		
				
		int bind_client_to_server();
		
		int routing_poll( void* p_number );
		//all the other required functions .
		
	};	


	//----------------------------------------------------------------------------------------------
	//
	//----------------------------------------------------------------------------------------------
	//
	//---------------------------------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	Clientstub()
	: radio_ ( 0 ),
	debug_ ( 0 )
	{}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	~Clientstub()
	{
		disable_radio();
		
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	init( void )
	{
		return 1;
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	destruct( void )
	{
		return disable_radio();
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	enable_radio( void )
	{
		return 1;
	}
	
	// -----------------------------------------------------------------------
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	disable_radio( void )
	{
	return 1;
		
	}
	//------------------------------------------------------------------------------------------
	
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P, Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	bind_client_to_server()
	{
		/**
		*broadcast rpc DISCOVERY message 

		*	wait for ADVITISE message from server
		*	send rpc ACCEPT message to server
		*	wait for ALLOW/ABORT message
		*	
		*	if rpc ALLOW
		*		IF connection NOT established
		*			send FINISH message
				else if already connected 
					send  ABORT message
		*
		*/
		return 1;
	}

	
	//-----------------------------------------------------------------------------------
	//SEND [interface to upper layer]
	//-----------------------------------------------------------------------------------	
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P,Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	remotesend( )
	{	
		/*data (marshelling)
		 of data
		 converting ipv6 address to mac address
		 forwarding to ClientDPS 
		*/
		return 1;
	}
	
	
	
	//---------------------------------------------------------------------------------------
	//RECIEVE PACKETS []
	//---------------------------------------------------------------------------------------
	
	template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	void 
	Clientstub<OsModel_P,Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	remotereceive( )
	{
		/*reciving data from ClientDPS
		and 
		unmarshelling it
		call required procedure
		*/
		
	}
	
	
	 //--------------------------------------------------------------------------------------------
	 //set addr of destination in Routing table .
	//-------------------------------------------------------------------------------------------		
		
		template<typename OsModel_P,
		typename Radio_ClientDPS_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P>
	int
	Clientstub<OsModel_P,Radio_ClientDPS_P, Radio_P, Debug_P, Timer_P>::
	routing_poll( void* p_number )
	{
		return 1;
	
	}
	
	//----------------------------------------------------------------------------------
	// GET_IPADDR
	//---------------------------------------------------------------------------------
	
	
	
}
	

#endif
