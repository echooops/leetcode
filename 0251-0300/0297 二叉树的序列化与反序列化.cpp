#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Lisp 树结构的思路
class Codec {
public:
    stack<TreeNode *> nodestack;

    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        if (root->left || root->right)
            return '(' + to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right) + ')';
        else
            return to_string(root->val);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 清空栈
        while(!nodestack.empty()) nodestack.pop();
        nodestack.push(NULL);
        for (int i = 0; i < data.size(); ) {
            if (data[i] == ' ') {
                i++; continue;
            }
            if (data[i] == '(') {
                auto index = data.find(' ', i);
                string tmp = data.substr(i + 1, index - i - 1);
                nodestack.push(new TreeNode(atoi(tmp.c_str())));  // operation
                i = index;
            } else if (data[i] == ')') {
                auto right = nodestack.top();
                nodestack.pop();
                auto left = nodestack.top();
                nodestack.pop();
                nodestack.top()->left = left;
                nodestack.top()->right = right;
                i++;
            } else if (data[i] == '#') {
                nodestack.push(NULL);
                i++;
            } else {
                auto index = min(data.find(' ', i), data.find(')', i));
                nodestack.push(new TreeNode(atoi(data.substr(i, index - 1).c_str())));
                i = index;
            }
        }
        return nodestack.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(int argc, char *argv[])
{
    string data = "(1 (5 4 5) (3 (2 1 3) 2))";
    Codec codec;
    TreeNode *root = codec.deserialize(data);
    cout << root->val << "\n";
    cout << root->left->val << "\n";
    cout << root->right->val << "\n";
    string str = codec.serialize(root);
    cout << str << "\n";
    return 0;
}
