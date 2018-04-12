/*
  Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
  给定两个以字符串表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积。

  Note:
  注意：

  The length of both num1 and num2 is < 110.
  num1 和 num2 的长度均小于110。
  Both num1 and num2 contains only digits 0-9.
  num1 和 num2 均只包含数字 0-9。
  Both num1 and num2 does not contain any leading zero.
  num1 和 num2 均不以零开头。
  You must not use any built-in BigInteger library or convert the inputs to integer directly.
  你不能使用任何内置的大整数库或直接将输入转换为整数。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    string multiply(string num1, string num2) {

        int m = num1.size(), n = num2.size();
        vector<int> product(m + n, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        string result;
        bool mark = false;
        for (int i = 0; i < m + n; i++) {
            product[i + 1] += product[i] / 10;
            product[i] %= 10;
            result.push_back(product[i] + '0');
        }

        reverse(result.begin(), result.end());
        size_t pos = result.find_first_not_of('0');
        if (pos == string::npos)
            return "0";
        return result.substr(pos);
    }
};
