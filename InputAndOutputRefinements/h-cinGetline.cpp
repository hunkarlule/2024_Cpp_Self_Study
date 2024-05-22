#include <iostream>

using namespace std;

/*
Member functions
The istream type supports the following member functions:

ignore(...): Ignores/discards character(s) from the input buffer
get(...): Extracts a character or a string from the input buffer
getline(...): Extracts a line of characters from the input buffer


getline():
getline() behaves like get(), but extracts the delimiting character from the input buffer:
getline(), like get(), does not skip leading whitespace and appends a null byte to the sequence of characters stored in system memory.
*/
//test with this: cdefghi<newline char>jklmn<tab charcter>opqr
int main() {
	char t[8], u[8], v;
	
	cin.getline(t, 8); // newline delimiter - accepts up to 7 chars and adds a null byte at the end.

	cin.getline(u, 8, '\t'); // tab-delimeter - accpets up to 7 chars and adds a null nyte at the end.

	cin.ignore(); // extarcts and discards a single char.

	cin.get(v);// extracts a single character.

	cout << "t = " << t << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;

	return 0;
}

