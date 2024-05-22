#include <iostream>

using namespace std;

// Cascading
// compressing a sequence of extraction operations into a single compound expression.
int main() {
	int i;
	char c;
	double x;
	char s[8];
	cout << "Enter an integer,\n"
		"a character,\n"
		"a floating-point number and\n"
		"a string : " << flush;
	cin >> i >> c >> x >> s; // this looks good but not recommended.
/*
	cin >> i;
	cin >> c;
	cin >> x;
	cin >> s;
	*/
	cout << "Entered: " << i << ' '
		<< c << ' ' << x << ' ' << s << endl;

	return 0;
}

