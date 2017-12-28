// SWAMI KARUPPASWAMI THUNNAI
#pragma once
#include"socket.h"
#include<string>

/**
This namespace will contain classes which provides specifc sockets
for various protocols like TCP, UDP etc.,
*/
namespace server_socket
{
	/**
	RFC:
	----
	The Transmission Control Protocol (TCP) is intended for use as a highly
	reliable host-to-host protocol between hosts in packet-switched computer
	communication networks, and in interconnected systems of such networks.
	*/
	class tcp :public Socket
	{
	private:
		SOCKET socket;
		sockaddr_in server;
	public:
		/**
		Description:
		------------
		A constructor to bind the specific ip address on a particular port number
		Throws:
		--------
		bind_error if the port is already in use
		*/
		tcp(std::string ip_address, int port_no);
		/**
		Description:
		------------
		Will listen for a specified backlog

		Throws:
		-------
		listen_error
		*/
		void tcp_listen(int backlog);
		/**
		Description:
		-------------
		Will accept connections from the client
		*/
		void accept_client(SOCKET& client, sockaddr_in& from);
				
		/**
		Description:
		-------------
		Will close the particular socket
		*/
		void close(SOCKET& socket);
		/**
		Description:
		-------------
		Will close the TCP connection itself.
		*/
		void close();		
	};
}