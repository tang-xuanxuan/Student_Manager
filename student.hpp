#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student
{
public:
    Student(std::string name,int id)
    {
        this->name = name;
        this->stu_id = id;
    }

    void getStu();

private:
    std::string name;
    int stu_id;
};


#endif
