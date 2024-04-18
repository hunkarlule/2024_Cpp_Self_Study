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
	// here we are reading 11 characters with getline().
	// indeed we reading 10 characters +  getline will add 11th character(null character)
	// at the end.
	// case-1:  we entered "Hello World" and pressed enter(new line character '\n')
	// so in hte buffer/keyboard there is: "Hello World'\n'"
	// getline() will read ==> "Hello Worl" and will
	// add null character('\0') at the and and put it into
	// name. So it will put "Hello Worl'\0'" into name.
	// However, getline() finished reading without hitting a
	// '\n'(newline)( this is default delimeter). 
	// So,"d'\n'" is still in the keyboard/console. Therefore,
	// cin will go into fail state and will not continue reading after that.

	// case-2:  we entered "Hey World" and pressed enter(new line character '\n')
	// so in hte buffer/keyboard there is: "Hey World'\n'"
	// getline() will read ==> "Hey World" and will
	// add null character('\0') at the and and put it into
	// name. So it will put "Hey World'\0'" into name.
	// This time, getline() finished reading by hitting a
	// '\n'(newline)( this is default delimeter). 
	// So,"'\n'" is still in the keyboard/console. However,
	// getline() will read that '\n' charcter and spit it out.
	// So,"'\n'" will not remaing in the keyboard/console.

	cin.getline(name, 11);
	cout << "*" << name << "*" << endl;

	if (cin.fail()) {
		cout << "cin in fail state. Fix cin before continue reading" << endl;
	}
	else {
		cout << "Enter a name\n>";

		// here we are reading 11 characters with get().
		// indeed we reading 10 characters +  get will add 11th character(null character)
		// at the end.
		// case-1:  we entered "Hello World" and pressed enter(new line character '\n')
		// so in the buffer/keyboard there is: "Hello World'\n'"
		// get() will read ==> "Hello Worl" and will
		// add null character('\0') at the and and put it into
		// name. So it will put "Hello Worl'\0'" into name.
		// However, get() finished reading without hitting a
		// '\n'(newline)( this is default delimeter). 
		// So,"d'\n'" is still in the keyboard/console.
		// cin will will still be in good state.

		// case-2:  we entered "Hey World" and pressed enter(new line character '\n')
		// so in hte buffer/keyboard there is: "Hey World'\n'"
		// get() will read ==> "Hey World" and will
		// add null character('\0') at the and and put it into
		// name. So, it will put "Hey World'\0'" into name.
		// This time, get() finished reading by hitting a
		// '\n'(newline)( this is default delimeter). 
		// So,"'\n'" is still in the keyboard/console. However,
		// get() will NOT read that '\n' charcter and
		// So,"'\n'" will continue to  remain the keyboard/console.

		cin.get(name, 11);
		cout << "*" << name << "*" << endl;

		if (cin.fail()) {
			cout << "cin in fail state. Fix cin before continue reading" << endl;
		}
	}

	return 0;
}
