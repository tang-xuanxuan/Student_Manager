#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP

#include <map>
#include "student.hpp"
#include "database_manager.hpp"

using namespace std;

class StudentManager
{
public:
    bool addStudent(const Student& stu);
    bool deleteStudent(int id);
    const Student* findStudent(int id) const;

    void loadFromDB(DatabaseManager& dbMgr);  // 从数据库加载数据
    bool addStudentWithDB(const Student& stu, DatabaseManager& dbMgr);  // 带数据库同步的添加
    bool deleteStudentWithDB(int id, DatabaseManager& dbMgr);  // 带数据库同步的删除
private:
    std::map<int, Student> students;
};

#endif
