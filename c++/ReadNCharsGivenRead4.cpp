// https://leetcode.com/problems/read-n-characters-given-read4/

/*
  The API: int read4(char *buf) reads 4 characters at a time from a file.

  The return value is the actual number of characters read. 
  For example, it returns 3 if there is only 3 characters left in the file.

  By using the read4 API, implement the function int read(char *buf, int n) 
  that reads n characters from the file.
*/

#include <algorithm>

// Forward declaration of the read4 API.
int read4(char* buf);

class Solution {
public:
  int read(char* buf, int n) {
    int total = 0;
    for (int i = 0; i < n / 4; ++i) total += read4(buf + total);
    int remain = n - total;
    if (remain) {
      int read = read4(buf + total);
      return total + std::min(read, remain);
    }
    return n;
  }
};
