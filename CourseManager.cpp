#include "CourseManager.hpp"

bool CourseManager::addCourse(const Course& course)
{
    int id = course.getCourseId();
    if(courses.find(id) != courses.end())
    {
        return false;
    }
    courses[id] = course;

}

bool CourseManager::deleteCourse(int id)
{
    return courses.erase(id) > 0;
}

Course* CourseManager::findCourse(int id)
{
    auto it = courses.find(id);
    if(it != courses.end())
    {
        return &(it->second);
    }
    return nullptr;
}