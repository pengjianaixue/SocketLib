#ifndef _CVISA_COMMUNICATION_H
#define _CVISA_COMMUNICATION_H
#pragma once
/*



*/
#include "Resoure.h"
#include "visa.h"
class CVisaCommunication
{

public:
	
	CVisaCommunication();
	virtual ~CVisaCommunication();
private:
	ViSession m_DefalutRm;
	ViSession m_vsInstrumentRe;
public:
	static bool FindInstrumentConnectStr(COMMUNICATIONTYPE comtype, std::string& ConnectDrescripeStr);
};
#endif // !_CVISA_COMMUNICATION_H

