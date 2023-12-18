//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Kemal Cankurt
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BinarySearchTree.hpp"
#include "Course.hpp"
#include "Node.hpp"

using namespace std;
// Implement destructor for Node
void BinarySearchTree::destroyNode(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    destroyNode(node->left);
    destroyNode(node->right);
    delete node;
}

// create default constructor
BinarySearchTree::BinarySearchTree()
{
    // set root to null
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    this->destroyNode(root); // Call the recursive deleteBST function starting from the root
    root = nullptr;          // Set root to nullptr to indicate the tree is empty
}

// Function to insert a course into the BST
void BinarySearchTree::Insert(Course course)
{
    // if root equal to null ptr
    if (root == nullptr)
    {
        // root is equal to new node course
        root = new Node(course);
    }
    // else
    else
    {
        // add Node root and course
        this->addNode(root, course);
    }
}

// Function to perform an in-order traversal and print courses in alphanumeric order
void BinarySearchTree::PrintAlphanumericCourseList()
{
    this->printAlphanumericCourseList(root);
}

void BinarySearchTree::printAlphanumericCourseList(Node *root)
{
    // if root is null
    if (root == nullptr)
    {
        // return
        return;
    }
    // else
    else
    {
        // recurse left
        this->printAlphanumericCourseList(root->left);

        // print root
        this->printCourseDetails(root->course);

        // recurse right
        this->printAlphanumericCourseList(root->right);
    }
}

Course BinarySearchTree::findCourse(string courseCode)
{
    // initialize course
    Course course;

    // set current node equal to root
    Node *current = this->root;

    // while current node is not null
    while (current != nullptr)
    {
        // if current node course code is equal to course code
        if (current->course.courseCode == courseCode)
        {
            // return current node course
            return current->course;
        }
        // else if current node course code is greater than course code
        else if (current->course.courseCode > courseCode)
        {
            // set current node equal to current node left
            current = current->left;
        }
        // else
        else
        {
            // set current node equal to current node right
            current = current->right;
        }
    }
    return course;
}

// Function to search for a course by course code and return the course
void BinarySearchTree::FindAndPrintCourse(string courseCode)
{
    this->findAndPrintCourse(courseCode);
}

void BinarySearchTree::findAndPrintCourse(string courseCode)
{
    // create new course
    Course course = this->findCourse(courseCode);

    // print course and prereqs
    this->printCourseDetails(course);
}
void BinarySearchTree::printCourseDetails(Course course)
{
    if (course.courseCode.empty())
    {
        std::cout << "Course was not found!" << std::endl; // Course was not found to print
        return;
    }

    std::cout << course.courseCode << ": " << course.courseTitle << std::endl;
    std::cout << "Prerequisites: ";

    if (course.prerequisites.empty())
    {
        std::cout << "None";
    }
    else
    {
        for (const std::string &prereq : course.prerequisites)
        {
            std::cout << prereq << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "----------------------" << std::endl;
}

/**
 * Add a course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(Node *node, Course course)
{
    // if node is larger then add to left
    if (node != nullptr && node->course.courseCode.compare(course.courseCode) > 0)
    {
        // if no left node
        if (node->left == nullptr)
        {
            // this node becomes left
            node->left = new Node(course);
            return;
        }
        else
        {
            // else recurse down the left node
            this->addNode(node->left, course);
        }
    }
    // else add to right
    else if (node != nullptr && node->course.courseCode.compare(course.courseCode) < 0)
    {
        // if no right node
        if (node->right == nullptr)
        {
            // this node becomes right
            node->right = new Node(course);
            return;
        }
        // else
        else
        {
            // recurse down the left node
            this->addNode(node->right, course);
        }
    }
}
