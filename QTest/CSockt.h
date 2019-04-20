#pragma once
/*


*/
#include <WinSock2.h>
#include "Utility.h"
#include "Resoure.h"
#ifdef _DEBUG
#define DEBUGMSG(msg) std::cout<<(msg)<<std::endl;
#else
	#define DEBUGMSG(msg)	 
#endif // _DEBUG
#define AllDATA     -1
typedef enum SocktType
{
	TCP = 0,
	UDP
} SOCKTTYPE;
typedef enum ClientType
{
	Client = 0,
	Server
} CLIENTTYPE;
class CSockt
{  

public:
	CSockt(std::string IpAddr = "127.0.0.1", std::string PortNum = "8080", 
				SOCKTTYPE socktype = SOCKTTYPE::TCP, CLIENTTYPE clienttype = CLIENTTYPE::Client);
	virtual		~CSockt();
	bool		Connect();
	bool		DisConnect();
	bool		Isopen();
	bool		IsConnect();
	int			SendData(std::string Data, int SendNum);
	int			Recvi(std::string &recvidata, int recvilength);
	bool		GetServerLinkinfor(SOCKTTYPE sockttype, SOCKADDR_IN &clientinforget);
	bool		SetUDPRemoteAddr(std::string Ipaddr, std::string Port);
public:
	std::function<int(std::string&,int)> RecviRegisterfun; //register recvi function interface
private:
	SOCKET					m_sockthandle; //Sockt Resource
	CLIENTTYPE				m_ClientType;
	SOCKTTYPE				m_SokcetType;
	std::string				m_IpAddr;
	std::string				m_PortNum;
	SOCKET					m_ServerAppcet;
	bool					m_ConnectFlag;
	SOCKADDR_IN				m_RemoteAddr;
	SOCKADDR_IN				m_UDPRemoteAddr;
	SOCKADDR_IN				m_TCPServerAccpet;
	std::deque<std::string>	m_Recvibuf;
	bool					m_ServerThreadRunflag;
	bool					m_TcpServerAccpetfalg;
	std::thread				*m_Serverrecvithread;
	std::mutex				m_server_recvi_var_mutex;
private:
	static bool SokctLoadinit();
	static void	ServerListenThread(LPVOID Param);
	std::string	recvithreadfun();


};

