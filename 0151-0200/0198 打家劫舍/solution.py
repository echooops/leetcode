'''
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

'''
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        '''
        状态定义：
        设动态规划列表dp，dp[i]代表前i个房子在满足条件下的能偷窃到的最高金额。
        转移方程：
        dp[i] = dp[i - 1] (不偷)
        dp[i] = dp[i - 2] + nums[i] (偷)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]) (偷或者不偷)
        '''
        n = len(nums)
        if n == 0 : return 0
        elif n == 1 : return nums[0]
        dp = n * [0]
        dp[0], dp[1] = nums[0], max(nums[:2])
        for i in range(2, n) :
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        return dp[-1]

    def rob(self, nums: List[int]) -> int:
        '''
        分析上面过程，发现：
        下一次获利 = 最大值（当前获利， 上一次获利 + 本次利益）
        cur : 为当前获利
        pre : 为上一次获利
        '''
        cur, pre = 0, 0
        for num in nums:
            cur, pre = max(cur, pre + num), cur
        return cur

