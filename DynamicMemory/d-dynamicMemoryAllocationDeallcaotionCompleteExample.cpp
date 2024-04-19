

/*
A Complete Example
Consider a simple program in which the user enters a number 
and the program allocates memory for that number of Students. 
The user then enters data for each student. The program displays 
the data stored, deallocates the memory and terminates:

*/

#include <iostream>
#include <cstring>
using namespace std;

struct Student {
	int no;
	float grade[2];
};

int main() {


	int n;
	Student* student = nullptr; //this will hold the address of the dynamic students array

	cout << "How many students\n> ";
	cin >> n;

	// contiguous memory 
	// dynamically allocated for an array of n students and returned the address 
	// of the array's first element. So, student pointer points to first 
	// element of the allocated dynamic memory/array.
	student = new Student[n];

	for (int i{}; i < n; i++) {
		cout << "Student number: ";
		cin >> student[i].no;

		cout << "Student grade 1: ";
		cin >> student[i].grade[0];

		cout << "Student grade 2: ";
		cin >> student[i].grade[1];
	}

	for (int i{}; i < n; i++) {
		cout << student[i].no << ": " << student[i].grade[0] << ", "
			<< student[i].grade[1] << endl;
	}
     
	// deallocated dynamic memory that allocated for students.
	delete[] student;
	student = nullptr; // setting student pointer to nullptr. good pratice.
}