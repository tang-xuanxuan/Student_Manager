// manager.cpp
#include "manager.hpp"
#include <iostream>
#include <string>

using namespace std;

void Manager::showMenu()
{
    system("cls"); // Windows清屏，Linux/macOS用"clear"
    cout << "============================" << endl;
    cout << "      学生成绩管理系统      " << endl;
    cout << "============================" << endl;
    cout << "1. 学生管理" << endl;
    cout << "2. 课程管理" << endl;
    cout << "3. 成绩管理" << endl;
    cout << "0. 退出系统" << endl;
    cout << "============================" << endl;
    cout << "请输入操作编号: ";
}

void Manager::run()
{
    int choice = 0;
    while (true)
    {
        showMenu();
        cin >> choice;
        
        switch (choice)
        {
        case 1: // 学生管理子菜单
            {
                int subChoice;
                while (true)
                {
                    system("cls");
                    cout << "============================" << endl;
                    cout << "        学生管理菜单        " << endl;
                    cout << "============================" << endl;
                    cout << "1. 添加学生" << endl;
                    cout << "2. 删除学生" << endl;
                    cout << "3. 查找学生" << endl;
                    cout << "4. 显示所有学生" << endl;
                    cout << "0. 返回上一级" << endl;
                    cout << "请输入操作编号: ";
                    cin >> subChoice;
                    
                    if (subChoice == 0) break;
                    
                    switch (subChoice)
                    {
                    case 1: addStudent(); break;
                    case 2: deleteStudent(); break;
                    case 3: findStudent(); break;
                    case 4: showAllStudents(); break;
                    default: cout << "无效操作，请重新输入！" << endl;
                    }
                    system("pause"); // 暂停显示结果
                }
            }
            break;
            
        case 2: // 课程管理子菜单
            {
                int subChoice;
                while (true)
                {
                    system("cls");
                    cout << "============================" << endl;
                    cout << "        课程管理菜单        " << endl;
                    cout << "============================" << endl;
                    cout << "1. 添加课程" << endl;
                    cout << "2. 删除课程" << endl;
                    cout << "3. 查找课程" << endl;
                    cout << "4. 显示所有课程" << endl;
                    cout << "0. 返回上一级" << endl;
                    cout << "请输入操作编号: ";
                    cin >> subChoice;
                    
                    if (subChoice == 0) break;
                    
                    switch (subChoice)
                    {
                    case 1: addCourse(); break;
                    case 2: deleteCourse(); break;
                    case 3: findCourse(); break;
                    case 4: showAllCourses(); break;
                    default: cout << "无效操作，请重新输入！" << endl;
                    }
                    system("pause");
                }
            }
            break;
            
        case 3: // 成绩管理子菜单
            {
                int subChoice;
                while (true)
                {
                    system("cls");
                    cout << "============================" << endl;
                    cout << "        成绩管理菜单        " << endl;
                    cout << "============================" << endl;
                    cout << "1. 添加成绩" << endl;
                    cout << "2. 修改成绩" << endl;
                    cout << "3. 删除成绩" << endl;
                    cout << "4. 查询成绩" << endl;
                    cout << "5. 显示所有成绩" << endl;
                    cout << "0. 返回上一级" << endl;
                    cout << "请输入操作编号: ";
                    cin >> subChoice;
                    
                    if (subChoice == 0) break;
                    
                    switch (subChoice)
                    {
                    case 1: addScore(); break;
                    case 2: modifyScore(); break;
                    case 3: deleteScore(); break;
                    case 4: queryScore(); break;
                    case 5: showAllScores(); break;
                    default: cout << "无效操作，请重新输入！" << endl;
                    }
                    system("pause");
                }
            }
            break;
            
        case 0: // 退出系统
            cout << "感谢使用，再见！" << endl;
            return;
            
        default:
            cout << "无效操作，请重新输入！" << endl;
            system("pause");
        }
    }
}

// 学生管理实现
void Manager::addStudent()
{
    int id;
    string name;
    cout << "请输入学生ID: ";
    cin >> id;
    cout << "请输入学生姓名: ";
    cin >> name;
    
    Student stu(name, id);
    if (stuMgr.addStudent(stu))
    {
        cout << "添加成功！" << endl;
    }
    else
    {
        cout << "添加失败，学生ID已存在！" << endl;
    }
}

