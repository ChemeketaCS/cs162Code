#include "CourseList.h"

#include <iostream>
#include <fstream>

using namespace std;


CourseList::CourseList(){
    ifstream inFile("Courses.txt");

    if(!inFile.is_open()) {
        cout << "Error opening file!!!";
        exit(0);
    }

    //read in number of courses
    inFile >> numCourses;
    //allocate storage
    courses = new Course[numCourses];

    for(int i = 0; i < numCourses; i++) {
        int crn;
        string name;
        string room;
        inFile >> crn >> name >> room;
        //Make a Course with that data, copy into array
        courses[i] = Course(crn, room, name);
    }

    //Check and see if there was an error while reading
    if(!inFile.good()) {
        cout << "Error reading file!!!";
        exit(0);
    }
}

CourseList::CourseList(const CourseList& other)
{
    //copy number of courses
    numCourses = other.numCourses;
    //allocate own storage
    courses = new Course[numCourses];
    //copy courses over
    for(int i = 0; i < numCourses; i++) {
        courses[i] = other.courses[i];
    }
}

CourseList& CourseList::operator=(const CourseList& other)
{
    //don't change anything if asked to do self assignment!
    if(this != &other) {
        //delete existin storage
        delete [] courses;

        //Make deep copy of other CourseList
        numCourses = other.numCourses;
        courses = new Course[numCourses];
        for(int i = 0; i < numCourses; i++) {
            courses[i] = other.courses[i];
        }
    }

    return *this;   //return self
}

CourseList::~CourseList() {
    //delete our memeory
    delete [] courses;
}

int CourseList::getNumCourses() const {
    return numCourses;
}


Course* CourseList::getCourseByIndex(int n) const {
    //return address of desired element in array
    return &courses[n];
}

Course* CourseList::getCourseByCRN(int crn) const {
    //look for right course
    for(int i = 0; i < numCourses; i++) {
        if( courses[i].getCRN() == crn ) {
            //found it, return it's address
            return &courses[i];
        }
    }
    //not there...
    return nullptr;
}

