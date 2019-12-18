#include <iostream>
#include "Student.h"

using namespace std;


int main()
{
    Student s1("Bob");
    Student s2("Jane");

    s1.print();
    s2.print();

    //Change the mascot
    s1.setMascot("Bruin");

    s1.print();
    s2.print();

    //Call static function of class directly:
    Student::getMascot();

    //Change mascot directly through class
    Student::setMascot("Trojan");

    return 0;
}

