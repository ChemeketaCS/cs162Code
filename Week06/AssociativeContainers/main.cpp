#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
  // Sample text to read words from
  string sampleText = R"(
  apple banana orange apple grape banana pear orange kiwi mango pear peach
  strawberry blueberry raspberry blackberry apple mango
  )";

  // Use a stringstream to simulate reading from a file
  stringstream textStream(sampleText);

  // Create a set to hold unique words
  set<string> uniqueWords;

  // Read words from the stream
  string word;
  while (textStream >> word) {
    // Insert the word into the set
    uniqueWords.insert(word);
  }

  cout << "Total unique words: " << uniqueWords.size() << endl;

  cout << "Contains the word 'apple': "
       << (uniqueWords.contains("apple") ? "yes" : "no") << endl;
  cout << "Contains the word 'missing': "
       << (uniqueWords.contains("missing") ? "yes" : "no") << endl;

  // Display the unique words
  // cout << "First unique word: " << uniqueWords.at(0) << endl; // set does not support at()
  auto it = uniqueWords.begin();  // it is set<string>::iterator
  cout << "First unique word: " << *it << endl;

  cout << "Unique words found:" << endl;
  for (const auto& w : uniqueWords) {
    cout << w << endl;
  }
}
