/*
  Given a string, find the length of the longest substring without repeating characters.

  Examples:

  Given "abcabcbb", the answer is "abc", which the length is 3.

  Given "bbbbb", the answer is "b", with the length of 1.

  Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

  Hints:
  "滑动窗口"
  比方说 abcabccc 当你右边扫描到abca的时候你得把第一个a删掉得到bca，
  然后"窗口"继续向右滑动，每当加到一个新char的时候，左边检查有无重复的char，
  然后如果没有重复的就正常添加，
  有重复的话就左边扔掉一部分（从最左到重复char这段扔掉），在这个过程中记录最大窗口长度
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring (string s) {
        // 一个字节能表示256种可能
        vector<int> dict(256, -1); // 初始化字典
        int start = -1, maxLen = 0;
        for (string::size_type i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            if (maxLen < (i-start)) maxLen = i - start;
            // 可以通过 s.substr(start + 1, maxLen);
        }
        return maxLen;
    }
};
