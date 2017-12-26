// SWAMI KARUPPASWAMI THUNNAI
#pragma once
#ifndef SOCKET_H
#define SOCKET_H
#include<windows.h>
#include<winsock.h>
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
	SOCKET get_socket(int type);
};

#endif // SOCKET_H

