#include "Employee.h"

using namespace std;

Employee::Employee(string nameValue)
{
    name = nameValue;
}

string Employee::getName() const {
    return name;
}


string Employee::getInfo() const {
    return "Name: " + name + "\n";
}
