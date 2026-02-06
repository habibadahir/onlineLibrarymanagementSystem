#include <iostream>
#include "Book.h"
#include "User.h"
#include "Library.h"

using namespace std;

int main() {
    Library library;

    // --- Add books ---
    Book b1("C++ Guide", "Musa","123-456" 2023, 20, 20);
    library.addBook(b1);

    // --- Add users ---
    User u1(101, "Zam");
    library.addUser(u1);

    // --- Borrowbook ---
    library.borrowBook(101, "C++ Guide"); 

    // ---borrowed books ---
    int userIndex = library.getUserIndex(101);
    cout << "Zam borrowed: ";
    for (string book : library.getUser(userIndex).getBorrowedBooks())
            cout << book << ", ";
   
    }
    cout << endl;

    // --- Return books ---
    library.returnBook(101, "C++ Guide");

    // -----borrowed books after the return ---
    cout << "After return:" << endl;
    cout << "Zam borrowed: ";
   if (userIndex != -1) {
        for (string book : library.getUser(userIndex).getBorrowedBooks())
            cout << book << ", ";
    }
    cout << endl;
  

    // --- Search book by title ---
     int bookIndex = library.searchBookByTitle("C++ Guide");
    if (bookIndex != -1)
        cout << "Found book: " << library.getBook(bookIndex).getTitle() << endl;
    else cout << "Book not found" << endl;

    return 0;
}
