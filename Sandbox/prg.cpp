#include <iostream>
using namespace std;
#include "CalculatorTester.h"

int main() {

    int passed = 0;
    passed += testSuite(5, 3, 125); 
    passed += testSuite(5, -3, 0.008);
    cout << passed << " tests passed." << endl;
    return 0;
}
