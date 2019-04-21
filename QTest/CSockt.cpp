#include "CSockt.h"
#pragma comment(lib,"ws2_32.lib")
//CRITICAL_SECTION			CSockt::s_Critical_Section;
//std::atomic<unsigned int>	CSockt::s_CriticalSectionCounter=0;
CSocket::CSocket(const std::string &IpAddr, const std::string &PortNum, SOCKTTYPE socktype, CLIENTTYPE clienttype):
m_sockthandle(INVALID_SOCKET),
m_ClientType(clienttype),
m_IpAddr(IpAddr),
m_PortNum(PortNum),
m_ServerAppcet(INVALID_SOCKET),
m_SokcetType(socktype),
m_ConnectFlag(false),
m_ServerThreadRunflag(false),
m_TcpServerAccpetfalg(false),
m_recvibuf(new  char[200000]),
m_hServerRecviThreadHandle(nullptr)
{
	
	//ZeroMemory(&m_RemoteAddr, sizeof(m_RemoteAddr));//Content Zero
	::InitializeCriticalSection(&m_Critical_Section);
	//s_CriticalSectionCounter += 1;
	SokctLoadinit();
	if (socktype == SOCKTTYPE::TCP) //TCP
	{
		this->m_sockthandle = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (clienttype == CLIENTTYPE::Client)
		{
			
			this->m_RemoteAddr.sin_family = AF_INET;
			this->m_RemoteAddr.sin_addr.S_un.S_addr = inet_addr(m_IpAddr.c_str());
			this->m_RemoteAddr.sin_port = htons(atoi(m_PortNum.c_str()));

		}
		else if (clienttype == CLIENTTYPE::Server)
		{
			this->m_RemoteAddr.sin_family = AF_INET;
			this->m_RemoteAddr.sin_addr.S_un.S_addr = INADDR_ANY;
			this->m_RemoteAddr.sin_port = htons(atoi(m_PortNum.c_str()));

		}

	}
	else if (socktype == SOCKTTYPE::UDP) //UDP
	{
		this->m_sockthandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		this->m_UDPRemoteAddr.sin_family = AF_INET;
		if (clienttype == CLIENTTYPE::Client)
		{
			this->m_RemoteAddr.sin_family = AF_INET;
			this->m_RemoteAddr.sin_addr.S_un.S_addr = inet_addr(m_IpAddr.c_str());
			this->m_RemoteAddr.sin_port = htons((atoi(m_PortNum.c_str())));
			
		}
		else if (clienttype == CLIENTTYPE::Server)
		{
			this->m_RemoteAddr.sin_family = AF_INET;
			this->m_RemoteAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
			this->m_RemoteAddr.sin_port = htons((atoi(m_PortNum.c_str())));
		}
	}
	else
	{
		return;
	}
	if (this->m_sockthandle == INVALID_SOCKET)
	{
		return;
	}
	
	return;
	
}
CSocket::~CSocket()
{
	if (m_Serverrecvithread!=nullptr)
	{
		m_ServerThreadRunflag = false;
		if (m_Serverrecvithread->joinable())
		{
			m_Serverrecvithread->join();
		}
		delete m_Serverrecvithread;
		m_Serverrecvithread = nullptr;
		m_hServerRecviThreadHandle = nullptr;
	}
	closesocket(this->m_sockthandle);
	this->m_sockthandle = INVALID_SOCKET;
	::DeleteCriticalSection(&m_Critical_Section);
	delete[] m_recvibuf;
	//s_CriticalSectionCounter -= 1;
	
}
bool CSocket::Connect()
{
	
	if (this->m_sockthandle == INVALID_SOCKET)
	{
		return false;
	}
	if (this->m_SokcetType == SOCKTTYPE::TCP)
	{

		if (this->m_ClientType == CLIENTTYPE::Client)
		{
			
			int ret = connect(this->m_sockthandle, (sockaddr*)(&this->m_RemoteAddr), sizeof(this->m_RemoteAddr));
			if (ret == SOCKET_ERROR)
			{


				DEBUGMSG(" Connect  TCP  erver  fail !!!")
				closesocket(this->m_sockthandle);
				WSACleanup();
				return false;
			}
			this->m_ConnectFlag = true;
		}
		else if (this->m_ClientType == CLIENTTYPE::Server)
		{
			if (SOCKET_ERROR == bind(this->m_sockthandle, (sockaddr*)(&this->m_RemoteAddr), sizeof(this->m_RemoteAddr)))
			{
				DEBUGMSG(" Bind TCP  sockt server addr fail !!!")
				closesocket(this->m_sockthandle);
				WSACleanup();
				return false;
			}
			DEBUGMSG(" Bind TCP  sockt server addr fail !!!")
			m_ServerThreadRunflag = true;
			m_Serverrecvithread = new std::thread(ServerListenThread, this);
			m_hServerRecviThreadHandle = m_Serverrecvithread->native_handle();
			if (!m_hServerRecviThreadHandle)
			{
				::SetThreadPriority(m_hServerRecviThreadHandle,THREAD_PRIORITY_ABOVE_NORMAL);
			}
			m_ConnectFlag = true;
		}
	}
	else if (m_SokcetType == SOCKTTYPE::UDP)
	{
		if (m_ClientType== CLIENTTYPE::Client)
		{
			m_ConnectFlag = true;
			return true;
		}
		else if (m_ClientType == CLIENTTYPE::Server)
		{
			
			if (bind(m_sockthandle, (sockaddr*)&m_RemoteAddr, sizeof(m_RemoteAddr)) == SOCKET_ERROR)
			{
				DEBUGMSG(" Bind UDP sockt server addr fail !!!")
				closesocket(m_sockthandle);
				WSACleanup();
				return false;
			}
			else
			{
				DEBUGMSG(" Bind UDP sockt server addr Success !!!")
				m_ServerThreadRunflag = true;
				m_Serverrecvithread = new std::thread(ServerListenThread, this);
				m_ConnectFlag = true;
			}

		}
		return false;

	}
	return true;
}
bool CSocket::DisConnect()
{
	closesocket(this->m_sockthandle);
	WSACleanup();
	return true;
}

