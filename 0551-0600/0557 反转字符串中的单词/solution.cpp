#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        auto start = s.begin();
        for (auto last = s.begin(); last != s.end(); last++) {
            if (isspace(*last)) {
                reverse(start, last);
                start = last + 1;
            }
        }
        reverse(start, s.end());
        return s;
    }
};
