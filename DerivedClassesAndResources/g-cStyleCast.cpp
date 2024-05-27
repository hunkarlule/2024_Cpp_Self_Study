/*
Plain C - Style Casts
To cast a value from one type to another using a plain C - style cast, we simply preface the identifier 
with the name of the target type enclosed in parentheses :
(Type)identifier
*/

// C-Style Casting
#include <iostream>

int main() {
    double hours;
    int minutes;
    std::cout << "Enter minutes : ";
    std::cin >> minutes;
    hours = (double)minutes / 60; // C-Style Cast
    std::cout << "In hours, this is " << hours;
}