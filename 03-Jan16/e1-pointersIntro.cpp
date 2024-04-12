#include <iostream>
using namespace std;


int main() {
	int a = 25;
	cout << a << endl; // will print 25
	// int* read as: int-pointer,  &a: read as address of a
	// type of p is int*(int pointer)
	// here p'ye address of a( memmory address of a) is assigned.
	int* p = &a; 

   //*p: read as target of p. 
   //means we assign/set 12345 to the memoryt place that is pointed by p( target of p)
	*p = 12345;
	cout << a << endl; // will print 12345
	cout << *p << endl;// will print 12345
	cout << p << endl; // will print addres of a.

	return 0;
}

