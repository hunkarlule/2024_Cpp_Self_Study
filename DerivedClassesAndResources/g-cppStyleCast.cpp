/*
C++ Function-Style Casts
To cast a value from one type to another using a function-style cast, we enclose in parentheses the variable or 
object to be cast to the target type:
Type(identfier)
*/

// C++ Function Style Casting

// Note: C-Style-Cast and C++ Function Style Casting are interchangeable for fundamental types, but not pointer types.
// For conversions to pointer types, only the C - style cast is available.

#include <iostream>

int main() {
    double hours;
    int minutes;
    std::cout << "Enter minutes : ";
    std::cin >> minutes;
    hours = double(minutes) / 60;  // C++ Function-Style Cast
    std::cout << "In hours, this is " << hours;
}