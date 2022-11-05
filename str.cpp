// give it time to absorb

# include "str.h"
# include <cstring>
#include <iostream>

using namespace std;

// constructor
Str::Str() {
  this->val = nullptr;
}
Str::Str(const char *str) {
  // new: specify lifetime delete
  // + 1: complier \0 null char 
  this->val = new char[strlen(str) + 1];
  strcpy(this->val, str);
  // for nullptrs
  // strcpy_s(this->val, strlen(str)+1, str);

}

Str::Str(const Str &ptr) {
  this->val = new char[strlen(ptr.val) + 1];
  cout << "Copy constructor B(const B&, int)" << endl;

  strcpy(this->val, ptr.val);
  // strcpy_s(this->val, strlen(ptr.val)+1, ptr.val);
}

// assign, need to delete other than copy
// to clear the memory before assigning other
// Str-return type
//Str-qualifier, specify where operator= is stored and accessed
// like an adjective
Str* Str::operator=(const Str* &ptr) {
  if (this->val != nullptr)
    delete[] this->val;
  // this->val = new char[strlen(ptr.val) + 1];
  this->val = new char[strlen(ptr->val) + 1];

  // strcpy(this->val, ptr.val);
  strcpy(this->val, ptr->val);
  //
  // num = ptr->num;
  // denom = ptr->denom;
  // +1 the last null char
  // strcpy_s(this->val, strlen(ptr.val)+1, ptr.val);
  // cout << "A& A::operator=(const A&)" << endl;
  // cout << *this << " *this type" << endl;
  // return val
  // return *this;
  return this;

}


// test might fail
Str Str::operator+(const Str &ptr) {
  Str str1 = Str(this->val);
  return str1;
}

int Str::length() {
  if (this->val == nullptr)
    return 0;
  return strlen(this->val);
}

Str::~Str() {
  if (this->val != nullptr)
    delete[] this->val;
}
