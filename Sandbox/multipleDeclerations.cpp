#include <iostream>
using namespace std;


/*
Declarations are not necessarily Definitions:
Forward declarations and function prototypes are declarations 
that are not definitions. They associate an identifier with a type, 
but do not attach any meaning to that identifier. 
We may repeat such declarations several times within 
the same code block or translation unit.

Header files consist of declarations. When we include several 
header files in a single implementation file, multiple declarations 
may occur. If some of the declarations are also definitions, 
this may result in multiple definitions within 
the same translation unit. Any translation unit must not break 
the one-definition rule. We need to design our header files to 
respect this rule.
*/

// here we did multiple forward declerations and multiple function
// prototype declerations. This does not cause any issue.
struct Transaction;
struct Transaction;

int add(int a, int b);
int add(int a, int b);

int main() {



    return 0;
}
