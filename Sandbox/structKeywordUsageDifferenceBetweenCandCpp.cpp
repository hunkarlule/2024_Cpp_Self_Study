#include <iostream>
using namespace std;

/*
A compound type is a type composed of other types. 
A struct is a compound type. 
An object-oriented class is also a compound type.

struct Transaction {
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount
};
*/

/*
The C++ language requires the keyword identifying a compound type 
only in the declaration of that type. The language does not require 
the keyword struct or class in a function prototype or an object 
definition. Note the first code snippet below. Recall that 
the C language requires the keyword struct throughout 
the code as listed in the code snippet for C example below.
*/

// C++ version. We only use struct/class keyword once
// when we declaring/creating the struct. After that, we do not
// need to use struct keywrod anymore. Here using Transaction1
// will be enough.
struct Transaction1 {
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount
};

void enter(Transaction1 *);
void display(const Transaction1 *);


// C version. We need to use struct keywrod in function ptorotypes
// or when creating instance of the struct etc.
struct Transaction2 {
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount
};

void enter(struct Transaction2 *);
void display(const struct Transaction2 *);


int main() {

    Transaction1 tr1;         // C++
    struct Transaction2 tr2; // C
 
    return 0;
}
