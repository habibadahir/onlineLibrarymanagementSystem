#include <iostream>
#include "../src/Book.h"
#include "../src/User.h"
#include "../src/Library.h"

using namespace std;

int main() {
    Library library;

    /*--------- Add books ------*/
    Book b1("C++ Guide", "Smith", 2023, 1, 1);
    Book b2("Python Basics", "John", 2022, 2, 2);
    Book b3("Java Fundamentals", "David Brown", 2021, 1, 1);
    Book b4("OOP", "Davis", 2020, 1, 1);
    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);
    library.addBook(b4);

    /*-------- Add users -------*/
    User u1(101, "Zam");
    User u2(102, "Ramla");
    User u3(103, "Ayan");
    library.addUser(u1);
    library.addUser(u2);
    library.addUser(u3);

    /*------ Positive Test: Borrow book ------*/
    library.borrowBook(101, "C++ Guide"); 
    library.borrowBook(102, "Python Basics"); 
    library.borrowBook(103, "Java Fundamentals"); 

    cout << "Borrowed books after borrowing:" << endl;
    cout << "Zam: ";
    for (string book : library.users[library.getUserIndex(101)].getBorrowedBooks())
        cout << book << ", ";
    cout << endl;

    cout << "Ramla: ";
    for (string book : library.users[library.getUserIndex(102)].getBorrowedBooks())
        cout << book << ", ";
    cout << endl;

    cout << "Ayan: ";
    for (string book : library.users[library.getUserIndex(103)].getBorrowedBooks())
        cout << book << ", ";
    cout << endl;

    /* --- Negative Test:----*/
    library.borrowBook(101, "C++ Guide"); 
    library.borrowBook(102, "Python Basics"); 

    cout << "After trying to borrow already borrowed books:" << endl;
    cout << "Zam: ";
    for (string book : library.users[library.getUserIndex(101)].getBorrowedBooks())
        cout << book << ", ";
    cout << endl;

    cout << "Ramla: ";
    for (string book : library.users[library.getUserIndex(102)].getBorrowedBooks())
        cout << book << ", ";
    cout << \n;
  

    /*------ Positive Test: Return books ------*/
    library.returnBook(101, "C++ Guide");
    library.returnBook(102, "Python Basics");

    cout << "After returning some books:" << endl;
    cout << "Zam: ";
    for (string book : library.users[library.getUserIndex(101)].getBorrowedBooks())
        cout << book << ", ";
    cout << \n;

    cout << "Ramla: ";
    for (string book : library.users[library.getUserIndex(102)].getBorrowedBooks())
        cout << book << ", ";
    cout << \n;

    /*--- Negative Test-----*/
    library.returnBook(103, "Python Basics"); 
    cout << "Ayan after returning unborrowed book: ";
    for (string book : library.users[library.getUserIndex(103)].getBorrowedBooks())
        cout << book << ", ";
    cout << \n; 
  

    /* --- Positive Test: Search book exists ---*/
    int idx = library.searchBookByTitle("OOP");
    if (idx != -1) cout << "Found book: " << library.books[idx].getTitle() << \n;
    else cout << "Book not found" << \n;

    // --- Negative Test
    idx = library.searchBookByTitle("C Guide");
    if (idx != -1) cout << "Found book: " << library.books[idx].getTitle() << \n;
    else cout << "Book not found" << \n;

    return 0;
}
