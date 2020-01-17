#! /usr/bin/env python3

from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        if n == 0:
            raise ValueError
        imin, imax, half = 0, m, (m + n + 1) >> 1
        # 给 i 寻找一个合适的位置 ( j = half - i) 所以 i 确定了 j 也就确定了
        while imin <= imax:
            # 这里采用 2 分法 时间效率为 O(log(min(m, n)))
            i = (imin + imax) >> 1
            j = half - i
            if i < m and nums1[i] < nums2[j - 1]: imin = i + 1
            elif i > 0 and nums1[i - 1] > nums2[j]: imax = i - 1
            else: break
        if i == 0 : lmax = nums2[j - 1]
        elif j == 0 : lmax = nums1[i - 1]
        else : lmax = max(nums1[i - 1], nums2[j - 1])
        # 判断奇偶
        if (m + n) & 1 == 1:
            return lmax         # 奇数则 直接返回左边界

        if i == m: rmin = nums2[j]
        elif j == n: rmin = nums1[i]
        else : rmin = min(nums1[i], nums2[j])

        return (lmax + rmin) / 2  # 偶数则 返回左右边界的平均值

