#include <iostream>
using namespace std;


struct Car {
	int speed;
	char model[51];
};

int main() {
	// In C, when creating an isntance of a struct we need to use struct
	// keyword like below.
	struct Car car1;
	// Car car2; ==> this will not work in C.
	
	// However, in C++, struct keyword are not required anymore.
	// Both of below ones, work with C++. Both of them creates an instance of
	// of Car struct. However, this is better: Car car3;
	struct Car car3;
	Car car4;
	 return 0;
}