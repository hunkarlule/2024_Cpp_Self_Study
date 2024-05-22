#include <iostream>

using namespace std;

/*
setf(), unsetf() - Format control
The setf() and unsetf() member functions control formatting and alignment. Their control flags include:

Control Flag		Result
ios::fixed			ddd.ddd
ios::scientific		d.ddddddEdd
ios::left			Align left
ios::right			Align right
The scope resolution (ios::) on these flags identifies them as part of the ios class.

The default format in C++ is general format, which outputs data in the simplest, most succinct way possible (1.34, 1.345E10, 1.345E-20).
To specify scientific format, we pass the ios::scientific flag to the setf() member function:

To turn off scientific format, we pass the ios::scientific flag to the unsetf() member function.
*/

int main() {

	double pi = 3.141592653;
	cout << "12345678901234" << endl;
	cout.fill('*');
	cout.width(14);
	cout.setf(ios::scientific);
	cout << pi << endl;

	cout.width(14);
	cout.unsetf(ios::scientific);
	cout << pi << endl;


	return 0;
}