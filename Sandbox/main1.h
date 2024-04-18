
#define NO_TRANSACTIONS 3
//#include "Transaction.h"  // BREAKS THE ONE-DEFINITION RULE!

// compiler error because compiler does not know what is Transaction1
// at this point yet.
// we can include (#include "Transaction.h") above to solce issue 
// but this time it will berak the ONE-DEFINITION RULE!. Brcause, main.cpp
// will have 2 definitions of Transaction1!.

// possible solutions to this porblem:
// Forward Declaration Solution - insert the prototype into main.h
// Compact Solution - insert the prototype into Transaction.h

// Forward devleration of Transaction1 type;
//struct  Transaction1;

//void add(double*, const Transaction1*); 


