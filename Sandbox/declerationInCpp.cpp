#include <iostream>
using namespace std;

/*
Modular programming can result in multiple definitions. 
To avoid conflicts or duplication, we need to design our header 
and implementation files accordingly. 
The C++ language distinguishes between declarations and 
definitions and stipulates the one-definition rule.

Declarations
A declaration associates an entity with a type, 
telling the compiler how to interpret the entity's identifier. 
The entity may be a variable, an object or a function.
*/


/* add functions prottype decleration
declares add() to be a function that receives two ints and 
returns an int.This declaration does not specify 
what the function does; 
it does not specify the function's meaning.
*/
int add(int, int);
int add2(int a, int b);

/*
 the forward declaration

declares Transaction to be of structure type. A forward declaration 
is like a function prototype: it tells the compiler how to interpret 
the entity's identifier. It tells the compiler that the entity 
is a valid type, but does not specify the entity's meaning.

Although a declaration does not necessarily specify meaning, 
it may specify it. Specifying a meaning is an optional 
part of any declaration.
*/

struct Transaction; // a forward decleration for a struct type named Transaction..

int main() {

    auto x = 4; // x is an int that is initialized to 4
    auto y = 3.5; // y is a double that is initialized to 3.5

    cout << x << "  " << y << endl;

    // this is compiler error because auto keyword requires us
    // to provide a initializer value so compiler can deduce the
    // type of the variable(z in this case) from initializer value. 
    //auto z;
 
    return 0;
}
