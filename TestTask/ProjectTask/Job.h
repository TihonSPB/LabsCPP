#ifndef JOB_H
#define JOB_H

#include <string>

class Job {
public:
    virtual std::string getOccupation() const = 0;
    virtual ~Job() {}
};

class StudentJob : public Job {
public:
    std::string getOccupation() const override { return "Студент"; }
};

class TeacherJob : public Job {
public:
    std::string getOccupation() const override { return "Преподаватель"; }
};

#endif // JOB_H
