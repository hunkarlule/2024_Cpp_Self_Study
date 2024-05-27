#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
Pointing to a String Literal
A string literal is an unmodifiable lvalue. We may not change its contents. 
*/


int main() {
	// this line causing issue :A value of type "const char*" cannot be used to initialize an entity of type "char *"
	// becaue "Avoid overwriting" is const char* and unmodifiable.  but we try to assign in to const*
	
	//char* p = "Avoid overwriting"; // poor coding style; newer compilers might flag this line
	const char* p = "Avoid overwriting"; // so this is the right way to do it.  good coding style
	
	//p[0] = 'm'; // this is error becuase string literal is unmidifiable. 'p': you cannot assign to a variable that is const. ERROR: assignment of read-only location '*p'

	std::cout << std::hex;
	std::cout << p << std::endl;

	return 0;
}