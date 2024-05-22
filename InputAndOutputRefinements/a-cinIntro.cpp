#include <iostream>

using namespace std;

int main() {
	int i;
	char c;
	double x;
	char s[8];

	cout << "enter an integer,\n"
		"a character,\n"
		"a floating number and \n"
		"a string: " << flush;
	cin >> i;
	cin >> c;
	cin >> x;
	cin >> s; // a possible oerflow here!

	cout << "entered: " << i << ' ' << c << ' ' << x << ' ' << s << endl;

	return 0;
}

