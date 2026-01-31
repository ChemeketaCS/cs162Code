#include <iostream>
#include <iterator>
#include <regex>

using namespace std;

int main() {
  // Lots of phone numbers in various formats
  //  R"( starts a multiline 'raw' string )" ends it
  string numberList = R"(
            1-503-555-4567
            503-432-5431
            (815) 109-9521
            5036371289
            503.437.3126
             )";

  // Pattern to match
  // Pattern is ([\d]{3}).?([\d]{4}) but surrounded by R"( and )" to make a raw string
  string regexPattern = R"(([\d]{3}).?([\d]{4}))";

  // Build regex object
  regex re(regexPattern);

  // Get an iterator that works over the string using our regex object
  sregex_iterator next(numberList.begin(), numberList.end(), re);
  // Default constructor produces an end-of-sequence iterator
  sregex_iterator end;
  while (next != end) {
    smatch match = *next;
    // match[0] is whole matched string, match[1]+ are subgroups
    cout << "Turning " << match[0] << " into:" << endl;
    cout << match[1] << "-" << match[2] << endl;
    // Advance to next match
    next++;
  }
}
