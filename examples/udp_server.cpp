// SWAMI KARUPPASWAMI THUNNAI

#include<iostream>
#include"server_socket.h"

int main()
{
	try {
		server_socket::udp server("127.0.0.1", 90);
		sockaddr_in from;
		std::cout << server.receive(10, from);
		server.send_message(from, "Hello there");
		server.close();
	}
	catch (std::exception &e)
	{
		std::cout << "exception: ";
		std::cout << e.what();
	}
}
