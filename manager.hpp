#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include "student_manager.hpp"
#include "course_manager.hpp"
#include "score_manager.hpp"

class Manager
{
public:
    // 显示主菜单
    void showMenu();
    
    // 运行管理系统
    void run();

private:
    // 学生管理相关操作
    void addStudent();
    void deleteStudent();
    void findStudent();
    void showAllStudents();
    
    // 课程管理相关操作
    void addCourse();
    void deleteCourse();
    void findCourse();
    void showAllCourses();
    
    // 成绩管理相关操作
    void addScore();
    void modifyScore();
    void deleteScore();
    void queryScore();
    void showAllScores();

    StudentManager stuMgr;   // 学生管理器
    CourseManager courseMgr; // 课程管理器
    ScoreManager scoreMgr;   // 成绩管理器
};

#endif