void Manager::deleteStudent()
{
    int id;
    cout << "请输入要删除的学生ID: ";
    cin >> id;
    
    if (stuMgr.deleteStudent(id))
    {
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "删除失败，学生不存在！" << endl;
    }
}

void Manager::findStudent()
{
    int id;
    cout << "请输入要查找的学生ID: ";
    cin >> id;
    
    const Student* stu = stuMgr.findStudent(id);
    if (stu)
    {
        cout << "找到学生: " << stu->getStuName() << " (ID: " << stu->getStuId() << ")" << endl;
    }
    else
    {
        cout << "未找到该学生！" << endl;
    }
}

void Manager::showAllStudents()
{
    // 需要在StudentManager中添加获取所有学生的方法才能实现
    cout << "暂未实现显示所有学生功能" << endl;
}

// 课程管理实现
void Manager::addCourse()
{
    int id;
    string name;
    cout << "请输入课程ID: ";
    cin >> id;
    cout << "请输入课程名称: ";
    cin >> name;
    
    Course course(name, id);
    if (courseMgr.addCourse(course))
    {
        cout << "添加成功！" << endl;
    }
    else
    {
        cout << "添加失败，课程ID已存在！" << endl;
    }
}

void Manager::deleteCourse()
{
    int id;
    cout << "请输入要删除的课程ID: ";
    cin >> id;
    
    if (courseMgr.deleteCourse(id))
    {
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "删除失败，课程不存在！" << endl;
    }
}

void Manager::findCourse()
{
    int id;
    cout << "请输入要查找的课程ID: ";
    cin >> id;
    
    const Course* course = courseMgr.findCourse(id);
    if (course)
    {
        cout << "找到课程: " << course->getCourseName() << " (ID: " << course->getCourseId() << ")" << endl;
    }
    else
    {
        cout << "未找到该课程！" << endl;
    }
}

void Manager::showAllCourses()
{
    // 需要在CourseManager中添加获取所有课程的方法才能实现
    cout << "暂未实现显示所有课程功能" << endl;
}

// 成绩管理实现
void Manager::addScore()
{
    int stuId, courseId;
    double score;
    cout << "请输入学生ID: ";
    cin >> stuId;
    cout << "请输入课程ID: ";
    cin >> courseId;
    cout << "请输入成绩: ";
    cin >> score;
    
    Score scr(stuId, courseId, score);
    if (scoreMgr.addScore(scr, stuMgr, courseMgr))
    {
        cout << "添加成绩成功！" << endl;
    }
    else
    {
        cout << "添加成绩失败！" << endl;
    }
}

void Manager::modifyScore()
{
    int stuId, courseId;
    double newScore;
    cout << "请输入学生ID: ";
    cin >> stuId;
    cout << "请输入课程ID: ";
    cin >> courseId;
    cout << "请输入新成绩: ";
    cin >> newScore;
    
    if (scoreMgr.modifyScore(stuId, courseId, newScore))
    {
        cout << "修改成绩成功！" << endl;
    }
    else
    {
        cout << "修改失败，未找到对应成绩！" << endl;
    }
}

void Manager::deleteScore()
{
    int stuId, courseId;
    cout << "请输入学生ID: ";
    cin >> stuId;
    cout << "请输入课程ID: ";
    cin >> courseId;
    
    if (scoreMgr.deleteScore(stuId, courseId))
    {
        cout << "删除成绩成功！" << endl;
    }
    else
    {
        cout << "删除失败，未找到对应成绩！" << endl;
    }
}

void Manager::queryScore()
{
    int stuId, courseId;
    cout << "请输入学生ID: ";
    cin >> stuId;
    cout << "请输入课程ID: ";
    cin >> courseId;
    
    const Score* scr = scoreMgr.findScore(stuId, courseId);
    if (scr)
    {
        cout << "学生ID: " << scr->getStuId() 
             << " 课程ID: " << scr->getCourseId() 
             << " 成绩: " << scr->getScore() << endl;
    }
    else
    {
        cout << "未找到对应成绩！" << endl;
    }
}

void Manager::showAllScores()
{
    // 需要将ScoreManager的scores成员改为public或提供访问接口才能实现
    cout << "暂未实现显示所有成绩功能" << endl;
}