// SWAMI KARUPPASWAMI THUNNAI
#include "socket.h"

Socket::Socket()
{
	// Initialize the winsock
	if ((WSAStartup(MAKEWORD(2, 2), &winsock) != 0))throw winsock_initialize_error();
}

SOCKET Socket::get_socket(int type)
{
	switch (type)
	{
	case TCP:
		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) throw socket_error_invalid();
		return sock;
	case UDP:
		if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) throw socket_error_invalid();
		return sock;
	default:
		break;
	}
	return SOCKET();
}

void Socket::send_message(SOCKET s, std::string message)
{
	// Send the message back
	int result = send(s, message.c_str(), message.size(), 0);
	if (result == SOCKET_ERROR) throw socket_error();
}

char * Socket::receive(SOCKET client_socket, int buffer_size)
{
	char* buffer = new char[buffer_size];
	recv(client_socket, buffer, buffer_size, 0);
	return buffer;
}
