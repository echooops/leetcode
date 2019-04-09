/*
  给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

  说明:

  初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
  你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 */
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n)
            if (!m || nums1[m - 1] < nums2[n - 1])
                nums1[m + n - 1] = nums2[n - 1], --n;
            else
                nums1[m + n - 1] = nums1[m - 1], --m;
    }
};
