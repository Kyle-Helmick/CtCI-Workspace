/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 5:
 *    There are three types of edits that can be performed on strings: insert a character,
 *      remove a character, or replace a character. Given two strings, write a function to
 *      check if they are one edit (or zero edits) away.
 *********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

bool oneAway(string, string);

int main(int argc, char* argv[]) {
  cout << "Result: " << oneAway("pale", "ple") << endl;
  cout << "Result: " << oneAway("pales", "pale") << endl;
  cout << "Result: " << oneAway("pale", "bale") << endl;
  cout << "Result: " << oneAway("pale", "bake") << endl;
  cout << "Result: " << oneAway("apples", "one") << endl;
  cout << "Result: " << oneAway("", "") << endl;
  cout << "Result: " << oneAway("Iamthesame", "Iamthesame") << endl;
  return 1;
}

bool oneAway(string str1, string str2) {

  // First we know that in order for strings to be "one away" they have to be
  //    at least within one character of size
  int diff = str1.length() - str2.length();
  if(!(diff < 2 && diff > -2)) {
    return false;
  }

  bool difference_found = false;

  if(diff == 0) {
    for(int i = 0; i < str1.length(); i++) {
      if(str1[i] != str2[i] && !difference_found) {
        difference_found = true;
      } else if(str1[i] != str2[i] && difference_found) {
        return false;
      }
    }
    return true;
  } else {
    int modifier1 = 0;
    int modifier2 = 0;
    
    int shortlen = 0;

    if(str1.length() < str2.length()){
      shortlen = str1.length();
    } else {
      shortlen = str2.length();
    }

    bool difference_found = false;

    for(int i = 0; i < shortlen; i++) {
      if(str1[i+modifier1] != str2[i+modifier2] && !difference_found) {
        difference_found = true;
        if(str1[i] == str2[i+1]) {
          modifier2 += 1;
        } else if (str1[i+1] == str2[i]) {
          modifier1 += 1;
        } else {
          return false;
        }
      } else if((str1[i+modifier1] != str2[i+modifier2]) && difference_found) {
        return false;
      }
    }

  }

  if(difference_found) {
    return false;
  }
  return true;
}