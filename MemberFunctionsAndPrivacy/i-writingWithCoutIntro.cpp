
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

cout
The cout object is an instance of the ostream type. An ostream 
object copies data from system memory into an output stream; 
in copying, it converts the data in system memory into a sequence 
of characters.

The general expression for inserting data into the standard 
output stream takes the form:

cout << identifier

where << is the insertion operator and identifier is the name of 
the variable or object that holds the data.
*/

int main() {

	/*


	*/
	int i = 6;
	char c = ' ';
	double x = 9.75;
	char s[] = "Harry";

	// endl inserts a newline character into the stream 
	// and flushes the stream's buffer.

	cout << i;
	cout << c;
	cout << x;
	cout << c;
	cout << s;
	cout << endl;
	cout << "Data has been written";

	return 0;
}

