#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct Name {
	// member variables/data
	char* m_givenName{};
	char* m_surname{};

	// all member-variables/attributes are visible/reachable in
	// member functions.
	void set(const char* name, const char* surname);

	void deallocate() {
		delete[] m_givenName;
		delete[] m_surname;
		m_givenName = m_surname = nullptr;
	}

	void read() {
		char name[61];
		char surname[81];
		cout << "name: ";
		cin >> name;
		cout << "surname: ";
		cin >> surname;
		set(name, surname);
	}

	// print member function will nat change the object. 
	// To enforece this, we added const keyword after
	// function paranthesis.

	void print() const {
		if (m_givenName && m_surname && m_givenName[0] && m_surname[0]) {
			cout << m_givenName << " " << m_surname << endl;
		}
		else {
			cout << "No name!" << endl;
		}

		// this is not allowed becuase we marked print with 'const'
		// keyword. That means prin cannot change object's data.
		//m_givenName = nullptr;
	}
};

// Here before the function name we wrote Name::. That means this set 
// belongs to Name function.(:: is scope-resolution operator)
void Name::set(const char* name, const char* surname) {
	m_givenName = new char[strlen(name) + 1];  // allocating dynamic memory to hold the passed name
	m_surname = new char[strlen(surname) + 1]; //allocating dynamic memory to hold the passed surname

	// checkin both allocation was successful. In other words,
	// checking if operating system gave 
	// us the memory for name and surname or not.
	// if allocations are successful then we copy passed name
	// and surname as the objects name and surname in the allocated places.
	if (m_givenName && m_surname) {
		strcpy(m_givenName, name);
		strcpy(m_surname, surname);
	}
	else {
		// if any of the allocations are not succesful
		// we delete both allocations to avoid any memory leak.
		deallocate();

	}
}




int main() {
	Name* names{}; // a Name-pointer and we initialized it with nullptr using {}.
	size_t num{};

	cout << "how mane names?\n>";
	cin >> num;

	// here DMA(dynamic memory allocation) to hold num names 
	// in the heap. addres of that place is assigned to pointer names.
	names = new Name[num];
	names[0].print();

	for (size_t i{}; i < num; i++) {
		names[i].read();
	}

	for (size_t i{}; i < num; i++) {
		names[i].print();
	}

	for (size_t i{}; i < num; i++) {
		names[i].deallocate();
	}

	delete[] names; // deallocating dynamic memory for names array.
	return 0;
}






