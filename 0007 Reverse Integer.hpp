/*
  Given a 32-bit signed integer, reverse digits of an integer.

  Example 1:
  Input: 123
  Output:  321

  Example 2:
  Input: -123
  Output: -321

  Example 3:
  Input: 120
  Output: 21

  Note:
  Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int reverse (int x) {
        int num = abs(x);
        long answer = 0;
        while (num != 0) {
            answer = answer * 10 + num % 10;
            if (answer > INT_MAX || answer < INT_MIN) return 0;
            num /= 10;
        }
        return x > 0 ? (int)answer : (int)-answer;
    }
    /* 还可通过跟字符串的转换来实现 */
};
