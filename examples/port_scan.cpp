// SWAMI KARUPPASWAMI THUNNAI

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