#include "Person.h"

#include <cassert>
#include <iostream>

Person::Person() {
  name = "?";
  numKids = 0;
  // array already initialized
}

Person::Person(string nameValue) {
  name = nameValue;
  numKids = 0;
  // array already initialized
}

string Person::getName() const {
  return name;
}

void Person::setName(string val) {
  name = val;
}

void Person::print() const {
  cout << name;

  if (numKids > 0) {
    cout << " who has children: " << endl;
    for (int i = 0; i < numKids; i++)
      cout << "\t" << children[i]->name << endl;
  } else {
    cout << " who has no kids" << endl;
  }
}

void Person::addChild(Person* other) {
  // Blow up if we try to add too many kids
  assert(numKids < 10);

  // Current number of children is index of next child
  //   When 0 kids, next child is children[0],
  //   When 1 kid, next child is children[1]...
  // Use that location in array to store address of child
  children[numKids] = other;

  // We now have one more child
  numKids++;
}

Person* Person::getNthChild(int n) const {
  // Blow up if we ask for a non-existant child
  assert(n >= 0 && n < numKids);
  // Otherwise return the address
  return children[n];
}

bool Person::hasKids() const {
  if (numKids > 0)
    return true;
  else
    return false;
}

Person* Person::Person::getFirstBorn() const {
  // Blow up if no kids
  assert(numKids > 0);
  return children[0];
}
