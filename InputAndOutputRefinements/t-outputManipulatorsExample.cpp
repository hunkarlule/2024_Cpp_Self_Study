#include <iostream>
#include <iomanip>

using namespace std;


int main() {
	int a = 4321;
	cout << "\n* ints *\n"
		<< "1234567890\n"
		<< "----------\n"
		<< a << '\n'
		<< setw(7) << a << '\n'
		<< setw(7) << setfill('0') << a << setfill(' ') << '\n'
		<< setw(7) << left << a << right << '\n';

	float b = 4321.9876546F;
	cout << "\n* floats *\n"
		<< "1234567890\n"
		<< "----------\n"
		<< b << '\n';

	double d = 4.9876546;
	cout << "\n* doubles *\n"
		<< "1234567890\n"
		<< "----------\n"
		<< fixed << d << '\n'
		<< setw(7) << setprecision(3) << d << '\n'
		<< setw(7) << setfill('0') << d << '\n'
		<< setw(7) << left << d << right << '\n';

	char ch = 'd';
	cout << "\n* chars *\n"
		<< "1234567890\n"
		<< "----------\n"
		<< ch << '\n'
		<< int(ch) << '\n';

	return 0;
}