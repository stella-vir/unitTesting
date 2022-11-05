# include <iostream>
# include <string>
# include "str.h"


using namespace std;

void test_length(int expecting, int actual, string test) {
  if (expecting == actual)
  {
    cout << test << " PASSED!" << endl;
  }
  else {
    cout << test << " Failed!" << endl;
    cout << "Was expecting " << expecting << " but got " << actual << endl;
  }
}

// operator= __str__ __repr__ ptr
/*
void test_operator(Str& expecting, Str& actual, string test) {
  if (expecting == actual)
  {
    cout << test << " PASSED!" << endl;
  }
  else {
    cout << test << " Failed!" << endl;
    cout << "Was expecting " << expecting << " but got " << actual << endl;
  }
}
*/

void testStrClass() {
  // test length()
  // Str str("");
  // test_length(0, str.length(), "String length 0");

  Str str("three");
  test_length(5, str.length(), "String length 5");


  // test operator=()
  // test_operator(*this, str.operator=(const Str str), "Strings copied ");
}


// g++ --std=c++11 str.cpp main.cpp -o m

int main(int argc, char const *argv[]) {
  /* code */
  testStrClass();
  // copying
  // const Str str_const;
  // Str s(str_const);

//  indirection requires pointer operand ('Str' invalid)
  // Str *w, *z;
  // The assignment w = z calls the user-defined operator A::operator=(A&)
  // *w->operator=(*z);
  // Str *pval1 = new Str(3);

  // Str& s1 = *ptr1;
  // Str& s2 = *ptr2;

  // string a;
  // cin >> a;
  // cout << "Hi there " << a << endl;
  return 0;
}
