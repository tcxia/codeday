/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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

class Solution {
    bool exists(TreeNode *root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode *cur = root;
        while (cur != nullptr && bits > 0) {
            if (!(bits & k)) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
            bits >>= 1;
        }
        return cur != nullptr;
    }

   public:
    int countNodesv1(TreeNode *root) {
        if (root == nullptr) return 0;
        int level = 0;
        TreeNode *cur = root;
        while (cur->left != nullptr) {
            level++;
            cur = cur->left;
        }

        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftHeight = 0, rightHeight = 0;
        while (left) {
            left = left->left;
            leftHeight++;
        }
        while (right) {
            right = right->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight) {
            return (2 << leftHeight) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end
