#ifndef BORROWER_H
#define BORROWER_H

#include "Library_Member.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;
 
class Borrower : public LibraryMember {
private: 
  map<string, string> borrowedBooks;
public:
  Borrower();
  Borrower(const string& n, const string& id, const string& contact) : 
  LibraryMember(n, id, contact) {}

  void borrowBook(Book* book);
  void returnBook(Book* book );
  void getDetails() const override;

};

#endif