#include <iostream>
using namespace std;

int main() {
	
	// formatting works same with C-strings.
	char val1[20] = "Hello!";

	// now we first print an asteriks and then set cout's width
	// after that we print val1. So, val1 will be printed in 30 spaces.
	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout << val1 << "*" << endl;

	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout.setf(ios::left); // set the flag of cout to make prints left-justified. This will affect all prints coming after this line until we unset the flag.
	cout << val1 << "*" << endl;
	cout.unsetf(ios::left);

	
	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout.setf(ios::left); // set the flag of cout to make prints left-justified. This will affect all prints coming after this line until we unset the flag.
	cout.fill('~'); // fill the spaces with tilda when printing. rhis is also permenant. Menas, it will affect all prints after this point until we  change it.
	cout << val1 << "*" << endl;
	cout.unsetf(ios::left);

	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout.setf(ios::left); // set the flag of cout to make prints left-justified. This will affect all prints coming after this line until we unset the flag.
	cout << val1 << "*" << endl;
	cout.unsetf(ios::left);

	cout << "*";
	cout.width(30); // setting cout so next print will be in 30 spaces.
	cout.setf(ios::right); // set the flag of cout to make prints left-justified. This will affect all prints coming after this line until we unset the flag.
	cout << val1 << "*" << endl;
	cout.unsetf(ios::right);

	return 0;
}