/*
  编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

  1. 每行中的整数从左到右按升序排列。
  2. 每行的第一个整数大于前一行的最后一个整数。
 */
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (!row) return false;
        int col = matrix[0].size();
        if (!col) return false;
        int left = 0, right = row * col - 1;
        while(left <= right) {
            int mid = (left + right)/2;
            int &e = matrix[mid / col][mid % col];
            if (e == target) return true;
            if (e < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
