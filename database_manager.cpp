#include "database_manager.hpp"
#include <iostream>
#include <cstring>

//构造函数：打开数据库
DatabaseManager::DatabaseManager(const std::string& dbName) //构造函数(打开数据库)
{
    int rc = sqlite3_open(dbName.c_str(), &db);
    if(rc != SQLITE_OK)
    {
        std::cerr << "无法打开数据库：" << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        db = nullptr;
    }
}

DatabaseManager::~DatabaseManager()
{
    if(db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
    if(errMsg != nullptr)
    {
        sqlite3_free(errMsg);
        errMsg = nullptr;
    }
}

//初始化数据库（创建表）
bool DatabaseManager::init()
{
    if(db == nullptr)
        return false;

    //创建学生表
    std::string sqlStudents = R"(
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL
        )
    )";

    //创建课程表
    std::string sqlCourses = R"(
        CREATE TABLE IF NOT EXISTS courses (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL
        )
    )";

    //创建成绩表(联合主键)
    std::string sqlScores = R"(
        CREATE TABLE IF NOT EXISTS scores (
            stu_id INTEGER NOT NULL,
            course_id INTEGER NOT NULL,
            score REAL NOT NULL,
            PRIMARY KEY (stu_id, course_id),
            FOREIGN KEY (stu_id) REFERENCES students(id),
            FOREIGN KEY (course_id) REFERENCES courses(id)
        )
    )";

    return executeSQL(sqlStudents) && executeSQL(sqlCourses) && executeSQL(sqlScores);
}

//执行无返回结果的 SQL 语句
bool DatabaseManager::executeSQL(const std::string& sql)
{
    if(db == nullptr) return false;
    int rc = sqlite3_exec(db ,sql.c_str(), nullptr, nullptr, &errMsg);
    if(rc != SQLITE_OK)
    {
        std::cerr << "SQL 错误：" << errMsg << std::endl;
        sqlite3_free(errMsg);
        errMsg = nullptr;
        return false;
    }
    return true;
}

//学生表操作实现
bool DatabaseManager::addStudentToDB(const Student& stu)
{
    char sql[256];
    //插入学生（若ID已存在则忽略）
    sprintf(sql, "INSERT OR IGNORE INTO students (id, name) VALUES (%d, '%s')",
            stu.getStuId(), stu.getStuName().c_str());
    return executeSQL(sql);
}

bool DatabaseManager::deleteStudentFromDB(int stuId)
{
    char sql[256];
    //删除学生（级联删除成绩）
    sprintf(sql, "DELETE FROM students WHERE id = %d;", stuId);
    return executeSQL(sql);
}

//从数据库加载所有学生到内存
std::vector<Student> DatabaseManager::getAllStudentsFromDB()
{
    std::vector<Student> students;
    if(db == nullptr) return students;

    std::string sql = "SELECT id, name FROM students;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if(rc != SQLITE_OK)
    {
        std::cerr << "查询学生失败：" << sqlite3_errmsg(db) << std::endl;
        return students;
    }

    //遍历查询结果
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        students.emplace_back(std::string(name), id);
    }

    sqlite3_finalize(stmt);
    return students;
}

Student* DatabaseManager::findStudentInDB(int stuId)    //查找学生
{
    //简化实现：实际可通过 SQL 查询单条记录
    auto students = getAllStudentsFromDB();
    for(auto& stu : students)
    {
        if(stu.getStuId() == stuId)
            return &stu;    //注意：实际应返回堆对象指针，避免局部变量销毁
    }
    return nullptr;
}

// ------------------------------
// 课程表操作实现（与学生表类似）
// ------------------------------
bool DatabaseManager::addCourseToDB(const Course& course) {
    char sql[256];
    sprintf(sql, "INSERT OR IGNORE INTO courses (id, name) VALUES (%d, '%s');",
            course.getCourseId(), course.getCourseName().c_str());
    return executeSQL(sql);
}

bool DatabaseManager::deleteCourseFromDB(int courseId) {
    char sql[256];
    sprintf(sql, "DELETE FROM courses WHERE id = %d;", courseId);
    return executeSQL(sql);
}

std::vector<Course> DatabaseManager::getAllCoursesFromDB() {
    std::vector<Course> courses;
    if (db == nullptr) return courses;

    std::string sql = "SELECT id, name FROM courses;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "查询课程失败: " << sqlite3_errmsg(db) << std::endl;
        return courses;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        courses.emplace_back(std::string(name), id);
    }

    sqlite3_finalize(stmt);
    return courses;
}

Course* DatabaseManager::findCourseInDB(int courseId) {
    auto courses = getAllCoursesFromDB();
    for (auto& course : courses) {
        if (course.getCourseId() == courseId) {
            return &course;
        }
    }
    return nullptr;
}

// ------------------------------
// 成绩表操作实现
// ------------------------------
bool DatabaseManager::addScoreToDB(const Score& score) 
{
    char sql[256];
    sprintf(sql, "INSERT OR IGNORE INTO scores (stu_id, course_id, score) VALUES (%d, %d, %.1f);",
            score.getStuId(), score.getCourseId(), score.getScore());
    return executeSQL(sql);
}

bool DatabaseManager::deleteScoreFromDB(int stuId, int courseId) 
{
    char sql[256];
    sprintf(sql, "DELETE FROM scores WHERE stu_id = %d AND course_id = %d;", stuId, courseId);
    return executeSQL(sql);
}

bool DatabaseManager::updateScoureInDB(int stuId, int courseId, double newScore) 
{
    char sql[256];
    sprintf(sql, "UPDATE scores SET score = %.1f WHERE stu_id = %d AND course_id = %d;",
            newScore, stuId, courseId);
    return executeSQL(sql);
}

std::vector<Score> DatabaseManager::getAllScoresFromDB() 
{
    std::vector<Score> scores;
    if (db == nullptr) return scores;

    std::string sql = "SELECT stu_id, course_id, score FROM scores;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "查询成绩失败: " << sqlite3_errmsg(db) << std::endl;
        return scores;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int stuId = sqlite3_column_int(stmt, 0);
        int courseId = sqlite3_column_int(stmt, 1);
        double score = sqlite3_column_double(stmt, 2);
        scores.emplace_back(stuId, courseId, score);
    }

    sqlite3_finalize(stmt);
    return scores;
}

Score* DatabaseManager::findScoreInDB(int stuId, int courseId) 
{
    auto scores = getAllScoresFromDB();
    for (auto& scr : scores) {
        if (scr.getStuId() == stuId && scr.getCourseId() == courseId) {
            return &scr;
        }
    }
    return nullptr;
}