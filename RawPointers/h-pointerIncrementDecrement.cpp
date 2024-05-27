#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstddef>

using namespace std;

/*
Postfix Operations
Increment and Decrement
Postfix expressions are useful for moving between adjacent type. For example, the following function determines the length of a C-style, 
null-terminated string. Execution leaves the while loop once it encounters the null byte (*s == '\0'). In this example, 
each type is of one-byte length:
*/

// Note that the dereferencing operator * has lower precedence than the post-fix operator ++. This means that the expression *s++ is 
// evaluated as *(s++). That is, the condition increments the address stored in pointer s to point to the next byte, 
// retrieves the value stored in that address, and checks that value against null character('\0').
unsigned int length(const char* s) {
	unsigned int len = 0u;
	while (*s++) {
		len++;
	}

	return len;
}


int main() {
	const char* testString= "this is a string";
	auto result = length(testString);

	std::cout << "length of" << " '" << testString << "' is: " << result << std::endl;

	return 0;
}