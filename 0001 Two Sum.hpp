/*
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  Example:
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
*/

#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum (vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            int res = target - nums[i];
            if (hash_map.count(res)) {
                return vector<int>({hash_map[res], i});
            }
            else {
                hash_map.insert(pair<int, int>(nums[i], i));
            }
        }
        return vector<int>();
    }
};
