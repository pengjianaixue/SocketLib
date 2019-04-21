#include "CSocketInterface.h"

CScoketBase::CScoketBase(const std::string & IpAddr, const std::string & PortNum, SOCKTTYPE socktype, CLIENTTYPE clienttype)
{
}

CScoketBase::~CScoketBase()
{
}

bool CScoketBase::Connect()
{
	return false;
}

bool CScoketBase::DisConnect()
{
	return false;
}

bool CScoketBase::Isopen()
{
	return false;
}

bool CScoketBase::IsConnect()
{
	return false;
}

int CScoketBase::SendData(const std::string & Data, int SendNum)
{
	return 0;
}

int CScoketBase::Recvi(std::string & recvidata, int recvilength)
{
	return 0;
}

bool CScoketBase::GetServerLinkInfor(SOCKTTYPE sockttype, SOCKADDR_IN & clientinforget)
{
	return false;
}

bool CScoketBase::SetUDPRemoteAddr(const std::string & Ipaddr, const std::string & Port)
{
	return false;
}
