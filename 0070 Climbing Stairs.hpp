/*
  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

  注意：给定 n 是一个正整数。
*/
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// 动态规划
class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        // 1 个台阶需要 1 次
        // 2 个台阶需要 2 次
        // 3 个台阶需要从 台阶1爬1个台阶 或者 台阶2爬2个台阶
        // 以此类推
        int i = 1, j = 2, k = 3, sums = n;
        while (k++ <= n) {
            sums = i + j, i = j, j = sums;
            // sums[k] = sums[k-1] + sums[k-2];
        }
        return sums;
    }
};
