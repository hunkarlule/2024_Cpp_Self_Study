// Sorter Interface
// iSorter.h

// iSorter is an interface because it is an abstrac class
// wothout any data members.
class iSorter {
public:
    virtual void sort(float*, int) = 0;
    virtual const char* name() const = 0;
};

iSorter* CreateSorter(int);
int noOfSorters();


// Sorter Concrete Classes
// Sorter.h

//#include "iSorter.h"

class SelectionSorter : public iSorter {
public:
    void sort(float*, int);
    const char* name() const;
};

class BubbleSorter : public iSorter {
public:
    void sort(float*, int);
    const char* name() const;
};

//iSorter* CreateSorter(int);
//int noOfSorters();


// Sorter Hierarchy - Implementation
// Sorter.cpp

////#include "Sorter.h"

void SelectionSorter::sort(float* a, int n) {
    int i, j, max;
    float temp;

    for (int i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (a[max] > a[j]) {
                max = j;
            }
            temp = a[max];
            a[max] = a[i];
            a[i] = temp;
        }
    }
}

const char* SelectionSorter::name() const {
    return "Selection sorter";
}

void BubbleSorter::sort(float* a, int n) {
    int i, j;
    float temp;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

const char* BubbleSorter::name() const {
    return "Bubble Sorter";
}

iSorter* CreateSorter(int i) {
    iSorter* sorter = nullptr;

    switch (i) 
    {
    case 0:
        sorter = new SelectionSorter();
        break;
    case 1 :
        sorter = new BubbleSorter();
        break;
    default:
        break;
    }

    return sorter;
}

int noOfSorters() {
    return 2;
}


// Test Main for the iSorter Interface
// Test_Main.cpp

#include <iostream>
#include <ctime>
//#include "iSorter.h"

void populate(float* a, int n) {
    srand(time(nullptr));
    float f = 1.0f / RAND_MAX;

    for (int i = 0; i < n; i++) {
        a[i] = rand() * f;
    }
}

void test(iSorter* sorter, float* a, int n){
    sorter->sort(a, n);
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            sorted = false;
        }
    }

    if (sorted) {
        std::cout << sorter->name() << " is sorted" << std::endl;
    }
    else {
        std::cout << sorter->name() << " is noy sorted" << std::endl;
    }

}

int main() {
    int n;
    std::cout << "enter no of elements: ";
    std::cin >> n;
    float* array = new float[n];

    for (int i = 0; i < noOfSorters(); i++) {
        iSorter* sorter = CreateSorter(i);
        populate(array, n);
        test(sorter, array, n);
        delete sorter;
    }

    delete[] array;
}