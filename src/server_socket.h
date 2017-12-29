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
	Transmission Control Protocol:
	------------------------------
	The Transmission Control Protocol (TCP) is intended for use as a highly
	reliable host-to-host protocol between hosts in packet-switched computer
	communication networks, and in interconnected systems of such networks.

	Reference:
	----------
	Definition from RFC
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
		socket_error --> if the socket cannot be created
		bind_error   --> if the port is already in use
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
		Will receive the message from the client with
		the specified buffer size
		*/
		char* receive(SOCKET client_socket, int buffer_size);

		/**
		Description:
		-------------
		This method is used to send message on the specified socket

		Throws:
		--------
		socket_error
		*/
		void send_message(SOCKET s, std::string message);

		/**
		Description:
		-------------
		Will close the TCP connection itself.
		*/
		void close();		
	};

	/**
	User Datagram Protocol
	----------------------
	*/
	class udp : public Socket
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
		socket_error --> if the socket cannot be created
		bind_error   --> if the port is already in use
		*/
		udp(std::string ip_address, int port_no);

		/**
		Description:
		------------
		This method is used to receive the message from the client
		for the specified buffer size.

		Throws:
		-------
		socket_error
		*/
		char* receive(int buffer_size, sockaddr_in& from);

		/**
		Description:
		-------------
		This method is used to send the message via UDP 
		in the specified socket

		Throws:
		-------
		socket_error
		*/
		void send_message(sockaddr_in from, std::string message);

		/**
		Definition:
		-----------
		This method is used to close the UDP connection
		*/
		void close();
	};
}