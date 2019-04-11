/*
  在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

  计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();

/*
 * 动态规划
 * 状态转移矩阵：rob(root) = max(root->val + nrob(root->left) + nrob(root->right), rob(root->left) + rob(root->right)
 *               nrob(root) = rob(root.left) + rob(root.right)
 */

class Solution {
public:
    // 添加记忆，对以经算过的最大值，直接返回。
    int rob(TreeNode *root) {
        map<TreeNode *, int> dict;
        function<int(TreeNode*)> f;
        f = [&dict, &f] (TreeNode* root)->int {
                if (!root) return 0;
                if (dict.count(root)) return dict[root];
                // max(能偷,不能偷)
                return (dict[root] = max(root->val + (root->left ? (f(root->left->left) + f(root->left->right)) : 0 ) + (root->right ? (f(root->right->left) + f(root->right->right)) : 0), f(root->left) + f(root->right)));
            };
        return f(root);
    }
    // 提交错误: Time Limit Exceeded 时间超限，递归次数太多？
    int _rob(TreeNode* root) {
        function<int(TreeNode*)> f;
        f = [&f] (TreeNode* root)->int {
                return root ? max(root->val + (root->left ? (f(root->left->left) + f(root->left->right)) : 0 ) + (root->right ? (f(root->right->left) + f(root->right->right)) : 0), f(root->left) + f(root->right)) : 0;
            };
        return f(root);
    }
};
// 底下是别人最快的方法 <妙>
class Solution {
public:
    int rob(TreeNode* Root) {
        std::function<std::tuple<int, int>(TreeNode *)> FindMaxReward;
        FindMaxReward = [&](TreeNode *Curr) {
                            if (!Curr)
                                return std::make_tuple(0, 0);
      
                            int MaxNotRobLeft, MaxRobLeft;
                            std::tie(MaxNotRobLeft, MaxRobLeft) = FindMaxReward(Curr->left);
      
                            int MaxNotRobRight, MaxRobRight;
                            std::tie(MaxNotRobRight, MaxRobRight) = FindMaxReward(Curr->right);
      
                            const int MaxNotRobCurr = std::max(MaxNotRobLeft, MaxRobLeft) +
                                std::max(MaxNotRobRight, MaxRobRight);
                            const int MaxRobCurr = Curr->val + MaxNotRobLeft + MaxNotRobRight;
      
                            return std::make_tuple(MaxNotRobCurr, MaxRobCurr);
                        };
    
        int MaxNotRobRoot, MaxRobRoot;
        std::tie(MaxNotRobRoot, MaxRobRoot) = FindMaxReward(Root);
    
        return std::max(MaxNotRobRoot, MaxRobRoot);
    }
};
