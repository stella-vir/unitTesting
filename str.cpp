// give it time to absorb

# include "str.h"
# include <cstring>

Str::Str() {
  this->val = nullptr;
}
Str::Str(const char *str) {
  this->val = new char[strlen(str) + 1];
  strcpy(this->val, str);
  // for nullptrs
  // strcpy_s(this->val, strlen(str)+1, str);

}

Str::Str(const Str &ptr) {
  this->val = new char[strlen(ptr.val) + 1];
  strcpy(this->val, ptr.val);
  // strcpy_s(this->val, strlen(ptr.val)+1, ptr.val);
}

Str Str::operator=(const Str &ptr) {
  if (this->val != nullptr)
    delete[] this->val;
  this->val = new char[strlen(ptr.val) + 1];
  strcpy(this->val, ptr.val);
  // strcpy_s(this->val, strlen(ptr.val)+1, ptr.val);

  return *this;
}

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
