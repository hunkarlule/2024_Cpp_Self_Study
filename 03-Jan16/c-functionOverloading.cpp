#include <iostream>
using namespace std;

// type size_t is basically is unsigned int

// function overlaoding. this is simplest fomr of polymorphism in C++.
// functions have same name both their signature ( name + arguments type/order/count) different.
// so, compiler determines to which version to call according to parameters
// that we passed during calling the function.
void line(char fill, size_t len);  //this is function declerations
void line(char fill);

// this overload is in conflict with version void line(char fill)
// since both int and char integral/int type in C++.
// so both functions signature becomes same (line + int)
//void line(size_t len); 
int main() {

	line('+', 40); // will call version: void line(char fill, size_t lenght);
	line('A'); // will call version: void line(char fill);
	line(65); // will call version: void line(char fill);
	line(60);
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

//void line(size_t len) {
//	line('-', len);
//}