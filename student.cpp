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

string Student::getName()
{
    return stu_name;
}

int Student::getId()
{
    return stu_id;
}