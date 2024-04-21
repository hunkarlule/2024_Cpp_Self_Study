
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
	cin treats whitespace in the input stream as a delimiter 
	for numeric and string data types. For C-style 
	null-terminated string types, cin adds the null byte 
	after the last non-whitespace character stored in memory:
	test-1:_______abc_______ xyz // _ shows multiple space and tabs
	*/

	char str[11];
	cout << "Enter a string : " << endl;
	cin >> str;
	cout << "|" << str << "|" << endl;

	char str2[11];
	cout << "Enter a string : " << endl;
	cin >> str2;
	cout << "|" << str2 << "|" << endl;

	return 0;
}

