/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;

        queue<TreeNode *> que;
        if (root) que.push(root);
        int count = 0;
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
            if (count % 2 == 0) {
                result.push_back(path);
            } else {
                reverse(path.begin(), path.end());
                result.push_back(path);
            }
            count++;
        }
        return result;
    }
};
// @lc code=end
