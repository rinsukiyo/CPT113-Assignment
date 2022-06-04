//
// Created by rinsuki on 03/06/2022.
//

#include "CourseReg.h"
#include <iostream>
#include <fstream>

using namespace std;

void CourseReg::menu()
{
    // Menu for Course Registration
    cout << "Course Registration Menu \n"
         << "1 - Add Courses \n"
         << "2 - Drop Courses \n"
         << "0 - Exit \n"
         << "Kindly type num of the function that you want to use: ";
    cin >> input;

    // Input Validation
    while (input != 0 && input != 1 && input != 2) inputValidation();

    switch (input)
    {
        // Back to the main menu
        case 0:
            // To be continued...
            cout << "";
            break;

        case 1:
            input = -1;
            cout << "Please wait... we're loading courses from the list." << endl;

            // Read from file
            addCourse();

            // Display the whole course list
            cout << "Do you want to check the course list offered by School of Computer Science, USM? \n"
                 << "1 - Yes, 0 - No \n";
            cin >> input;

            // Input Validation
            while (input != 1 && input != 0) inputValidation();

            // Display the course list
            if (input == 1) displayList();

            // Add Courses
            input = -1;
            cout << "Please type num of the course you want to add: ";
            cin >> input;

            // Input Validation: Check if the num exists

            // Add a course
            while (input != 0)
            {
                if (input == 1) cout << "1";

                // Check if the course exists by the num

                // Successfully added
                cout << "Course #" << input << " has been added. \n"
                     << "If you want to add more, please continue typing the num. \n"
                     << "Press 0 to stop. \n";
                cin >> input;
            }

            cout << "Thanks for using Add Courses." << endl;
            // Go back to the main menu or terminate the program.
            break;

//        case 2:
//            input = -1;
//            cout << "Course List"
//                 // Linked List
//                 << "Please type num of the course you want to drop: ";
//            cin >> input;
//
//            // Input Validation: Check if the num exists
//
//            // Drop a course
//            while (input != 0)
//            {
//                if (input == 1) cout << "1";
//
//                cout << "Course #" << input << " has been dropped. \n"
//                     << "If you want to drop more, please continue typing the num. \n"
//                     << "Press 0 to stop. \n";
//                cin >> input;
//            }
//
//            // Completion
//            input = -1;
//            cout << "Dropping operation completed. Do you want to see the current course list? \n"
//                 << "1 - Yes, 0 - No \n";
//            cin >> input;
//
//            // Input Validation
//            while (input != 1 && input != 0) inputValidation();
//
//            // Display the current course list (after dropping)
//            if (input == 1)
//            {
//                // To be continued...
//            }
//
//            cout << "Thanks for using Drop Courses." << endl;
//            // Go back to the main menu or terminate the program.
//            break;
//
//        // Default
//        default:
//            cout << "Wrong lah!" << endl;
//            break;
    }

}

// Input Validation
void CourseReg::inputValidation()
{
    cout << "Sorry, the num you typed was wrong. Please enter again: ";
    cin >> input;
}

// Add Courses
void CourseReg::addCourse()
{
    // Open the course list
    ifstream infile;
    infile.open("CourseList.txt", ios::in);

    // Initialization
    string currentCode = "default";
    short currentUnit = 0;
    char currentType = 'D';

    // If the file is lost
    if (!infile) cout << "Sorry, we can't find any file called CourseList.txt." << endl;

    for (int currentNum = 1; infile; currentNum++)
    {
        // SetInfo START
        SetInfo *newInfo;
        SetInfo *InfoPtr;

        // Read data from the course list
        infile >> currentCode;
        infile >> currentUnit;
        infile >> currentType;

        // Allocate memory for new info
        newInfo = new SetInfo;

        // Assign the value to the node
//        newInfo->num = currentNum;
        newInfo->code = currentCode;
        newInfo->unit = currentUnit;
        newInfo->type = currentType;

        // Make next pointer point to nullptr
        newInfo->next = nullptr;

        // If the course list is empty
        if (!head) head = newInfo;

        else
        {
            InfoPtr = head;
            while (InfoPtr->next) InfoPtr = InfoPtr->next; // Find the last node of info
            InfoPtr->next = newInfo; // Assign the value to the course list

        }

    }

    // Close the file
    infile.close();
}

// Display the list
void CourseReg::displayList() const
{
    SetInfo *infoPtr;
    infoPtr = head;

    cout << "Here are the courses offered to School of Computer Sciences. \n"
         << "Num\t\t" << "Code\t\t" << "Unit\t" << "Type\t" << endl;

    int num = 0; // Initialization

    while (infoPtr->next)
    {
        cout << ++num << "\t\t"
             << infoPtr->code << "\t\t"
             << infoPtr->unit << "\t\t"
             << infoPtr->type << "\t"
             << endl;

        infoPtr = infoPtr->next;
    }

    cout << "Currently, there are " << num << " courses offered to students from School of Computer Sciences. \n";


}