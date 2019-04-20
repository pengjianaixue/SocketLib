#pragma once
#include <string>
#include <Windows.h>
#include <codecvt>
#include <locale>
#include <vector>
using WCHAR_GBK = std::codecvt_byname<wchar_t, char, mbstate_t>;
using WCHAR_UTF8 = std::codecvt_utf8<wchar_t>;
#define GBK_NAME ".936"
class CUtility
{
public:

	CUtility()
	{

	}

	~CUtility()
	{

	}
public:
	inline static  std::string ToUnicode(std::string str);
	inline static  std::wstring gbk_to_wstring(const std::string &str);
	inline static std::string  gbk_to_utf8(const std::string &str);
	inline static std::string  utf8_to_gb2312(const std::string &strUtf8);
};

inline std::wstring  CUtility::gbk_to_wstring(const std::string &str)
{
	std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> gbk_cvt(new std::codecvt<wchar_t, char, mbstate_t>("chs"));
	return gbk_cvt.from_bytes(str);
}

inline std::string  CUtility::gbk_to_utf8(const std::string &str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_cvt; // utf8-¡·unicode×ª»»Æ÷
	std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> gbk_cvt(new std::codecvt<wchar_t, char, mbstate_t>("chs")); // unicode-¡·gbk×ª»»Æ÷
	std::wstring t = gbk_cvt.from_bytes(str);
	return utf8_cvt.to_bytes(t);
}
inline std::string CUtility::ToUnicode(std::string str)
{
	std::string retstr;
	wchar_t *pWideChar;
	
	/*int nLen = MultiByteToWideChar(CP_ACP, 0,
		(char*)str.c_str(), -1, NULL, 0);
	if (nLen == 0)
	{
		return 0;
	}
	pWideChar = (PWSTR)HeapAlloc(GetProcessHeap(), 0, nLen * sizeof(WCHAR));
	if (pWideChar == NULL)
	{
		return 0;
	}
	if (nLen != WideCharToMultiByte(CP_ACP, 0,
		(char*)retstr.c_str(), -1, pWideChar, nLen))
	{
		HeapFree(GetProcessHeap(), 0, pWideChar);
		return 0;
	}
	str = pWideChar;
	HeapFree(GetProcessHeap(), 0, pWideChar);*/
	
	return str;
}
std::string CUtility::utf8_to_gb2312(std::string const &strUtf8)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
	std::wstring wTemp = cutf8.from_bytes(strUtf8);
#ifdef _MSC_VER
	std::locale loc("zh-CN");
#else
	std::locale loc("zh_CN.GB18030");
#endif
	const wchar_t* pwszNext = nullptr;
	char* pszNext = nullptr;
	mbstate_t state = {};
	std::vector<char> buff(wTemp.size() * 2);
	int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
		(loc).out(state,
			wTemp.data(), wTemp.data() + wTemp.size(), pwszNext,
			buff.data(), buff.data() + buff.size(), pszNext);
	if (std::codecvt_base::ok == res)
	{
		return std::string(buff.data(), pszNext);
	}
	return "";
}

