/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 4:
 *    Given a string, write a function to check if it is a permutation of palindrome.
 *      A palindrome is a word or phrase that is the same forwards and backwards. A
 *      permutation is a rearrangement of letters. The palindrome does not need to
 *      be limited to just dictionary words.
 *********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

bool palindromePermutation(string);

int main(int argc, char* argv[]) {
  cout << palindromePermutation("accacc") << endl;
  cout << palindromePermutation("aaaab") << endl;
  cout << palindromePermutation("abcde") << endl;
  cout << palindromePermutation("aabbcdbbaa") << endl;
  cout << palindromePermutation("") << endl;
  return 0;
}

bool palindromePermutation(string str) {
  // How many times do I have to say it? We are assuming a 128 characterset for our hashtable
  int hashTable[128];

  // Make sure we zero out the hashtable
  for(int i = 0; i < 128; i++) {
    hashTable[i] = 0;
  }

  // Assume that our palindrome is even size
  bool odd = false; 

  // I could probably have used a ternary for identifying if the string is odd or not but it's ok
  if(str.length()%2  == 1) {
    odd = true;
  }

  // Hash all of our characters
  for(int i = 0; i < str.length(); i++) {
    hashTable[int(str[i])] += 1;
  }

  // If the value at an indice in the hashtable is odd, and we have identified odd then we want to
  //    make sure that we ok that exception and treat the rest of the hashtable as if we had an even
  //    palindrome. Likewise, if we have a value that is odd and we have not identified the palindrome
  //    as odd, we want to return false. Otherwise all return true.
  for(int i = 0; i < 128; i++) {
    if(hashTable[i] % 2 == 1 && odd) {
      odd = false;
      continue;
    } else if(hashTable[i] % 2 == 1) {
      return false;
    }
  }

  return true;
}