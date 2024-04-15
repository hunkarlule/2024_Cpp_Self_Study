#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;

// case1- enter "Hello"
// case2- enter "Hello World"
//to see difference/issue.
int main() {
	Utils ut;
	char name[81]{};

	cout << "Enter a name\n>";
	cin >> name;
	cout << "*" << name << "*" << endl;

	cout << "Enter a name\n>";
	cin >> name;
	cout << "*" << name << "*" << endl;

	return 0;
}
