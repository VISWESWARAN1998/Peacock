// SWAMI KARUPPASWAMI THUNNAI

#include"client_socket.h"

client_socket::udp::udp(std::string ip_address, int port_no)
{
	// Initailize the socket to udp
	socket = get_socket(UDP);
	// Initialize the client's ip address to ip version 4
	client.sin_family = AF_INET;
	// Client's ip address
	client.sin_addr.S_un.S_addr = inet_addr(ip_address.c_str());
	// Client's port no
	client.sin_port = htons(port_no);
}

void client_socket::udp::get_client_socketaddr(sockaddr_in& from)
{
	from = this->client;
}

void client_socket::udp::send_message(sockaddr_in from, std::string message)
{
	int size = sizeof(from);
	if (sendto(socket, message.c_str(), message.size(), 0,
		(struct sockaddr*)&from, size) == SOCKET_ERROR)
	{
		throw socket_error();
	}
}

char * client_socket::udp::receive(int buffer_size, sockaddr_in& from)
{
	char* buffer = new char[buffer_size];
	int size = sizeof(from);
	if (recvfrom(socket, buffer, buffer_size, 0,
		(struct sockaddr*)&from, &size) == SOCKET_ERROR) throw socket_error();
	return buffer;
}

void client_socket::udp::close()
{
	closesocket(socket);
}