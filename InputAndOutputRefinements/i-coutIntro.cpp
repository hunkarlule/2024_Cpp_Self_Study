#include <iostream>

using namespace std;

/*
Output Objects
An output object is an instance of the ostream class. The ostream class defines the structure of an output device. 
An ostream object copies data from system memory into an output stream; in copying, it converts the data in system memory 
into a sequence of characters.

The standard iostream library defines three distinct standard output objects:

cout: Transfers a buffered sequence of characters to the standard output device
cerr: Transfers an unbuffered sequence of characters to the standard error output device
clog: Transfers a buffered sequence of characters to the standard error output device

Inserting Data
The expression for inserting data into an output stream takes the form

output << identifier

where output is the name of the ostream object, << is the insertion operator and identifier is the name of 
the variable or object that holds the data.

Each expression that takes an ostream object as its left operand converts the data in its right operand into 
a sequence of characters based on the type of the expression's right operand.

endl inserts a newline character into the output stream and flushes the stream's buffer.
*/

int main() {

	int i = 6;
	char c = ' ';
	double x = 9.75;
	char s[] = "Harry";
	clog << "Writing data to console" << endl;
	cout << i;
	cout << c;
	cout << x;
	cout << c;
	cout << s;
	cout << endl;
	
	cerr << "Data has been written";

	return 0;
}

