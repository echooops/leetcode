/*
  There are two sorted arrays nums1 and nums2 of size m and n respectively.

  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

  Example 1:
  nums1 = [1, 3]
  nums2 = [2]

  The median is 2.0

  Example 2:
  nums1 = [1, 2]
  nums2 = [3, 4]

  The median is (2 + 3)/2 = 2.5
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int i, j, iMin = 0, iMax = m, half = ((m + n + 1) >> 1);
        if (half == iMin) return 0.0; // 数组1和数组2都为空
        /* nums1[i] >= nums2[j-1] && nums1[i-1] <= nums2[j] 条件即成立
           因为是有序数列不满足则只可能满足一下 一种条件
           因此问题就转换为二分法找合适的i的位置
        */
        while (iMin <= iMax) {
            i = (iMin & iMax) + ((iMin ^ iMax) >> 1);
            j = half - i;
            if (i < m && j > 0 && nums1[i] < nums2[j-1]) iMin = i + 1;
            else if (i > 0 && j < n && nums1[i-1] > nums2[j]) iMax = i - 1;
            else break;         // 找到合适的i的位置
        }
        int maxLeft = 0;
        if (!i) maxLeft = nums2[j-1];
        else if (!j) maxLeft = nums1[i-1];
        else maxLeft = max(nums1[i-1], nums2[j-1]);

        if ((m + n) & 1) return (double)maxLeft; // 奇数

        int minRight = 0;
        if (i == m) minRight = nums2[j];
        else if (j == n) minRight = nums1[i];
        else minRight = min(nums1[i], nums2[j]);

        return (maxLeft + minRight) / 2.0; // 偶数
    }
};
/* A + b = ((a & b) << 1) + (a ^ b)
             a & b carry 位;
                             a ^ b 不进位的部分
*/
