/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 3:
 *    Write a method to replace all spaces in a string with '%20' you may assume that
 *        the string has sufficient space at the end to hold the additional characters,
 *        and that you are given the :true" length of the string. (Note: If implementing
 *        in Java, please use a character array so that you can perform this operation in
 *        place.
 *********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

string URLify(string, int);

int main(int argc, char* argv[]) {
  cout << URLify("Mr John Smith    ", 13) << endl;
  cout << URLify("KyleHelmick", 11) << endl;
  cout << URLify("         ", 3) << endl;
  cout << URLify("", 0) << endl;
  return 0;
}

string URLify(string str, int trueLength) {
  // We start at the end of the true string and move each character to the
  //    end of the actual string
  int position = str.length()-1;

  for(int i = trueLength-1; i >= 0; i--) {
    if(str[i] != ' ') {
      str[position] = str[i];
      position--;
    } else {
      str[position] = '0';
      position--;
      str[position] = '2';
      position--;
      str[position] = '%';
      position--;
    }
  }

  return str;
}