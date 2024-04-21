
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
	fill()
	The fill(char) member function defines the padding character.
	The output object inserts this character into the stream
	wherever text occupies less space than the specified field
	width. The default fill character is ' ' (space).
	To pad a field with '*''s, we add:

	Note that, The padding character remains unchanged, 
	until we reset it. In other words, its effect is permenant.
	*/
	int attendance = 27;
	cout << "1234567890" << endl;
	cout.width(10);
	cout.fill('*');
	cout << attendance << endl; // see that setting fill affected this.
	cout.width(15);
	cout << attendance << endl; // see that setting fill affected this also.

	// to set padding char to defauly(' ') or another value we need
	// to set it again.
	cout.width(15);
	cout.fill(' ');
	cout << attendance << endl; // see that setting fill affected this.

	return 0;
}

