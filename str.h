class Str {
public:
  // constructor
  Str();
  // default constructor
  Str(const char *str);
  // copy constructor
  Str(const Str &ptr);
  // assignment op copy
  Str* operator=(const Str* &ptr);
  // concat
  Str operator+(const Str &ptr);
  int length();
  ~Str();
private:
  // member
  char *val;
  // char *num;
  // char *denom;
};
