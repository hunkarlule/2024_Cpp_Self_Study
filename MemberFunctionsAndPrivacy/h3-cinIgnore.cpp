
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

cin
The cin object is an instance of the istream type. 
This object extracts a sequence of characters from 
the standard input stream, converts that sequence into 
a specified type and stores that type in system memory.

The general expression for extracting characters from 
the standard input stream takes the form

cin >> identifier

where >> is the extraction operator and identifier is the name 
of the destination variable.

For example,
*/

int main() {

	/*
	The istream type supports the following member functions:

	ignore(...): Ignores/discards character(s) from the input buffer
	get(...): Extracts a character or a string from the input buffer
	getline(...): Extracts a line of characters from the input buffer

	ignore():
	The ignore() member function extracts characters from the 
	input buffer and discards them. ignore() does not skip leading 
	whitespace. Two versions of ignore() are available:

	// The no-argument version discards a single character.
			cin.ignore();
	// The two-argument version removes and discards up to 
	the specified number of characters or up to the specified 
	delimiting character, whichever occurs first and discards 
	the delimiting character. The default delimiter is 
	end-of-file (not end-of-line).
			cin.ignore(2000, '\n');
	*/

	// test-1: Hello world!
	// test-2: Object Oriented
	// test-3: Hello cin // see what happens in this case!!

	char str[11];
	char str2[11];
	cout << "Enter a string : " << endl;
	cin >> str;
	cin.ignore();
	cin.ignore(3, '\n');
	cin >> str2;
	cout << "|" << str << "|" << endl;
	cout << "|" << str2 << "|" << endl;

	return 0;
}

