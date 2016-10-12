// https://leetcode.com/problems/add-binary/

/*
  Given two binary strings, return their sum (also a binary string).

  For example,
  a = "11"
  b = "1"
  Return "100".
*/

#include <string>

using std::string;

class Solution {
public:
  string addBinary(string a, string b) {
    int carry = 0;
    string s = "";
    int num1 = a.size() - 1;
    int num2 = b.size() - 1;
    
    while(num1 >= 0 || num2 >= 0 || carry == 1) {
      // Add a[num1] to carry. If num1 dips below 0, add 0
      carry += num1 >= 0 ? a[num1--] - '0' : 0;
      
      // Add a[num2] to carry. If num2 dips below 0, add 0
      carry += num2 >= 0 ? b[num2--] - '0' : 0;

      // Append carry % 2 to the front of the string
      s = char(carry % 2 + '0') + s;

      // If carry is 2 sets it to 1 and otherwise 0
      carry /= 2;
    }
        
    return s;
  }
};
