
#include <iostream>
using namespace std;

/*
ARRAY OF POINTERS
Arrays of pointers are data structures like arrays of values.
Arrays of pointers contain addresses rather than values.
We refer to the object stored at a particular address by
dereferencing that address. Arrays of pointers play
an important role in implementing polymorphism in the C++ language.

An array of pointers provides an efficient mechanism for processing
the set. With the objects' addresses collected in a contiguous array,
we can refer to each object indirectly through the pointers
in the array and process the data by iterating on its elements.

*/

const int N_CHARS = 31;

struct Student {
	int no;
	double grade;
	char name[N_CHARS];
};

int main() {

	const int NO_STUDENTS = 3;

	Student john = { 1234, 67.8, "john" };
	Student jane = { 1235, 89.5, "jane" };
	Student dave = { 1236, 78.4, "dave" };

	Student* pStudent[NO_STUDENTS]; // array of pointers

	//assigning values to array
	pStudent[0] = &john; // 1st value in the array holds the address of john
	pStudent[1] = &jane; // 2nd value in the array holds the address of jane
	pStudent[2] = &dave; // 3rd value in the array holds the address of dave

	cout << "address of john: " << & john << endl;
	cout << "address of jane: " << &jane << endl;
	cout << "address of dave: " << &dave<< endl;
	cout << "==========================" << endl;

	for (int i = 0; i < NO_STUDENTS; i++) {
		cout << pStudent[i] << endl;
		cout << pStudent[i]->no << endl;
		cout << (*(pStudent[i])).no<< endl; // same as above line but above one is better.
		cout << pStudent[i]->grade << endl;
		cout << pStudent[i]->name << endl;
		cout << "==========================" << endl;
	}

	return 0;
}
