#include "SalariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee(string nameValue, double salaryValue)
    //Let Employee constructor set up the name
    : Employee(nameValue)
{
    salary = salaryValue;
}

double SalariedEmployee::getPay() const {
    //Assume salary is yearly and pay is weekly
    return salary / 52;
}

double SalariedEmployee::getSalary() const {
    return salary;
}

string SalariedEmployee::getInfo() const {
    //Start with the version form Emplyee
    string returnString = Employee::getInfo();

    //Now add on new information:
    returnString += "Salary: " + to_string(salary) + "\n";

    return returnString;
}
