#include <iostream>
using namespace std;

// we can allocate dynamic memory for a single value
// (like a single integer, single student object) or we can
// allocate dynamic memory for an array of values 
// (like an arrays of ints or students)
//The differencei is that when deleteing/deallocating the memory:
// we need to use delete[] var => for array and delete var => for single value.
int main() {
	cout << "hello world!" << endl;
	
	// dynamically allocating memory in the heap for 
	// only one integer. there is garbage value in it.
	int* p = new int; 
	
	// dynamically allocating memory in the heap for only one integer 
	// and initilalize/set it with 20.
	int* p1 = new int{20}; 
	//cout << "int pointed by p is: " << *p << endl; // prints grbage value here.
	cout << "int pointed by p1 is: " << *p1 << endl;

	cout << "enter an int: ";
	cin >> *p;

	cout << "int pointed by p is: " << *p << endl;

	//becase p and p1 is pointing to memory in the heap 
	// that is allocated for only a single integer
	// when deleteing/deallocating we DON'T need to use [] brackets
	// with delete keyword. We need to deallocate memory as follows.
	delete[] p;
	delete p1;

	// dynamically allocating memory in the heapfor 25 integers.
	// in other words we allocating  memory for an array 
	// one integer and initilalize it with 20.
	// there are garbage values in them.
	int* p2 = new int[25];

	p2[0] = 12;// assigning first element to 12.
	cout << "firts element of the arrays is: " << p2[0] << endl;
    
	//becase p2 is pointing to an array allaocated in the heap
	// when deleteing/deallocating we need to use [] brackets
	// with delete keyword to delete whole array. If we do not use
	// [] brackets only memory for the fist element will be deallocated
	// and we will have memory leak.
	delete[] p2;

	return 0;
}

