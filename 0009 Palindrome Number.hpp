/*
  Determine whether an integer is a palindrome. Do this without extra space.
  判断一个整数是否是回文数。不能使用辅助空间。

  Some hints:
  一些提示:

  Could negative integers be palindromes? (ie, -1)
  负整数可以是回文数吗？（例如 -1）

  If you are thinking of converting the integer to string, note the restriction of using extra space.
  如果你打算把整数转为字符串，请注意不允许使用辅助空间的限制。

  You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
  你也可以考虑将数字颠倒。但是如果你已经解决了 “颠倒整数” 问题的话，就会注意到颠倒整数时可能会发生溢出。你怎么来解决这个问题呢？

  There is a more generic way of solving this problem.
  本题有一种比较通用的解决方式。
*/
#include <iostream>

// 这种全局执行函数，纯粹是为了刷排名
static const auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int revertedNumber = 0;
        while (x > revertedNumber) { // 因为回文特性，这里实际上只需处理一半数字
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10; // 处理奇数和偶数两种可能
    }
};
