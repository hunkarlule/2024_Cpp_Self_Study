// this code compile in C but when run it gives "Segmentation Fault"
// error.This is because C is not as type-safe as C++.
/*
The prototype for foo()(void foo();) instructs the compiler to omit checking 
for argument/parameter type mismatches. The argument in 
the function call is an int of negative value (-25) 
and the type received in the parameter is the address of 
a char array. Since the parameter's value is an invalid address, 
printing from that address causes a segmentation fault 
at run-time, but no error at compile-time.
*/

/*
However C++ is more type-safe. C++ rules  C++ all prototypes 
list their parameter types, which has forced all C++ compilers 
to check for argument/parameter type mismatches at compile-time.
*/
#include <stdio.h>

void foo(); 

int main(void)
{
    foo(-25);
}
void foo(char x[])
{
    printf("%s", x); /* ERROR */
}

// In C, we can avoid run-time error by doing this:
/*
 If we include the parameter type in the prototype as 
 shown below, the compiler will check for an argument/parameter 
 type mismatch and issue an error message 
 like that shown on the right:
*/
// So in thic case, C compile will chekc argument/parameter type
// and give us error.

#include <stdio.h>

void foo(char x []);

int main(void)
{
    foo(-25); //Function argument assignment between types "char*" and "int" is not allowed.
}
void foo(char x[])
{
    printf("%s", x); /* ERROR */
}