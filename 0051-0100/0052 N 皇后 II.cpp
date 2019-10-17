#include <iostream>

class Solution {
public:
    int totalNQueens(int n) {
        N = n;
        dfs(0, 0, 0, 0);
        return this->res;
    }
    void dfs(int row, int col, int rd, int ld) {
        if (row >= N) { res++; return; }
        int bits = ~(col | rd | ld) & ((1 << N) - 1);
        while (bits > 0) {
            int pick = bits & -bits;
            dfs(row + 1, col | pick, (rd | pick) << 1, (ld | pick) >> 1);
            bits &= bits - 1;
        }
    }
private:
    int N;
    int res = 0;
};


int main(int argc, char *argv[])
{
    int n = 5;
    Solution s;
    int r = s.totalNQueens(n);
    std::cout << r << "\n";
    return 0;
}
