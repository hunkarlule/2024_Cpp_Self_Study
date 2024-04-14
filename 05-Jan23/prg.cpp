
#include <iostream>
#include "Name.h"
using namespace std;
using namespace seneca;

int main() {
	Name* names{}; // a Name-pointer and we initialized it with nullptr using {}.
	size_t num{};

	cout << "how mane names?\n>";
	cin >> num;

	// here DMA(dynamic memory allocation) to hold num names 
	// in the heap. addres of that place is assigned to pointer names.
	names = new Name[num];

	// no need anymore because constructor do  job
	//for (size_t i{}; i < num; i++) {
	//	names[i].init();
	//}

	names[0].print();

	// here we allow the client code directly 
	// change the object attributes. However, wo do not want this.
	// This is allowed becuase in Struct, definition data-members
	// are defult public. In struct definition, we need to mark them
	// as private.
	//names[0].m_givenName = nullptr;

	for (size_t i{}; i < num; i++) {
		names[i].read();
	}

	for (size_t i{}; i < num; i++) {
		names[i].print();
	}

	// no need anymore because destructor do the job
	//for (size_t i{}; i < num; i++) {
	//	names[i].finalize();
	//}

	names[1].set("homer", "simpson");

	for (size_t i{}; i < num; i++) {
		names[i].print();
	}

	delete[] names; // deallocating dynamic memory for names array.
	return 0;
}






