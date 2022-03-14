/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& res){
        if (!root) {return;}

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
// @lc code=end
