#include <iostream>
using namespace std;

// type size_t is basically is unsigned int

// it is good idea to provide default values for arguments
// instead of writing overloads for each case.
// for example we commented out overload(void line();) and provided
// default value for arguments in oveload(void line(char fill = '-');)
// our program still doing the same job exactly.
void line(char fill, size_t len);  //this is function decleration
void line(char fill = '-');
//void line();
int main() {

	line('+', 40); // will call version: void line(char fill, size_t lenght);
	line('='); // will call version: void line(char fill = '-');
	line(); // will call version: void line(char fill = '-');

	return 0;
}

// this is function implementation.
void line(char fill, size_t len) {
	for (size_t i{}; i < len; i++) { // same with writing size_t i = 0;
		cout << fill;
	}
	cout << endl;
}

void line(char fill) {
	line(fill, 70);
}

//void line() {
//	line('-');
//}