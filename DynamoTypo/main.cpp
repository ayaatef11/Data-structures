
#include <stdexcept>
#include<cstdlib>
#include<iostream>
#include<Windows.h>
#include"socialMediaActivityTracker.h"
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
void mainMenu() {
    SetConsoleTextAttribute(cout_handle, 11);
    cout << "\n*~~~~~~~~~~~~~~~~~~~~Social media activity tracker System~~~~~~~~~~~~~~~~~~~~~~~*\n";
    SetConsoleTextAttribute(cout_handle, 13);
    cout << "1- User menu\n2-Search menu\n3-Activity menu\n4-Sorting\n5-Statistics\n6-Show details\n\tEnter Selection: " ;
}

void userMenue() {
    cout << "\t\t\t\t<<User menu>>\n1-Add user\n2-Delete user"<<
    "\n3 - Return to main menu\n\t\t Enter selection : " ;
}

void searchMenu() {
    cout << "\t\t\t\t<<User menu>>\n1-Search for a user\n"<<
    "2-Return to main menu\n\t\tEnter selection: " ;
}

void activityMenu() {
    cout << "\t\t\t\t<<Activity menu>>\n1-Add activity\n2-Delete activity\n3-Return to main menu\n\tEnter selection: ";
}

void statisticsMenue() {
    cout << "\t\t\t\t<<Statistics menu>>\n1-Most active users\n2-Popular post\n3-Trends\n4-Return to main menu\n\tEnter selection: ";
}

void showDetailsMenue() {
    cout << "\t\t\t\t<<System Details>>\n1-Show user details\n2-Show activity details\n3-Return to main menu\n\tEnter selection: ";
}

void handleException(const exception& ex) {
    SetConsoleTextAttribute(cout_handle, 12);
    cerr << "Error: " << ex.what() << endl;
    SetConsoleTextAttribute(cout_handle, 6);
}

int main()
{
    socialMediaActivityTracker tracker;
    Sleep(3000);
    system("cls");
    int cc = -1;
    int c = -1;
    while (cc) {
        mainMenu();
        while (!(cin >> cc))
        {
            cout << "Error>>you must enter a number ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        system("cls");
        switch (cc) {
        case 1:
            try {
                userMenue();
                while (!(cin >> c))
                {
                    cout << "Error>>you must enter a number ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (c) {
                case 1:
                    tracker.addUser();
                    break;
                case 2:
                    tracker.removeUser();
                    break;
                case 3:
                    cout << "Returning to main menu";
                    break;
                }
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;
        case 2:
            try {
                    searchMenu();
                    while (!(cin >> c))
                    {
                        cout << "Error>>you must enter a number ";
                        cin.clear();
                        cin.ignore(123, '\n');
                    }
                    system("cls");
                    switch (c) {
                    case 1:
                        cout<<*(tracker.searchUser());
                        break;
                    case 2:
                        cout << "Returning to main menu";
                        break;
                    }
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;
        case 3:
            try {               
                activityMenu();
                while (!(cin >> c))
                {
                    cout << "Error>>you must enter a number ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (c) {
                case 1:
                    tracker.addActivity();
                    break;
                case 2:
                    tracker.removeActivity();
                    break;
                case 3:
                    cout << "Returning to main menu";
                    break;
                }
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;

        case 4:
            try {
                tracker.SortAactivitiesBasedOnTime();
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;

        case 5:
            try {
                statisticsMenue();

                while (!(cin >> c))
                {
                    cout << "Error>>you must enter a number ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (c) {
                case 1:
                    tracker.activeUsers();
                    break;
                case 2:
                    tracker.popularPosts();
                    break;

                case 3:
                    tracker.trends();
                    break;
                case 4:
                    cout << "Returning to main menu";
                    break;
                }
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;
        case 6:
            try {
                showDetailsMenue();
                while (!(cin >> c))
                {
                    cout << "Error>>you must enter a number ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (c) {
                case 1:
                    tracker.printUser();
                    break;
                case 2:
                    tracker.printActivities();
                    break;
                case 3:
                    cout << "Returning to main menu";
                    break;
                }
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;
        case 0:
            cout << "\t\tProgram ended...";
            break;
        default:
            cout << "\nWrong choice,try again!";
        }
        cout << "\n\n\tReturning to main menu......";
        Sleep(6000);
        system("cls");

    }
}