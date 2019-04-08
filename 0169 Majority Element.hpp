/*
  给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 [ n/2 ] 的元素。
  
  你可以假设数组是非空的，并且给定的数组总是存在众数。
*/

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// 摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (auto &e : nums) {
            if (!counts)
                major = e;
            counts += (e == major) ? 1 : -1;
        }
        return major;
    }
};
