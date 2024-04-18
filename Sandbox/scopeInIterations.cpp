#include <iostream>
using namespace std;

int main() {
	/*
	Iterations
	In the following code snippet, the counter i, declared within
	the for statement, goes out of scope immediately after the closing
	brace.
	We cannot refer to i after the closing brace.
	*/

	for (int i = 0; i < 4; i++) {
		cout << "The value of i is " << i << endl;
	} // i goes out of scope here

	/*
	A variable or object declared within a block goes out of scope
	immediately before the block's closing brace.
	The scope of j extends from its definition to just before
	the end of the current iteration. j goes out of scope
	with each iteration. The scope of i extends across
	the complete set of iterations.
	*/
	for (int i = 0; i < 3; i++) {
		int j = 2 * i;
		cout << "The value of j is " << j << endl;
	} // j goes out of scope here

	return 0;
}