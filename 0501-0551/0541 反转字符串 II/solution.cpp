#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (auto it = s.begin(); it < s.end(); it += 2 * k)
            if (it + k < s.end()) reverse(it, it + k);
            else reverse(it, s.end());
        return s;
    }
};

int main(int argc, char *argv[])
{
    string s = "12345678901234";
    Solution ss;
    cout << "原字符串:" << s << "\n";
    cout << "k = 1 :" << ss.reverseStr(s, 1) << "\n";
    cout << "k = 2 :" << ss.reverseStr(s, 2) << "\n";
    cout << "k = 3 :" << ss.reverseStr(s, 3) << "\n";
    cout << "k = 4 :" << ss.reverseStr(s, 4) << "\n";
    return 0;
}
