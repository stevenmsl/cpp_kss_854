#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol854;

/*
Input: A = "ab", B = "ba"
Output: 1
Explanation: Both S and T become "ac".
*/
tuple<string, string, int>
testFixture1()
{
  return make_tuple("ab", "ba", 1);
}

/*
Input: A = "abc", B = "bca"
Output: 2
*/
tuple<string, string, int>
testFixture2()
{
  return make_tuple("abc", "bca", 2);
}

/*
Input: A = "abac", B = "baca"
Output: 2
*/
tuple<string, string, int>
testFixture3()
{
  return make_tuple("abac", "baca", 2);
}

/*
Input: A = "aabc", B = "abca"
Output: 2
*/
tuple<string, string, int>
testFixture4()
{
  return make_tuple("aabc", "abca", 2);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << get<2>(f) << ": " << sol.minSteps(get<0>(f), get<1>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<2>(f) << ": " << sol.minSteps(get<0>(f), get<1>(f)) << endl;
}
void test3()
{
  auto f = testFixture3();
  Solution sol;
  cout << "Expect to see " << get<2>(f) << ": " << sol.minSteps(get<0>(f), get<1>(f)) << endl;
}
void test4()
{
  auto f = testFixture4();
  Solution sol;
  cout << "Expect to see " << get<2>(f) << ": " << sol.minSteps(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}