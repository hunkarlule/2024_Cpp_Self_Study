#include <iostream>
#include <fstream>


/*
The Logical Negation Operator
The standard library overloads the logical negation operator (!) as an alternative to the fail() query. 
This operator reports true if the latest operation has failed or if the stream has encountered a serious error.

We can invoke this operator on any stream object to check the success of the most recent activity:
*/
int main() {
    int x = 10;
    std::ofstream fout("output.txt"); // connects fout to output.txt for writing to file.

    // for writing to file
    if (!fout) { // checks if file connection is valid/exist.
        std::cerr << "File is not open" << std::endl;

    }
    else {
        std::cout << "File is open" << std::endl;
        fout << x << std::endl;
        fout.close();
    }

    

    int i;
    std::ifstream fin("outputx.txt"); // connects fin to output.txt for readin from file

    //if (fin.fail()) {
    if (!fin) { //same as above line.
        std::cerr << "Read error";
        fin.clear();
    }
    else {
        fin >> i;
        std::cout << i << std::endl;
    }

}