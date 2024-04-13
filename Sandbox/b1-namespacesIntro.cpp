#include <iostream>
using namespace std;

namespace english {
    int x = 2;
}

namespace french {
    int x = 3;
}

/*
To access a variable defined within a namespace, 
we precede its identifier with the namespace's identifier and 
separate them with a double colon (::). 
We call this double colon the scope resolution operator.

For example, to print the x in namespace english and to print 
the x in namespace french, we write:
*/

int main() {
    //cout << x << endl; // error compiler cound nor know which x we try to reach.
    cout << english::x << endl;
    cout << french::x << endl;


    return 0;
}
