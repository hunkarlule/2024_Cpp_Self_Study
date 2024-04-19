

/*
Dynamic Memory
The memory that an application obtains from the operating system during 
execution is called dynamic memory.

Dynamic memory is distinct from the static memory. While the operating 
system allocates static memory for an application at load time, 
the system reserves dynamic memory, allocates it and deallocates it 
at run-time.

Scope Considerations
To keep track of an application's dynamic memory, we store the address 
of each allocated region in a pointer variable. We allocate memory for 
this pointer itself in static memory. This pointer variable must remain 
in scope as long as we need access to the data in the allocated region 
of dynamic memory.

Consider allocating dynamic memory for an array of n elements. We store 
the array's address in a pointer, ptr, in static memory. 
We allocate memory for the elements of the array dynamically and 
store the data in those elements.

Lifetime
The lifetime of any dynamically allocated memory ends when the pointer 
holding its address goes out of scope. The application must explicitly 
deallocate the allocated region of dynamic memory within this scope. 
If the application neglects to deallocate the allocated region, 
that memory becomes inaccessible and irrecoverable until the application 
returns control to the operating system.

Unlike variables and objects that have been allocated in static memory, 
those in dynamic memory do not automatically go of out scope 
at the closing brace of the code block within which they were defined. 
We must manage their deallocation explicitly ourselves.
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
Dynamic Memory Allocation(dma):
The keyword new followed by [n] allocates contiguous memory dynamically 
for an array of n elements and returns the address of the array's 
first element.

Dynamic allocation of arrays takes the form

pointer = new Type[size];

where Type is the type of the array's elements.

For example, to allocate dynamic memory for an array of n Students, 
we write:
*/

	int n; 

	// The nullptr keyword identifies the address pointed to as 
	// the null address. This keyword is an implementation constant. 
	// Initialization to nullptr ensures that student is not pointing to 
	// any valid dereferencable address. 
	Student* student = nullptr; //this will hold the address of the dynamic students array
	
	cout << "How many students\n> ";
	cin >> n;

	// here we dynamically allocate memory in the heap for n students.
	// n is entered by the user during  run-time. 
	// The keyword new followed by [n] allocates contiguous memory 
	// dynamically for an array of n students and returns the address 
	// of the array's first element. So, student pointer points to first 
	// element of the allocated dynamic memory/array.
	// Note that: The size of the array is a run-time variable and 
	// not an integer constant or constant expression. Note that 
	// the size of an array allocated in static memory must be 
	// an integer constant or constant expression.
	student = new Student[n];
}