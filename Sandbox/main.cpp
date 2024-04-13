#include <iostream>
#include "main.h"
#include "Transaction.h"


int main() {

    int i;
    // struct keyword is reuqired when creating a varibale/instance of 
    // a Struct(Transaction in this case) in C. However it is not
    // required in C++. So, it is better to rite like this.
    //struct Transaction tr; // C way
    Transaction tr; // C++ way

    for (i = 0; i < NO_TRANSACTIONS; i++) {
        enter(&tr);
        display(&tr);
    }
    return 0;
}
