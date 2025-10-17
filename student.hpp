#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student() : stu_name(""), stu_id(0) {}  // 初始化列表赋默认值
    
    Student(string name,int id)
    {
        this->stu_name = name;
        this->stu_id = id;
    }

    void getStu();
    void setName(string name);
    void setId(int id);
    string getStuName() const;
    int getStuId() const;

private:
    string stu_name;
    int stu_id;
};


#endif
