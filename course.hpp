#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>

using namespace std;

class Course
{
public:
    Course(string name, int id)
    {
        this->course_name = name;
        this->course_id = id;
    }

    void setCourseName(string name);
    void setCourseId(int id);
    string getCourseName() const;
    int getCourseId() const;
private:
    string course_name;
    int course_id;

};

#endif
