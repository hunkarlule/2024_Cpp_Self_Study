#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // this is corresponds to C langiages string.h file. In other words, this is comes from C but when using it we use cstring instead of string.h

using namespace std;

// here we created a Teacher struct in C++ (OOP) style/way.
// so, attributes and actions / functions are packeged. ==> Encapsulation.


struct Teacher {
private: // this makes the attributes private tham means they can be reached only inside the class. Clinet code cannot access attributes directly.
	char m_subject[7]{}; // {} this will initialize/set it subject to default for that type. So, in this case all characters to empyt char.
	char m_name[41]{};
	int m_rating{};// here {} sets to rating to 0(zero)
	int m_grading{};

public: // functions are public, means client code can access and call them.
	// because set is inside of Teacher struct then it has access to
	// all attributes of Teacher. so we do not need pass a Teacher to it.
	// we can write it as follows.
	// as naming convection we removed changed setTeacher to set.
	
	// here we have 4 member functions with the same name(set).
	// This is OK because, all functions have different signatures.
	// This is function overloading(statis polymorphism).
	void set(const char* subject, const char* name, int rating, int grading) {
		strcpy(m_name, name);
		strcpy(m_subject, subject);
		m_rating = rating;
		m_grading = grading;
	}

	void set(const char* subject) {
		strcpy(m_subject, subject);
	}

	void set(int rating) {
		m_rating = rating;
	}

	void set() {
		char name[41]{}, sub[7]{};
		int rating{}, grading{};
		cout << "Name:\n> ";
		cin >> name;
		cout << "Subject:\n> ";
		cin >> sub;
		cout << "Rating:\n> ";
		cin >> rating;
		cout << "Grading:\n> ";
		cin >> grading;
		set(sub, name, rating, grading);
	}

	void print() {
		cout << m_name << ": subject (" << m_subject << ")" << endl
			<< "Rating: " << m_rating << endl
			<< "Grading: " << m_grading << endl;
	}
};

/*  we converted Teacher to OOP (C++ style) and moved them inside the struct definition.
	so, attributes and actions/funstions are packeged. ==> Encapsulation.

void setTeacher(Teacher* T, const char* subject, const char* name, int rating, int grading) {
	strcpy(T->m_name, name);
	strcpy(T->m_subject, subject);
	T->m_rating = rating;
	T->m_grading = grading;
}

void printTeacher(const Teacher* T) {
	cout << T->m_name << ": subject (" << T->m_subject << ")" << endl
		<< "Rating: " << T->m_rating << endl
		<< "Grading: " << T->m_grading << endl;
}
 */
int main() {
	Teacher T, U;
	//setTeacher(&T, "OOP244", "Fred Soley", 4, 10);
	//printTeacher(&T);


	// here in OOP case we call the functions like this.
	T.set("OOP244", "Fred Soley", 4, 10);

	// here client code change the Teacher's attribute directly(T.m_rating = 1(0;).
	// This is not a good design. Instead of it, it should ask for change
	// to Teacher struct( like a calling a member function ( such as named setRating))
	// and if all conditions are met then that member function set it.
	// For example, here the client code can set it to an absurd value like -999.
	// In order to succeed this, in struct definition we need to make m_rating "Private".
	
	//T.m_rating = 10;  // because we made Teacher's attribute private and this line is not allowed anymore.
	T.print();

	U.set("IPC144", "Fardad Soley", 8, 4);
	U.print();

	// here in client code, we want to set subject  and rating for T.
	// because they are private attributes we cannot access them directly. Instead
	// we call the member functions to ste them.
	// 
	// strcpy(T.m_subject, "OOP345"); //error
	T.set("OOP345");

	//T.m_rating = 10; // error
	T.set(3);
	T.print();

	U.set();
	U.print();

	return 0;
}
