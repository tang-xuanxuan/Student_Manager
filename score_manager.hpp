#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

#include <map>
#include <utility>
#include "score.hpp"
#include "student.hpp"
#include "course.hpp"

class StudentManager;
class CourseManager;

class ScoreManager
{
public:
    bool addScore(const Score& score, const StudentManager& stuMgr, const CourseManager& courseMgr);

    bool deleteScore(int stu_id, int course_id);

    const Score* findScore(int stu_id, int course_id) const;

    bool modifyScore(int stu_id, int course_id, double new_score);
    
private:
    std::map<std::pair<int, int>, Score> scores;
};

#endif