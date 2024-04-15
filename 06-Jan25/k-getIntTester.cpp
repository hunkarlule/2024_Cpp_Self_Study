#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;

// Note that we created a Utils object to call/use the getInt() method
// and get an int from user!
int main() {
	Utils ut;
	int num{ 10 };

	cout << "Enter an int\n>";
	num = ut.getInt();
	cout << "you entered: " << num << endl;

	cout << "Enter an int\n>";
	num = ut.getInt();
	cout << "you entered: " << num << endl;

	return 0;
}
