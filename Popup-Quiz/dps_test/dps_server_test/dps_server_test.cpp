/*
*File:dps_server_test.cpp
*Author: Darshan - GSoC 2013 - Pop Quiz
*
*/
/**
*an example appilcation layer server node which uses DPSStack.
*In this communication between desitnation node takes place by using
*Full Protocol stack and between clients using RPC call .
*/

#include "external_interface/external_interface.h"


#include "algorithms/dps/dps_server/dps_server_stack.h"
/*
*#include "algorithms/6lowpan/ipv6_address.h"
*
*/

typedef wiselib::OSMODEL Os;
typedef Os::Radio Radio;
typedef Os::Radio::node_id_t node_id_t;
typedef Os::Uart Uart;


typedef wiselib::DPSServerStack<Os, Radio, Os::Debug, Os::Timer, Uart> DPS_server_stack_t;

//typedef wiselib::IPv6Address<Radio, Os::Debug> IPv6Address_t;

class DpsserverApp
{

public :
	
	
	DPS_server_stack_t dps_server_stack_;
	Radio::self_pointer_t radio_;
	Os::Timer::self_pointer_t timer_;
	Os::Debug::self_pointer_t debug_;
	Uart::self_pointer_t uart_;
	
	
	void init( Os::AppMainParameter& value )
	{
		radio_ = &wiselib::FacetProvider<Os, Os::Radio>::get_facet( value );
		timer_ = &wiselib::FacetProvider<Os, Os::Timer>::get_facet( value );
		debug_ = &wiselib::FacetProvider<Os, Os::Debug>::get_facet( value );
		uart_ = &wiselib::FacetProvider<Os, Uart>::get_facet( value );

		
	        timer_->set_timer<DpsserverApp,
                           &DpsserverApp::start>( 5000, this, 0 );
                           //if server is not reachable find new server by re inisializing the stack
	
	
		/** on inisialization of dps stack ,it waits for rpc DISCOVER message which is send by the client 
		*to find the potential server.on reciving one 
		*and the client's ipv6 address is set by the server.
		*/
		dps_server_stack_.init ( *radio_, *debug_, *timer_, *uart_ );
				
		
		
		/** transport layer protocol  upd / icmpv6 over ipv6  can be used to send
		* and recive message over the network 
		*/
		
		//callback_id = dps_stack_.udp.reg_recv_callback<DpsclientApp,
		//				&DpsclientApp::receive_reply>( this );	
						
						
	  /** create socket for udp using callback_id and destination address etc etc..
	  */
	  
	  
	 /** send message to the destination using remote protocol stack
	 */
	 
	 /** listen to reply message and act
	 */
	
	}
	
	void start( void* )
	{
	
		
	 
	}
	
//	void receive_reply( IPv6Address_t from, uint16_t len, Os::Radio::block_data_t *buf )
//	{
//		char str[43];
//		debug_->debug( "Application layer received msg at %x from %s", radio_->id(), from.get_address(str) );
//		debug_->debug( "    Size: %i Content: %s ", len, buf);
//	}

	
private:
	int callback_id;
	//IPv6Address_t destinationaddr;
	
};
// --------------------------------------------------------------------------
wiselib::WiselibApplication<Os, DpsserverApp> example_app;
// --------------------------------------------------------------------------
void application_main( Os::AppMainParameter& value )
{
  example_app.init( value );
}
