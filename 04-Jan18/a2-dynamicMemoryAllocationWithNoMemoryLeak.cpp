#include <iostream>
using namespace std;
// here we allocated memorry and read integres in it from user.
// however when program finishes we did not release/deallocate the
// memory. It still lives in the heap. Our program/executab;e ran, did its job and removed from
// memory/stack. However, the allocated memory in the heap for us by 
// operating system still lives there because we did not deallicate it.
//This is called memory leak. To preven this we need to deallocate memory
// from heap before our program finishes.

int main() {
	cout << "hello world!" << endl;
	// when there is an unused pointer it is good to set them to null
	int* numbers{};  // here we initilaized int-pointer numbers to null(nullptr).
	//int* numbers = nullptr; // same as above. but above one is better.
	
	size_t size{};

	cout << "enter the number of integers to be printed in reverse. \n>";
	cin >> size; // number of integers users wants to neter from keyboard.

	// here we allocating a int array with size.
	// here we allocating dyanmic memory because we are allicating it
	// with "new" keyword. that means we ask operating system to allocate
	// memory in heap that is enough to hold size integers.
	// sothe 'numbers' pointers points to that location in the heap that
	// allocated for us to hold size integers.
	numbers = new int[size];
	
	for (size_t i{}; i < size; i++) {
		cout << (i + 1) << " > ";
		cin >> numbers[i];
	}

	for (size_t i{}; i < size; i++) {
		cout << (i + 1) << ": " << numbers[size - i - 1] << endl;
	}

	// be careful this loops tries to do same thing above but
	// it causes infinite loop because. we defined i as size_t. it is
	// an unsigned int. When we decrement i. itreaches zero but.
	// when we try to decrement 1 from zero, it should be -1 however
	// it can not because  i is size_t(unsigned int) therefore  i
	// becomes biggset value allowed for a sizt_t type when we
	// decrement 1 from 0. think it is like this: Assume that biggest value for
	// size_t is 128 and we started decrement from 3. then:
	// 3 2 1 0 128 127.......4 3 2 1 0 128
	/*for (size_t i{size - 1}; i >= 0; i--) {
		cout << i << endl;
		cout << (i + 1) << ": " << numbers[i] << endl;
	}*/

	// To prevent this we need to deallocate memory from heap before our program finishes.
	// it is also good idea to set it to nullprt after delete/deallocating memory from heap.
	delete[] numbers;
	// second delete causing run-time error/crush. Because
	// we deleted the memory from heap already and it is not belong
	// to us. so we get the cursh. therfore it is good practice
	// to set the pointer to nullptr after delteting the memory.
		//delete[] numbers; 

	// But if we set it to nullptr and try to delete it second time
	// we do not get any error. Because, when we use delete operator
	// it looks and see that the pointer is nullptr and it does not
	// do anything becuase there is nothing to delete.
	numbers = nullptr;
	delete[] numbers;

	return 0;
}

