#include <vector>
#include <iostream>

using namespace std;

static auto cmp = [] (const vector<int> &lhs, const vector<int> &rhs) {
                      return lhs[0] < rhs[0] && lhs[1] < rhs[1];
                  };
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {move(newInterval)};

        auto lt = lower_bound(intervals.begin(), intervals.end(), vector<int>(2, newInterval[0]), cmp);
        auto rt = upper_bound(intervals.begin(), intervals.end(), vector<int>(2, newInterval[1]), cmp);
        if (lt == rt) {
            intervals.insert(lt, newInterval);
        } else {
            lt->at(0) = min(lt->at(0), newInterval[0]);
            lt->at(1) = max(prev(rt)->at(1), newInterval[1]);
            intervals.erase(next(lt), rt);
        }
        return intervals;
    }
};


int main(int argc, char *argv[])
{
    vector<vector<int>> intervals = {{1,2},{7,8},{10,12},{15,18}};
    // vector<vector<int>> intervals = {{1,4},{4,5}};
    // vector<vector<int>> intervals = {{1,4},{2,3}};
    vector<int> newInterval = {3,14};

    Solution s;
    auto r = s.insert(intervals, newInterval);
    for (auto &v : r) {
        cout << "[";
        for (auto &e : v)
            cout << e << " ";
        cout << "]";
    }
    cout << " " << "\n";

    return 0;
}
