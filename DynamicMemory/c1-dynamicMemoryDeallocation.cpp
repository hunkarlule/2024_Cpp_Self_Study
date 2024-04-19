

/*
Dynamic Deallocation
The keyword delete followed by [] and the address of a dynamically
allocated region of memory deallocates the memory that the corresponding
new[] operator had allocated.

Dynamic deallocation of arrays takes the form

delete [] pointer;

where pointer holds the address of the dynamically allocated array.

For example, to deallocate the memory allocated for
the array of n Students above, we write:


*/

#include <iostream>
#include <cstring>
using namespace std;

struct Student {
	int no;
	float grade[2];
};

int main() {


	int n;
	Student* student = nullptr; //this will hold the address of the dynamic students array

	cout << "How many students\n> ";
	cin >> n;

	// contiguous memory 
	// dynamically allocated for an array of n students and returned the address 
	// of the array's first element. So, student pointer points to first 
	// element of the allocated dynamic memory/array.
	student = new Student[n];

	/*
	For example, to deallocate the memory allocated for the array of
	n Students above, we write:
	*/
	delete[] student;


	/*
	The nullptr assignment ensures that student now holds
	the null address. This optional assignment eliminates
	the possibility of deleting the original address a second time,
	which is a serious run-time error. Deleting the nullptr address
	has no effect.
	*/

	// here this causing a run-time error/crush because we already 
	// deleted/deallocated dynamic memory pointed by student pointer above. 
	// So, that emmory doesn't belong to us anymore. So, trying to access and
	// delete a mrmory that does not belong to us causes crush/error at run-time.!
		//delete[] student;
	// therefore setting the pointer to nullptr after deallocations is a good practice.
	// Because Deleting the nullptr address has no effect.
	student = nullptr; // assigning the pointer to nullptr after deleting memory is a good practice.

	// this is not causing any issue becuase student is nullptr. So, delete 
	// operator doesn't do anything when it sees that student is nullptr. 
	// In other words, there is no memory to delete/deallocate.
	delete[] student;
}