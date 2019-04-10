/*
  给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

  如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

  注意你不能在买入股票前卖出股票。
*/
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = numeric_limits<int>::max(), profit = 0;
        for (auto &e: prices) {
            if (min > e) min = e;
            else if (e - min > profit)
                profit = e - min;
        }
        return profit;
    }
};
