#include <iostream>

using namespace std;

int main() {
	const char s[] = "A C string";

	/*
	The std::hex manipulator specifies the current output format as hexadecimal.
	*/
	std::cout << std::hex;
	//std::cout << std::dec;
	//std::cout << std::oct;


	/*
	Note that in order to display the address of an element we cast it to an int* type.
	Without the int* cast, the substring starting at the address would display like this:
		A C string : A
		C string :
		C string : C
		string :
		string : s
		tring : t
		ring : r
		ing : i
		ng : n
		g : g
	Displaying a substring starts with the value stored at the address of the first element in the substring and ends
	once the element's value is the null byte (the value of the C-style character string terminator).
	*/
	for (size_t i = 0; s[i] != '\0'; i++) {  //s[i] != '\0' with this we are hckeing if we reached the end of the c-string. becuase C-string ends with a null('\0') char.
		//std::cout << "address: " << reinterpret_cast<uintptr_t>(& s[i]) << " char: " << s[i] << std::endl;
		std::cout << "address: " << (int*)&s[i] << " char: " << s[i] << std::endl;
		//std::cout << "address: " << &s[i] << " char: " << s[i] << std::endl;  // see diffeerence between this and above line.
	}




	//std::cout << "The number 42 in octal:   " << std::oct << 42 << '\n'
	//	<< "The number 42 in decimal: " << std::dec << 42 << '\n'
	//	<< "The number 42 in hex:     " << std::hex << 42 << '\n';

	return 0;
}