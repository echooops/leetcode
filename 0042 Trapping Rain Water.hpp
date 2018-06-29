/*
  Given n non-negative integers representing an elevation map where the width of each bar is 1,
  compute how much water it is able to trap after raining.
  给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算下雨之后能接多少雨水。

  For example,
  例如，

  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
  输入 [0,1,0,2,1,0,1,3,2,1,2,1]，返回 6。

         #
     #***##*#
  _#*##*######

  上面的高度图由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示（#号部分），在这种情况下，可以接 6 个单位的雨水（*号部分）。
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // 使用栈 (虽然不容易理解，但是思路很好)
    int traps(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
    // 从两边向中间逼近并保存值
    int trap(vector<int>& height) {

        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? left_max = height[left] : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? right_max = height[right] : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
