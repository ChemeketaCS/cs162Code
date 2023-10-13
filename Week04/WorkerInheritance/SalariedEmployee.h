#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(std::string nameValue, double salaryValue);

    //provide a better version of getPay
    virtual double getPay() const override;

    //provide a better version of getInfo
    virtual std::string getInfo() const override;

    //I do not expect subclasses to override this function
    double getSalary() const;

protected:
    double salary;
};

#endif // SALARIEDEMPLOYEE_H
