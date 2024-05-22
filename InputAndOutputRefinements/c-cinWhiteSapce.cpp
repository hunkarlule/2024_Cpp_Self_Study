#include <iostream>

using namespace std;

// The input object treats whitespace in its input stream as a delimiter for numeric and string data types. 
// In converting input bytes into a C-style null-terminated string, the input object adds the null byte after 
// the last non-whitespace character stored in memory:
//test it like: <___abc___> , _: denotes space, like  sapace-bar, tab.
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

