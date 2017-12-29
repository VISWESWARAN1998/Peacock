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
	if (listen(socket, backlog) != 0) throw listen_error();
}

void server_socket::tcp::accept_client(SOCKET& client,  sockaddr_in& from)
{
	int size = sizeof(from);
	client = accept(socket, (sockaddr*)&from, &size);
}

char * server_socket::tcp::receive(SOCKET client_socket, int buffer_size)
{
	char* buffer = new char[buffer_size];
	recv(client_socket, buffer, buffer_size, 0);
	return buffer;
}

void server_socket::tcp::send_message(SOCKET s, std::string message)
{
	// Send the message back
	int result = send(s, message.c_str(), message.size(), 0);
	if (result == SOCKET_ERROR) throw socket_error();
}

void server_socket::tcp::close()
{
	closesocket(socket);
}