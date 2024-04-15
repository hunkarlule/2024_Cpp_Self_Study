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
	ut.getCstr(name, 5);
	cout << "*" << name << "*" << endl;

	cout << "Enter a name\n>";
	ut.getCstr(name, 80);
	cout << "*" << name << "*" << endl;

	return 0;
}
