#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP

#include <map>
#include "student.hpp"

using namespace std;

class StudentManager
{
public:
    map<int, Student> students;
private:
    bool addStudent(const Student& stu);
    bool deleteStudent(int id);
    Student* findStudent(int id);
};

#endif
