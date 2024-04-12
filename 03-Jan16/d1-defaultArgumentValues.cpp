#include <iostream>
using namespace std;

// type size_t is basically is unsigned int

// default argument values for function arguments.
// see , with doing this we eliminated other two overloads.
void line(char fill = '-', size_t len = 70);  //this is function decleration
//void line(char fill = '-');
//void line();
int main() {

	line('+', 40); // will call version: void line(char fill, size_t lenght);
	line('='); // will call version: void line(char fill);
	line(); // will call version: void line();

	return 0;
}

// this is function implementation.
void line(char fill, size_t len) {
	for (size_t i{}; i < len; i++) { // same with writing size_t i = 0;
		cout << fill;
	}
	cout << endl;
}

//void line(char fill) {
//	line(fill, 70);
//}

//void line() {
//	line('-');
//}