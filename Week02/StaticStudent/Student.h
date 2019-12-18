#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;            //own name
    static string mascot;   //common mascot

public:
    Student(const string& nameValue);

    void print();

    //A method that is static can only access static variables
    static void setMascot(const string& newMascot);

    //A method that is static can only access
    //   static variables
    static string getMascot();
};


#endif // STUDENT_H
