// Concatenate Two Files
// concatenate.cpp
#include <iostream>
#include <fstream>

int main() {  
    std::ifstream in("src1.txt"); // open 1st source file
    std::ofstream out("output.txt"); // open destination file
    
    if (in) {
        while (!in.eof()) { // while end of file not reached. means while there is char/byte to reead in the input file
           out << in.get(); // get the char/bytes from input file and write them to output file. byte by byte copy
        }
        in.clear(); // clear.
        in.close(); // close the file.
    }

    in.open("src2.txt"); //// open 2nd source file

    // same as above copy byte by byte from source to ouptput file.
    if (in) {
        while (!in.eof())
            out << in.get();        // byte by byte copy
        in.clear();
    }
}