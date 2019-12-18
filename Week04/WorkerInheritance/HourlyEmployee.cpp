#include "HourlyEmployee.h"

using namespace std;

HourlyEmployee::HourlyEmployee(string nameValue,
                               double hoursWorkedValue,
                               double hourlyRateValue)
    //Let Employee constructor set up the name
    : Employee(nameValue)
{
    hoursWorked = hoursWorkedValue;
    hourlyRate = hourlyRateValue;
}

double HourlyEmployee::getPay() const {
    return hoursWorked * hourlyRate;
}


string HourlyEmployee::getInfo() const {
    //Start with the version form Emplyee
    string returnString = Employee::getInfo();

    //Now add on new information:
    returnString += "Hours worked: " + to_string(hoursWorked) + "\n";
    returnString += "Hourly rate: " + to_string(hourlyRate) + "\n";

    return returnString;
}
