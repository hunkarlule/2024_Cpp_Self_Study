
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
	setf(), unsetf() - Alignment
	The default alignment is right-justified.

	To specify left-justification, we pass the ios::left flag
	to the setf() member function:
	
	Setting alignment's effect is permenant. So, we need to unset
	it to turn off its effect.
	*/
	double pi = 3.141592653;
	cout << "1234567890" << endl;
	cout.width(10);
	cout.fill('?');
	cout << pi << endl; // we did not set any alignment but the default alignment is right-justified. So, see how this is printed.

	cout.width(10);
	cout.setf(ios::left); // setting alingment to left. it will affect all prints until we unset/turn off it.
	cout << pi << endl;

	cout.width(14);
	cout << pi << endl;

	/*
	To turn off left-justification, we pass the ios::left flag 
	to the unsetf() member function:
	*/
	cout.unsetf(ios::left);
	cout.width(10);
	cout << pi << endl;

	return 0;
}


