#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Represents a course
struct Course {
    string courseNum; // Course number
    string courseName; // Course name
    vector<string> prerequisites; // Prerequisite courses

    // Default constructor
    Course() {}

    // Constructor with course number and name
    Course(string aCourseNum, string aCourseName) {
        courseNum = aCourseNum;
        courseName = aCourseName;
    }

    // Constructor with course number, name, and prerequisites
    Course(string aCourseNum, string aCourseName, vector<string> prereqs) {
        courseNum = aCourseNum;
        courseName = aCourseName;
        prerequisites = prereqs;
    }
};

// Represents a node in the binary search tree
struct Node {
    Course course; // Course information
    Node* left; // Pointer to left child node
    Node* right; // Pointer to right child node

    // Default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // Constructor with a course
    Node(Course acourse) : Node() {
        this->course = acourse;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;
    void addNode(Course acourse, Node* node);
    void inOrder(Node* node);
    void printCourse(Node* node, string courseNum);

public:
    BST(); // Constructor
    void InOrder(); // Print courses in order
    void PrintCourse(string courseNum); // Print a specific course
    bool loadData(); // Load course data from file
    bool validatePrerequisites(Course course); // Validate prerequisites of a course
    void insert(Course course); // Insert a course into the tree
};

// Constructor for BST
BST::BST() {
    root = nullptr;
}

// Print courses in order
void BST::InOrder() {
    this->inOrder(root);
}

// Print a specific course
void BST::PrintCourse(string courseNum) {
    this->printCourse(root, courseNum);
}

// Insert a course into the tree
void BST::insert(Course course) {
    if (root == nullptr) {
        root = new Node(course);
    }
    else {
        this->addNode(course, root);
    }
}

// Add a node to the tree
void BST::addNode(Course acourse, Node* node) {
    if (node->course.courseNum.compare(acourse.courseNum) > 0) {
        if (node->left == nullptr) {
            node->left = new Node(acourse);
        }
        else {
            this->addNode(acourse, node->left);
        }
    }
    else {
        if (node->right == nullptr) {
            node->right = new Node(acourse);
        }
        else {
            this->addNode(acourse, node->right);
        }
    }
}

// Print courses in order (private)
void BST::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << "Course Number: " << node->course.courseNum;
        cout << " Course Name: " << node->course.courseName;
        cout << " Prerequisite(s): ";
        for (int i = 0; i < node->course.prerequisites.size(); ++i) {
            cout << node->course.prerequisites[i] << " ";
        }
        if (node->course.prerequisites.size() == 0) {
            cout << "None";
        }
        cout << "\n";
        inOrder(node->right);
    }
}

// Print individual course information (private)
void BST::printCourse(Node* node, string courseNum) {
    while (node != nullptr) {
        if (node->course.courseNum.compare(courseNum) == 0) {
            cout << "Course Number: " << node->course.courseNum;
            cout << "  Course Name: " << node->course.courseName;
            cout << "  Prerequisite(s): ";
            for (int i = 0; i < node->course.prerequisites.size(); ++i) {
                cout << node->course.prerequisites[i] << " ";
            }
            if (node->course.prerequisites.size() == 0) {
                cout << "None";
            }
            cout << "\n";
            return;
        }
        else if (node->course.courseNum.compare(courseNum) > 0 && node->left != nullptr) {
            node = node->left;
        }
        else if (node->course.courseNum.compare(courseNum) < 0 && node->right != nullptr) {
            node = node->right;
        }
        else {
            cout << "Course not found. Are you sure you entered the right course number? \n";
            return;
        }
    }
    if (root == nullptr) {
        cout << "Error loading data. =[ \n";
        return;
    }
}

// Load course data from file
bool BST::loadData() {
    ifstream file;
    file.open("ABCU_Advising_Program_Input.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            vector<string> courseLine;
            string line;

            getline(file, line);
            while (line.length() > 0) {
                unsigned int delim = line.find(',');
                if (delim < 100) {
                    courseLine.push_back(line.substr(0, delim));
                    line.erase(0, delim + 1);
                }
                else {
                    courseLine.push_back(line.substr(0, line.length()));
                    line = "";
                }
            }

            Course course;
            course.courseNum = courseLine[0];
            course.courseName = courseLine[1];
            for (unsigned int i = 2; i < courseLine.size(); i++) {
                course.prerequisites.push_back(courseLine[i]);
            }
            insert(course);
        }
        return true;
    }
    if (!file) {
        cout << "Error: Unable to open file. \n";
        return false;
    }
    file.close();
}

// Validate prerequisites of a course
bool BST::validatePrerequisites(Course course) {
    Node* current = root;
    if (current->course.prerequisites.size() > 0) {
        for (int i = 0; i < course.prerequisites.size(); i++) {
            while (current != nullptr) {
                if (course.prerequisites[i] == current->course.courseNum) {
                    return true;
                }
                else if (course.prerequisites[i].compare(current->course.courseNum) > 0 && current->left != nullptr) {
                    current = current->left;
                }
                else if (course.prerequisites[i].compare(current->course.courseNum) < 0 && current->right != nullptr) {
                    current = current->right;
                }
                else {
                    cout << "Prerequisite not found. \n";
                    return false;
                }
            }
        }
    }
    else {
        return true;
    }
}

int main()
{
    BST* bst = new BST();
    string courseNum;
    int choice = 0;

    cout << "Welcome to the planner! \n\n";
    while (choice != 4) {
        cout << "**_____________________________**\n";
        cout << "||            MENU             ||\n";
        cout << "||-----------------------------||\n";
        cout << "||[1] Load Data Structure      ||\n";
        cout << "||[2] Print Course List        ||\n";
        cout << "||[3] Print Course             ||\n";
        cout << "||[4] Exit                     ||\n";
        cout << "||_____________________________||\n";
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:
            bst->loadData();
            break;
        case 2:
            cout << "\nHere is a sample schedule: \n";
            cout << "---------------------------- \n";
            bst->InOrder();
            cout << "\n";
            break;
        case 3:
            cout << "Please enter the course number you would like to search: ";
            cin >> courseNum;
            bst->PrintCourse(courseNum);
            cout << "\n";
            break;
        case 4:
            cout << "\nThank you for using the course planner!\n";
            break;
        default:
            cout << choice << " is not a valid option. Please enter a number 1 - 4.\n";
        }
    }
    return 0;
}