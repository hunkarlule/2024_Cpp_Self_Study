#include <iostream>
#include "Utils.h"
using namespace std;
using namespace seneca;

int main() {

	char str1[6] = "Hello";
	char str2[8]{};
	char str3[8]{};

	//testing strlne from Utils:
	cout << ut.strlen(str1) << endl;


	//testing strcpy from  Utils:
	cout << ut.strcpy(str2, str1,3) << endl;


	//testing strcpy from  Utils:
	cout << ut.strcpy(str3, str1) << endl;



	return 0;
}
