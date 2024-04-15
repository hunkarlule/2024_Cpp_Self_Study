#include <iostream>
using namespace std;

int main() {
	// cout prints double whichever way is convenient.
	// In other words, there is no fixed format when printing double with
	// cout.
	// However we can set the cout in a fixed format that we want.
   
	double val1 = 123.4568; 
	//double val1 = 12345678.123456;
	
	cout.setf(ios::fixed); // this force the cout to print all floint points numbers in the same format.
	cout.precision(3); // how many points we want after decimal point.

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