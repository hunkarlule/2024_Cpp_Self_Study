#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"
using namespace std;

// we have a special pointer called "this". 'this' pointer
// points to current object and can only be used inside the class.

namespace seneca {
	int counter = 0;

	//void Name::init() {
	//	m_givenName = m_surname = nullptr;
	//}

	// Here before the function name we wrote Name::. That means this set 
	// belongs to Name function.(:: is scope-resolution operator)
	
	// never never make the member-variables names and function argument names same
	// it is error prone. I made them smae in set function to 
	// explain use of 'this' pointer.
	void Name::set(const char* name, const char* m_surname) {
		deallocate(); // here we deallotaing givenname and surname before setting them. So we prevent memory leak.
		m_givenName = new char[strlen(name) + 1];  // allocating dynamic memory to hold the passed name
		this->m_surname = new char[strlen(m_surname) + 1]; //allocating dynamic memory to hold the passed surname

		// checkin both allocation was successful. In other words,
		// checking if operating system gave 
		// us the memory for name and surname or not.
		// if allocations are successful then we copy passed name
		// and surname as the objects name and surname in the allocated places.
		if (m_givenName && this->m_surname) {
			strcpy(m_givenName, name);
			strcpy(this->m_surname, m_surname);
		}
		else {
			// if any of the allocations are not succesful
			// we delete both allocations to avoid any memory leak.
			deallocate();

		}
	}

	void Name::deallocate() {
		delete[] m_givenName;
		delete[] m_surname;
		m_givenName = m_surname = nullptr;
	}

	void Name::read() {
		char name[61];
		char surname[81];
		cout << "name: ";
		cin >> name;
		cout << "surname: ";
		cin >> surname;
		set(name, surname);
	}

	Name::Name() {
		m_givenName = m_surname = nullptr;
		cout << "Name " << ++counter << " is created." << endl;
	}

	// print member function will nat change the object. 
	// To enforece this, we added const keyword after
	// function paranthesis.

	void Name::print() const {
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
	Name::~Name() {
		deallocate();
		cout << "Name " << counter-- << " is deleted." << endl;
	}

	//void Name::finalize() {
	//	deallocate();
	//}

	size_t Name::length() const {
		size_t len{};
		if (m_givenName && m_surname && m_givenName[0] && m_surname[0]) {
			len = strlen(m_givenName) + strlen(m_surname);
		}
		return len;
	}
};


