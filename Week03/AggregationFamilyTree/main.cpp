/**
 * Simulates a family tree
 */

#include <iostream>

#include "Person.h"

using namespace std;

// Fill in an array of Persons (assumed to have space for 8 elements)
// Connect the family relationships between them with addChild
void setupFamily(Person familyMembers[]) {

  // Create some pointers so that places in the array can have more
  // meaningful identifiers locally, while we're filling them in.
  Person* anna = &familyMembers[0];
  Person* bob = &familyMembers[1];
  Person* carl = &familyMembers[2];
  Person* dana = &familyMembers[3];
  Person* erin = &familyMembers[4];
  Person* fay = &familyMembers[5];
  Person* george = &familyMembers[6];
  Person* henry = &familyMembers[7];

  // Assign each slot a new Person value with the appropriate name
  *anna = Person("Anna"); // same as familyMembers[0] = Person("Anna")
  *bob = Person("Bob");
  *carl = Person("Carl");
  *dana = Person("Dana");
  *erin = Person("Erin");
  *fay = Person("Fay");
  *george = Person("George");
  *henry = Person("Henry");

  // Set up parent-child relationships
  anna->addChild(bob); // same as familyMembers[0].addChild(&familyMembers[1])
  anna->addChild(carl);
  bob->addChild(dana);
  bob->addChild(erin);
  carl->addChild(fay);
  erin->addChild(george);
  fay->addChild(henry);
}

const int FAMILY_SIZE = 8;

int main() {
  // Make an array that contains 8 People - will start with "default" People
  // that we replace. Slightly wasteful, but simpler. More efficient version
  // would store an array of Pointers to people.
  Person familyList[FAMILY_SIZE];
  setupFamily(familyList);

  cout << "Print whole family:" << endl;
  for (int i = 0; i < FAMILY_SIZE; i++) {
    familyList[i].print();
  }

  cout << "===========================" << endl;
  // Get the matriarch (Anna)
  cout << "Top of family tree: " << endl;
  Person* annaPtr = &familyList[0];
  annaPtr->print();

  cout << "===========================" << endl;
  cout << "Chaging Carl's name to Chris..." << endl;
  familyList[2].setName("Chris");
  cout << "Top of family tree: " << endl;
  annaPtr->print();

  cout << "===========================" << endl;
  // Child 1 == second child
  Person* secondChildPtr = annaPtr->getNthChild(1);
  cout << "Second child: " << endl;
  secondChildPtr->print();

  cout << "===========================" << endl;
  cout << "Starting from anna, find the chain of first born children:" << endl;

  // Will use currentPerson to point to where we are... start from anna
  Person* currentPerson = annaPtr;
  cout << currentPerson->getName() << endl;

  // Keep going until current person has no kids
  while (currentPerson->hasKids()) {
    // The currentPerson becomes the old currentPerson's first born child
    currentPerson = currentPerson->getFirstBorn();
    // Print the new currentPerson
    cout << currentPerson->getName() << endl;
  }
}
