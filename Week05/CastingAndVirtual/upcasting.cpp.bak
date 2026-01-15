#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string m_name;
    int m_age;

public:
    Person(string name, int age) {
        m_name = name;
        m_age = age;
    }
    
    string getName() const {
        return m_name;
    }

    void introduce() const {
        cout << "Hi, my name is " << m_name << " and I am " << m_age << " years old." << endl;
    }
};

class Student : public Person {
private:
    string m_major;
public:
    Student(string name, int age, string major)
      : Person(name, age) {
        m_major = major;
    }

    void introduce() const {
        cout << "Hi, my name is " << m_name << " and I am " << m_age << " years old." << endl;
        cout << "My major is " << m_major << "." << endl;
    }
};

void makeIntroduction(const Person& person) {
    cout << "Let's meet: " << person.getName() << endl;
    person.introduce();
}

int main() {
    Person p("Wendy", 30);
    Student s("Alex", 20, "Computer Science");

    Person& personRef1 = p;
    Person& personRef2 = s;

    personRef1.introduce();
    personRef2.introduce();
    
    makeIntroduction(p);
    makeIntroduction(s);

    // Student& studentRef1 = p;
    // Student& studentRef2 = s;

    // studentRef1.introduce();
    // studentRef2.introduce();
}

