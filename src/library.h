
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;

class Library {
private:
    vector<Book> books; 
    vector<User> users; 

public:
    void addBook(Book book);
    void removeBook(string bookTitle);
    int searchBookByTitle(string title); 
    vector<int> searchBookByAuthor(string author); 

    void addUser(User user);
    void removeUser(int userId);
    int getUserIndex(int userId); 

    void borrowBook(int userId, string bookTitle);
    void returnBook(int userId, string bookTitle);
};
