#include <iostream>

using namespace std;

/*
fill()
The fill(char) member function defines the padding character. The output object inserts this character into the stream 
wherever text occupies less space than the specified field width. The default fill character is ' ' (space). 
To pad a field with '*'s, we add:
The padding character remains unchanged, until we reset it.
*/

int main() {

	int attendance = 27;
	cout << "1234567890" << endl;
	cout.fill('*');
	cout.width(10);
	cout << attendance << endl;
	cout << attendance << endl;
	cout.width(8);
	cout << attendance << endl;

	return 0;
}