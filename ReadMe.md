![logo](static/peacock.png)
</br>
# Peacock - A Networking library for C++
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/2d46ec03c4fb48a3a80ea6a889268d71)](https://www.codacy.com/app/VISWESWARAN1998/Peacock?utm_source=github.com&utm_medium=referral&utm_content=VISWESWARAN1998/Peacock&utm_campaign=badger)
[![GitHub stars](https://img.shields.io/github/stars/VISWESWARAN1998/Peacock.svg)](https://github.com/VISWESWARAN1998/Peacock/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/VISWESWARAN1998/Peacock.svg)](https://github.com/VISWESWARAN1998/Peacock/network)
![Platform](https://img.shields.io/badge/platform-windows-blue.svg)
</br>
# Documentation:
### Lesson 1: Creating a simple TCP server:
```C++
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
```