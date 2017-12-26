![logo](static/peacock.png)
</br>
# Peacock - A Networking library for C++
[![GitHub stars](https://img.shields.io/github/stars/VISWESWARAN1998/Peacock.svg)](https://github.com/VISWESWARAN1998/Peacock/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/VISWESWARAN1998/Peacock.svg)](https://github.com/VISWESWARAN1998/Peacock/network)
![Platform](https://img.shields.io/badge/platform-windows-blue.svg)
</br>
# Documentation:
### Getting the sockets:
Generally, sockets are said to be the end points of the bidirectional communication. These socekts follow two main protocol.
1. TCP
2. UDP

*The socket class which is declared in **socket.h** will provide these two sockets. Here is how the class will look like*

```C++
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
	// type = 0 for TCP
	// type = 1 for UDP
	SOCKET get_socket(int type);
};
```

# Example to get the TCP socket
```C++
Socket tcp_socket;
SOCKET s = tcp_socket.get_socket(0); // Change this to 1 for UDP
```

### Architecture of Computer Networking
In computer networking, we follow two types of architecture
1. Client Server Architecture
2. Peer to Peer Architecture

#### 1.Client Server Architecture:
##### 1.1 Servers:
Almost all servers including HTTP, FTP, SMTP, DNS, etc., follows either TCP or UPD [protocol](https://fcit.usf.edu/network/chap2/chap2.htm) <br/>
we will inherit the **Socket** class to form server sockets which is capable of sending and receiving data using TCP and UDP
