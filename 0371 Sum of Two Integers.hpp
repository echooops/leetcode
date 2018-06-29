/*
  Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
  不使用运算符 + 和 -，计算两整数a 、b之和。

  Example:
  Given a = 1 and b = 2, return 3.
*/

// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};
