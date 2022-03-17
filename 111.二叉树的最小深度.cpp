/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// #include <algorithm>
#include <queue>
using namespace std;

class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int count = 1;

        queue<TreeNode *> que;

        if (root) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) return count;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            count++;
        }
        return count;
    }
};
// @lc code=end
