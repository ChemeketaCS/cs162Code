#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(const string& name) {
  m_name = name;
  // vector starts empty by default
}

void Person::addFriend(Person* friendPerson) {
  m_friends.push_back(friendPerson);
}

Person* Person::getFriend(int index) const {
  return m_friends.at(index);
}

int Person::getNumFriends() const {
  return static_cast<int>(m_friends.size());
}

string Person::getName() const {
  return m_name;
}
