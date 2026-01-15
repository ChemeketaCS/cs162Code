#include <iostream>

// We techincally don't need Employee.h or SalariedEmployee.h as they
//   are included by other .h's
// Header guards will make sure we only get one copy of them
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Salesperson.h"

using namespace std;

// Prints out names and pay amounts for all employees
void printPayroll(Employee* employeeList[], int size) {
  for (int i = 0; i < size; i++) {
    // Give the current employee* a variable name:
    Employee* currentEmployeePtr = employeeList[i];

    cout << currentEmployeePtr->getName();

    // Since we have a pointer, virtual dispatch will call the
    //  version of getPay defined by the actual type of current employee
    // We never have to know exactly which kind of employee each is
    cout << " : " << currentEmployeePtr->getPay() << endl;
  }
}

// Prints out all the salaried employees
void printSalaried(Employee* employeeList[], int size) {
  for (int i = 0; i < size; i++) {
    // get the current pointer
    Employee* currentEmployeePtr = employeeList[i];
    // see if it can be made into a pointer to a salaried (this would include
    // salespersons)
    SalariedEmployee* currentAsSalaried =
        dynamic_cast<SalariedEmployee*>(currentEmployeePtr);
    if (currentAsSalaried != nullptr) {
      // if the dynamic cast did not produce a nullpointer, it must have worked
      //  use that new pointer to call getInfo()
      cout << currentAsSalaried->getInfo() << endl;
    } else {
      // nullptr indicates that currentEmployeePtr must point to an
      //   Hourly or other non Salary type
      // Do nothing
    }
  }
}

int main() {
  SalariedEmployee employee1("Bob Smith", 50000);
  HourlyEmployee employee2("Jan Jones", 40, 50);
  SalariedEmployee employee3("Maria Cruz", 80000);
  Salesperson employee4("Anthony Jones", 40000, 300000);

  // We want a list of the various employees
  // Need to use pointers so we can retain all the specialized information
  // An array of Employees would slice off all the subclass information for each
  // object
  Employee* employees[4];
  employees[0] = &employee1;
  employees[1] = &employee2;
  employees[2] = &employee3;
  employees[3] = &employee4;

  cout << "Payroll:" << endl;
  cout << "-------------------------------" << endl;
  printPayroll(employees, 4);
  cout << "-------------------------------" << endl;

  cout << endl;

  cout << "Salaried Employee Roster:" << endl;
  cout << "-------------------------------" << endl;
  printSalaried(employees, 4);
  cout << "-------------------------------" << endl;
}
