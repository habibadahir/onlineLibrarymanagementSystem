
#include <string>
using namespace std;

class Book{
private:
  string title;
  string author;
  string isbn;
  int publishedYear;
  int totalCopies;
  int availableCopies;

public:
  Book(string t, string a, string i, int year, int copies, int available);

  string getTitle();
  string getAuthor();
  string getISBN();
  int getPublishedYear();
  int getTotalCopies();
  int getAvailableCopies();

  void setTitle(string t);
  void setAuthor(string a);
  void setISBN(string i);
  void setPublishedYear(int year);
  void setTotalCopies(int copies);
  void setAvailableCopies(int available);


  bool borrowBook();
  bool returnBook();
      
};

