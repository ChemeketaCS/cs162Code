#include "Course.h"
#include <sstream> //string stream library

using namespace std;

Course::Course() {
  location = "???";
  name = "???";
}

Course::Course(int courseNumber, const string& locationVal,
               const string& nameVal) {
  crn = courseNumber;
  location = locationVal;
  name = nameVal;
}

Course::~Course() {
  // Nothing to do... don't own any memory
}

string Course::getName() const {
  return name;
}

void Course::setName(const string& val) {
  name = val;
}

string Course::getRoom() const {
  // Have to dereference our room ptr to return the actual location
  //  caller gets a reference to that location.
  return location;
}

void Course::setRoom(const string& val) {
  location = val;
}

int Course::getCRN() const {
  return crn;
}

string Course::getInfo() const {
  // build up string using stringstream
  stringstream output;
  output << name << "(" << crn << ")"
         << " in " << location;
  return output.str(); // return string that stringstream made
}