bool CSocket::Isopen()
{
	return (m_sockthandle!= INVALID_SOCKET);
}
bool CSocket::IsConnect()
{
	return m_ConnectFlag;
}

int CSocket::SendData(const std::string &Data, int SendNum)
{
	if (this->m_sockthandle == INVALID_SOCKET)
	{
		return -1;
	}
#ifdef _UNICODE
	std::string cvt = CUtility::utf8_to_gb2312(Data);
#else
	std::string cvt = Data;
#endif // 

	if (m_SokcetType == SOCKTTYPE::TCP)
	{


		if (m_ClientType == CLIENTTYPE::Client)
		{

			return send(this->m_sockthandle, cvt.c_str(), cvt.length(), 0);

		}
		else if (this->m_ClientType == CLIENTTYPE::Server)
		{
			if (m_ServerAppcet!= INVALID_SOCKET)
			{
				
				int sendnum = send(m_ServerAppcet, Data.c_str(), Data.length(), 0);
				//TODO Link break judgement need better way
				if (sendnum<0)
				{

					m_ServerAppcet = INVALID_SOCKET;
					m_TcpServerAccpetfalg = false;

				}
				return sendnum;
			}
			return -1;

		}
	}
	else if (this->m_SokcetType == SOCKTTYPE::UDP)
	{
		

		if (this->m_ClientType == CLIENTTYPE::Client)
		{
			if (this->m_RemoteAddr.sin_port == 0)
			{
				
				DEBUGMSG("Please Set the UDP Remote Addr !!!");
				return -1;
			}
			int addrlen = sizeof(this->m_RemoteAddr);
			return sendto(this->m_sockthandle, Data.c_str(), Data.length(),0,(SOCKADDR*)&this->m_RemoteAddr, addrlen);
		}
		else if (this->m_ClientType == CLIENTTYPE::Server)
		{
			if (this->m_UDPRemoteAddr.sin_port == 0 )
			{
				DEBUGMSG("Not Client Connect to Server !!!");
				return -1;
			}
			
			int addrlen = sizeof(this->m_UDPRemoteAddr);
			return sendto(this->m_sockthandle, Data.c_str(), Data.length(), 0, (SOCKADDR*)&this->m_UDPRemoteAddr, addrlen);
		}
		return  -1;
	}
	return -1;
}

