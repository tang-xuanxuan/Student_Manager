#include "score_manager.hpp"
#include "student_manager.hpp"
#include "course_manager.hpp"

// 添加成绩：先校验学生和课程是否存在，再检查是否重复添加
bool ScoreManager::addScore(const Score& score, const StudentManager& stuMgr, const CourseManager& courseMgr)
{
    int s_id = score.getStuId();
    int c_id = score.getCourseId();

    // 1. 校验学生是否存在
    if(stuMgr.findStudent(s_id) == nullptr)
    {
        std::cout<< "学生不存在" << std::endl;
        return false;
    }

    if(courseMgr.findCourse(c_id) == nullptr)
    {
        std::cout << "课程不存在" << std::endl;
        return false;
    }

    auto key = std::make_pair(s_id, c_id);
    if(scores.find(key) != scores.end())
    {
        std::cout << "成绩已存在" << std::endl;
        return false;
    }
    
    scores[key] = score;
    return true;
}

bool ScoreManager::deleteScore(int stu_id, int course_id)
{
    auto key = std::make_pair(stu_id, course_id);
    return scores.erase(key) > 0;
}

const Score* ScoreManager::findScore(int stu_id, int course_id) const
{
    auto key = std::make_pair(stu_id, course_id);
    auto it = scores.find(key);
    if(it != scores.end())
    {
        return &(it->second);
    }
    return nullptr;
}

bool ScoreManager::modifyScore(int stu_id, int course_id, double new_score)
{
    auto key = std::make_pair(stu_id, course_id);
    auto it = scores.find(key);
    if(it != scores.end())
    {
        it->second.setScore(new_score);
        return true;
    }
    return false;
}