

/*
Allocation/Deallocation Memory for a Single Instances:
Although dynamic memory is often allocated for data structures like arrays,
we can also allocate dynamic memory for single instances of 
any type(like int, Student, double etc.). 
The allocation and deallocation syntax is similar to that for arrays. 
We simply remove the brackets.

*/

#include <iostream>
#include <cstring>
using namespace std;

struct Student {
	int no;
	float grade[2];
};

int main() {
	/*
	Allocation
	The keyword new without brackets allocates dynamic memory for 
	a single variable or object.
	A dynamic allocation statement takes the form:

	pointer = new Type;

	For example, to store one instance of a Student in dynamic memory, 
	we write
	*/

	Student* joe = nullptr; //a pointer in static memory. this will hold the address of dynamic memory to store a student.

	// memory dynamically allocated for a student and  new operator 
	// returned the address of allocated memory.
	//pointer joe points to a Student in dynamic memory
	joe = new Student;

	// setting joe's data.
	joe->no = 123;
	joe->grade[0] = 95.6;
	joe->grade[1] = 75.0;

	cout << joe->no << ": " << joe->grade[0] << ", "
			<< joe->grade[1] << endl;
     
	
	/*
	Deallocation
	The keyword delete without brackets deallocates dynamic memory 
	at the address specified.

	A dynamic deallocation statement takes the form

	 delete pointer;

	delete takes the address that was returned by the new operator.

	For example, to deallocate the memory for joe, we write
	*/

	// here because joe points to only a sinlge variable/object(Student in this case)
	// when deleting we do not use [] during deallocation.
	delete joe;
	joe = nullptr; // setting student pointer to nullptr. good pratice.
}