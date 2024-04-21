
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
	int i;
	char c;
	double x;
	char s[8];

	cout << "Enter an integer,\n"
		"a character,\n"
		"a floating-point number and\n"
		"a string : " << flush;
	/*
	The cin object skips leading whitespace with numeric, 
	string and character types (in the same way that 
	scanf("%d"...), scanf("%lf"...), scanf("%s"...) and 
	scanf(" %c"...) skip whitespace in C).
	test-1:		 9			t	 -23.5			harry // for leading white spaces
    test-2:9t-23.5harry
	test-2:9t-23.5harrypotter // this is overflow case!

	*/
	cin >> i;
	cin >> c;
	cin >> x;
	cin >> s; // possible overflow

	cout << "Entered " << i << ' ' << c << ' ' << x << ' ' << s << endl;

	

	return 0;
}

