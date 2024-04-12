#include <iostream>
#include "pointers.h"
using namespace std;


// pointers in plain english.
// see pointers.h to see how this plain english pointers work.
/*
In pointers.h we have these 3 #define statements:
#define targetOf *
#define addressOf &
#define pointer *

And at line two, with  statment(#include "pointers.h") content of pointers will be copy-paste there by pre=processor.

#define targetOf * ==> means, please search and find targetOf in the code and replace it with *
#define addressOf * ==> means, please search and find addressOf in the code and replace it with &
#define pointer * ==> means, please search and find pointer in the code and replace it with *

So, after pre-processor finishes its job, out code will be like this:
	int main() {
		int a = 25;
		cout << a << endl; // will print 25
		int * p = & a;
		* p = 12345;
		cout << a << endl; // will print 12345

		return 0;
	}

*/
int main() {
	int a = 25;
	cout << a << endl; // will print 25
	int pointer p = addressOf a;
	targetOf p = 12345;
	cout << a << endl; // will print 12345

	return 0;
}

