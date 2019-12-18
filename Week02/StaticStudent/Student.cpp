#include "Student.h"
#include <iostream>


Student::Student(const string& nameValue) {
    name = nameValue;
}

void Student::print() {
    cout << name << " is a " << mascot << endl;
}

//A method that is static can only access static variables
void Student::setMascot(const string& newMascot) {
   mascot = newMascot;
}

//A method that is static can only access
//   static variables
string Student::getMascot() {
    return mascot;
}


//Initialize the static variable mascot
string Student::mascot = "Storm";
