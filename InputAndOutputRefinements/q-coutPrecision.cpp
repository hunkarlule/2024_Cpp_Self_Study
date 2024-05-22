#include <iostream>

using namespace std;

/*
precision()
The precision() member function sets the precision of subsequent floating-point fields. 
The default precision is 6 units. General, fixed, and scientific formats implement precision differently. 
General format counts the number of significant digits. Scientific and fixed formats 
count the number of digits following the decimal point.
The precision setting applies to the output of all subsequent floating-point values until we change it.
*/

int main() {

	double pi = 3.141592653;
	cout << "1234567890" << endl;
	cout.fill('*');
	cout.width(10);
	cout << pi << endl;

	cout.setf(ios::fixed);
	cout.precision(2);
	cout.width(10);
	cout << pi << endl;

	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout.width(10);
	cout << pi << endl;






	return 0;
}