#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include "sqlite3.h"
#include <string>
#include <vector>
#include "student.hpp"
#include "course.hpp"
#include "score.hpp"

class DatabaseManager
{
public:
    DatabaseManager(const std::string& dbName); //构造函数(打开数据库)
    ~DatabaseManager();

    //初始化数据库（创建表）
    bool init();

    //学生表操作
    bool addStudentToDB(const Student& stu);
    bool deleteStudentFromDB(int stuId);
    std::vector<Student> getAllStudentsFromDB();
    Student* findStudentInDB(int stuId);    //查找学生

    //课程表操作
    bool addCourseToDB(const Course& course);
    bool deleteCourseFromDB(int courseId);
    std::vector<Course> getAllCoursesFromDB();
    Course* findCourseInDB(int courseId);   //查找课程

    //成绩表操作
    bool addScoreToDB(const Score& score);
    bool deleteScoreFromDB(int stuId, int courseId);
    bool updateScoureInDB(int stuId, int courseId, double newScore);
    std::vector<Score> getAllScoresFromDB();
    Score* findScoreInDB(int stuId, int courseId);  //查找成绩

private:
    sqlite3* db;            //SQLite 数据库句柄
    std::string dbName;     //数据库文件名
    char* errMsg;           //错误信息缓冲区

    //执行SQL语句(无返回结果， 如 CREATE, INSERT, DELETE)
    bool executeSQL(const std::string& sql);
};


#endif