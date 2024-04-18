
#include <iostream>
using namespace std;

/*
REFERENCES
A reference is an alias for a variable or object.
It is like a person with two names.
*/

// Swapping values by reference
void swapUsingReferences(char& a, char& b);

int main() {

	char left2{'x'};
	char right2{ 'y' };

	// here newChar becomes a new name/alias/nickname for left2
	// there is only one obejc wirh two names/idetifiers.
	// So we can use newChar instead of left2 anywhere.
	// see that all the time values and addresses of left2 nad newChar
	// are same. This proves that they are only two different names
	// for the same object.
	// It is like a person with two names.
	char& newChar = left2; 

	// This is compiler error. Because a referecne is a nickname/alias
	// for an existing object/variable we should initialize the reference
	// when we declare it.
		//char& theChar; // illegal.

	cout << "left2 is: ";
	cin >> left2;
	cout << "right2 is: ";
	cin >> right2;

	cout << "before swapping:" << endl;
	cout << "left2: " << left2 << ", right2: " << right2 << endl;
	cout << "newChar: " << newChar << endl;
	cout << "address of left2: " << static_cast<void*>(&left2) << ", address of newChar: " << static_cast<void*>(&newChar) << ", address of right2: " << static_cast<void*>(&right2) << endl;

	cout << "==========================" << endl;
	swapUsingReferences(left2, right2);
	cout << "after swapping left2 and right2:" << endl;
	cout << "left2: " << left2 << ", right2: " << right2 << endl;
	cout << "newChar: " << newChar << endl;
	cout << "address of left2: " << static_cast<void*>(&left2) << ", address of newChar: " << static_cast<void*>(&newChar) << ", address of right2: " << static_cast<void*>(&right2) << endl;

	cout << "==========================" << endl;
	cout << "after swapping newChar and right2:" << endl;
	swapUsingReferences(newChar, right2);
	cout << "left2: " << left2 << ", right2: " << right2 << endl;
	cout << "newChar: " << newChar << endl;
	cout << "address of left2: " << static_cast<void*>(&left2) << ", address of newChar: " << static_cast<void*>(&newChar) << ", address of right2: " << static_cast<void*>(&right2) << endl;



	return 0;
}




// swap2 definition
void swapUsingReferences(char& a, char& b) {
	char c{};

	c = a;
	a = b;
	b = c;
}
