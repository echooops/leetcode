/*
  你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

  给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
*/

static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();
// 动态规划 偷或者不偷
// 到第i家偷:i-2家之前最大所得加本次所得。不偷:保持i-1家之前所得。
// dp[i] = max(dp[i-1], dp[i-2] + menoy)
class Solution {
public:
    // 减少多余变量
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int last[3] = {0};      // 1 上一个 2 上上一个 0 交换数据
        last[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            last[0] = last[1];
            last[1] = max(last[1], last[2] + nums[i]);
            last[2] = last[0];
        }
        return last[1];
    }
    
    int _rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1 , 0);
        if (nums.size() == 0) return 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        return dp[nums.size()];
    }
};
