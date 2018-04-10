/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

  括号必须以正确的顺序关闭，"()" 和 "()[]{}" 是有效的但是 "(]" 和 "([)]" 不是。
*/
#include <iostream>
#include <stack>

using namespace std;
// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char &c : s) {
            switch (c) {
            case '(' :
            case '{' :
            case '[' : paren.push(c); break;
            case ')' : if (paren.empty() || paren.top() != '(') return false; else paren.pop(); break;
            case ']' : if (paren.empty() || paren.top() != '[') return false; else paren.pop(); break;
            case '}' : if (paren.empty() || paren.top() != '{') return false; else paren.pop(); break;
            default: return false;
            }
        }
        return paren.empty();
    }
};
