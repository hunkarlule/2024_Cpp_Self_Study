/*
Inline Functions
Inlining is a technique for improving a function's execution time by replacing the function call with the function logic proper and 
thereby removing the overhead associated with parameter passing. The primary cost of inlining is an increase in the size of 
the executable code.

An inline request directs the compiler to insert the body of the function at every call to the function, if possible. The compiler, 
instead of storing the function's definition once in its own dedicated region of memory and transferring control to that region 
for each call, inserts a copy of the body at each and every call. Inlining is particularly useful with member functions 
that contain small blocks of code. Member functions that do not contain iterations are candidates for inlining.

The compiler determines whether or not to implement an inline request. If the function contains too many statements or an iteration, 
the compiler ignores the request and calls the function in the usual way.

Example
To inline a member function, we embed its definition within the class definition as shown on below or alternatively add 
the keyword inline to the definition
*/


// Inline Functions - Embedded
const int NG = 20;

struct Student {
private:
    int no;
    float grade[NG];
    int ng;
public:
    void set(int n, const char* g);
    const float* getGrades() const { // get grades is an inline function.
        return grade;
    }
};


// Inline Functions - Separate

const int NG = 20;

struct Student {
private:
    int no;
    float grade[NG];
    int ng;
public:
    void set(int n, const char* g);
    const float* getGrades() const;
};

inline const float* Student::getGrades() const { // getGrades is an inline function.
    return grade;
}