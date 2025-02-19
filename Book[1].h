#ifndef BOOK_H
#define BOOK_H

#include "Library_Item.h"
#include <string>
#include <iostream>

using namespace std;

class Book : public LibraryItem {
private:
  string author;
  string genre;
  int copyCount;
  int totalCopies;
public:
  Book();
  Book(string id, string title, string author,
  string genre, int copies);

  string getAuthor() const;
  void setAuthor(const string& author);

  string getGenre() const;
  void setGenre(const string& genre);

  int getCopyCount() const;
  void setCopyCount(int count);

  int getTotalCopies() const;
  void setTotalCopies(int total);

  void borrowCopy();
  void returnCopy();

  void saveToFile(ofstream& outFile) override;
  void loadFromFile(ifstream& inFile) override;
  void getDetails() const override;
};

#endif