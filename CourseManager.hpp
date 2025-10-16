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