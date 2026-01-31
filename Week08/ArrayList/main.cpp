#include <iostream>
#include <string>

using namespace std;

class IPrintable {
public:
  virtual void print() const = 0;
};

class GeometricObject {
private:
  string color;

public:
  GeometricObject(const string& colorVal) {
    this->color = colorVal;
  }
};

class Circle: public GeometricObject, public IPrintable {
private:
  double radius;

public:
  Circle(const string& name, double r): GeometricObject(name) {
    radius = r;
  }

  virtual void print() const override {
    cout << "A circle with radius: " << radius << endl;
  }
};

class Person: public IPrintable {
private:
  string name;

public:
  Person(const string& nameValue) {
    name = nameValue;
  }

  virtual void print() const override {
    cout << "A person: " << name << endl;
  }
};

void usePrinter(IPrintable& thing) {
  thing.print();
}

int main() {
  Circle c1("Blue", 5);

  Person p1("Bob");

  usePrinter(c1);
  usePrinter(p1);

}
