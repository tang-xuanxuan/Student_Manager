#ifndef COURSE_MANAGER_HPP
#define COURSE_MANAGER_HPP

#include "course.hpp"
#include <map>

class CourseManager
{
public:
    bool addCourse(const Course& course);
    bool deleteCourse(int id);
    Course* findCourse(int id);
private:
    map<int, Course> courses;
};

#endif