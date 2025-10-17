#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP

#include <map>
#include "student.hpp"

using namespace std;

class StudentManager
{
public:
    bool addStudent(const Student& stu);
    bool deleteStudent(int id);
    const Student* findStudent(int id) const;
private:
    map<int, Student> students;
};

#endif
