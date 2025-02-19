#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <string>
#include <fstream>
using namespace std;

//base class for book
class LibraryItem {
protected:
  string itemID;
  string Title;
  bool isAvailable;

public:
  LibraryItem(); //default constructor
  LibraryItem(const string id, const string title, bool available = true); //constructor with parameters
  virtual ~LibraryItem(); //destructor
  //all getters and setters
  string getitemID() const;
  void setitemID(const string& id);

  string getTitle() const;
  void setTitle(const string& title);

  bool getisAvailable() const;
  void setisAvailable(bool available);
  //pure virtual functions
  virtual void getDetails() const = 0;
  virtual void saveToFile(ofstream& outFile) = 0;
  virtual void loadFromFile(ifstream& inFile) = 0;
};

#endif