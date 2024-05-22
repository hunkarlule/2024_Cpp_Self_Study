#include <iostream>
#include <iomanip>

using namespace std;

/*
Manipulators
The C++ language defines manipulators that are elegant alternatives to member function calls. 
These manipulators are operands for the extraction and insertion operators. Manipulators that don't take any argument 
do not include parentheses and are defined in <iostream>. Those that take an argument include parentheses 
and are defined in <iomanip>. That is, we must include <iomanip> whenever we use manipulators that take an argument.

Output Manipulators
The manipulators of output objects are listed below:

Manipulator	Effect
fixed				Output floating-point numbers in fixed-point format
scientific			Output floating-point numbers in scientific format
left				Left justify
right				Right justify
endl				Output end of line and flush the buffer
setprecision(int)	Set the precision of the output
setfill(int)		Set the fill character for the field width
setw(int)			Set the field width for the next output operand only
setbase(int)		Set the base of the number system for int output
flush				Flush the output buffer
Manipulators (except for setw(i), which only modifies the format setting for the next object) modify the format settings until we change them.
*/
// test it with:<multiple spaces>abcde<multiple spaces>fgh
int main() {
	double a = 12.376;
	cout << "1234567890" << endl;
	cout << a << endl;
	cout << fixed << left << setw(5) << setprecision(1) << a << endl;
	cout << fixed << left << setprecision(5) << a << endl;

	return 0;
}