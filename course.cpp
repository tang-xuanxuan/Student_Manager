#include "course.hpp"

void Course::setCourseName(std::string name)
{
    this->course_name = name;
}

void Course::setCourseId(int id)
{
    this->course_id = id;
}

std::string Course::getCourseName() const
{
    return course_name;
}

int Course::getCourseId() const
{
    return course_id;
}
