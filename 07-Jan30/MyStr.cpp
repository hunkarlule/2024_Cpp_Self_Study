#include <iostream>
#include "Utils.h"
#include "MyStr.h"

using namespace std;
namespace seneca {
	/*
	area between  parameters closing paranthesis and
	body open curly backets are called "initizalization area/list.
	we can initialize the object's member variables here. So, if we
	do this first member variables will be initizalized and after
	that constructo's body will be ran and object will be constrcuted.
	here we initizalized m_data in the initizalization area like
	this:  m_data(nullptr). we can do the same thing like 
	this m_data {nullptr} . Note that we can not use  m_data = nullptr
	in the initialization area.
	*/
	MyStr::MyStr(const char* cstr, size_t maxLen) : m_data(nullptr)
	{
		if (cstr) {
			size_t len = ut.strlen(cstr);
			m_data = new char[(len < maxLen ? len : maxLen) + 1];
			ut.strcpy(m_data, cstr, maxLen);
		}
	}

	/*
	here we initizalized m_data in the initizalization area like
	this:  m_data{nullptr}.
	*/
	MyStr::MyStr(const char* cstr) : m_data{ nullptr }
	{
		//if (cstr) {
		//	m_data = new char[ut.strlen(cstr) + 1];
		//	ut.strcpy(m_data, cstr);
		//}

		set(cstr);
	}
	
	/*
	here we initizalized m_data in the initizalization area like
	this:  m_data{nullptr}.*/
	MyStr::MyStr() : m_data{ nullptr } { }

	MyStr::~MyStr()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	// So here set returns a reference to current object.
	//void MyStr::set(const char* cstr)
	MyStr& MyStr::set(const char* cstr)
	{
		delete[] m_data;
		m_data = nullptr;
		if (cstr) {
			m_data = new char[ut.strlen(cstr) + 1];
			ut.strcpy(m_data, cstr);
		}

		return *this; //returns a reference to current object.
	}

	// not using anymore.
	//void MyStr::print() const
	//{
	//	if (m_data) {
	//		cout << m_data;
	//	}
	//}

	ostream& MyStr::print() const
	{
		//if (m_data) {
		//	cout << m_data;
		//}
		//return cout;

		// better then above one.
		return cout << (m_data ? m_data : "");
	}

}





