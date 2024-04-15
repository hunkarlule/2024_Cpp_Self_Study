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
	cin.getline(name, 81); // in 81 there is also null character('\0')
	//cin >> name;
	cout << "*" << name << "*" << endl;

	if (!cin) {
		cout << "cin failed!";
	}

	cout << "Enter a name\n>";
	cin.getline(name, 81);
	//cin >> name;
	cout << "*" << name << "*" << endl;

	return 0;
}
