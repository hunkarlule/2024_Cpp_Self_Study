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
Namespaces hide their entities. To expose an identifier to 
the current namespace, we insert the using declaration 
into our code before referring to the identifier.
*/
using english::x;
using french::y;

int main() {

    
    cout << x << endl; // x from english
    cout << french::x << endl; // x from french
    cout << english::y << endl; // y from english
    cout << y << endl; // y from french


    return 0;
}
