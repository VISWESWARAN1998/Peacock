// SWAMI KARUPPASWAMI THUNNAI

#include"client_socket.h"

client_socket::tcp::tcp(std::string ip_address, int port_no)
{
	// Initialize the socket to tcp
	socket = get_socket(TCP);
	// Initialize the client's ip address to ip version 4
	client.sin_family = AF_INET;
	// Client's ip address
	client.sin_addr.S_un.S_addr = inet_addr(ip_address.c_str());
	// Client's port no
	client.sin_port = htons(port_no);
	// connect to the specified ip address and port no
	if (connect(socket, (struct sockaddr*)&client, sizeof(client)) < 0) throw connection_error();
}

void client_socket::tcp::get_client_socket(SOCKET & socket)
{
	socket = this->socket;
}

char * client_socket::tcp::receive(SOCKET client_socket, int buffer_size)
{
	char* buffer = new char[buffer_size];
	// Intialize null value to all the elements present in the
	// array in order to avoid garbage data
	for (int i = 0; i < buffer_size; i++) buffer[i] = '\0';
	recv(client_socket, buffer, buffer_size, 0);
	return buffer;
}

void client_socket::tcp::send_message(SOCKET s, std::string message)
{
	// Send the message back
	int result = send(s, message.c_str(), message.size(), 0);
	if (result == SOCKET_ERROR) throw socket_error();
}


void client_socket::tcp::close()
{
	closesocket(socket);
}
