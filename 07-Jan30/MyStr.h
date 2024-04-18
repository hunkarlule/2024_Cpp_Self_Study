#ifndef SENECA_MYSTR_H
#define SENECA_MYSTR_H

#include <iostream>
// this is not allowed(using namesapce) in .h files.
// So, therfore, we need to qualify every obejct with the namespace with :: operator
// like this: for example we want to use some indetifiers from
// std namespace:  std::cout, or std:ostream
//using namespace std; // DO not do this!
namespace seneca {
	class MyStr {
		char* m_data;
		// we can alsoset/initizalize attributes in C++ while creating
		// like below. So if we do this, objects will always start with this
		// values in attributes.
		//char* m_data{};

	public:
		MyStr();
		MyStr(const char* cString);
		MyStr(const char* cString, size_t maxLen);
		~MyStr();
		//void set(const char* cString);
		MyStr& set(const char* cString); // instead of void we return MyString reference.

		//void print() const;
		std::ostream& print() const; // we want to retirn ostream reference instrad of void.
	};
}


#endif // !SENECA_MYSTR_H



