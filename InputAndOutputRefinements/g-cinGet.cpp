#include <iostream>

using namespace std;

/*
Member functions
The istream type supports the following member functions:

ignore(...): Ignores/discards character(s) from the input buffer
get(...): Extracts a character or a string from the input buffer
getline(...): Extracts a line of characters from the input buffer
ignore()
The ignore() member function extracts bytes from the input buffer and discards them without skipping whitespace. 
The iostream hierarchy defines two overloaded versions of ignore():

cin.ignore();
cin.ignore(2000, '\n');

The no-argument version discards a single byte. The two-argument version removes and discards up to the number 
of bytes specified by the first argument or up to the specified delimiting character, whichever occurs first 
and discards the delimiting character. The default delimiter is the end-of-file character (not the newline character).

get()
The get() member function extracts either a single character or a string from the input buffer. Three versions are available:

get() does not skip leading whitespace. get(,) leaves the delimiting character in the input buffer. 
In using get(,) we need to remove the delimiting character, if there is one. 
Both string versions - get(char*, int) and get(char*, int, char) - append a null byte to the sequence of characters stored in memory.
*/
//test with this: abcdefghij<newline char>klmn<tab charcter>opqr
int main() {
	char c, d, t[8], u[8], v;
	
	c = cin.get(); // exctracts a single character.
	cin.get(d); // exctracts a single character

	cin.get(t, 8); // newline delimiter - accepts up to 7 chars and adds a null byte at the end.

	cin.ignore(2000, '\n'); //extracts and discards 2000 characters or until a new-line charcter.( extracts the 'j' and the newline)

	cin.get(u, 8, '\t'); // tab-delimeter - accpets up to 7 chars and adds a null nyte at the end.

	cin.ignore(); // extarcts and discards a single char.(extracts the tab)

	cin.get(v);// extracts a single character.

	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "t = " << t << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;

	return 0;
}

