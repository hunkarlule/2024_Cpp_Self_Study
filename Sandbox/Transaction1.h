
struct Transaction1
{
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount
};

void enter(Transaction1* tr);
void display(const Transaction1* tr);
// Compact Solution - insert the prototype into Transaction.h

void add(double*, const Transaction1*); 

