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

setf(), unsetf() - Alignment
The default alignment is right-justified.

To switch to left-justification, we pass the ios::left flag to the setf() member function:
To switch off left-justification, we pass the ios::left flag to the unsetf() member function:
*/

int main() {

	double pi = 3.141592653;
	cout << "1234567890" << endl;
	cout.fill('?');
	cout.width(10);
	cout.setf(ios::left);
	cout << pi << endl;


	cout.width(10);
	cout.unsetf(ios::left);
	cout << pi << endl;






	return 0;
}