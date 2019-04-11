/*
  给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 */
static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();

// 动态规划 dp[i] = max(0, dp[i-1]) + num[i];

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;
        vector<int> dp(size + 1, nums[0]);
        for (int i = 1; i < size; i++) {
            dp[i] = max(0 , dp[i-1]) + nums[i];
            dp[size] = max(dp[i], dp[size]);
        }
        return dp[size];
    }
};
