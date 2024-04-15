#include <iostream>
using namespace std;


int main() {

	int num{ 10 };
	char str[81]{ "hoo hoo" };

	// here enter an ivalid value istead of integer like: abc
	// and see what happens!
	// when invalid value entered cin state becomes fail and then
	// it does not read anything anymore.
	// we need to clear/fix the cin state and fluch the buffer before 
	// continue to reading.
	cout << "enter int\n> ";
	cin >> num;
	cout << "enter string\n> ";
	cin >> str;

	cout << "num is: " << num << ", str is: *" << str << "*" << endl;

	return 0;
}
