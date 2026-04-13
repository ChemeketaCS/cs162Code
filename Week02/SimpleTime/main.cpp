#include <iostream>
#include <format>
#include <string>

using namespace std;

class Time {
public:
  // BEHAVIORS - member functions
  int getHour() {
    return m_hour;
  }

  int getMinute() {
    return m_minute;
  }

  void setHour(int newHour) {
    if(newHour < 0 || newHour >= 24) {
      cout << "Invalid hour value: " << newHour << endl;
      return;
    }
    m_hour = newHour;
  }

  void setMinute(int newMinute) {
    if(newMinute < 0 || newMinute >= 60) {
      cout << "Invalid minute value: " << newMinute << endl;
      return;
    }
    m_minute = newMinute;
  }

  string toString() {
    int hour = getHour();
    int minute = getMinute();
    string result = format("{}:{:02}",  hour,  minute);
    return result;
  }

private:
  // STATE - variables
  int m_hour;
  int m_minute;
};

int main() {
  Time t1;
  t1.setHour(10);
  t1.setMinute(30);

  cout << "t1's hour is " << t1.getHour() << endl;
  cout << "t1's minute is " << t1.getMinute() << endl;
  cout << "t1 is " << t1.toString() << endl;

  t1.setHour(3);
  cout << "t1 is now " << t1.toString() << endl;

  t1.setHour(6);
  cout << "t1 is now " << t1.toString() << endl;
}
