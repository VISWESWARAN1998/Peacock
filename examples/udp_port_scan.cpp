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
}