/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> path;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                path.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            result.push_back(path);
        }
        return result;
    }
};
// @lc code=end
