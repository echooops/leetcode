#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 贪心 O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto &e : nums) {
            auto iter = lower_bound(res.begin(), res.end(), e);
            if (iter == res.end()) res.push_back(e);
            else *iter = e;
        }
        return res.size();
    }
    // 动态规划 O(n2)
    // dp[i] = max(dp[i], dp[j] + 1) (dp[i] > dp[j] && i > j)
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);

        return *max_element(dp.begin(), dp.end());
    }
};


int main(int argc, char *argv[])
{
    vector<int> nums = {4, 10, 4, 3, 8, 9};

    Solution s;
    int len = s.lengthOfLIS(nums);
    cout << len << "\n";
    len = s.lengthOfLIS2(nums);
    cout << len << "\n";
    return 0;
}
