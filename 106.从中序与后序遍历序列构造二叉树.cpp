/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

#include <vector>
using namespace std;

class Solution {
    TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return nullptr;

        int rootValue = postorder[postorderEnd - 1];  // 最后一个元素
        TreeNode *root = new TreeNode(rootValue);

        if (postorderEnd - postorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;

        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin +  delimiterIndex - inorderBegin;

        int rightPostorderBegin = postorderBegin +  delimiterIndex - inorderBegin;
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;

    }

   public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end
