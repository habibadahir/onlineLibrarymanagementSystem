
#include "Book.h"
#include <string>
using namespace std;
Book::Book(string t, string a, string i, int year, int copies, int available){
  title = t;
  author = a;
  isbn = i;
  publishedYear = year;
  totalCopies = copies;
  availableCopies = available;
  
}
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getISBN() { return isbn; }
int Book::getPublishedYear() { return publishedYear; }
int Book::getTotalCopies() { return totalCopies; }
int Book::getAvailableCopies() { return availableCopies; }

void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }
void Book::setISBN(string i) { isbn = i; }
void Book::setPublishedYear(int year) { publishedYear = year; }
void Book::setTotalCopies(int copies) { totalCopies = copies; }
void Book::setAvailableCopies(int available) { availableCopies = available; }



bool Book::borrowBook(){
  if (availableCopies > 0){
    availableCopies--;
    return true;
  }
  return false;
  
}

bool Book::returnBook(){
  if (availableCopies < totalCopies){
    availableCopies++;
    return true;
  }
  return false;
  
}
