#include <iostream>

using namespace std;

int main() {

	int num{ 10 };
	char str[81]{ "hoo hoo" };

	// when invalid value entered cin state becomes fail and then
	// it does not read anything anymore.
	// we need to clear/fix the cin state and fluch the buffer before 
	// continue to reading.
	cout << "enter int\n> ";
	cin >> num;

	// here after reading num with cin, we check if cin is still good.
	// if it is in error/fail state, we clear/fix cin and tell cin to
	// ignore 10000 character in keybord/buffer until it sees/hits '\n' 
	// character. In other words, we are flushing the keyboard 
	// before continue to reading.
	// 
	//if (!cin) {
	if (cin.fail()) { // instead of above we can check cin fail state bu calling fail() mehhod on cin.
		cin.clear(); // clear/fix cin's error/fail state.
		cin.ignore(10000, '\n'); // ignore 10000 chars in the keyboard until hitting '\n'
	}

	cout << "enter string\n> ";
	cin >> str;

	cout << "num is: " << num << ", str is: *" << str << "*" << endl;

	return 0;
}
