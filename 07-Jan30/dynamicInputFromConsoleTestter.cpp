#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;

int main() {

	char* ptr;
	ut.getCstr2(ptr);
	cout << "========================================\n";
	cout << ptr << endl;

	return 0;
}
