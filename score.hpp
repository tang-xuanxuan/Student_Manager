#ifndef SCORE_HPP
#define SCORE_HPP

using namespace std;

class Score
{
public:
    Score(int s_id, int c_id, double scr)
    {
        this->stu_id = s_id;
        this->course_id = c_id;
        this->score = scr;
    }

    int getStuId() const { return stu_id; }

    int getCourseId() const { return course_id; }

    double getScore() const { return score; }

    void setScore(double new_score) { score = new_score; }
    
private:
    int stu_id;
    int course_id;
    double score;
};

#endif