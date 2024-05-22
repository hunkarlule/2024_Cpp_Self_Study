#include <iostream>

using namespace std;

// The cin object skips leading whitespace with numeric, string and character types
// test it with <_____abc> , _: denotes a space character like space-bar or tab
int main() {
	int i;
	char c;
	double x;
	char s[11];

	cout << "enter a string : " << flush;
	cin >> s; 

	cout << "|" << s << "|" <<endl;

	return 0;
}

