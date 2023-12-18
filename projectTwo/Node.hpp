//============================================================================
// Name        : Node.hpp
// Author      : Kemal Cankurt
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef NODE_HPP
#define NODE_HPP

#include "Course.hpp"

// Internal structure for tree node
struct Node
{
    Course course;
    Node *left;
    Node *right;

    // default constructor
    Node()
    {
        this->left = nullptr;
        this->right = nullptr;
        this->course = Course(); // Assign a default-constructed Course object
    }

    // initialize with a course
    // error: delegating constructors are permitted only in C++11

    Node(Course aCourse) : Node()
    {
        course = aCourse;
    }
};

#endif // NODE_HPP
