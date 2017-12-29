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
		server.close(); // I know this wont get called :) but in real world applications 
						// you have to close the tcp connection like this
	}
	catch (std::exception &e)
	{
		std::cout << "exception: ";
		std::cout << e.what();
	}
}