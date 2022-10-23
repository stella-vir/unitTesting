# include <iostream>
# include <string>
# include "str.h"


using namespace std;

void test(int expecting, int actual, string test) {
  if (expecting == actual)
  {
    cout << test << " PASSED!" << endl;
  }
  else {
    cout << test << " Failed!" << endl;
    cout << "Was expecting " << expecting << " but got " << actual << endl;
  }
}

void testStrClass() {
  // Str str("");
  // test(0, str.length(), "String length 0");

  Str str("three");
  test(5, str.length(), "String length 5");

}


// g++ --std=c++11 str.cpp main.cpp -o m

int main(int argc, char const *argv[]) {
  /* code */
  testStrClass();

  // string a;
  // cin >> a;
  // cout << "Hi there " << a << endl;
  return 0;
}
