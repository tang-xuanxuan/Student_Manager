#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course
{
public:
    Course() : course_name(""), course_id(0) {}  // 初始化列表赋默认值

    Course(std::string name, int id)
    {
        this->course_name = name;
        this->course_id = id;
    }

    void setCourseName(std::string name);
    void setCourseId(int id);
    std::string getCourseName() const;
    int getCourseId() const;
private:
    std::string course_name;
    int course_id;

};

#endif
