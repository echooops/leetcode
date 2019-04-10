/*
  给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

  设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

  注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();

// 动态规划公式
// dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
class Solution {
public:
    // 由于 dp[k][i] i 和 dp[k][i] 成正比，只需记录一个最大值即可。
    // 这里需要把循环颠倒一下，为了同步dp[k] dp[k-1] 在同一个 i 位置。
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int dp[3] = {0}, diff[3];
        for (int k = 1; k <= 2; k++)
            diff[k] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            for (int k = 1; k <= 2; k++) {
                diff[k] = min(diff[k], prices[i] - dp[k-1]);
                dp[k] = max(dp[k], prices[i] - diff[k]);
            }
        }
        return dp[2];
    }
    // 发现寻找落差的循环没有必要，优化循环
    int _maxProfit(vector<int>& prices) {
        int dp[3][prices.size()];
        memset(dp[0], 0, 3 * sizeof(int) * prices.size());
        for (int k = 1; k <= 2; k++) {
            int diff = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                diff = min(diff, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - diff);
            }
        }
        return dp[2][prices.size() - 1];
    }
    // 根据动态规划公式所得
    int __maxProfit(vector<int>& prices) {
        int dp[3][prices.size()];
        memset(dp[0], 0, sizeof(int) * prices.size());
        for (int k = 1; k <= 3; k++) {
            for (int i = 1; i < prices.size(); i++) {
                int diff = prices[0];
                // 节省一次机会，找一次可能。需要找到一个落差
                for (int j = 1; j <= i; j++)
                    diff = min(diff, prices[j] - dp[k-1][j-1]);
                // 确认这次可能，这个落差后涨幅较高
                dp[k][i] = max(dp[k][i-1], prices[i] - diff);
            }
        }
        return dp[2][prices.size() - 1];
    }
};
