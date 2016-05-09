class Solution {
public:
  static int addDigits(int num) {
    int sum = num % 10 + (num > 9 ? addDigits(num / 10) : 0);
    return sum > 9 ? addDigits(sum) : sum;
  }
};
