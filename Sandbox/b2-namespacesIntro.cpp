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
To access a variable defined within a namespace,
we precede its identifier with the namespace's identifier and
separate them with a double colon (::).
We call this double colon the scope resolution operator.

For example, to increment the x in namespace english and to 
decrement the x in namespace french, we write as follws.
Each prefix uniquely identifies each variable's namespace.
*/

int main() {
    //cout << x << endl; // error compiler cound nor know which x we try to reach.
    // :: is scope resoultion operator.
    cout << english::x << endl; // We say we want to reach x from english namespace
    cout << french::x << endl; // We say we want to reach x from french namespace

    english::x++;
    french::x++;
    cout << english::x << endl;
    cout << french::x << endl;


    return 0;
}
