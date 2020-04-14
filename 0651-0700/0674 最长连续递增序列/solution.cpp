#include <iostream>
#include <vector>

using namespace std;

// 动态规划 dp[i] = dp[i - 1] + 1 (dp[i] > dp[i - 1])
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        vector<int>::size_type size = nums.size();
        if (size == 0) return size;

        vector<int> dp(size, 1);

        for (int i = 1; i < size; i++) {

            if (nums[i - 1] < nums[i])
                dp[i] = dp[i - 1] + 1;
        }

        return *max_element(dp.begin(), dp.end());

    }
};


int main(int argc, char *argv[])
{
    vector<int> nums = {100, 4, 200, 1, 3, 2, 3, 5, 4, 7};
    Solution s;
    cout << s.findLengthOfLCIS(nums) << "\n";
    return 0;
}
