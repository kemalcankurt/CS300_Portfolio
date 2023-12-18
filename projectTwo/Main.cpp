#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "BinarySearchTree.hpp"
#include "Course.hpp"
#include "Node.hpp"

#include <sstream> // Include for stringstream

using namespace std;

// Function to parse course data from a line and create a Course object
Course ParseCourseData(const std::string &line)
{
    std::istringstream iss(line);
    std::string courseCode, courseTitle;
    std::vector<std::string> prerequisites;

    // Read course code
    if (std::getline(iss, courseCode, ','))
    {
        // Read course title
        if (std::getline(iss, courseTitle, ','))
        {
            std::string prereq;
            // Read prerequisites if available
            while (std::getline(iss, prereq, ','))
            {
                prerequisites.push_back(prereq);
            }
        }
        else
        {
            // Handle error: Missing course title
            std::cerr << "Error: Missing course title in line: " << line << std::endl;
            return Course();
        }
    }
    else
    {
        // Handle error: Missing course code
        std::cerr << "Error: Missing course code in line: " << line << std::endl;
        return Course();
    }

    return Course(courseCode, courseTitle, prerequisites);
}

int main()
{
    // initialize BST class
    BinarySearchTree bst = BinarySearchTree();

    clock_t ticks;

    while (true)
    {
        // Display menu options
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Load Data Structure" << std::endl;
        std::cout << "2. Print Course List" << std::endl;
        std::cout << "3. Print Course Information" << std::endl;
        std::cout << "4. Exit from program" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        if (!(std::cin >> choice))
        {
            std::cin.clear();                                                   // clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            continue;                                                           // skip the rest of this loop iteration
        }

        switch (choice)
        {
        case 1:
        {
            ticks = clock(); // get starting clock ticks

            // Load course data from a file and insert into the BST
            std::ifstream file("courses.txt");
            if (!file.is_open())
            {
                std::cerr << "Error: Unable to open the file." << std::endl;
                return 1;
            }

            // define a timer variable

            std::string line;
            while (std::getline(file, line))
            {
                // Parse and create Course objects, then insert into the BST
                // Ensure proper parsing and error handling for each line
                Course course = ParseCourseData(line);

                // if course is not null then add course to BST
                if (!course.courseCode.empty())
                {
                    bst.Insert(course);
                }
            }

            file.close();

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        }
        case 2:
        {
            ticks = clock();

            // Print courses in alphanumeric order
            bst.PrintAlphanumericCourseList();

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;
        }
        case 3:
        {
            // Prompt the user to enter a course code and print its information
            std::string courseCode;
            std::cout << "Enter the course code: ";
            std::cin >> courseCode;

            ticks = clock();

            bst.FindAndPrintCourse(courseCode);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        }
        case 4:
        {
            std::cout << "Exiting the program." << std::endl;
            return 0;
        }
        default:
        {
            std::cerr << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
        }
    }

    // Clean up memory (release BST nodes)
    bst.~BinarySearchTree();

    return 0;
}
