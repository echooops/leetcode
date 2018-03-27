/*
  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

  Example:

  Input: "babad"

  Output: "bab"

  Note: "aba" is also a valid answer.


  Example:

  Input: "cbbd"

  Output: "bb"
 */
#include <iostream>
#include <vector>
using namespace std;

// 这种全局执行函数，纯粹是为了刷排名
static const auto _______ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    /* 中心检测法 */
    string longestPalindrome(string s) {
        const int len = s.size();
        if (len <= 1) return s;
        /*
          start 最长回文串起始为止, max 最长回文字符串长度，
          left 左边界，right 右边界。
        */
        int start, max = 0, left, right;

        for (int i = 0; i < len && len - i > max / 2; i++) {
            left = right = i;
            while (s[i] == s[i+1] && i++ < len - 1); // 跳过重复字符串
            // 更新左边界
            right = i;
            // 向两边扩展
            while (right < len - 1 && left > 0 && s[left-1] == s[right+1])
                ++right, --left;
            // 标记并更新最大回文串
            if (max < right - left + 1) {
                start = left;
                max = right - left + 1;
                cout << start << " " << max << "\n";
            }
        }
        return s.substr(start, max);
    }
    /* 经典马拉车算法 构造T串 */
    string manacher(string s) {
        string T;
        // 构造 T 串
        for (int i = 0; i < s.size(); i++)
            T += "#" + s.substr(i, 1);
        T.push_back('#');
        // 构造 P 串
        vector<int> P(T.size(), 1);

        int center = 0, right = 0, mirror = 0;
        int maxLen = 1, resCenter = 0;
        for (int i = 0; i < P.size() ; i++) {
            mirror = (center << 1) - i; // center - (i - center)

            // 该语句是保证 O(n) 的核心算法
//            P[i] = right > i ? min(right - i, P[mirror]) : 1;
            // 因为初始化已经赋值所以以上代码可以省略
            if (right > i) P[i] = min(right - i, P[mirror]);

            // 根据已有记录P[i]向外扩张
            while (i >= P[i] && (i + P[i]) < T.size() && T[(i - P[i])] == T[(i + P[i])])
                P[i]++;
            // 更新 center 和 right (右边界)
            if (P[i] + i > right) {
                center = i;
                right = P[i] + i;
            }
            // 记录并更新最大值
            if (P[i] > maxLen) {
                maxLen = P[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - maxLen + 1) / 2, maxLen - 1);
    }
    /* 改良版 不构造T串 试试 */
    string improvedManacher(string s) {
        return s;
    }
};
