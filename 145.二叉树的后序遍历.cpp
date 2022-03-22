/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <stack>
#include <vector>
using namespace std;

class Solution {
    void traversal(TreeNode *root, vector<int> &nums) {
        if (root) {
            traversal(root->left, nums);
            traversal(root->right, nums);
            nums.push_back(root->val);
        }
    }

   public:
    vector<int> postorderTraversalv1(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());  // 注意翻转
        return result;
    }
};
// @lc code=end
