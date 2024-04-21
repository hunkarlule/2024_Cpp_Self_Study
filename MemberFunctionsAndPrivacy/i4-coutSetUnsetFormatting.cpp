
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
	setf(), unsetf()
	The setf() and unsetf() member functions control formatting
	and alignment. Their control flags include:

	Control Flag	Result
	ios::fixed		ddd.ddd
	ios::scientific	d.ddddddEdd
	ios::left		align left
	ios::right		align right

	The scope resolution (ios::) on these flags identifies them
	as part of the ios class.
	*/

	/*
	setf(), unsetf() - Formatting
	The default format in C++ is general format, which outputs
	data in the simplest, most succinct way possible
	(1.34, 1.345E10, 1.345E-20). To output a fixed number of
	decimal places, we select fixed format. To specify fixed
	format, we pass the ios::fixed flag to setf():
	effect of setf is permenant. So, we need to use unsetf function
	to turn off its effect.
	*/
	double pi = 3.141592653;
	cout << "1234567890" << endl;
	cout.width(10);
	cout << pi << endl;

	cout.width(10);
	cout.setf(ios::fixed);
	cout << pi << endl;

	/*
	Format settings persist until we change them. To unset fixed
	format, we pass the ios::fixed flag to the unsetf() member
	function:
	*/

	cout.unsetf(ios::fixed);
	cout << pi << endl;

	/*
	To specify scientific format, we pass the ios::scientific
	flag to the setf() member function:
	*/

	cout << "12345678901234" << endl;
	cout.width(14);
	cout.setf(ios::scientific);
	cout << pi << endl;

	cout.width(14);
	cout << pi << endl;

	/*
	To turn off scientific format, we pass the ios::scientific
	flag to the unsetf() member function.
	*/

	cout.unsetf(ios::scientific);
	cout.width(14);
	cout << pi << endl;

	return 0;
}