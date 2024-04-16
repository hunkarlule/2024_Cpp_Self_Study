#include <iostream>
using namespace std;

/*
The auto keyword was introduced in the C++11 standard. 
This keyword deduces the object's type directly from 
its initializer's type. 
We must provide the initializer in any auto declaration.
auto is quite useful: it simplifies our coding by using information 
that the compiler already has.
*/

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
