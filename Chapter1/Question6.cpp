/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 6:
 *    Implement a method to perform basic string compression using the counts of repeated
 *    characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
 *    "compressed" string would not become smaller than the original string, your
 *    method should return the original string You can assume the string has only
 *    uppercase and lowercase letters (a-z).
 *********************************************************************************/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string stringCompression(string);
string convertNumber(int);

int main(int argc, char* argv[]) {
  cout << "Result: " << stringCompression("aabcccccaaa") << endl;
  cout << "Result: " << stringCompression("abcdef") << endl;
  cout << "Result: " << stringCompression("aaaaaaaaaaaaaabiiiiiiiiiuouiiamnnnm") << endl;
  cout << "Result: " << stringCompression("") << endl;
  cout << "Result: " << stringCompression("a") << endl;
  return 1;
}

string stringCompression(string str) {
  // worstcase our string is "aa", "a", or "". All three of these will not be shorter
  //    with our "compression" so we will just return 
  if(str.length() < 3) {
    return str;
  }

  // Start our return string empty (we'll add into it)
  //    also start with a current character and a count to one (the mentioned character)
  string retstring = "";
  char current = str[0];
  int count = 1;

  // Iterate through the characters and treat string in sections, whenever current changes
  //    log the contents of the section that was just passed
  for(int i = 1; i < str.length(); i++) {
    if(str[i] != current) {
      retstring += current;
      retstring += convertNumber(count);
      count = 1;
      current = str[i];
    } else {
      count += 1;
    }
  }

  // Since the forloop ends before a new section change we need to make sure we still account
  //    for the last section of the string
  retstring += current;
  retstring += convertNumber(count);

  // If our "encoded" string is longer than our original string we just trash it and revert back
  //    to the original string
  if(str.length() <= retstring.length()) {
    retstring = str;
  }

  return retstring;
}

string convertNumber(int num) {
  // This is just a quick function to convert integers to strings in C++
  stringstream ss;
  ss << num;
  return ss.str();
}