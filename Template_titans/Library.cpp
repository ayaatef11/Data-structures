#include "Library.h"

Library::Library() : Bookcatalog("DynamicArray") {
    size = borrowed = 0;
}

void Library::add_book(Book& b) {
    cout << "\n\n*~~~~~~~~Adding a book \n\n";
    b.read();
    Bookcatalog.Push_back(b);
   AvailableBooks.Push_back(b);
    size++;
    available++;
}

void Library::remove_book() {
    cout << "\n\n*~~~~~~~~~Removing a book..... \n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Book* b2 = search();
    Bookcatalog.pop(*b2);
    if (b2->isAvailable()) {
        AvailableBooks.pop(*b2);
        available--;
    }
    else {
        borrowedBooks.pop(*b2);
        borrowed--;
    }
    size--;
    
    cout << "\n\tRemoved successfully......\n";
}

Book* Library::search() {
    return Bookcatalog.search();
}

void Library::Search() {
    cout << "\nSearching a book:\n ";
    Book* b = Bookcatalog.search();
    cout << "\nFound successfully\n";
    b->display();
    if (!b->isAvailable())cout << "\n\n---Warning! this book isn't available yet..\n";
}

void Library::sortAscending() {
    cout << "\n\n*~~~~~~Sorting Ascending\n\n";
    cout << "Enter attribute name: ";
    string val;
    cin >> val;
    Bookcatalog.sortasc(val);
    cout << "\n\tSorted successfully go to display all books menu to see changes\n";
}

void Library::sortDescending() {
    cout << "\n\n*~~~~~~Sorting Descending\n\n";
    cout << "Enter attribute name: ";
    string val;
    cin >> val;
    Bookcatalog.sortdesc(val);
    cout << "\n\tSorted successfully go to display all books menu to see changes\n";
}

void Library::book_statistics() {
   cout << "\n\nTotal number of books = " << size  << endl;
    cout << "Number of available books = " << available << endl;
    cout << "Number of borrowed books= " << borrowed << endl;
}

void Library::display() {
    if (size == 0)cout << "\n Empty library";
    else {
        cout << "\n\n*~~~~~~~Books' Library\n\n";
        Bookcatalog.print();
    }
   
}

void Library::displayBorrowedBooks()  {
    if (borrowed == 0)cout << "\nNo borrowed books yet" << endl;
    else{
        cout << "\n\n*~~~~~~~~~~Borrowed Books\n\n";
        borrowedBooks.print();
    }
   
}

void Library::borrow() {
    cout << "*~~~~~~~~~~Borrowing a book \n";
         Book* b= Bookcatalog.search();
         if (b == nullptr)cout << "\nBook specified isn't available\n";
         else if (!b->isAvailable())cout << "\nSpecified book is actually borrowwed\n";
         else {
             (*b).setAvailability(0);
             borrowedBooks.Push_back(*b); //why still one
             AvailableBooks.pop(*b);
             borrowed++;
             available--;
             cout << "Borrowed successfully\n";
         }
}



void Library::returnBook() {
    cout << "*~~~~~~~~~~Returning a book \n";
    Book* b = borrowedBooks.search();
    if (b == nullptr)cout << "Book specified isn't available\n";
    else {
        b->setAvailability(1);
       AvailableBooks.Push_back(*b);
       borrowedBooks.pop(*b);
        borrowed--;
        available++;
        cout << "Returned successfully\n";
    }
}

void Library::displayAvailableBooks() {
    if (available == 0)cout << "\nNo available books yet\n";
    else{
        cout << "\n*~~~~~~~Available books\n";
        AvailableBooks.print();
    }
    
}

