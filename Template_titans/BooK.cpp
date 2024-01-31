#include"BooK.h"
void Book::read() {
	cout << "*****************Enter Book details********************\n";
	cout << " Title: ";
	cin >> title;
	cout << " Author: ";
	cin >> author;
	cout << " ISBN: ";
	cin >> ISBN;
	cout << " Genre: ";
	cin >> genre;
}
void Book::display() {
	cout << "===========Book Information=====================\n";
	cout << "Title:" << title << " ||Auhtor: " << author << " ||ISBN: " << ISBN << " ||Genre: " << genre << endl << endl;
}
void Book::edit() {
	cout << "what do you want to edit: 1/Title..2/Author..3/ISBN..4/genre ";
	int c;
A:
	cin >> c;
	switch (c) {
	case 1:
		cin >> title;
		cout << "title after edit: " << title;
		break;
	case 2:
		cin >> author;
		cout << "author after edit: " << author;
		break;
	case 3:
		cin >> ISBN;
		cout << "ISBN after edit: " << ISBN;
		break;
	case 4:
		cin >> genre;
		cout << "genre after edit: " << genre;
		break;
	default:
		cout << "wrong input try again:)";
		goto A;
	}

}
bool Book::isAvailable()const {
	return available;
}
size_t Book::getIsBN() {
	return ISBN;
}
/*string Book::readFromFile(const string& filename) {
	std::ifstream inFile(filename);
	std::string data;
	if (inFile.is_open()) {
		std::getline(inFile, data);
		inFile.close();
	} else {
		std::cerr << "Failed to open the file for reading-.-" << std::endl;
	}
	return data;
}*/


string Book::get(const string& s) {
	return (s == "Author") ? author : (s == "Title") ? title : (s == "Genre") ? genre 
		: (s == "ISBN") ? to_string(ISBN) : "your request isn't found";
}

void Book::setAvailability(int n) {
	available = n;
}

bool Book::operator >(const Book& other) const {
	return ISBN > other.ISBN;
}

bool Book::operator <(const Book& other) const {
	return ISBN < other.ISBN;
}

bool Book::operator ==(const Book& other) const {
	return ISBN ==other.ISBN;
}

bool Book::operator >=(const Book& other) const {
	return ISBN >= other.ISBN;
}

bool Book::operator <=(const Book& other) const {
	return ISBN > other.ISBN;
}

Book& Book :: operator= (const Book& other)
{
	title = other.title;
	ISBN = other.ISBN;
	author = other.author;
	genre = other.genre;
	return *this;
}