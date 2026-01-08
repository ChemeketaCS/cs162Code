#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A Weekday type can only take these values:
enum class Weekday { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

const vector<string> DAY_NAMES = {"Mon", "Tues", "Wed", "Thurs", "Fri"};

// functions that take/return Weekday
string getDayName(Weekday day);
Weekday getDay(string name);

int main() {
  Weekday today = Weekday::FRIDAY;
  cout << "Today is " << static_cast<int>(today) << endl;
  cout << "Today is " << DAY_NAMES.at(static_cast<int>(today)) << endl;

  if (today == Weekday::THURSDAY)
    cout << "Today is trash day" << endl;

  if (today < Weekday::FRIDAY)
    cout << "No weekend in sight" << endl;

  // call function, pass enumerated value
  cout << getDayName(today) << endl;

  cout << "Enter meeting day: ";
  string userInput;
  cin >> userInput;

  // get Weekday from function
  Weekday meetingDay = getDay(userInput);
  cout << getDayName(meetingDay) << endl;
}

string getDayName(Weekday day) {
  switch (day) {
  case Weekday::MONDAY:
    return "Monday";
  case Weekday::TUESDAY:
    return "Tuesday";
  case Weekday::WEDNESDAY:
    return "Wednesday";
  case Weekday::THURSDAY:
    return "Thursday";
  case Weekday::FRIDAY:
    return "Friday";
  }
  return "Unknown day"; // should never reach this
}

Weekday getDay(string name) {
  if (name == "Monday")
    return Weekday::MONDAY;
  else if (name == "Tuesday")
    return Weekday::TUESDAY;
  else if (name == "Wednesday")
    return Weekday::WEDNESDAY;
  else if (name == "Thursday")
    return Weekday::THURSDAY;
  else if (name == "Friday")
    return Weekday::FRIDAY;

  throw invalid_argument("Invalid day name");
  return Weekday::FRIDAY; // will never reach this
}
