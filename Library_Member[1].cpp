#include "Library_Member.h"
using namespace std;

LibraryMember::LibraryMember() {
  name = "";
  memberID = "";
  contactInfo = "";
}

LibraryMember::LibraryMember(const string& n, const string& id, const string& contact) {
  name = n;
  memberID = id;
  contactInfo = contact;
}
LibraryMember::~LibraryMember() {}

string LibraryMember::getName() const {
  return name;
}
void LibraryMember::setName(const string &name) {
  this->name = name;
}

string LibraryMember::getMemberID() const {
  return memberID;
}
void LibraryMember::setMemberID(const string &memberid) {
  memberID = memberid;
}

string LibraryMember::getContactInfo() const {
  return contactInfo;
}
void LibraryMember::setContactInfo(const string &contactinfo) {
  contactInfo = contactinfo;
}

void LibraryMember::getDetails() const {
  cout<< "Name: " << name << ", Member ID: " << memberID <<
    ", Contact Info: " << contactInfo << endl;
}