#include <iostream>
using namespace std;

namespace english {
    int x = 2;
    int y = 20;
}

namespace french {
    int x = 3;
    int y = 30;
}

/*
To expose all of a namespace's identifiers, 
we insert the using directive into our code before 
referring to any of them.

For example, to expose all of the identifiers within 
namespace english, we write:
Exposing a single identifier or a complete namespace 
simply adds the identifier(s) to the hosting namespace.
*/
using namespace english;
int main() {

    
    cout << x << endl; // x from english
    cout << french::x << endl; // x from french
    cout << y << endl; // y from english
    cout << french::y << endl; // y from french


    return 0;
}
