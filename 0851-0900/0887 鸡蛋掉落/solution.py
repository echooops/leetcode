'''
你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再使用它。

你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

你的目标是确切地知道 F 的值是多少。

无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
'''

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        '''
        动态规划
        状态定义：
        设 K 为鸡蛋数，N 为楼层，状态可以表示为 dp(K, N)
        当从 X 层扔鸡蛋的转移方程：
        dp(1, N) = N
        dp(K, N) = dp(K, N - X) (1<=X<=N) (没碎)
        dp(K, N) = dp(K - 1, X - 1) (1<=X<=N) (碎了)
        dp(K, N) = max(dp(K, N - X), dp(K - 1, X - 1)) (1<=X<=N) (碎或没碎)
        最小次数：
        dp(K, N) = min(max(dp(K, N - X), dp(K - 1, X - 1))) (1<=X<=N) (最小次数)
        '''
        memo = dict()
        def dp(K: int, N: int) -> int:
            if K == 1 : return N
            if N == 0 : return 0
            # 避免重复计算
            if (K, N) in memo :
                return memo[(K, N)]

            res = float('INF')  # 正无穷大
            for X in range(1, N + 1) :
                # 在 X 楼扔了一次的意思，所以需要 +1
                res = min(res, max(dp(K, N - X), dp(K - 1, X - 1)) + 1)
            # 计入备忘录
            memo[(K, N)] = res
            return res
        return dp(K, N)

    def superEggDrop(self, K: int, N: int) -> int:
        '''
        动态规划
        思路：
        1.从多少楼层多少个蛋最少要扔几次，转变为有多少个蛋扔几次可以测试出多少楼层。
        2.如果只有 1 个蛋了，蛋不能碎，只能一层一层判断，所以有 T 次机会，就只可以判断出 T + 1 层。
        3.当只有 1 次机会时，无论有多少个蛋，你能测试出的楼层都只有 2 层。（T + 1 == 2）
        4.其他情况时，递归。【可以测试的楼层】 = 【蛋碎了，机会减1次】 + 【蛋没碎，机会减1次】
        状态定义：
        设 K 为鸡蛋数，T 为尝试次数，状态可以表示为 dp(K, T)
        K 个鸡蛋 尝试 T 能测试的楼层数的转移方程：
        dp[K][T] = dp[K][T - 1] + dp[K - 1][T - 1]
        '''
        if K < 1 or N < 1 : return 0
        # 存储已经计算的结果，避免重复递归
        memo = dict()
        # 计算 K 个鸡蛋，仍 T 次，可以覆盖多少层楼
        def dp(K: int, T: int) -> int:
            if T == 1 or K == 1 :
                return T + 1
            if (K, T) in memo :
                return memo[(K, T)]
            res = dp(K - 1, T - 1) + dp(K, T - 1)
            memo[(K, T)] = res
            return res

        T = 1
        while dp(K, T) <= N :
            # 依次累加测试机会
            T += 1
        return T
