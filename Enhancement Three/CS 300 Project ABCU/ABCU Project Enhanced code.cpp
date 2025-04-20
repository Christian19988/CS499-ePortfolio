#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Represents a course
struct Course {
    string courseNum;
    string courseName;
    vector<string> prerequisites;

    Course() {}

    Course(string num, string name, vector<string> prereqs = {}) {
        courseNum = num;
        courseName = name;
        prerequisites = prereqs;
    }
};

// Node in the binary search tree
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course c) : course(c), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    void addNode(Course course, Node* node);
    void inOrder(Node* node);
    void printCourse(Node* node, const string& courseNum);
    bool findCourse(Node* node, const string& courseNum);

public:
    BST() : root(nullptr) {}

    void InOrder() { inOrder(root); }
    void PrintCourse(const string& courseNum) { printCourse(root, courseNum); }
    bool LoadData(const string& filename);
    bool ValidatePrerequisites(const Course& course);
    void Insert(Course course);
};

// Insert course into BST
void BST::Insert(Course course) {
    if (!root)
        root = new Node(course);
    else
        addNode(course, root);
}

void BST::addNode(Course course, Node* node) {
    if (course.courseNum < node->course.courseNum) {
        if (!node->left)
            node->left = new Node(course);
        else
            addNode(course, node->left);
    } else {
        if (!node->right)
            node->right = new Node(course);
        else
            addNode(course, node->right);
    }
}

// Print in-order traversal
void BST::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        cout << "Course Number: " << node->course.courseNum
             << " | Name: " << node->course.courseName
             << " | Prerequisites: ";
        if (node->course.prerequisites.empty())
            cout << "None";
        else {
            for (const string& prereq : node->course.prerequisites)
                cout << prereq << " ";
        }
        cout << "\n";
        inOrder(node->right);
    }
}

// Print a specific course
void BST::printCourse(Node* node, const string& courseNum) {
    if (!node) {
        cout << "Course not found.\n";
        return;
    }

    if (courseNum == node->course.courseNum) {
        cout << "Course Number: " << node->course.courseNum
             << "\nCourse Name: " << node->course.courseName
             << "\nPrerequisites: ";
        if (node->course.prerequisites.empty())
            cout << "None";
        else {
            for (const string& prereq : node->course.prerequisites)
                cout << prereq << " ";
        }
        cout << "\n";
    } else if (courseNum < node->course.courseNum)
        printCourse(node->left, courseNum);
    else
        printCourse(node->right, courseNum);
}

// Check if a course exists in BST
bool BST::findCourse(Node* node, const string& courseNum) {
    if (!node) return false;
    if (node->course.courseNum == courseNum) return true;
    if (courseNum < node->course.courseNum)
        return findCourse(node->left, courseNum);
    else
        return findCourse(node->right, courseNum);
}

// Validate prerequisites
bool BST::ValidatePrerequisites(const Course& course) {
    for (const string& prereq : course.prerequisites) {
        if (!findCourse(root, prereq)) {
            cout << "Missing prerequisite: " << prereq << "\n";
            return false;
        }
    }
    return true;
}

// Load course data from file
bool BST::LoadData(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        vector<string> tokens;
        stringstream ss(line);
        string token;

        while (getline(ss, token, ',')) {
            token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
            tokens.push_back(token);
        }

        if (tokens.size() >= 2) {
            string courseNum = tokens[0];
            string courseName = tokens[1];
            vector<string> prereqs(tokens.begin() + 2, tokens.end());

            Course course(courseNum, courseName, prereqs);
            Insert(course);
        }
    }
    file.close();
    return true;
}

// Main menu
int main() {
    BST bst;
    int choice;
    string courseNum;
    string filename = "ABCU_Advising_Program_Input.txt";

    cout << "Welcome to the ABCU Course Planner\n";

    do {
        cout << "\nMenu:\n"
             << "1. Load Data Structure\n"
             << "2. Print Course List\n"
             << "3. Print Course Details\n"
             << "4. Exit\n"
             << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (bst.LoadData(filename))
                    cout << "Data loaded successfully.\n";
                break;
            case 2:
                cout << "\nCourse List (In-Order):\n";
                bst.InOrder();
                break;
            case 3:
                cout << "Enter course number (e.g., CS101): ";
                cin >> courseNum;
                bst.PrintCourse(courseNum);
                break;
            case 4:
                cout << "Thank you for using the course planner. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}