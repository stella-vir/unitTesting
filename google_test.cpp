// g++ -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1 google_test.cpp -o g
// brew install googletest
// linker command failed g++ compiler for gcc
// brew info googletest
// /usr/local/Cellar/googletest/1.12.1_1
// g++ -std=c++11 -L/usr/local/Cellar/googletest/1.12.1_1 google_test.cpp -o g
// clang++ -std=c++11 google_test.cpp -lgtest
// no main(), need to also link -lgtest_main
// /usr/bin/g++ -g google_test.cpp -std=c++11 -o g -lgtest -lgtest_main

// g++ -g google_test.cpp -std=c++11 -o g -lgtest -lgtest_main

// g++ google_test.cpp -std=c++11 -o g -lgtest -lgtest_main

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

struct BankAcct {
  int bal = 0;
  // construct
  BankAcct() {

  }
  // initialize
  explicit BankAcct(const int bal):bal{bal} {

  }
  // member func
  void deposit(int amt) {
    bal += amt;
  }
  void withdraw(int amt) {
    if (amt > 0)
      bal -= amt;
  }
  bool withdraw1(int amt) {
    if (amt <= bal) {
      bal -= amt;
      return true;
    }
    return false;
  }
};

// test fixture
struct BankAcctTest:testing::Test {
  // roll ptr / unique ptr
  // constructor
  // BankAcct acct;
  BankAcct *acct;
  BankAcctTest() {
    acct = new BankAcct;
  }
  // virtual: to reuse BankAcctTest
  virtual ~BankAcctTest() {
    delete acct;
  }

};

// test w/ func
TEST_F(BankAcctTest, Canwithdraw) {
    // BankAcct acct;
    // ptr ref
    acct->deposit(1000);
    acct->withdraw(200);
    EXPECT_EQ(800, acct->bal) << "Withdrew 200";
}

TEST_F(BankAcctTest, CanDeposit) {
    // BankAcct acct;
    // ptr ref
    acct->deposit(1000);
    EXPECT_EQ(1000, acct->bal) << "Deposited 1000";
}


// TEST_F(BankAcctTest, BankAcctStartsEmpty) {
//     // BankAcct acct;
//     // ptr ref
//     EXPECT_EQ(0, acct->bal) << "Should be equal to zero";
// }

// TEST(AcctTest, BankAcctStartsEmpty) {
//     // BankAcct acct;
//     EXPECT_EQ(0, acct.bal) << "Should be equal to zero";
// }

// TEST(MyTestSuitName, MyTestCaseName) {
//     int actual = 1;
//     EXPECT_GT(actual, 0);
//     EXPECT_EQ(1, actual) << "Should be equal to one";
// }

struct acct_state {
  int init_bal;
  int withdraw_bal;
  int total_bal;
  bool success;

  friend ostream &operator<<(ostream &os, const acct_state &obj) {
    os
      << "init " << obj.init_bal
      << " withdraw " << obj.withdraw_bal
      << " total_bal " << obj.total_bal
      << " success " << obj.success;

      return os;


  }
};

// test fixture
// inherit from BankAcctTest
// template arg acct_state to feed into
struct WithdrawAcctTest:BankAcctTest, testing::WithParamInterface<acct_state> {

  // initialize
  WithdrawAcctTest() {
    acct->bal = GetParam().init_bal;

  }
};

// test w/ param
TEST_P(WithdrawAcctTest, TotalBal) {
  auto para = GetParam();
  auto success = acct->withdraw1(para.withdraw_bal);
  EXPECT_EQ(para.total_bal, acct->bal) << "Para.total_bal";
  // default: para.success set instantiate -> true
  // acct->withdraw1 -> false
  EXPECT_EQ(para.success, success) << "Successfully withdrew";

}

// provide the para
// cartesian matrix/ list
// (prefix-a set of data, name, generator)
INSTANTIATE_TEST_SUITE_P(Default, WithdrawAcctTest, testing::Values(
  // don't get personal
  acct_state{3000, 2000, 1000, true},
  acct_state{3000, 5000, 3000, false}

));

// ugh, ugly
int main(int argc, char *argv[]) {
  /* code */
  // int* argc, char** argv
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
