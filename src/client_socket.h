//SWAMI KARUPPASWAMI THUNNAI

#pragma once
#include"socket.h"
#include<string>

namespace client_socket
{
	/**
	Transmission Control Protocol - Client Class:
	---------------------------------------------
	The Transmission Control Protocol (TCP) is intended for use as a highly
	reliable host-to-host protocol between hosts in packet-switched computer
	communication networks, and in interconnected systems of such networks.

	Reference:
	----------
	Definition from RFC
	*/
	class tcp : public Socket
	{
	private:
		SOCKET socket;
		sockaddr_in client;
	public:
		/**
		Description:
		------------
		This method will help you to connect the client on the specified
		IP and port number.

		Throws:
		-------
		connection_error, socket_error
		*/
		tcp(std::string ip_address, int port_no);
		/**
		Description:
		-------------
		This method will return the client socket
		*/
		void get_client_socket(SOCKET& socket);

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
		-----------
		closes the tcp connection
		*/
		void close();
	};

	/**
	User Datagram Protocol - Client Class
	---------------------------------------
	1. Unlike TCP, UDP is a connectionless protocol which has no handshaking
	mechanisms.
	2. UDP has minimal error checking mechanisms compared to tcp and will 
	provide no guarantee that the packet is transmitted.
	3. You cannot use UDP for reliable data transfer.
	*/
	class udp : public Socket
	{
	private:
		SOCKET socket;
		sockaddr_in client;
	public:
		/**
		Description:
		------------
		This method will help you to connect the client on the specified
		IP and port number.

		Throws:
		-------
		socket_error
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
		Description:
		-------------
		This method will return the client socket
		*/
		void get_client_socketaddr(sockaddr_in& from);

		/**
		Description:
		-----------
		closes the udp connection
		*/
		void close();
	};
}