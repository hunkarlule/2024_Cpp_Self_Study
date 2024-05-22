#include <iostream>
#include <iomanip>

using namespace std;

/*
Manipulators
The C++ language defines manipulators that are elegant alternatives to member function calls. 
These manipulators are operands for the extraction and insertion operators. Manipulators that don't take any argument 
do not include parentheses and are defined in <iostream>. Those that take an argument include parentheses 
and are defined in <iomanip>. That is, we must include <iomanip> whenever we use manipulators that take an argument.

Input Manipulators
The manipulators of input objects are listed below:

Manipulator	Effect
skipws			Skip whitespace
noskipws		Turn off skip whitespace
setw(int)		Set the field width for next input (strings only)
The argument to setw() should be one more than the maximum number of input bytes to be read. 
Note that the setw() manipulator is an alternative to get(char*, int), but setw() skips leading whitespace unless we turn off skipping.

Once a manipulator has modified the format settings of an input object, those settings remain modified.

We may combine manipulators with input variables directly to form compound expressions. For example,
*/
// test it with:<multiple spaces>abcde<multiple spaces>fgh
int main() {

	char a[5], b[2], c, d[7];

	cout << "enter: ";
	cin >> setw(5) >> a >> setw(2) >> b >> noskipws >> c >> skipws >> d;

	cout << "Stored '" << a <<
		"' & '" << b <<
		"' & '" << c <<
		"' & '" << d << "'" << endl;

	return 0;
}