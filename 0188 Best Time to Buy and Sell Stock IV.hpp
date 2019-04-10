/*
  给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

  设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

  注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();

// 动态规划公式
// dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        // 问题简化为 122 “只求上山路程”
        if (k >= prices.size() / 2) { 
            int profit = 0;
            for (int i = 1; i < prices.size(); ++i)
                profit += prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0;
            return profit;
        }
        
        vector<int> dp(k + 1, 0);
        vector<int> diff(k + 1, prices[0]);

        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                diff[j] = min(diff[j], prices[i] - dp[j-1]);
                dp[j] = max(dp[j], prices[i] - diff[j]);
            }
        }
        return dp.back();
    }

	int _maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        // 问题简化为 122 “只求上山路程”
        if (k >= prices.size() / 2) { 
            int profit = 0;
            for (int i = 1; i < prices.size(); ++i)
                profit += prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0;
            return profit;
        }

		vector<int> buy(k + 1, numeric_limits<int>::min()), sell(k + 1, 0);
        
		for (auto &price : prices) {
			for (int j = 1; j <= k; j++)
			{
				buy[j] = max(buy[j], sell[j - 1] - price);
				sell[j] = max(sell[j], buy[j] + price);
			}
        }
        
		return sell.back();
	}
};
