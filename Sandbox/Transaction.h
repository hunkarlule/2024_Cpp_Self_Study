#pragma once
struct Transaction {
	int acct; // account number
	char type; // acount type c: credit, d: debit
	double amount; // transaction amount
};

// function protoype declerations

// Note: in C++, struct keyword is not required when creating/declaring variables
// from a struct
void enter(struct Transaction* tr); // this will work and better: void enter(Transactin* tr)
void display(const struct Transaction* tr); // this will work and better: void display(const Transactin* tr)
