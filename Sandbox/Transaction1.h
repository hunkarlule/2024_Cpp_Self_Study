
struct Transaction1
{
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount
};

void enter(Transaction1* tr);
void display(const Transaction1 tr);
