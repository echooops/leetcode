#include <iostream>

// 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

int main()
{
    Solution s;
    std::cout << std::boolalpha << s.isPowerOfTwo(1) << "\n";
    std::cout << std::boolalpha << s.isPowerOfTwo(16) << "\n";
    std::cout << std::boolalpha << s.isPowerOfTwo(218) << "\n";
    return 0;
}
