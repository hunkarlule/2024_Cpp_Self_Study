
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
	width()
	The width(int) member function specifies the minimum width of
	the next output field:
	In other words, effct of width is temporary. It only affects the
	first print coming after width.

	*/
	int attendance = 27;
	cout << "1234567890" << endl;

	/*
	width(int) applies only to the next field. Note how the field
	width for the first display of attendance is 10,
	while the field width for the second display of attendance
	is just the minimum number of characters needed to
	display the value (2).
	*/
	cout.width(10);
	cout << attendance << endl; // ss that setting width affected only this.
	cout << attendance << endl;

	return 0;
}



