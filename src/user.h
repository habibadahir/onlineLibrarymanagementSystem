#include <vector>
using namespace std;

class User {
private:
    int id;                      
    string name;                   
    vector<string> borrowedBooks; 

public:
    User(int id, string name);

    int getId();
    string getName();
    vector<string> getborrowedBooks();


    void setName(string n);

bool hasBorrowed(string bookTitle);
void borrowBook(string bookTitle);
void returnBook(string bookTitle);
};
