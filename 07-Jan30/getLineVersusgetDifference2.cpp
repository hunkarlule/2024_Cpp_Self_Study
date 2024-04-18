#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;

// getline() and get() do the same things with a few difference:
// for both of them, '\n' is default delimeter.
// if we want to cahnge delimeter we can pass a delimeter
// character as third parameter.
// getline() ==> if it does not hit a delimeter character
// and read the number of chars passed as second argument then
// cin fails.
// get() == if it does not hit a delimeter character
// and read the number of chars passed as second argument then
// nothing happens. cin continue to stay in good state.

// getline() ==> also reads and spits the delimeter charcter.
// get() ==> leave delimeter character in the keyboard.

int main() {


	char name[11]{};

	cout << "Enter a name\n>";


	cin.getline(name, 11, ',');
	cout << "*" << name << "*" << endl;

	if (cin.fail()) {
		cout << "cin in fail state. Fix cin before continue reading" << endl;
	}
	else {
		cout << "Enter a name\n>";
		cin.get(name, 11, ',');
		cout << "*" << name << "*" << endl;

		if (cin.fail()) {
			cout << "cin in fail state. Fix cin before continue reading" << endl;
		}
		else {
			cout << "Enter a name\n>";
			cin.get(name, 11, ',');
			cout << "*" << name << "*" << endl;
			if (cin.fail()) {
				cout << "cin in fail state. Fix cin before continue reading" << endl;
			}
		}
	}

	return 0;
}
