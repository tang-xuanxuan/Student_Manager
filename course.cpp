#include "course.hpp"

void Course::setCourseName(string name)
{
    this->course_name = name;
}

void Course::setCourseId(int id)
{
    this->course_id = id;
}

string Course::getCourseName()
{
    return course_name;
}

int Course::getCourseId()
{
    return course_id;
}
