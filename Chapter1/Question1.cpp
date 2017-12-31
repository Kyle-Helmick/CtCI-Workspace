/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 1:
 *    Implement an algorithm to determine if a string has all unique characters.
 *    What if you cannot use additional data structures?
 *********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

bool isUnique(string);

int main(int argc, char* argv[]) {
  cout << isUnique("abc123def") << endl;
  cout << isUnique("aaa") << endl;
  cout << isUnique("") << endl;
  cout << isUnique("abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+-=[]{};':\"<>,.?/\\|~` ") << endl;
  cout << isUnique("The quick brown fox jumped over the lazy dogs") << endl;
  return 1;
}

bool isUnique(string myString) {
  // We will be assuming a character set of 128 characters
  if(myString.length() > 128) {
    return false;
  }

  if(myString.length() < 2) {
    return true;
  }

  // Create our hashtable for each letter
  bool hashTable[128];

  for(int i = 0; i < 128; i++) {
    hashTable[i] = false;
  }

  int indice = -1;

  // Loop through the characters, and cast them to integer.
  // If the hashtable at the integer is "true" then we have a duplicate  
  for(int i = 0; i < myString.length(); i++) {
    indice = int(myString[i]);
    if(hashTable[indice] == true) {
      return false;
    }
    hashTable[indice] = true;
  }
  return true;
}