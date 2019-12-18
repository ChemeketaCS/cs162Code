/**
  * Simulates a family tree
  */

#include <iostream>

#include "Person.h"

using namespace std;


//Fills an array of Persons (assumed to have 8 elements)
// Sets up a particular family structure by connecting parent to children
void setupFamily(Person familyMembers[]) {
    familyMembers[0] = Person("Anna");
    familyMembers[1] = Person("Bob");
    familyMembers[2] = Person("Carl");
    familyMembers[3] = Person("Dana");
    familyMembers[4] = Person("Erin");
    familyMembers[5] = Person("Fay");
    familyMembers[6] = Person("George");
    familyMembers[7] = Person("Henry");

    //make Bob and Carl children of Anna
    familyMembers[0].addChild(&familyMembers[1]);
    familyMembers[0].addChild(&familyMembers[2]);

    //make Dana and Erin children of Bob
    familyMembers[1].addChild(&familyMembers[3]);
    familyMembers[1].addChild(&familyMembers[4]);

    //make Fay child of Carl
    familyMembers[2].addChild(&familyMembers[5]);

    //make George child of Erin
    familyMembers[4].addChild(&familyMembers[6]);

    //make Henry child of Fay
    familyMembers[5].addChild(&familyMembers[7]);
}


const int FAMILY_SIZE = 8;

int main()
{
    //Make an array that contains 8 People - will start with "default" People
    // that we replace. Slightly wasteful, but simpler. More efficient version
    // would store an array of Pointers to people.
    Person familyList[FAMILY_SIZE];
    setupFamily(familyList);

    cout << "Print whole family:" << endl;
    for(int i = 0; i < FAMILY_SIZE; i++) {
        familyList[i].print();
    }

    cout << "===========================" << endl;
    //Get the matriarch (Anna)
    cout << "Top of family tree: " << endl;
    Person* annaPtr = &familyList[0];
    annaPtr->print();

    cout << "===========================" << endl;
    cout << "Chaging Carl's name to Chris..." << endl;
    familyList[2].setName("Chris");
    cout << "Top of family tree: " << endl;
    annaPtr->print();

    cout << "===========================" << endl;
    //Child 1 == second child
    Person* secondChildPtr = annaPtr->getNthChild(1);
    cout << "Second child: " << endl;
    secondChildPtr->print();


    cout << "===========================" << endl;
    cout << "Starting from anna, find the chain of first born children:" << endl;

    //Will use currentPerson to point to where we are... start from anna
    Person* currentPerson = annaPtr;
    cout << currentPerson->getName() << endl;

    //Keep going until current person has no kids
    while(currentPerson->hasKids()) {
        //The currentPerson becomes the old currentPerson's first born child
        currentPerson = currentPerson->getFirstBorn();
        //Print the new currentPerson
        cout << currentPerson->getName() << endl;
    }

}
