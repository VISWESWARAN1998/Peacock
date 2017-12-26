// SWAMI KARUPPASWAMI THUNNAI
#pragma once
#include<exception>


//=====================================================
// FOR THROWING ERROR IN INITIALIZING WSADATA        //
//====================================================
class winsock_initialize_error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Unable to initialize winsock";
	}
};

// ========================================
//FOR THROWING INVALID SOCKET 
//=========================================
class socket_error_invalid : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid sockets";
	}
};

// ===================================
// FOR THROWING SOCKET_ERROR 
// ===================================
class socket_error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Unable to create the sockets";
	}
};

//=============================================
// FOR THROWING INVALID PORT NO
//=============================================

class invalid_port : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid Port No";
	}
};

//===================================================
// BIND ERROR: unable to bind on the specific address
//===================================================
class bind_error : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Cannot bind on the specific address";
	}
};


class listen_error :public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Unable to listen";
	}
};