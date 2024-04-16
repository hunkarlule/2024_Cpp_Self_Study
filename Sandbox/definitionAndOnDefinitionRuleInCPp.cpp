#include <iostream>
using namespace std;


/*
A definition is a declaration that associates a meaning with an 
identifier.
For example, the following definitions attach meanings to 
Transaction and to display():

One Definition Rule:
In the C++ language, a definition may only appear once within 
its scope. This is called the one-definition rule.

For example, we cannot define Transaction or display() 
more than once within the same code block or translation unit.
*/

struct Transaction { // definition of struct Transaction
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount
};

void display(const Transaction* tr) { // definition of display
    cout << "Account " << tr->acct << endl;
    cout << (tr->type == 'd' ? " Debit $" : " Credit $") << endl;
    cout << tr->amount << endl;
}

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
