#include <cmath>
#include <iostream>

#include "Person.h"

using namespace std;

// set up some relationships
void friendShipShuffle(vector<Person>& people) {
  int numPeople = static_cast<int>(people.size());
  unsigned int seed = 1;
  for (int personIndex = 0; personIndex < numPeople; ++personIndex) {
    for (int numFriends = 0; numFriends < numPeople / 3; ++numFriends) {
      int friendIndex = seed % numPeople;
      seed = seed * 13 + 1;
      if (friendIndex != personIndex)
        people.at(personIndex).addFriend(&people.at(friendIndex));
    }
  }
}

int main() {
  vector<Person> peopleVec = {Person("Anna"),   Person("Bob"),  Person("Carl"),
                              Person("Diana"),  Person("Erin"), Person("Fay"),
                              Person("George"), Person("Henry")};

  friendShipShuffle(peopleVec);

  Person* p1 = &peopleVec.at(0);
  cout << p1->getName() << endl;
  // Do not modify anything above
  //----------------------------------------------------------------------

  // Try to print out the people in order, only working from currentPerson
  // do not access the peopleVec

  // Bob is Anna's first friend:
  Person* p2 = p1->getFriend(0);
  cout << p2->getName();
}
