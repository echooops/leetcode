#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        for (int i = 0; i < n; i++) {
            string s(n, '.');
            s[i] = 'Q';
            matrix.push_back(s);
        }
        dfs(0, 0, 0, 0);
        return result;
    }
    void dfs(int row, int col, int rd, int ld) {
        if (row >= N) {
            result.push_back(cache);
            return;
        }
        int bits = ~(col | rd | ld) & ((1 << N) - 1);
        while (bits > 0) {
            int pick = bits & -bits;
            cache.push_back(matrix[log(pick)/log(2)]);
            dfs(row + 1, col | pick, (rd | pick) << 1, (ld | pick) >> 1);
            cache.pop_back();
            bits &= bits - 1;
        }
    }
private:
    int N;
    vector<string> cache;
    vector<vector<string>> result;
    vector<string> matrix;
};

int main(int argc, char *argv[])
{
    int n = 5;
    Solution s;
    auto r = s.solveNQueens(n);
    for (auto &v : r) {
        cout << string(n, '-') << "\n";
        for (auto &e : v)
            cout << e << "\n";
    }
    return 0;
}
