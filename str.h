class Str {
public:
  Str();
  Str(const char *str);
  Str(const Str &ptr);
  Str operator=(const Str &ptr);
  Str operator+(const Str &ptr);
  int length();
  ~Str();
private:
  char *val;
};
