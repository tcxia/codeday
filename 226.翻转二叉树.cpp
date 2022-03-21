/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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

#include <algorithm>
using namespace std;

class Solution {
    TreeNode *traversal(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right);
        traversal(root->left);
        traversal(root->right);
        return root;
    }

   public:
    TreeNode *invertTree(TreeNode *root) {
        return traversal(root);
    }
};
// @lc code=end
