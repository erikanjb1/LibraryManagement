#include "Library_Item.h"
#include <iostream>
using namespace std;

LibraryItem::LibraryItem() {
  itemID = "";
  Title = "";
  isAvailable = true;
}
LibraryItem::LibraryItem(string id, string title, bool available) {
  itemID = id;
  Title = title;
  isAvailable = available;
}

LibraryItem::~LibraryItem() {}

string LibraryItem::getitemID() const {
  return itemID;
}
void LibraryItem::setitemID(const string& id) {
  itemID = id;
}

string LibraryItem::getTitle() const {
  return Title;
}
void LibraryItem::setTitle(const string& title) {
  Title = title;
}

bool LibraryItem::getisAvailable() const {
  return isAvailable;
}
void LibraryItem::setisAvailable(bool available) {
  isAvailable = available;
}

void LibraryItem::getDetails() const {
  cout << "ID: " << itemID << ", Title: " << Title << ", Available: " << (isAvailable ? "yes" : "no") << endl;
}