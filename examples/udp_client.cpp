// SWAMI KARUPPASWAMI THUNNAI

#include<iostream>
#include"client_socket.h"

int main()
{
	try {
		client_socket::udp client("127.0.0.1", 90);
		sockaddr_in from;
		client.get_client_socketaddr(from);
		client.send_message(from, "Hello There");
		std::cout<<client.receive(100, from);
	}
	catch (std::exception &e)
	{
		std::cout << "exception: ";
		std::cout << e.what();
	}
}