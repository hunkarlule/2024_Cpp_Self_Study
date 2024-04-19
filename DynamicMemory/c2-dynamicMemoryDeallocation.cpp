

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

What Happens to deallocated memory:
Deallocation does not return dynamic memory to the operating system. 
The deallocated memory remains available for subsequent dynamic 
allocations. The operating system only reclaims all of the dynamically 
allocated memory once the application has returned control 
to the system.

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
	Note that omitting the brackets in a deallocation expression 
	deallocates the first element of the array, leaving 
	the other elements inaccessible..
	*/
	// This is WRONG!. Becuase, student points to a dynamically allocated 
	// array in the memory. This will only deallocate/delete the first 
	// element from the memory. Others will still be in the memory and
	// this will cause memory-leak. Therfore if we allocated the
	// memory like this: ptr = new Student[n] (means with square brackets[], means
	// for an array) ==> the we need to delete memory with delete[] ptr 
	// (means  with squre brackets[], means we are deleting whole memory for array)
	
		//delete student; // WRONG! do not do this!
	delete[] student;
}