#include "Book.h"
#include "Borrower.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

vector<Book*> libraryBooks;

void addBook() {
  string id, title, author, genre;
  int copies;
  
  cout << "Enter book ID: ";
  cin >> id;
  cout << "Enter book title: ";
  cin.ignore();
  getline(cin, title);
  cout << "Enter book author: ";
  getline(cin, author);
  cout << "Enter book genre: ";
  getline(cin, genre);
  cout << "Enter total copies: ";
  cin >> copies;
  cin.ignore();
  
  Book* book = new Book(id, title, author, genre, copies);
  libraryBooks.push_back(book);
  
  ofstream
  outFile("Librarybook.txt");
  for (Book* book : libraryBooks) {
    book->saveToFile(outFile);
  }

  outFile.close();
  cout << "Book: "<< "'" << title << "'" << "added successfully"<< endl;
}
void borrowBook(Borrower& borrower) {
  string id;
  cout << "Enter book ID to borrow: ";
  cin >> id;
  
  for (Book*book :libraryBooks) {
    if (book-> getitemID() == id) {
      borrower.borrowBook(book);
       return;
    }
  }
  cout << "Book not in system. " << endl;
}

void returnBook(Borrower &borrower) {
  string id;
  cout << "Enter Book ID to return: ";
  cin >> id;

  for (Book* book : libraryBooks) {
    if (book->getitemID() == id) {
      borrower.returnBook(book);
      return;
    }
  }
  cout << "Book not found in system" << endl;
}
int searchBook(const vector <Book*>& books) {
  string itemid;
  cout << "Enter book ID to search: ";
  cin.ignore();
  getline(cin, itemid);
  for (size_t i = 0; i < books.size(); i++){
    if (books[i]->getitemID() == itemid) {
      cout << "Book Details: " << endl;
      books[i]->getDetails();
      return i;
    }
  }
  cout << "Book not found in system"<< endl; 
  return -1;
}
void saveLibraryData(const vector<Book*>& libraryBooks, const string& filename) {
  ofstream outfile(filename);
  if (outfile.is_open()) {
    for (const Book* book : libraryBooks) {
      outfile << book->getitemID() << "," << book->getTitle() << "," << book->getAuthor() << "," << book->getGenre() << endl;
  }
    outfile.close();
} else {
    cerr << "Could not open file" << endl;
}
}

void removeBook(vector<Book*>& Librarybooks) {
  string removeID;
  cout << "Enter book title to remove: ";
  cin.ignore();
  getline(cin, removeID);
  for (size_t i = 0; i < Librarybooks.size(); i++) {
    if (Librarybooks[i]->getTitle() == removeID) {
      delete Librarybooks[i];
      Librarybooks.erase(Librarybooks.begin() + i);
      cout << "Book removed successfully" << endl;
      saveLibraryData(Librarybooks, "Librarybook.txt");
      return;
    }
  }
  cout << "Book not found in system" << endl;
}

void saveToFile() {
  ofstream outFile("Librarybook.txt");
  for (const auto& book : libraryBooks) {
    book->saveToFile(outFile);
  }
  outFile.close();
  cout << "Library data saved" << endl;
}

void loadFromFile() {
  ifstream inFile("Librarybook.txt");
  while (inFile) {
    Book* book = new Book();
    book->loadFromFile(inFile);
    if (inFile) libraryBooks.push_back(book);
  }
  inFile.close();
  cout << "Library data loaded" << endl;
}

int main() { 
  Borrower borrower("Jane Doe", "a001", "jane.doe@examplemail.com");
  loadFromFile();

  int number;
  do {
  cout <<"|" << "Library Management System"<< endl;
  cout << "|1. Add Book" << endl;
  cout << "|2. Borrow Book" << endl;
  cout << "|3. Return Book" << endl;
  cout << "|4. Search Book" << endl;
  cout << "|5. Remove Book" << endl;
  cout << "|6. Save and Exit " << endl;
  cout << "|Enter number choice: ";
  cin >> number;

    switch (number) {
      case 1:
        addBook();
        break;
      case 2:
        borrowBook(borrower);
        break;
      case 3: 
        returnBook(borrower);
        break;
      case 4:
        searchBook(libraryBooks);
        break;
      case 5:
        removeBook(libraryBooks);
        break;
      case 6:
        saveToFile();
        break;
      default:
        cout << "Invalid, try again." << endl;
    }
  } while (number != 6);
  
  for (auto book : libraryBooks) {
    delete book;
  }
  return 0;
  
}