#include "User.h"

User::User(int id, string name) {
    this->id = id;
    this->name = name;

}

int User::getId() {
    return id;
}
string User::getName() {
    return name; 
}
vector<string> User::getBorrowedBooks() { 
    return borrowedBooks; 
}
void User::setName(string n) {
    name = n;
}

bool User::hasBorrowed(string bookTitle) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == bookTitle) {
            return true;
        }
    }
    return false;
}

void User::borrowBook(string bookTitle) {
    if (!hasBorrowed(bookTitle)) {
        borrowedBooks.push_back(bookTitle);
    }
}

void User::returnBook(string bookTitle) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == bookTitle) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            break;
        }
    }
}
