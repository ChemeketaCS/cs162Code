#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

/**
 * @brief The Person class stores information about a person:
 *   name and a list of children
 *
 * Each child is stored as a pointer off to the appropriate Person object
 * An array of Person* stores the list of children
 */
class Person {
private:
  Person* children[10] = {
      nullptr}; /// Max 10 children... pointers all initialized with 0's
  int numKids;  /// How many kids this person actually has
  string name;

public:
  Person();
  Person(string nameValue);

  string getName() const;
  void setName(string newName);

  /**
   * @brief print person's anme and list of children
   */
  void print() const;

  /**
   * @brief record some other person as this person's child
   * @param other memory address of Person who is the child
   */
  void addChild(Person* other);

  /**
   * @brief get memory address of nth child of this person
   * @param n Child number to get. First child is 0.
   *          n must be a valid index or program will die
   * @return memory address of child Person
   */
  Person* getNthChild(int n) const;

  /**
   * @brief Return whether or not this Person has children
   * @return true if there are 1+ children, false otherwise
   */
  bool hasKids() const;

  /**
   * @brief Return memory address of first child of this Person
   *          If no children, program will blow up
   * @return memory address of child
   */
  Person* getFirstBorn() const;
};

#endif // PERSON_H
