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

	// finding len of a C-string
	size_t Utils::strlen(const char* str) {
		size_t len{};
		// while character in the str is not null charcter('\n')
		// Becasue, for C-strings last character is null charcter('\n')
		while (str[len]) { // null chacrter is evaluated as false!.
			len++;
		}
		return len;
	}


	// copying len charcters from a C-string to another C-string.
	char* Utils::strcpy(char* des, const char* src, size_t  len) {
		size_t i{};
		for (i = 0; src[i] && i < len; i++) {
			des[i] = src[i];
		}
		// making last character of the C-string is null-character('\n')
		// otherwise, it will not be C-string.
		// In other words, ending string with null-character('\n'). So, it
		// will become a C-string.
		des[i] = 0; 
		return des;
	}

	// copying a C-string to another C-string.
	char* Utils::strcpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i]; i++) {
			des[i] = src[i];
		}

		// making last character of the C-string is null-character('\n')
		// otherwise, it will not be C-string.
		// In other words, ending string with null-character('\n'). So, it
		// will become a C-string.
		des[i] = 0;
		return des;
	}

	int Utils::getInt() {
		int val{};
		cin >> val;

		while (cin.fail()) {
			cout << "Invalid int, retry\n> ";
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
			cout << "Maximum " << len << " chars!, retry\n> ";
			cin.clear();
			cin.ignore(12000, '\n');
			cin.getline(str, len);
		}
		// we do not these ignores anymore at the end becuase getline() eats/flushes '\n'  char at the end automatically.
		////cin.ignore(); // ignores only one character.
		//cin.ignore(12000, '\n'); // ignore up to 12000 chars until it hits '\n' charcter.

	}

	bool Utils::getCstr2(char*& str)
	{
		str = nullptr;
		char* buf{};
		int muliptlier = 1;
		bool done{};

		do {
			buf = new char[MAX_DYNAMIC_READ * muliptlier];
			cout << "Enter text\n>";
			cin.getline(buf, MAX_DYNAMIC_READ * muliptlier);
			cout << buf << endl;
			if (cin) {
				str = new char[this->strlen(buf) + 1];
				this->strcpy(str, buf);
				delete[] buf;
				buf = nullptr;
				done = true;
			}
			else {
				cout << "cin is in fail state!" << endl;
				delete[] buf;
				buf = nullptr;
				muliptlier += 1;
				cin.clear();
				cin.ignore(10000, '\n');
				done = false;
			}

		} while (!done);
		//return !!str;
		return bool(str); // same as above.
	}

	bool Utils::getCstr(char*& str )
	{
		str = nullptr;
		char buf[MAX_DYNAMIC_READ];
		cout << "Enter text\n>";
		cin.getline(buf, MAX_DYNAMIC_READ);
		if (cin) {
			str = new char[this->strlen(buf) + 1];
			this->strcpy(str, buf);
		}
		else {
			cout << "cin is in fail state!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		//return !!str;
		return bool(str); // same as above.
	}

	bool Utils::yes(const char* prompt)
	{
		char res{};
		char newline{};
		bool done{ false };

		//we can read char from console with get method in two ways;
	   //res = cin.get(); // reads a character from keyboard
	   // this return cin itself. so, we can state of returned
	   // cin and check whether reading failed or not.
		   // cin.get(res); // reads a char and put into res
		if (prompt) {
			cout << prompt;
		}
		do {
			res = cin.get();
			newline = cin.get();
			if (newline != '\n') {
				cin.ignore(10000, '\n');
			}
			else if (res == 'y' || res == 'Y' || res == 'n' || res == 'N') {
				done = true;
			}
		} while (!done && cout << "Y(es)/N(o) only, please retyr\n> ");

		return (res == 'Y' || res == 'y');
	}

}

