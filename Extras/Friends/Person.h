#ifndef POINT_H
#define POINT_H

#include <string>
#include <vector>

class Person {
private:
  std::string m_name;
  std::vector<Person*> m_friends;

public:
  Person(const std::string& name);
  void addFriend(Person* friendPerson);
  Person* getFriend(int index) const;
  int getNumFriends() const;
  std::string getName() const;
};

#endif // POINT_H
