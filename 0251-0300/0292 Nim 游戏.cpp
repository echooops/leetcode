#include <iostream>
/* 解答
 *
 * 这是道有趣的智力题。我们首先考虑什么情况下能赢，从示例可以看到，当只剩下4块石头时，轮到谁拿谁输，因为另一个人总是可以把剩下的石头全部拿完。
 *
 * 那么胜利目标就成为希望自己拿走石头后保证还剩4块石头，怎样才能做到呢？同样的道理，只需要还剩8块石头的时候轮到了对方拿，那么不管对方拿多少，1个2个或者3个，自己拿的时候都可以保证只剩4块石头，那怎么保证还剩8块石头的时候轮到了对方拿呢……
 *
 * 综上，我们可以得出，只要我们能够保证自己这轮拿走石头后，剩余的石头个数是4的整数倍，这时轮到谁拿谁输，就可以逼死队友，这样问题就很简单，如果给定的石头个数不是4的整数倍，那么这种情况就稳胜，否则就会输（如果队友掌握了以上技巧的话）。
*/
class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4) return true;
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.canWinNim(13) << "\n";
    return 0;
}
