
#include <iostream>
using namespace std;


/*
Default Parameter Values
We may include default values for some or all of a function's 
parameters in the first declaration of that function. 
The parameters with default values must be the rightmost parameters 
in the function signature.

Declarations with default parameter values take the following form:

 type identifier(type[, ...], type = value);

The assignment operator followed by a value identifies 
the default value for each parameter.

Specifying default values for function parameters reduces 
the need for multiple function definitions if the function logic 
is identical in every respect except for the values received 
by the parameters.

*/

// function decleration. We can provide default values like below 
// in function decleration.
void display(int a, int b = 5, int c = 0);    

// same as above one. See we did not parameter names/identifiers
// in the decleration. However, above one is better/more readable.
//void display(int, int = 5, int = 0);

int main() {
	/*
	Each call to display() must include enough arguments to 
	initialize the parameters that don't have default values. 
	In this example, each call must include at least one argument. 
	An argument passed to a parameter that has a default 
	value overrides the default value.
	*/
	display(6, 7, 8); // we passed all arguments. So default values will not be used.
	display(6); // we passed only first(a). For other two( b and c) default values will be used.
	display(3, 4); // We passed only first 2 arguments( a and b), for the third one (c) default value will be used.

	return 0;
}


// see we did not write the default values in the definition again.
void display(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;
}