int CSocket::Recvi(std::string &recvidata, int recvilength)
{	
	char *recvidatabuf = new char[recvilength+1];
	if (this->m_SokcetType == SOCKTTYPE::TCP)
	{

		if (this->m_ClientType == CLIENTTYPE::Client)
		{
			int sendnum = recv(this->m_sockthandle, recvidatabuf, recvilength,0);
			recvidata = recvidatabuf;
			delete[] recvidatabuf;
			return sendnum;
		}
		else if (this->m_ClientType == CLIENTTYPE::Server)
		{
			if (m_Recvibufdeque.size()>0)
			{
				if (recvilength!=AllDATA)
				{	
					for (size_t i = 0; i <= m_Recvibufdeque.size(); i++)
					{
						if (recvidata.length() < recvilength)
						{
							CriticalSectionLockGuardian cslock(m_Critical_Section);
							recvidata.append(m_Recvibufdeque.front());
							m_Recvibufdeque.pop_front();
						}
					}
				}
				else
				{
					for (size_t i = 0; i < m_Recvibufdeque.size(); i++)
					{
						CriticalSectionLockGuardian cslock(m_Critical_Section);
						recvidata.append(m_Recvibufdeque.front());
						m_Recvibufdeque.pop_front();
					}
				}
			}
			return 0;
		}
	}
	else if (m_SokcetType == SOCKTTYPE::UDP)
	{
		if (m_ClientType == CLIENTTYPE::Client)
		{
			int nServerlen = sizeof(this->m_RemoteAddr);
			return recvfrom(this->m_sockthandle, recvidatabuf, recvilength,0, (SOCKADDR*)&this->m_RemoteAddr, &nServerlen);
		}
		else if (this->m_ClientType == CLIENTTYPE::Server)
		{
			if (m_Recvibufdeque.size()>0)
			{
				if (recvilength != AllDATA)
				{
					for (size_t i = 0; i < m_Recvibufdeque.size(); i++)
					{
						if (recvidata.length() < recvilength)
						{
							CriticalSectionLockGuardian cslock(m_Critical_Section);;
							recvidata.append(m_Recvibufdeque.front());
							m_Recvibufdeque.pop_front();
						}
					}
				}
				else
				{
					for (size_t i = 0; i < m_Recvibufdeque.size(); i++)
					{
						CriticalSectionLockGuardian cslock(m_Critical_Section);;
						recvidata.append(m_Recvibufdeque.front());
						m_Recvibufdeque.pop_front();
					}
				}
			}
			return 0;
		}
		return  -1;
	}
	return -1;
}

bool CSocket::GetServerLinkinfor(SOCKTTYPE sockttype, SOCKADDR_IN & clientinforget)
{
	return false;
}

bool CSocket::SetUDPRemoteAddr(const std::string &Ipaddr, const std::string &Port)
{
	try
	{	
		this->m_UDPRemoteAddr.sin_addr.S_un.S_addr = inet_addr(Ipaddr.c_str());
		this->m_UDPRemoteAddr.sin_port = htons(atoi(Port.c_str()));
		return true;

	}
	catch (const std::exception& e)
	{
		DEBUGMSG(" Set the UDPRemoteAddr fail: !!!");
		return false;

	}
	return false;	
}

const char* CSocket::recvithreadfun()
{
	
	memset(m_recvibuf, 0, 200000);
	if (this->m_SokcetType == SOCKTTYPE::TCP)
	{

		if (!m_TcpServerAccpetfalg)
		{
			if (listen(this->m_sockthandle, 1) == SOCKET_ERROR)
			{
				closesocket(this->m_sockthandle);
				WSACleanup();
				return nullptr;
			}
			int addrlen = sizeof(m_TCPServerAccpet);
			if ((m_ServerAppcet = accept(this->m_sockthandle, (sockaddr*)(&m_TCPServerAccpet), &addrlen)) == INVALID_SOCKET)
			{

				closesocket(this->m_sockthandle);
				WSACleanup();
				return nullptr;
			}
			else
			{
				m_TcpServerAccpetfalg = true;
			}
		}
		if (m_TcpServerAccpetfalg)
		{
			recv(this->m_ServerAppcet, (char*)(m_recvibuf), 200000, 0);
		}
		DEBUGMSG(std::string(m_recvibuf));
		return m_recvibuf;
	}
	else if (this->m_SokcetType == SOCKTTYPE::UDP)
	{
		if (this->m_UDPRemoteAddr.sin_port!=0)
		{
			int len = sizeof(m_UDPRemoteAddr);
			recvfrom(m_sockthandle, m_recvibuf, 2000, 0, (SOCKADDR*)&m_UDPRemoteAddr, &len);
			DEBUGMSG(std::string(m_recvibuf));
			return m_recvibuf;
		}
	}
	return nullptr;
}

bool CSocket::SokctLoadinit()
{
	DWORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	 {
		   return false;
	}
	return true;
}

void CSocket::ServerListenThread(LPVOID Param)
{
	
	CSocket *Serverthread = static_cast<CSocket *>(Param);
	while (Serverthread->m_ServerThreadRunflag)
	{

		/*select(Serverthread->m_sockthandle);*/
		//std::this_thread::yield();
		const char* recvi = Serverthread->recvithreadfun();
		CriticalSectionLockGuardian cslock(Serverthread->m_Critical_Section);
		Serverthread->m_Recvibufdeque.push_back(recvi);
	}
}
