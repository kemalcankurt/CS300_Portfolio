//============================================================================
// Name        : BinarySearchTree.hpp
// Author      : Kemal Cankurt
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Course.hpp"
#include "Node.hpp"

#include <iostream>
#include <string>

using namespace std;

// Define a binary search tree (BST) node structure
class BinarySearchTree
{

private:
    Node *root;

    void addNode(Node *node, Course course);
    void destroyNode(Node *node);
    void printAlphanumericCourseList(Node *root);
    Course findCourse(string courseCode);
    void printCourseDetails(Course course);
    void findAndPrintCourse(string courseCode);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void Insert(Course course);
    void PrintAlphanumericCourseList();
    void FindAndPrintCourse(string courseCode);
};
