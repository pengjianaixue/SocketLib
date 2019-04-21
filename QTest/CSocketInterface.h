#pragma once
#include <Windows.h>
#include <string>
#include <WinSock2.h>
class CScoketBase
{
typedef enum SocktType
{
	TCP ,
	UDP
} SOCKTTYPE;
typedef enum ClientType
{
	Client ,
	Server
} CLIENTTYPE;

public:
	CScoketBase(const std::string &IpAddr = "127.0.0.1", const std::string &PortNum = "8080",
		SOCKTTYPE socktype = SOCKTTYPE::TCP, CLIENTTYPE clienttype = CLIENTTYPE::Client);
	virtual				~CScoketBase() ;
	virtual	bool		Connect()	 ;
	virtual	bool		DisConnect() ;
	virtual	bool		Isopen() ;
	virtual	bool		IsConnect() ;
	virtual	int			SendData(const std::string &Data, int SendNum) ;
	virtual	int			Recvi(std::string &recvidata, int recvilength) ;
	virtual	bool		GetServerLinkInfor(SOCKTTYPE sockttype, SOCKADDR_IN &clientinforget) ;
	virtual	bool		SetUDPRemoteAddr(const std::string &Ipaddr, const std::string &Port) ;
};