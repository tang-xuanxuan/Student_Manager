#ifndef COURSE_MANAGER_HPP
#define COURSE_MANAGER_HPP

#include "course.hpp"
#include <map>

class CourseManager
{
public:
    bool addCourse(const Course& course);
    bool deleteCourse(int id);
    const Course* findCourse(int id) const;
private:
    map<int, Course> courses;
};

#endif