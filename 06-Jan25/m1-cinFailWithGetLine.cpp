#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;


// case1- enter "Hello"
// case2- enter "Hello World"
// to see how getline() working and fixing issue if we use cin >> name;
int main() {
	Utils ut;
	char name[81]{};

	cout << "Enter a name\n>";
	//cin.getline(name, 81); // in 81 there is also null character('\0')
	
	// here we changed 81 to 5 for testing. If we enter "Simpson Homer"
	// it will read 'Simp' nad put into name. However, after that cin will fail.
	// because getline() reached the limit(5) before hitting a '\n' character.
	// therefore cin will wailt and we could not read anymore before fixing the cin.
	cin.getline(name, 5); //

	//cin >> name;
	cout << "*" << name << "*" << endl;

	if (!cin) {
		cout << "cin failed!" << endl;
	}

	cout << "Enter a name\n>";
	cin.getline(name, 81);
	//cin >> name;
	cout << "*" << name << "*" << endl;

	return 0;
}
