// SWAMI KARUPPASWAMI THUNNAI

#include<iostream>
#include"client_socket.h"

int main()
{
	try {
		client_socket::tcp client("127.0.0.1", 90);
		SOCKET s;
		client.get_client_socket(s);
		client.send_message(s, "Hello World");
		std::cout<< client.receive(s, 100);
	}
	catch (std::exception &e)
	{
		std::cout << "exception: ";
		std::cout << e.what();
	}
	int a;
	std::cin >> a;
}