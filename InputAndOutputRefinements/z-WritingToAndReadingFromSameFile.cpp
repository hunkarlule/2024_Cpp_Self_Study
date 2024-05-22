// File Objects - writing and reading
// fstream.cpp

#include <iostream>
#include <fstream>

int main() {

    std::fstream f("file.txt", std::ios::in | std::ios::out | std::ios::trunc);
    
    f << "Line 1" << std::endl;   // record 1
    f << "Line 2" << std::endl;   // record 2
    f << "Line 3" << std::endl;   // record 3

    f.seekp(0);                   // rewind output
    f << "****";                  // overwrite

    char c;
    f.seekg(0);                   // rewind input
    f << std::noskipws;           // don't skip whitespace

    while (f.good()) {
        f >> c;              // read 1 char at a time
        if (f.good()) {
            std::cout << c;  // display the character
        }
    }

    f.clear();      // clear failed (eof) state

}