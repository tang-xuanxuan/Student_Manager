#ifndef COURSE_MANAGER_HPP
#define COURSE_MANAGER_HPP

#include "course.hpp"
#include <map>
#include "database_manager.hpp"

class CourseManager
{
public:
    bool addCourse(const Course& course);
    bool deleteCourse(int id);
    const Course* findCourse(int id) const;

    void loadFromDB(DatabaseManager& dbMgr);  // 从数据库加载
    bool addCourseWithDB(const Course& course, DatabaseManager& dbMgr);  // 带数据库同步的添加
    bool deleteCourseWithDB(int id, DatabaseManager& dbMgr);  // 带数据库同步的删除
private:
    std::map<int, Course> courses;
};

#endif