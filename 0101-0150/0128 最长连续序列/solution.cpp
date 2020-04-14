#include <iostream>
#include <vector>


using namespace std;

/*
 * 动态规划:
 * dp[i] = dp[i - 1] + 1 (nums[i] == nums[i - 1] + 1)
 * dp[i] = dp[i - 1]     (nums[i] == nums[i - 1])
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(size, 1);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == 1) {
                dp[i] = dp[i - 1] + 1;
            } else if (nums[i] == nums[i-1]) {
                dp[i] = dp[i - 1];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
