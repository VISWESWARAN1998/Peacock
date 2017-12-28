// SWAMI KARUPPASWAMI THUNNAI
#pragma once
#ifndef SOCKET_H
#define SOCKET_H
#include<windows.h>
#include<winsock.h>
#include<string>
#include"exceptions.h"


#pragma comment(lib, "ws2_32.lib")

/**
DESCRIPTION:
	In networking there are two primary types of socket
		1. TCP
		2. UDP
	This class will give you the above specified socket of your choice
*/
class Socket
{
private:
	WSADATA winsock;
	SOCKET sock;
protected:
	const enum {
		TCP = 0,
		UDP = 1
	};
public:
	Socket();
	// Will return the socket of specified type
	// type = 0 for TCP
	// type = 1 for UDP
	// Throws: socket_error
	SOCKET get_socket(int type);

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
	Will receive the message from the client with
	the specified buffer size
	*/
	char* receive(SOCKET client_socket, int buffer_size);
};

#endif // SOCKET_H

