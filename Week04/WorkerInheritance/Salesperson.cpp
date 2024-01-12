#include "Salesperson.h"

using namespace std;

Salesperson::Salesperson(string nameValue, double salaryValue,
                         double totalSalesValue)
    // Let the parent class constructor set up name/salary
    // It will in turn ask the Employee constructor to deal with the name
    :
    SalariedEmployee(nameValue, salaryValue) {
  totalSales = totalSalesValue;
}

double Salesperson::getPay() const {
  // Start with the base pay calculated by SalariedEmployee
  double basePay = SalariedEmployee::getPay();
  double bonus = totalSales * 0.05; // 5% of sales as bonus
  return basePay + bonus;
}

string Salesperson::getInfo() const {
  // Start with the version form SalariedEmployee
  string returnString = SalariedEmployee::getInfo();

  // Now add on new information:
  returnString += "Total Sales: " + to_string(totalSales) + "\n";

  return returnString;
}
