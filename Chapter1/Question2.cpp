/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 2:
 *    Given two strings, write a method to decide if one is a permutation of the other.
 *********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

bool checkPermutation(string, string);

int main(int argc, char* argv[]) {
  cout << checkPermutation("Hello", "ellHo") << endl;
  cout << checkPermutation("oranges", "apples") << endl;
  cout << checkPermutation("thequickbrownfox", "quickfoxthebrown") << endl;
  cout << checkPermutation("", "1") << endl;
  cout << checkPermutation("", "") << endl;
  cout << checkPermutation("CaseSensitive", "casesensitive") << endl;
  return 0;
}

bool checkPermutation(string str1, string str2) {
  // We know that if the strings aren't the same length
  //    then one isn't a permutation of the other
  if(str1.length() != str2.length()) {
    return false;
  }

  // We will be assuming a 128 character set for possible
  //    characters again (in reference to Question1)

  int str1hash[128];
  int str2hash[128];

  // Zero out the hashtables

  for(int i = 0; i < 128; i++) {
    str1hash[i] = 0;
    str2hash[i] = 0;
  }

  for(int i = 0; i < str1.length(); i++) {
    str1hash[int(str1[i])] += 1;
    str2hash[int(str2[i])] += 1;
  }

  for(int i = 0; i < 128; i++) {
    if(str1hash[i] != str2hash[i]) {
      return false;
    }
  }

  return true;

}