#include <iostream>

using namespace std;

/*
Cascading
We may combine a sequence of insertion operations into a compound insertion expression:
*/

int main() {

	int i = 6;
	char c = ' ';
	double x = 9.75;
	char s[] = "Harry";

	clog << "Writing data" << endl;
	cout << i << c << x << c << s << endl;

	cerr << "Data has been written";

	return 0;
}

