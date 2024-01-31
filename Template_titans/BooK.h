#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include <sstream>
using namespace std;
class Book {
public:
	Book(int ISBN = 0) {
		this->ISBN = ISBN;
	}
	void read();
	void display();// modify to >> operator and << operator
	void edit();
	bool isAvailable()const;//we need to know if it borrowed or not
	size_t getIsBN();
	//string readFromFile(const string& filename);////update
	string get(const string&);
	void setAvailability(int);
	Book& operator= (const Book& other);
	friend std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << "===========Book Information=====================\n";
		os << "Title: " << book.title << " ||Author: " << book.author << " ||ISBN: " << book.ISBN << " ||Genre: " << book.genre << " ||Available: "<<book.isAvailable() << "\n\n";
		return os;
	}

	/*string operator[](string s) {//author
		//return  "Author : "+ author +"\tTitle : "+ title +"\tGenre : " +genre +"ISBN : "+ to_string(ISBN)+"Available: "+to_string(available);
		return get(s);
	}*/

	bool operator >(const Book& other) const;

	bool operator <(const Book& other) const;

	bool operator ==(const Book& other) const;

	bool operator >=(const Book& other) const;

	bool operator <=(const Book& other) const;
private:
	string title;
	string author;
	size_t ISBN;
	string genre;

	bool available = 1;
};

