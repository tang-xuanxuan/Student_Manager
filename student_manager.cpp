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