

/*
Static and Dynamic Memory
The memory accessible by a C++ program throughout its execution consists 
of static and dynamic components. After the user starts an application, 
the operating system loads its executable into RAM and transfers control 
to that executable's entry point (the main() function). 
The loaded executable only includes the memory allocated at compile time. 
During execution, the application may request more memory from 
the operating system. The system satisfies such requests by allocating 
more memory in RAM. After the application terminates and returns control 
to the operating system, the system recovers all of the memory 
that the application has used.

Static Memory
The memory that the operating system allocates for the application 
at load time is called static memory. Static memory includes the memory 
allocated for program instructions and program data. The compiler 
determines the amount of static memory that each translation unit 
requires. The linker determines the amount of static memory 
that the entire application requires.

Static Memory

The application's variables and objects share static memory amongst 
themselves. When a variable or object goes out of scope its memory 
becomes available for newly defined variables or objects. The lifetime 
of each local variable and object concludes at the closing brace of 
the code block within which it has been defined:

*/

#include <iostream>
using namespace std;

int main() {
    /*
    Since the variable x goes out of scope before the variable y 
    is declared, the two variables may occupy the same memory location. 
    This system of sharing memory amongst local variables and 
    objects ensures that each application minimizes its use of RAM.

    Static memory requirements are determined at compile-link time and 
    do not change during execution. This memory is fast, fixed in its 
    amount and allocated at load time.
    */
    // lifetime of a local variable or object
    for (int i = 0; i < 10; i++) {
        double x = 0;      // lifetime of x starts here
        // ...
    }                      // lifetime of x ends here

    for (int i = 0; i < 10; i++) {
        double y = 4;      // lifetime of y starts here
        // ...
    }                      // lifetime of y ends here
	return 0;
}