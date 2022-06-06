//
// Created by rinsuki on 03/06/2022.
//

#ifndef TUITION_CPP_COURSEREG_H
#define TUITION_CPP_COURSEREG_H
#include <string>

using namespace std;

class CourseReg {
private:
    short input;
    int numOfCourses = 0;

    // Declare a structure for the info-setting list
    struct SetInfo
    {
    	int number;
        string code;
        short unit;
        char type;


        struct SetInfo *next;
        struct SetInfo *pre;//doubly linked list
    };

    SetInfo *head; // Head Pointer for setting Info
    SetInfo *end;  //end pointer for setting Info
    
    protected:
    	   int count=0;//to calculate the number of courses has been added

//    // Declare a structure for the Unit List
//    struct Unit
//    {
//        short unit;
//        struct Unit *next;
//    };
//
//    Unit *unitHead; // Head Pointer for the Unit List
//
//    // Declare a structure for the Type List
//    struct Type
//    {
//        short type;
//        struct Type *next;
//    };
//
//    Unit *typeHead; // Head Pointer for the Unit List

public:
    // Default Constructor
    CourseReg() {
        input = -1;
        head = nullptr;
        end=nullptr;
    }

//    // Destructor
//    ~CourseReg();

    // Prototype
    void menu();
    void inputValidation();
    void setCourse();
    void displayList();
    void modifyCourse();
    void passData(string, short, char);
    
    bool search(int);
    void addCourse(string,short,char);
    void dropCourse(int);
    void showNewList();//finally show the courses this student has choose

};

// Linked List for Info
class SetInfo
{
public:
	int num;
    string code; // Current Code
    short unit;
    char type;

    SetInfo *next; // Pointer to the next code
    SetInfo *pre;

    // Constructor
    SetInfo()
    {

    }

//    CourseCode (string currentCode)
//    {
//        code = currentCode;
//        next = nullptr;
//    }

};

#endif //TUITION_CPP_COURSEREG_H
