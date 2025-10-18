#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

#include <map>
#include <utility>
#include "score.hpp"
#include "student.hpp"
#include "course.hpp"
#include "database_manager.hpp"

class StudentManager;
class CourseManager;

class ScoreManager
{
public:
    bool addScore(const Score& score, const StudentManager& stuMgr, const CourseManager& courseMgr);
    bool deleteScore(int stu_id, int course_id);
    const Score* findScore(int stu_id, int course_id) const;
    bool modifyScore(int stu_id, int course_id, double new_score);
    
    void loadFromDB(DatabaseManager& dbMgr);  // 从数据库加载
    bool addScoreWithDB(const Score& score, const StudentManager& stuMgr, 
                      const CourseManager& courseMgr, DatabaseManager& dbMgr);  // 带数据库同步的添加
    bool modifyScoreWithDB(int stu_id, int course_id, double new_score, DatabaseManager& dbMgr);  // 带数据库同步的修改
    bool deleteScoreWithDB(int stu_id, int course_id, DatabaseManager& dbMgr);  // 带数据库同步的删除
private:
    std::map<std::pair<int, int>, Score> scores;
};

#endif