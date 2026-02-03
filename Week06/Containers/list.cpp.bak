#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> jobs;

    // Add jobs at the back (FIFO input)
    jobs.push_back("jobA");
    jobs.push_back("jobB");
    jobs.push_back("jobC");

    cout << "Front: " << jobs.front() << endl;
    cout << "Back: " << jobs.back() << endl;
    cout << "Size: " << jobs.size() << endl;

    // Add an urgent job at the front
    jobs.push_front("urgent");

    cout << "Front: " << jobs.front() << endl;
    cout << "Size: " << jobs.size() << endl;

    // Process jobs FIFO: pop from the front
    while (!jobs.empty()) {
        cout << "Processing: " << jobs.front() << endl;
        jobs.pop_front();
    }

    // Demonstrate back operations
    jobs.push_back("cleanup1");
    jobs.push_back("cleanup2");
    cout << "Removing from back: " << jobs.back() << endl;
    jobs.pop_back();
    cout << "New back: " << jobs.back() << endl;
}
