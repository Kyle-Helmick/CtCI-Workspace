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
  cout << oneAway("pale", "ple") << endl;
  cout << oneAway("pales", "pale") << endl;
  cout << oneAway("pale", "bale") << endl;
  cout << oneAway("pale", "bake") << endl;
  cout << oneAway("apples", "one") << endl;
  cout << oneAway("", "") << endl;
  cout << oneAway("Iamthesame", "Iamthesame") << endl;
  return 0;
}

bool oneAway(string str1, string str2) {

  // First we know that in order for strings to be "one away" they have to be
  //    at least within one character of size
  int diff = str1.length() - str2.length();
  if(!(diff < 2 && diff > -2)) {
    return false;
  }

  // This boolean will keep track of whether we've identified a difference
  //    or not
  bool difference_found = false;

  // Basically if the strings are the same size we just need to make sure there's
  //    only one difference between the two strings
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
    // These modifiers will help keep track of the current indices for
    //    str1 and str2
    int modifier1 = 0;
    int modifier2 = 0;
    
    int shortlen = 0;

    // We also want to use the shorter string as our "base" string so we
    //    don't have to worry about any segfaults or going out of bounds
    //    of arrays
    if(str1.length() < str2.length()){
      shortlen = str1.length();
    } else {
      shortlen = str2.length();
    }

    // This boolean will keep track of whether we've identified a difference
    //    or not
    bool difference_found = false;

    for(int i = 0; i < shortlen; i++) {
      // First if there's a difference and we haven't identified a difference yet
      if(str1[i+modifier1] != str2[i+modifier2] && !difference_found) {
        // Make sure we note that we just found a difference
        difference_found = true;
        // If string 1 is "ahead" of string 2 then we want to catch string 2 up
        if(str1[i] == str2[i+1]) {
          modifier2 += 1;
        // If string 2 is "ahead" of string 1 then we want to catch string 1 up
        } else if (str1[i+1] == str2[i]) {
          modifier1 += 1;
        // Otherwise we've found different characters where the string aligns afterwards
        //    which is similar to our first case (same length) and creates a problem because
        //    of the difference of string lengths
        } else {
          return false;
        }
      // If we find another difference the strings are not one apart
      } else if((str1[i+modifier1] != str2[i+modifier2]) && difference_found) {
        return false;
      }
    }

  }

  return true;
}