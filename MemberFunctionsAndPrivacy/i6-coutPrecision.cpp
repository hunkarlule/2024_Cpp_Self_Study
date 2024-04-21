
#include <iostream>
using namespace std;

/*
Input and Output Examples
The iostream type that represents the standard input and output
objects, like cin and cout, provides member functions for
controlling the conversion of characters from the input stream
into data types stored in system memory and the conversion of
data types stored in system memory into characters sent to
the output stream.

The ostream type supports the following public member functions
for formatting conversions:

width(int): Sets the field width to the integer received
fill(char): Sets the padding character to the character received
setf(...): Sets a formatting flag to the flag received
unsetf(...): Unsets a formatting flag for the flag received
precision(int): Sets the decimal precision to the integer received
*/

int main() {

	/*
	precision()
	The precision() member function sets the precision of 
	subsequent floating-point fields. The default precision is 6 
	units. General, fixed, and scientific formats implement 
	precision differently. General format counts the number of 
	significant digits. Scientific and fixed formats count 
	the number of digits following the decimal point.

	For a precision of 2 under general format, we write:
	Effect of precision is permenant. In other words,
	The precision setting applies to the output of all subsequent floating-point 
	values until we change it.
	*/

	double pi = 3.141592653;
	cout << "1234567890" << endl;
	cout.width(10);
	cout << pi << endl;

	// general format with precision
	cout.precision(2); 
	cout.width(10);
	cout << pi << endl;

	// fixed format with precision
	cout.setf(ios::fixed);
	cout.width(10);
	cout.precision(2);
	cout << pi << endl;

	cout.width(10);
	cout << pi << endl;

	cout.unsetf(ios::fixed);

	// scientific format with precision
	cout.setf(ios::scientific);
	cout.precision(2);
	cout.width(10);
	cout << pi << endl;



	return 0;
}


