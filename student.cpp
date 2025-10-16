#include "student.hpp"

void Student::getStu()
{
    std::cout << stu_name << " " << stu_id << std::endl;
}

void Student::setName(string name)
{
    this->stu_name = name;
}

void Student::setId(int id)
{
    this->stu_id = id;
}

string Student::getStuName() const
{
    return stu_name;
}

int Student::getStuId() const
{
    return stu_id;
}