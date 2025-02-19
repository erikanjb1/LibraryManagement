#include "Borrower.h"
#include "Library_Member.h"
#include <iostream>
using namespace std;


void Borrower::borrowBook(Book *book) {
  if (book->getisAvailable() && book->getCopyCount() > 0 ) {
    book->borrowCopy();
    borrowedBooks[book->getitemID()] = book->getTitle();
    cout << "Borrowed book: " << book->getTitle() << endl;
  }
    else
      cout << "Book not available" << endl;
}


void Borrower::returnBook(Book *book) {
  auto it = borrowedBooks.find(book->getitemID());
  if (it != borrowedBooks.end()) {
    book->returnCopy();
    borrowedBooks.erase(it);
    cout << "Returned book: " << book->getTitle() << endl;
  }
  else
    cout << "Book unable to return";
    
}
void Borrower::getDetails() const {
  LibraryMember::getDetails();
  cout << "Borrowed Books: " << endl;
  for (const auto&pair : borrowedBooks) {
    cout << " - " << pair.second << "(ID: " << pair.first << endl;
  }
}