#include "Library.h"

//*******************************************************************

//support exception handling in the linked list
//skip lists
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
int main() {
	int c = -1;
	Library Library;
	Book b1;
	while (c!=0) {
		SetConsoleTextAttribute(cout_handle, 6);
		cout << "-----------------------------------------------------------\n";
		cout << "\t\tBook Managment System\n";
		cout << "-----------------------------------------------------------\n";
		cout << "*~~Where do you want to go?\n\n1*Adding a book\n2*Removing a book\n3*Searching for a book\n" <<
			"4*Sorting ascending\n5*Sorting descending\n6*Borrowing a book\n7*Returning a book"<<
			"\n8*Printing available books\n" <<
			"9*Printing borrowed books\n10*Printing all books\n0*Exit\n\nEnter Selection:" << endl;
		cin >> c;
		system("cls");
		switch (c) {
		case 1:
			Library.add_book(b1);
			break;
			case 2:
				Library.remove_book(); 
				break;
			case 3:	
				Library.Search();
				break;
			case 4:
				Library.sortAscending();
				break;
			case 5:
				Library.sortDescending();
				break;
			case 6:
				Library.borrow();
				break;
			case 7:
				Library.returnBook();
				break;
			case 8:
				Library.displayAvailableBooks();
				break;
			case 9:
				Library.displayBorrowedBooks();
				break;
			case 10:
				Library.display();
				break;
			case 0:
				cout << "\t\tGood Bye...";
				break;
			default:
				cout << "\nWrong choice,try again!";
		}
		cout << "\n\n\tReturning to main menu......";
		Sleep(3000);
		system("cls");
	}
	return 0;
}