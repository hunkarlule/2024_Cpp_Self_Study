#include <iostream>

using namespace std;

/*
width()
The width(int) member function specifies the minimum width of the next output field:
width(int) applies only to the next field. Note how the field width for the first display of attendance is 10, 
while the field width for the second display of attendance is just the minimum number of characters needed to display the value (2).
*/

int main() {

	int attendance = 27;
	cout << "1234567890" << endl;
	cout.width(10);
	cout << attendance << endl;
	cout << attendance << endl;

	return 0;
}