#include <iostream>
#include <vector>
#include "Book.h"
#include "User.h"
#include "Library.h"

using namespace std;

int main() {
    Library library;

    // --- Add books ---
    Book b1("C++ Guide", "Musa", 2023, 20, 20);
    library.addBook(b1);

    // --- Add users ---
    User u1(101, "Zam");
    library.addUser(u1);

    // --- Borrowbook ---
    library.borrowBook(101, "C++ Guide"); 

    // ---borrowed books ---
    cout << "Zam borrowed: ";
    for (string book : library.getUserIndex(101) != -1 ? library.users[library.getUserIndex(101)].getBorrowedBooks() : vector<string>{}) {
        cout << book << ", ";
    }
    cout << endl;

    // --- Return books ---
    library.returnBook(101, "C++ Guide");

    // -----borrowed books after the return ---
    cout << "After return:" << endl;
    cout << "Zam borrowed: ";
    for (string book : library.getUserIndex(101) != -1 ? library.users[library.getUserIndex(101)].getBorrowedBooks() : vector<string>{}) {
        cout << book << ", ";
    }
    cout << endl;
  

    // --- Search book by title ---
    int idx = library.searchBookByTitle("C++ Guide");
    if (idx != -1) cout << "Found book: " << library.books[idx].getTitle() << endl;
    else cout << "Book not found" << endl;

    return 0;
}
