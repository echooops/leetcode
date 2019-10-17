#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> cache = intervals[0];
        for (auto &e : intervals) {
            if (cache[1] >= e[0]) {
                cache[1] = cache[1] > e[1] ? cache[1] : e[1];
            } else {
                result.emplace_back(cache);
                cache = e;
            }
        }
        result.emplace_back(cache);
        return result;
    }
};


int main(int argc, char *argv[])
{
    // vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> intervals = {{1,4},{4,5}};
    vector<vector<int>> intervals = {{1,4},{2,3}};
    Solution s;
    auto r = s.merge(intervals);
    for (auto &v : r) {
        cout << "[";
        for (auto &e : v)
            cout << e << " ";
        cout << "]";
    }
    cout << " " << "\n";

    return 0;
}
