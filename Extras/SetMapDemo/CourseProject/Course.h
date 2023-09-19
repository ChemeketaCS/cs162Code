#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

//Simple class... not much interesting to see here
class Course
{
    public:
        Course();
        Course(int courseNumber, const string& locationVal, const string& nameVal);
        ~Course();

        string getName() const;
        void setName(const string& val);

        string getRoom() const;
        void setRoom(const string& val);

        int getCRN() const;

        string getInfo() const;

    private:
        int crn;
        string name;
        string location;
};

#endif // COURSE_H
