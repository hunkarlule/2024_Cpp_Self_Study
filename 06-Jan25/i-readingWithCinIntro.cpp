#include <iostream>
using namespace std;

int main() {
	
	int num{10};
	char str[81]{"hoo hoo"};

	cout << "enter int\n> ";
	cin >> num;
	cout << "enter string\n> ";
	cin >> str;

	cout << "num is: " << num << ", str is: " << str << endl;
	 
	return 0;
}