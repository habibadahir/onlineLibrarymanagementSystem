#include <string>
using namespace std;

class User {
private:
    int id;                      
    string name;                   
    vector<string> borrowBooks; 

public:
    User(int id, string name);

    int getId();
    string getName();
    vector<string> getborrowBooks();


    void setName(string n);
  
    bool hasBorrowed(const string &isbn);      
    void borrowBook(const string &isbn);       
    void returnBook(const string &isbn);
};
