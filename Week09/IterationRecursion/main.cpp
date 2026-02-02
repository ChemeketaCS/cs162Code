#include <iostream>
#include <string> 

using namespace std;

string cleanUpSpaces(const string& input) {
    string result;
    bool inSpace = false; // Track if we are currently in a space sequence
    for (char c : input) {
        if (c == ' ') {
            // Only add space if it is first one
            if (!inSpace) { 
                result += c;
                // Mark that we are in a space sequence
                inSpace = true; 
            }
        } else {
            // Add all non-space characters
            result += c;
            // Mark that we are no longer in a space sequence
            inSpace = false;
        }
    }

    return result;
}

int main() {
    string input = "This  is   a   string   with extra      spaces.";
    string cleaned = cleanUpSpaces(input);
    cout << "Cleaned: '" << cleaned << "'" << endl;
}
