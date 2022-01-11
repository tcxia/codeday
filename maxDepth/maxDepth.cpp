#include <iostream>
#include <queue>
using namespace std;

#include "../common/binaryTree.h"
class Solution {
    vector<vector<int>> result;

   public:
    // 迭代法，采用层次遍历
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(temp);
        }
        return result.size();
    }

    int maxDepthv2(TreeNode *root) {
        if (root == nullptr) return 0;
        // if (root->left == nullptr && root->right == nullptr) return 1;
        int left = maxDepthv2(root->left);
        int right = maxDepthv2(root->right);

        int depth = max(left, right) + 1;
        return depth;
    }
};