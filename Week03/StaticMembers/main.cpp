#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string name) {
        m_name = name;
        numStudents++;
        cout << "Student " << m_name << " created. Total students: " 
             << numStudents << endl;
    }
    int getNumStudents() const {
        return numStudents;
    }
private:
    string m_name;
    static int numStudents;  //shared variable
};

// Must initialize static variable ONCE outside the class
int Student::numStudents = 0;

int main()
{
    Student s1("Alice");
    Student s2("Bob");
    Student s3("Charlie");
    cout << "Total students according to Alice: " << s1.getNumStudents() << endl;
    cout << "Total students according to Bob: " << s2.getNumStudents() << endl;
}
