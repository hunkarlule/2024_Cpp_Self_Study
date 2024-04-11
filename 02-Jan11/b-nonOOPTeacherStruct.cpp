#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // this is corresponds to C langiages string.h file. In other words, this is comes from C but when using it we use cstring instead of string.h

using namespace std;

// here we created a teacher struct.
// we wrote the functions out of struct and passed them  a Teacher object
// to do operations on/with them.
// this is non-oop way. In other words, this is C style/way
struct Teacher {
	char m_subject[7]{}; // {} this will initialize/set it subject to default for that type. So, in this case all characters to empyt char.
	char m_name[41]{};
	int m_rating{};// here {} sets to rating to 0(zero)
	int m_grading{};
};

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

int main() {
	Teacher T;
	setTeacher(&T, "OOP244", "Fred Soley", 4, 10);
	printTeacher(&T);

	return 0;
}
