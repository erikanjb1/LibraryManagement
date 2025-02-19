#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H

#include <string>
#include <iostream>
using namespace std;

class LibraryMember {
protected:
  string name;
  string memberID;
  string contactInfo;
public:
  LibraryMember();
  LibraryMember(const string& n, const string& id, const string& contact);
virtual ~LibraryMember();

  string getName() const;
  void setName(const string& name);

  string getMemberID() const;
  void setMemberID(const string& memberid);

  string getContactInfo() const;
  void setContactInfo(const string& contactinfo);

  virtual void getDetails() const;
  
};

#endif