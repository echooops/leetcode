'''
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

说明:
你可以认为每种硬币的数量是无限的。
'''
from typing import List
import collections

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        '''
        动态规划（自上而下）- 递归
        dp[amount] = min(dp[amount - coins[1 -> n]]) + 1
        '''
        memo = {0:0}
        def helper(n) :
            if n in memo :
                return memo[n]
            res = float('inf')
            for coin in coins:
                if n >= coin :
                    res = min(res, helper(n - coin) + 1)
            memo[n] = res
            return res
        return helper(amount) if(helper(amount) != float('inf')) else -1

    def coinChange(self, coins: List[int], amount: int) -> int:
        '''
        动态规划（自下而上）
        dp[i] = min(dp[i], dp(i − coins[1 -> n]) + 1)
        '''
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1) :
            for coin in coins :
                if i >= coin :
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return dp[-1] if(dp[-1] != float('inf')) else -1

