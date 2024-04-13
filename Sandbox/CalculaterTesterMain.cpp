#include <iostream>
using namespace std;
#include "CalculatorTester.h"


// Note that when we run this code we see that out iplementation in Calculator.cpp
// doe not handle negative exponent values so they are needed to update.
// this is the advantage of witing a test code for our modules.
/*
It is good programming practice to write the suite of unit tests for 
the work units in a module as soon as we have defined the header file and 
before coding the bodies of the work units. As we complete implementation details, 
we continue testing our module to ensure that it produces the results 
that we expect and to identity the work that needs to be done.
*/
int main() {

    int passed = 0;
    passed += testSuite(5, 3, 125); 
    passed += testSuite(5, -3, 0.008);
    cout << passed << " tests passed." << endl;
    return 0;
}
