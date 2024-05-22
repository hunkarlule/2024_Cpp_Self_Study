#include <iostream>

using namespace std;

/*
Overflow
In the above two examples, overflow may occur while filling s. The extraction operator >> does not restrict 
the number of bytes accepted. If more than 7 bytes are in the input stream the data stored for the string may corrupt 
other data that has been stored in memory
*/
//test with this: 6 - 9.75 Constantinople
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

