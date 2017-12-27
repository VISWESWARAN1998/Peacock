#include "server_socket.h"
#include<iostream>

server_socket::tcp::tcp(std::string ip_address, int port_no)
{
	// Initialize the socket to tcp
	socket = get_socket(TCP);
	// Initialize the server's ip family to IP version 4
	server.sin_family = AF_INET;
	// Server's ip address
	server.sin_addr.S_un.S_addr = inet_addr(ip_address.c_str());
	// Server's port no
	server.sin_port = htons(port_no);
	// Now bind the server on the specific port
	if (bind(socket, (struct sockaddr*)&server, sizeof(server)) < 0) throw bind_error();
}

void server_socket::tcp::tcp_listen(int backlog)
{
	if (listen(socket, 10) != 0) throw listen_error();
}

SOCKET server_socket::tcp::accept_client(sockaddr_in& from)
{
	int size = sizeof(from);
	SOCKET s = accept(socket, (sockaddr*)&from, &size);
	return s;
}

char* server_socket::tcp::receive(SOCKET client_socket, int buffer_size)
{
	int result = 0;
	int current_buffer_size = 0;
	char* buffer = (char*)malloc(buffer_size * sizeof(int));
	result = recv(client_socket, buffer, buffer_size, 0);
	return buffer;
}

void server_socket::tcp::send_back(std::string message)
{
	// Send the message back
	send(socket, message.c_str(), message.size(), 0);
}

void server_socket::tcp::close()
{
	closesocket(socket);
}

void server_socket::tcp::close(SOCKET socket)
{
	closesocket(socket);
}
