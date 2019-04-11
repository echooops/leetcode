/*
  你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

  给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
*/
static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();
// 动态规划
// dp[i] = max(dp[i-1], dp[i-2] + menoy)
// 掐头算，去尾算，求最大。
class Solution {
public:
    // 减少变量的使用
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int last[6] = {0};      // 1 上一个 2 上上一个 0 交换数据
        last[1] = nums[0], last[4] = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            last[0] = last[1], last[3] = last[4];
            last[1] = max(last[1], last[2] + nums[i - 1]);
            last[4] = max(last[4], last[5] + nums[i]);
            last[2] = last[0], last[5] = last[3];
        }
        return max(last[1], last[4]);
    }
    
    int _rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        dp1[1] = nums[0];
        dp2[1] = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i-1]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        
        return max(dp1[nums.size() - 1], dp2[nums.size() - 1]);
    }
};
