#ifndef SALESPERSON_H
#define SALESPERSON_H

// By including Salaried Employee, we get Employee also as Salaried includes it
#include "SalariedEmployee.h"

// Salesperson is a salaried employee who gets a bonus based on their total
// sales
class Salesperson: public SalariedEmployee {
public:
  Salesperson(std::string nameValue, double salaryValue,
              double totalSalesValue);

  // provide a better version of getPay
  virtual double getPay() const override;

  // provide a better version of getInfo
  virtual std::string getInfo() const override;

private:
  // already have salary from Salesperson

  double totalSales;
};

#endif // SALESPERSON_H
