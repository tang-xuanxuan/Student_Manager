#include "course_manager.hpp"

bool CourseManager::addCourse(const Course& course)
{
    int id = course.getCourseId();
    if(courses.find(id) != courses.end())
    {
        return false;
    }
    courses[id] = course;
    return true;
}

bool CourseManager::deleteCourse(int id)
{
    return courses.erase(id) > 0;
}

const Course* CourseManager::findCourse(int id) const
{
    auto it = courses.find(id);
    if(it != courses.end())
    {
        return &(it->second);
    }
    return nullptr;
}

// 从数据库加载课程到内存
void CourseManager::loadFromDB(DatabaseManager& dbMgr)
{
    courses.clear();
    std::vector<Course> dbCourses = dbMgr.getAllCoursesFromDB();
    for (const auto& course : dbCourses)
    {
        courses[course.getCourseId()] = course;
    }
}

// 添加课程并同步到数据库
bool CourseManager::addCourseWithDB(const Course& course, DatabaseManager& dbMgr)
{
    if (!addCourse(course))  // 复用内存添加逻辑
        return false;
    return dbMgr.addCourseToDB(course);  // 同步数据库
}

// 删除课程并同步到数据库
bool CourseManager::deleteCourseWithDB(int id, DatabaseManager& dbMgr)
{
    if (!deleteCourse(id))  // 复用内存删除逻辑
        return false;
    return dbMgr.deleteCourseFromDB(id);  // 同步数据库
}