#include <iostream>

using namespace std;

/* 
we have cout object to print/write the things to 
the console. Also we have its 2 cousins clog(console-log) 
and cerr(console-err). They do the same things as cout. 
They rpint/wrote the things to the console. However, they are used 
different purposes. clog is for logging/debugging  and
cerr is for errors.
These three are different objects.

*/

int main() {
	char name[81] = "Hello world";
	int num = 25;
	double val = 35.23;

	// we can disbale any of these three object. 
	// So thye will not do the printing.

	//cout.setstate(std::ios_base::failbit); // setting cout failstate. So it will do printing anymore.
	//clog.setstate(std::ios_base::failbit); // setting clog failstate. So it will do printing anymore
	cerr.setstate(std::ios_base::failbit); // setting err failstate. So it will do printing anymore

	cout << "printing with cout: " << "name is: " << name << ", num is: " << num << ", val is: " << val << endl;
	clog << "printing with clog: " << "name is: " << name << ", num is: " << num << ", val is: " << val << endl;
	cerr << "printing with cerr: " << "name is: " << name << ", num is: " << num << ", val is: " << val << endl;
	return 0;
}