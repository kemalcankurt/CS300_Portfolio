#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>

class Course
{
public:
    std::string courseCode;
    std::string courseTitle;
    std::vector<std::string> prerequisites;

    // default constructor
    Course()
    {
        this->courseCode = "";
        this->courseTitle = "";
        this->prerequisites = std::vector<std::string>(); // Assign an empty vector to prerequisites
    }
    Course(const std::string &code, const std::string &title, const std::vector<std::string> &prereqs)
        : courseCode(code), courseTitle(title), prerequisites(prereqs) {}
};

#endif // COURSE_HPP
