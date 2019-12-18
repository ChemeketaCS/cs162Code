#include "Student.h"

#include <iostream>
#include <sstream>
using namespace std;


Student::Student(string nameVal, int numberOfCourses)
{
    //setup non dynamic info
    name = nameVal;
    //keep track of how many courses we can teach
    numCourses = numberOfCourses;
    //first class will be index 0 in array
    nextCourseIndex = 0;

    //Allocate an array of pointers to Courses using appropriate size
    courses = new Course*[numberOfCourses];

    //fancier version to make sure all pointers are null to start
    //courses = new Course*[numCourses]{ nullptr };

    //less fancy version should set all pointers to null in a loop
    for(int i = 0; i < numberOfCourses; i++) {
        courses[i] = nullptr;
    }
}

Student::Student(const Student& other)
{
    //setup non dynamic info
    name = other.name;
    numCourses = other.numCourses;
    nextCourseIndex = other.nextCourseIndex;

    //Allocate an array of pointers to Courses using appropriate size
    courses = new Course*[numCourses];

    //Copy courses from other student
    for(int i = 0; i < numCourses; i++) {
        courses[i] = other.courses[i];
    }
}


Student& Student::operator=(const Student& other)
{
    //don't change anything if asked to do self assignment!
    if(this != &other) {
        //delete existin storage
        delete [] courses;

        //Make deep copy of other Student
        name = other.name;
        numCourses = other.numCourses;
        nextCourseIndex = other.nextCourseIndex;

        courses = new Course*[numCourses];
        for(int i = 0; i < numCourses; i++) {
            courses[i] = other.courses[i];
        }
    }

    return *this;   //return self
}


Student::~Student()
{
    //We have to delete the array we created in constructor
    delete[] courses;
    //Do NOT want to delete courses... we don't own them
    //No need to null out pointers, we are going away...
}


string Student::getName() const
{
    return name;
}

void Student::setName(string val)
{
    name = val;
}

void Student::addClass(Course* newCourse) {
    //make sure we do not overflow
    if(nextCourseIndex == numCourses) {
        cout << "Too many courses for someone!!!" << endl;
        exit(0);
    }

    //make a copy of the given pointer into our array of courses
    courses[nextCourseIndex] = newCourse;
    //increment counter for next time
    nextCourseIndex++;
}

string Student::getInfo() const {
    //use stringstream to build output
    std::stringstream output;

    output << name << endl;
    output << "  Taking:" << endl;
    //loop through our list, add each course's info to list
    for(int i = 0; i < nextCourseIndex; i++) {
        //each element of array is a pointer, so use -> to access members
        output << "  " << courses[i]->getInfo() << endl;
    }
    //return string from the streingstream
    return output.str();
}
