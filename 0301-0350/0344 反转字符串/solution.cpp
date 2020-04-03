#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // STL algorithm
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
