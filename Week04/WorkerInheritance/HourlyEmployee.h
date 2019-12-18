#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(std::string nameValue,
                   double hoursWorkedValue,
                   double hourlyRateValue);

    //provide a better version of getPay
    virtual double getPay() const;

    //provide a better version of getInfo
    virtual std::string getInfo() const;

private:
    double hoursWorked;
    double hourlyRate;
};

#endif // HOURLYEMPLOYEE_H
