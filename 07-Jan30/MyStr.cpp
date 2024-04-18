#include <iostream>
#include "Utils.h"
#include "MyStr.h"

using namespace std;
namespace seneca {
	MyStr::MyStr()
	{
		m_data = nullptr;
	}

	MyStr::MyStr(const char* cstr)
	{
		m_data = nullptr;
		if (cstr) {
			m_data = new char[ut.strlen(cstr) + 1];
			ut.strcpy(m_data, cstr);
		}
	}
	MyStr::MyStr(const char* cstr, size_t maxLen)
	{
		m_data = nullptr;
		if (cstr) {
			size_t len = ut.strlen(cstr);
			m_data = new char[(len < maxLen ? len : maxLen) + 1];
			ut.strcpy(m_data, cstr, maxLen);
		}
	}

	MyStr::~MyStr()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	void MyStr::print() const
	{
		if (m_data) {
			cout << m_data;
		}
	}
}





