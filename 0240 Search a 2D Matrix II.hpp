/*
  编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

  1. 每行的元素从左到右升序排列。
  2. 每列的元素从上到下升序排列。
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
        int y = row - 1, x = 0;
        while(y >= 0 && x < col) {
            int &e = matrix[y][x];
            if (target < e) --y;
            else if (target > e) ++x;
            else return true;
        }
        return false;
    }
};
