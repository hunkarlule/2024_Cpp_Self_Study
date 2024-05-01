#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Universal Polymorphism - Parametric

/*
Parametric
Parametric (or generic) polymorphism addresses differences 
between argument types in a function call and the parameter 
types in the function's definition. Parametric polymorphism 
allows function definitions that share identical logic 
independently of type. Unlike coercion, the logic is common 
to all possible types, without restriction. The types do not 
need to be related in any way. For example, a function that 
sorts ints uses the same logic as a function that sorts Students. 
If we have already written a function to sort ints, we only need 
to ensure that the Student class includes a comparison operator 
identical to that used by the sort function.
*/

/*
Parametric polymorphism eliminates duplicate logic across all 
types without generating a missing function definition error. 
C++ implements parametric polymorphism at compile-time using 
template syntax.
*/


// a templae sort function. that sorts an array of n elements.
template<typename T>
void sort(T* a, int n) {
	int i, j;
	T temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

// a simple student class
class  Student
{
	int no;
public:
	Student(int n = 0) : no(n) {}
	// overload  comparison operator(>) for student class. 
	// so we can make a comparision like: studentA > studentB
	bool operator>(const Student& rhs) const {
		return no > rhs.no;
	}

	std::ostream& display(std::ostream& os) const {
		os << no << std::endl;
		return os;
	}

};




int main() {

	int m[] = { 189, 843, 321 }; // initializing an array of 3 ints
	Student s[] = { Student(1256), Student(1267), Student(1234) }; // initializing an array of 3 students
	
	sort(m, 3); // template sort function is used to sort ints
	for (int i = 0; i < 3; i++) {
		std::cout << m[i] << std::endl;
	}

	std::cout << "=======================================\n";

	sort(s, 3); // template sort function is used to sort students.
	for (int i = 0; i < 3; i++) {
		s[i].display(std::cout);
	}


	return 0;
}


