#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct Name {
	char* m_name{};
	char* m_surname{};
};

void set(Name& n, const char* name, const char* surname);
void deallocate(Name& n);
void print(const Name& n);
void read(Name& n);

int main() {
	Name* names{}; // a Name-pointer and we initialized it with nullptr using {}.
	size_t num{};

	cout << "how mane names?\n>";
	cin >> num;

	// here DMA(dynamic memory allocation) to hold num names 
	// in the heap. addres of that place is assigned to pointer names.
	names = new Name[num];
	print(names[0]);

	for (size_t i{}; i < num; i++) {
		read(names[i]);
	}

	for (size_t i{}; i < num; i++) {
		print(names[i]);
	}

	for (size_t i{}; i < num; i++) {
		deallocate(names[i]);
	}

	delete[] names; // deallocating dynamic memory for names array.
	return 0;
}

void set(Name& n, const char* name, const char* surname) {
	n.m_name = new char[strlen(name) + 1];  // allocating dynamic memory to hold the passed name
	n.m_surname = new char[strlen(surname) + 1]; //allocating dynamic memory to hold the passed surname

	// checkin both allocation was successful. In other words,
	// checking if operating system gave 
	// us the memory for name and surname or not.
	// if allocations are successful then we copy passed name
	// and surname as the objects name and surname in the allocated places.
	if (n.m_name && n.m_surname) {
		strcpy(n.m_name, name);
		strcpy(n.m_surname, surname);
	}
	else {
		// if any of the allocations are not succesful
		// we delete both allocations to avoid any memory leak.
		delete[] n.m_name;
		delete[] n.m_surname;
		n.m_name = n.m_surname = nullptr;

	}
}

void deallocate(Name& n) {
	delete[] n.m_name;
	delete[] n.m_surname;
	n.m_name = n.m_surname = nullptr;
}

void print(const Name& n) {
	if (n.m_name && n.m_surname) {
		cout << n.m_name << " " << n.m_surname << endl;
	}
	else {
		cout << "No name!" << endl;
	}
}

void read(Name& n) {
	char name[61];
	char surname[81];
	cout << "name: ";
	cin >> name;
	cout << "surname: ";
	cin >> surname;
	set(n, name, surname);
}


