
#include "Library.h"

/* ---------Book Management --------*/

void Library::addBook(Book book) {
    books.push_back(book);
}

void Library::removeBook(string bookTitle) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == bookTitle) {
            books.erase(books.begin() + i);
            break;
        }
    }
}

int Library::searchBookByTitle(string title) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            return i;
        }
    }
    return -1; 
}

vector<int> Library::searchBookByAuthor(string author) {
    vector<int> results;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getAuthor() == author) {
            results.push_back(i);
        }
    }
    return results;
}

/* --- User Management ---*/

void Library::addUser(User user) {
    users.push_back(user);
}

void Library::removeUser(int userId) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == userId) {
            users.erase(users.begin() + i);
            break;
        }
    }
}

int Library::getUserIndex(int userId) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == userId) {
            return i;
        }
    }
    return -1; 
}

/*--- Borrow/Return Books---*/

void Library::borrowBook(int userId, string bookTitle) {
    int uIndex = getUserIndex(userId);
    int bIndex = searchBookByTitle(bookTitle);
    if (uIndex != -1 && bIndex != -1) {
        if (books[bIndex].getAvailableCopies() > 0) {
            books[bIndex].borrowBook();
            users[uIndex].borrowBook(bookTitle);
        }
    }
}

void Library::returnBook(int userId, string bookTitle) {
    int uIndex = getUserIndex(userId);
    int bIndex = searchBookByTitle(bookTitle);
    if (uIndex != -1 && bIndex != -1) {
        books[bIndex].returnBook();
        users[uIndex].returnBook(bookTitle);
    }
}
