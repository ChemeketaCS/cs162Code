#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

//Employee is an abstract class
//Unites various types of Employees
class Employee
{
public:
    //Pure virtual function - no idea how to get pay
    virtual double getPay() const = 0;

    //Makes a string with info about the employee
    //virtual so child classes can provide better version
    virtual std::string getInfo() const;

    //Non-virtual function - child classes not expected to
    // try to override this
    std::string getName() const;

protected:
    //protected constructor - only subclasses should use it
    //Will never make "just an Employee" in other code
    Employee(std::string nameValue);

private:
    std::string name;
};

#endif // EMPLOYEE_H
