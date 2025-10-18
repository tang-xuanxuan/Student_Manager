#include "student_manager.hpp"

bool StudentManager::addStudent(const Student& stu)
{
    int id = stu.getStuId();
    if(students.find(id) != students.end())
    {
        return false;
    }
    students[id] = stu;
    return true;
}

bool StudentManager::deleteStudent(int id)
{
    return students.erase(id) > 0;
}

const Student* StudentManager::findStudent(int id) const
{
    auto it = students.find(id);
    if(it != students.end())
    {
        return &(it->second);
    }
    return nullptr;
}

// 从数据库加载学生数据到内存
void StudentManager::loadFromDB(DatabaseManager& dbMgr) 
{
    students.clear();   //情况现有内存数据
    std::vector<Student> dbStudents = dbMgr.getAllStudentsFromDB(); //从数据库查询
    for(const auto& stu : dbStudents)
    {
        students[stu.getStuId()] = stu; //存入内存map
    }
}

bool StudentManager::addStudentWithDB(const Student& stu, DatabaseManager& dbMgr)
{
    //1.先执行内存添加
    if(!addStudent(stu))    //复用原有内存添加逻辑
        return false;
    
    //2.再同步到数据库
    return dbMgr.addStudentToDB(stu);
}

bool StudentManager::deleteStudentWithDB(int id, DatabaseManager& dbMgr)
{
    //1.先执行内存删除
    if(!deleteStudent(id))  //复用原有内存删除逻辑
        return false;
    
    //2.再同步到数据库
    return dbMgr.deleteStudentFromDB(id);
}