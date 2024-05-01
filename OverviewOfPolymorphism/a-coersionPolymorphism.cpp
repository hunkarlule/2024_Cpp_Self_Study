#include <iostream>
using namespace std;

// Ad-Hoc Polymorphism - Coercion

/*
Coercion
Coercion addresses differences between argument types in a 
function call and the parameter types in the function's definition.
Coercion allows convertible changes in the argument's type to 
match the type of the corresponding function parameter. 
It is a semantic operation that avoids a type error.

If the compiler encounters a mismatch between the type of 
an argument in a function call and the type of the corresponding 
 parameter, the language allows conversion from the type of 
 the argument to the type of the corresponding parameter. 
 The compiler inserts the code necessary to perform the coercion. 
 The function definition itself only ever executes on 
 one type - the type of its parameter.

Coercion has two possible variations:

Narrow the argument type (narrowing coercion)
Widen the argument type (promotion)
*/
void display(int a) {
	std::cout << "One argument (" << a << ')' << endl;
}


/*
Coercion eliminates type mismatch or missing function definition 
errors. C++ implements coercion at compile time. If the compiler 
recognizes a type mismatch that is a candidate for coercion, 
the compiler inserts the conversion code immediately before 
the function call.


*/
int main() {
	/*
	here we called diplay function that accepts an int as a argument
	in case of double(12.6) ==> compiler narrowed it to int(12)
	in case of char('A') ==> compiler promoted it to int(65).
	this is due to coersion prolmorphism.
	*/
	display(10);
	display(12.6); // narrowing
	display('A'); // promotion

	return 0;
}