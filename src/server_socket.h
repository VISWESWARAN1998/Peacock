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
	class tcp :public Socket
	{
	private:
		SOCKET socket;
		sockaddr_in server;
	public:
		tcp(std::string ip_address, int port_no);
		void tcp_listen(int backlog);
		SOCKET accept_client(sockaddr_in& from);
		char* receive(SOCKET client_socket);
		void close(SOCKET socket);

		void close();		
	};
}