#include <iostream>
#include <iomanip>

using namespace std;
/*
The ios base class defines public member functions that report or change the state of istream and ostream objects.
These member functions include:

good(): The next operation might succeed
fail(): The next operation will fail
eof(): End of data has been encountered
bad(): The data may be corrupted
clear(): Reset the state to good
For user-friendly input processing, we should check the state of the input object every time it extracts a sequence of bytes from
the input buffer. If the object has encountered an invalid character, the object will fail and leave that invalid character
in the input buffer and the fail() member function will return true.

Before a failed object can continue extracting data from the input buffer, we must clear the object of its failed state.
The clear() function resets the state of the object to good:
*/

int main() {
	int x;

	cin >> x;

	if (cin.fail()) {            // checks if cin is in a failed state
		cout << "cin failed. Cleraing it to continue reading!" << endl;
		cin.clear();            // clears state to allow further extraction
		cin.ignore(2000, '\n'); // clears the input buffer
	}
	return 0;
}