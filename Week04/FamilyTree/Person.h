#ifndef POINT_H
#define POINT_H

#include <string>
#include <vector>

class Person {
private:
  std::string m_name;
  Person* m_mother;
  std::vector<Person*> m_children;

public:
  Person(const std::string& name);
  void setName(const std::string& name);

  Person* getMother() const;
  void setMother(Person* mother);

  bool hasChildren() const;
  Person* getChild(size_t childNum) const;

  void print() const;
};

#endif // POINT_H
