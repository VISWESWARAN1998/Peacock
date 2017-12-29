//SWAMI KARUPPASWAMI THUNNAI

#pragma once
#include"socket.h"
#include<string>

namespace client_socket
{
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
}