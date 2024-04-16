
// One Definition Rule

#include <iostream>
#include "main.h"        // prototype for add()
#include "Transaction.h" // prototypes for enter() and display()
using namespace std;

int main() {
    int i;
    double balance = 0.0;
    Transaction tr;

    for (i = 0; i < NO_TRANSACTIONS; i++) {
        enter(&tr);
        display(&tr);
        add(&balance, &tr);
    }
    cout << "Balance " << balance << endl;
}

void add(double* bal, const Transaction1* tr) {
    *bal += (tr->type == 'd' ? -tr->amount : tr->amount);
}
