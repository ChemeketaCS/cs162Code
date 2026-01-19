#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include <string>

class GeometricObject {
protected:
    std::string m_color;
    
public:
    // Constructor
    GeometricObject(std::string color);
    
    // getArea is an abstract function
    //   we have no way to do it at the base class level
    virtual double getArea() const = 0;
    
    // getColor is a regular virtual function
    //   it does not necessarily need to be virtual, it is unlikely
    //   to be overridden in derived classes
    virtual std::string getColor() const;
    
    // toString is a regular virtual function
    //   we can do the job here, but derived classes will likely want to override
    //   it to provide more specific information
    virtual std::string toString() const;
};


#endif