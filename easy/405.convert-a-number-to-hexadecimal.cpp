/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
#include <string>
using namespace std;


class Solution {
public:
    string toHex(int num) {
    string answer, table = "0123456789abcdef";
    unsigned int n = num;
    
    do{
      answer = table[n%16] + answer;
      n = n >> 4;                              // n = n / 16
      }while(n);
	
    return answer;
  }
};
// @lc code=end

