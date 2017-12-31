// SWAMI KARUPPASWAMI THUNNAI

#include"server_socket.h"

server_socket::udp::udp(std::string ip_address, int port_no)
{
	// Initailize the socket as UDP
	socket = get_socket(UDP);
	// Initialize the server's ip family to IP version 4
	server.sin_family = AF_INET;
	// Server's ip address
	server.sin_addr.S_un.S_addr = inet_addr(ip_address.c_str());
	// Server's port no
	server.sin_port = htons(port_no);
	// Now bind the server on the specific port
	if (bind(socket, (struct sockaddr*)&server, sizeof(server)) < 0) throw bind_error();
}

char * server_socket::udp::receive(int buffer_size, sockaddr_in& from)
{
	char* buffer = new char[buffer_size];
	int size = sizeof(from);
	// Intialize null value to all the elements present in the
	// array in order to avoid garbage data
	for (int i = 0; i < buffer_size; i++) buffer[i] = '\0';
	if (recvfrom(socket, buffer, buffer_size, 0, 
		(struct sockaddr*)&from, &size) == SOCKET_ERROR) throw socket_error();
	return buffer;
}

void server_socket::udp::send_message(sockaddr_in from, std::string message)
{
	int size = sizeof(from);
	if (sendto(socket, message.c_str(), message.size(), 0, 
		(struct sockaddr*)&from, size) == SOCKET_ERROR)
	{
		throw socket_error();
	}
}

void server_socket::udp::close()
{
	closesocket(socket);
}
