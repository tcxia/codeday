/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void traversal(TreeNode *root, vector<TreeNode *> &nums) {
        if (root) {
            nums.push_back(root);
            traversal(root->left, nums);
            traversal(root->right, nums);
        }
    }

   public:
    void flatten(TreeNode *root) {
        vector<TreeNode *> nums;
        traversal(root, nums);
        for (int i = 1; i < nums.size(); i++) {
            TreeNode *prev = nums[i - 1];
            TreeNode *curr = nums[i];
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};
// @lc code=end
