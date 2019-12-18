#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
    //Go look for better versions if this function is called
    virtual string toString() const;

    //void setFilled(bool filled); - no setFilled provided
    GeometricObject(); //- No no-arg constructor provided
    GeometricObject(const string& color, bool filled);

    //Destructor - called automatically when destroyed
    ~GeometricObject();

    string getColor() const;
    void setColor(const string& color);
    bool isFilled() const;

private:
    string color;
    bool filled;
};

#endif 
