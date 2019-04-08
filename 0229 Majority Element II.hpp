/*
  给定一个大小为 n 的数组，找出其中所有出现超过 [ n/3 ] 次的元素。

  说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
*/

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// 摩尔投票法 扩展
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m, n, counts_m = 0, counts_n = 0;
        for (auto &e : nums) {
            if (e == m) counts_m++;
            else if (e == n) counts_n++;
            else if (!counts_m) m = e, counts_m = 1;
            else if (!counts_n) n = e, counts_n = 1;
            else counts_m--, counts_n--;
        }
        
        counts_m = counts_n = 0;
        for (auto &e : nums) {
            if (e == m)
                counts_m ++;
            if (e == n)
                counts_n ++;
        }
        
        vector<int> res;
        int counts = nums.size() / 3;
        if (counts_m > counts) res.push_back(m);
        if (counts_n > counts) res.push_back(n);
        return res;
    }
};
