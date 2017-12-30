![logo](static/peacock.png)
</br>
# Peacock - A Networking library for C++
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/2d46ec03c4fb48a3a80ea6a889268d71)](https://www.codacy.com/app/VISWESWARAN1998/Peacock?utm_source=github.com&utm_medium=referral&utm_content=VISWESWARAN1998/Peacock&utm_campaign=badger)
[![GitHub stars](https://img.shields.io/github/stars/VISWESWARAN1998/Peacock.svg)](https://github.com/VISWESWARAN1998/Peacock/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/VISWESWARAN1998/Peacock.svg)](https://github.com/VISWESWARAN1998/Peacock/network)
![Platform](https://img.shields.io/badge/platform-windows-blue.svg)
</br>
# Documentation:
## Index:
1. [Creating a simple TCP Server](https://github.com/VISWESWARAN1998/Peacock#lesson-1-creating-a-simple-tcp-server)
2. [Creating a simple TCP Client](https://github.com/VISWESWARAN1998/Peacock#lesson-2-creating-a-simple-tcp-client)
3. [Creating a TCP port scanner](https://github.com/VISWESWARAN1998/Peacock#lesson-3-creating-a-simple-tcp-port-scanner)
4. [Creating a simple UDP server](https://github.com/VISWESWARAN1998/Peacock#lesson-4-creating-a-udp-server)
5. [Creating a simple UDP client](https://github.com/VISWESWARAN1998/Peacock/blob/master/ReadMe.md#lesson-5-creating-a-simple-udp-client)
6. [Creating a Local host UDP port Scanner]()


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

### Lesson 2: Creating a simple TCP client
```C++
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
```

### Lesson 3: Creating a simple TCP port scanner:

```C++
#include<iostream>
#include"client_socket.h"

int main()
{
	for (int i = 0; i < 65536; i++)
	{
		try 
		{
			client_socket::tcp client("127.0.0.1", i);
			std::cout << i << " is opened.\n";
			client.close();
		}
		catch (connection_error &e)
		{
			std::cout << i << " is not opened.\n";
			// log e.what() if you want
		}
	}
}
```

### Lesson 4: Creating a simple UDP server
```C++
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
```

### Lesson 5: Creating a simple UDP client
```C++
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
```

### Lesson 6: Creating a localhost UDP port scanner
```C++
// SWAMI KARUPPASWAMI THUNNAI

#include<iostream>
#include<typeinfo>
#include"server_socket.h"
#include"exceptions.h"

bool is_port_opened(int port_no)
{
	try {
		server_socket::udp server("127.0.0.1", port_no);
		server.close();
		return false;
	}
	catch (bind_error &e) {
		return true;
	}
}

int main()
{
	std::cout << "Local Host Port Scanner\n";
	for (int i = 0; i < 65536; i++)
	{
		if (is_port_opened(i))
		{
			std::cout << "Port: " << i << " is opened\n";
		}
	}
	int a;
	std::cin >> a;
}
```