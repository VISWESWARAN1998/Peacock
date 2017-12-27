// SWAMI KARUPPASWAMI THUNNAI

#include<iostream>
#include"server_socket.h"

int main()
{
	try {
		server_socket::tcp server("127.0.0.1", 90);
		server.tcp_listen(10);
		std::cout << "The server is listening\n";
		sockaddr_in from;
		SOCKET client;
		while (true) //we are looping endlessly
		{
			server.accept_client(client, from);
			std::cout << "Accepted connection\n";
			std::cout << server.receive(client, 4096);
			std::cout << "Received\n";
			server.send_message(client, "<h1>Hello World</h1>");
		}
		server.close(); // I know this wont get called :) but in real world applications 
		// you have to close the tcp connection like this
	}
	catch (std::exception &e)
	{
		std::cout << "exception: ";
		std::cout << e.what();
	}
	int a;
	std::cin >> a;
}