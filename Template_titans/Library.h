#pragma once
#include "Book.h"
#include"Container.h"
#include <chrono>
#include <thread>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
class Library {
    Container<Ilist<Book>> Bookcatalog;
    Container<Ilist<Book>> borrowedBooks;
    Container<Ilist<Book>> AvailableBooks;
    size_t borrowed;
    size_t available;
    size_t size;
    Book* search();
public:
    Library();
    void add_book(Book&);
    void remove_book();
    void Search();
    void borrow();
    void sortAscending();
    void sortDescending();
    void book_statistics();
    void display();
    void displayBorrowedBooks();
    void returnBook();
    void displayAvailableBooks();
};




