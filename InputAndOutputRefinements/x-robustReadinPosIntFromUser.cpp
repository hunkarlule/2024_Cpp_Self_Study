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

int getPosInt(int max) {
	int value{};
	int keepreading{};

	keepreading = 1;

	do {
		cout << "enter a positive integer (<= " << max << "):";
		cin >> value;

		if (cin.fail()) {
			cerr << "invalid entry. try again." << endl;
			cin.clear();
			cin.ignore(2000, '\n');
		}
		else if (value <= 0 || value > max) {
			cerr << value << " is outside the range [1, " << max << "]" << endl;
			cerr << "invalid input. try again." << endl;
			cin.ignore(2000, '\n');
		}
		else if (char(cin.get()) != '\n') {
			cerr << "trailing characters. enter only integer. try again." << endl;
			cin.ignore(2000, '\n');
		}
		else {
			keepreading = 0;
		}
	} while (keepreading == 1);

		return value;
}

int main() {
	int x;

	x = getPosInt(10);

	cout << "you entered: " << x << endl;
	return 0;
}