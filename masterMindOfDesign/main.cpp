#include <thread>
#include <chrono>
#include <stdexcept>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
#include "shipping.h"
#include"dataStructure.h"
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
void displayMenu() {
    cout << "\n\n1. Add customer\n2. Place an Order\n3. show customers details\n";
    cout<<"4. show ready products \n5. display all customers \n6. shipping order\n7. GetPreparedOrder";
        cout << "\n0. Exit\nEnter your choice (0-6): ";       
}

void handleException(const exception& ex) {
    SetConsoleTextAttribute(cout_handle, 12);
    cerr << "Error: " << ex.what() << endl;
    SetConsoleTextAttribute(cout_handle, 6);  
}

int main()
{
    SetConsoleTextAttribute(cout_handle, 11);
    cout<< "\n*~~~~~~~~~~~~~~~~~~~~Manufacturing System~~~~~~~~~~~~~~~~~~~~~~~*\n";
    SetConsoleTextAttribute(cout_handle, 6);
    Factory* f = new laptopFactory();
     f->arrangeOperations();
     cout << "\n\t\t...Returning to main menu" << endl;
     Sleep(3000);
     system("cls");
    Shipping s;
    int cc = -1;
    while (cc) {
        displayMenu();
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
                f->addCustomer();
            }
            catch (const exception& ex) {
                handleException(ex);
            }
            break;
        case 2:
        try{
            char c;
            do {
                f->addProducts();
                cout << "Do you want to add any more produts(y/n)<<every customer is permitted to add only one product>> ";
                cin >> c;
            } while (c == 'y');
            try {
                f->mangingProducts();
            }
            catch (const exception& ex) {
                handleException(ex);
            }
        }
        catch (const exception& ex) {
            handleException(ex);
        }
            break;
        case 3:
        try{
            f->getCustomer()->printDetails();
        }
        catch (const exception& ex) {
            handleException(ex);
        }
            break;      
        case 4:
        try{
            f->displayCompletedProducts();
        }
        catch (const exception& ex) {
            handleException(ex);
        }
            break;
       
        case 5:
        try{
            f->displayAllCustomers();
        }
        catch (const exception& ex) {
            handleException(ex);
        }
            break;
        case 6:
        try{
            s.setFactory(f);
            s.setCustomer();
            s.shipOrder();
            s.getShippingDetails();
        }
        catch (const exception& ex) {
            handleException(ex);
        }
            break;
        case 7:
            cout<<f->getCustomer()->getProduct();
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

