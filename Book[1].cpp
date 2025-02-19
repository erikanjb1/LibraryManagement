#include "Book.h"
#include "Library_Item.h"
#include <iostream>
using namespace std;

Book::Book() {
  copyCount = 0;
  totalCopies = 0;
}

Book::Book(string id, string title, string author, string genre, int copies) {
  itemID = id;
  Title = title;
  this->author=author;
  this->genre=genre;
  this->copyCount = copies;
  this->totalCopies = copies;
}

string Book::getAuthor() const {
   return author;
}
void Book::setAuthor(const string& author) {
  this->author = author;
}

string Book::getGenre() const {
  return genre;  
}
void Book::setGenre(const string& genre) {
  this->genre = genre;
}

int Book::getCopyCount() const {
  return copyCount;
}
void Book::setCopyCount(int count) {
  this->copyCount = count;
}

int Book::getTotalCopies() const {
  return totalCopies;
}
void Book::setTotalCopies(int total) {
  this->totalCopies = total;
}
void Book::borrowCopy() {
  if (copyCount > 0)
    copyCount--;
}
void Book::returnCopy() {
  if (copyCount < totalCopies)
    copyCount++;
}

void Book::saveToFile(ofstream& outFile) {
  outFile << itemID << "," << Title << "," << author << "," << genre << ","
  << copyCount << "," << totalCopies << endl;
}

void Book::loadFromFile(ifstream &inFile) {
  getline(inFile, itemID, ',');
  getline(inFile, Title, ',');
  getline(inFile, author, ',');
  getline(inFile, genre, ',');
  inFile >> copyCount;
  inFile.ignore(); // Ignore any commas
  inFile >> totalCopies;
  inFile.ignore(); // Ignore newlines
}

void Book::getDetails() const {
  cout << "ID: " << itemID << endl;
  cout << ", Title: " << Title << endl;
  cout <<  ", Author: " << author << endl;
  cout << ", Genre: " << genre << endl;
  cout << ", Available Copies: " << copyCount << endl;
}