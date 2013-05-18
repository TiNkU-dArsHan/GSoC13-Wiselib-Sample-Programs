#ifndef __ALGORITHMS_DPS_DPS_CLIENT_UART_RADIO_H__
#define __ALGORITHMS_DPS_DPS_CLIENT_UART_RADIO_H__

#include "util/base_classes/radio_base.h"

/**
header files of all the required  managers
*/

namespace wiselib
{
	/** \brief Class for the uart communication
	* As a radio it provides send and receive functions.
	*/
	template<typename OsModel_P,
		typename Radio_P,
		typename Debug_P,
		typename Timer_P,
		typename Uart_P>
	class UartRadio
	: public RadioBase<OsModel_P, typename Radio_P::node_id_t, typename Radio_P::size_t, typename Radio_P::block_data_t>
	{
	
	public:
		typedef OsModel_P OsModel;
		typedef Radio_P Radio;
		typedef Debug_P Debug;
		typedef Timer_P Timer;
		typedef Uart_P Uart;
		
		typedef typename Radio::node_id_t node_id_t;
		
		typedef typename Uart::block_data_t block_data_t;
		typedef typename Uart::size_t size_t;
		
		typedef UartRadio<OsModel, Radio, Debug, Timer, Uart> self_type;
		typedef self_type* self_pointer_t;
		
		
		enum ErrorCodes
		{
		 SUCCESS = OsModel::SUCCESS,
		 ERR_UNSPEC = OsModel::ERR_UNSPEC,
		 ERR_NOTIMPL = OsModel::ERR_NOTIMPL,
		 ERR_HOSTUNREACH = OsModel::ERR_HOSTUNREACH
		};
		
		enum InterfaceID
		{
			INTERFACE_UART = 1
		};


		// -----------------------------------------------------------------
		UartRadio()
		{
		
		}

		// -----------------------------------------------------------------
		
		/**
		* Initialize the manager, get instances
		*/
		void init( Uart& uart, Radio& radio, Debug& debug,  Timer& timer )
		{
			radio_ = &radio;
			debug_ = &debug;
			uart_ = &uart;
			timer_ = &timer;
		
		}
		
		// -----------------------------------------------------------------
		/** \brief Enable the communication and register for callbacks
		* \return error codes
		*/
		int enable()
		{
			
			
			int result = uart_->enable_serial_comm();
			
			if( result != SUCCESS )
				return result;

			callback_id_ = uart().template reg_read_callback<self_type, &self_type::receive_packet>( this );
			
			
		}
		
		// -----------------------------------------------------------------
		/** \brief Disable the communication and unregister callbacks
		* \return error codes
		*/
		int disable()
		{
			int result = uart_->disable_serial_comm();
			if( result != SUCCESS )
				return result;
			
			uart_->unreg_read_callback( callback_id_ );
			return SUCCESS;
		}
		
		// -----------------------------------------------------------------------
		/** brief Send a packet to the uart
		* 
		*/
		int send(  )
		{
			
		}
		
		// -----------------------------------------------------------------------
		/** \brief Callback function for the Uart
		* In byte-by-byte order a packet can be received in shorter packets.
		* A timeout function reset the receiver if the packet is not fully arrived.
		* \param len the size of the received array
		* \param buf the pointer to the data
		*/
		void receive_packet( size_t len, block_data_t *buf )
		{
			
		}
		
		// -----------------------------------------------------------------------
		
		
		void timeout( )
		{
			//If no new fragment since set the timer, reset the fragmentation process
			
		}
		
		
		
	 private:
	 	typename Uart::self_pointer_t uart_;
		typename Radio::self_pointer_t radio_;
		typename Debug::self_pointer_t debug_;
		typename Timer::self_pointer_t timer_;
		
				
		Uart& uart()
		{ return *uart_; }
		
		Timer& timer()
		{ return *timer_; }
		
	
		
		int callback_id_;
		
	};

}
#endif

