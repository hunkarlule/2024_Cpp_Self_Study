
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

	/*
	We may combine these expressions into a single statement
	that specifies multiple insertions: we are able to do that 
	becasie << operatore returns "cout" object after doing printing.
	We call such repeated use of the insertion operator cascading.
	
	For this expression: cout << i << c << x << c << s << endl; 
	followings happens:
	cout << i << c << x << c << s << endl; // starting expression
	cout << c << x << c << s << endl; // i printed in the console and cout returned. so, remaining expression become this.
	cout << x << c << s << endl; // c printed in the console and cout returned. so, remaining expression become this.
	cout << c << s << endl; // x printed in the console and cout returned. so, remaining expression become this.
	cout << s << endl; // c printed in the console and cout returned. so, remaining expression become this.
	cout << endl; // s printed in the console and cout returned. so, remaining expression become this.
	// endl printed in the console and cout returned. There is nothing left to print so flow goes to next line.

	*/
	cout << i << c << x << c << s << endl;
	cout << "Data has been written";

	return 0;
}

