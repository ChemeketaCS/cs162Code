#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject {
protected:
  // Protected constructors... should only be made from inside child class
  GeometricObject(); //- No no-arg constructor provided
  GeometricObject(const string& color, bool filled);

public:
  // I want to guarantee all GeometricObjects can do this
  //   but I don't know how
  virtual double getArea() const = 0;
  virtual double getPerimeter() const = 0;

  // Go look for better versions if this function is called
  virtual string toString() const;

  // void setFilled(bool filled); - no setFilled provided
  string getColor() const;
  void setColor(const string& color);
  bool isFilled() const;

private:
  string color;
  bool filled;
};

#endif
