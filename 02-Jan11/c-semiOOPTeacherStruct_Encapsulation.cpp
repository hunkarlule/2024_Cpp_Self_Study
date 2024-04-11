#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // this is corresponds to C langiages string.h file. In other words, this is comes from C but when using it we use cstring instead of string.h

using namespace std;

// here we created a Teacher struct in C++ (OOP) style/way.
// so, attributes and actions / functions are packeged. ==> Encapsulation.

struct Teacher {
	char m_subject[7]{}; // {} this will initialize/set it subject to default for that type. So, in this case all characters to empyt char.
	char m_name[41]{};
	int m_rating{};// here {} sets to rating to 0(zero)
	int m_grading{};

	// because set is inside of Teacher struct then it has access to
	// all attributes of Teacher. so we do not need pass a Teacher to it.
	// we can write it as follows.
	// as naming convection we removed changed setTeacher to set.
	void set(const char* subject, const char* name, int rating, int grading) {
		strcpy(m_name, name);
		strcpy(m_subject, subject);
		m_rating = rating;
		m_grading = grading;
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
	T.print();

	U.set("IPC144", "Fardad Soley", 8, 4);
	U.print();

	return 0;
}
