#include <iostream>
#include "Utils.h"

using namespace std;

namespace seneca {
	// Here we creadted a Utils object/instance ut, we also need to make a prototype decleration for
	// ut in Utils.h file like this(extern Utils ut;). So, everyone that
	// includes Utils.h will know and access the ut object/instance and then do not need to
	// create a seperate Utils object. In this way, ut becomes like a cout/cin objects.
	// When we include(#include <iostream>) cout and cin object becomes availbale to us and we can use them
	// without creating them.
	Utils ut; // here ut becomes a global variable.

	int Utils::getInt() {
		int val{};
		cin >> val;

		while (cin.fail()) {
			cout << "Invalid int, retry\> ";
			cin.clear();
			cin.ignore(12000, '\n');
			cin >> val;
		}
		//cin.ignore(); // ignores only one character.
		cin.ignore(12000, '\n'); // ignore up to 12000 chars until it hits '\n' charcter.
		return val;
	}

	void Utils::getCstr(char* str, size_t len) {
		cin.getline(str, len + 1); // added 1 for null charcter at the end. getline  will add null chracter at the ned automatically.

		while (cin.fail()) {
			cout << "Maximum " <<  len << " chars!, retry\n> ";
			cin.clear();
			cin.ignore(12000, '\n');
			cin.getline(str, len);
		}
		// we do not these ignores anymore at the end becuase getline() eats/flushes '\n'  char at the end automatically.
		////cin.ignore(); // ignores only one character.
		//cin.ignore(12000, '\n'); // ignore up to 12000 chars until it hits '\n' charcter.

	}

}

