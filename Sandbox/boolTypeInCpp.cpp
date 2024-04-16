#include <iostream>
using namespace std;

/*
The bool type stores a logical value: true or false.
The ! operator reverses that value: !true is false and !false is true.
! is self-inverting on bool types, but not self-inverting 
on other types.
Conversions from bool type to any integral type and
vice versa require care. true promotes to an int of value 1, 
while false promotes to an int of value 0. Applying the ! operator to 
an int value other than 0 produces a value of 0, while applying 
the ! operator to an int value of 0 produces a value of 1.
Note that the following code snippet displays 1 (not 4).
Both C and C++ treat the integer value 0 as false and any other value as true.
*/
int main() {

    //int x = 4;
    int x = 0;
    cout << !x << endl;
    cout << !!x << endl;
    
    bool y = false;
    cout << y << endl;
    cout << !y << endl;

    if (x) {
        cout << "x evaluated as true" << endl;
    }
    else {
        cout << "x evaluated as false" << endl;
    }
    return 0;
}
