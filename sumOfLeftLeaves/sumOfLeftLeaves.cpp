#include <iostream>
#include <queue>
#include <stack>

#include "../common/binaryTree.h"
using namespace std;

class Solution {
   public:
    int sumOfLeftLeaves(TreeNode* root) {
        vector<int> result;
        int sum = 0;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
                    result.push_back(node->left->val);
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        for (int i = 0; i < result.size(); i++) {
            sum += result[i];
        }
        return sum;
    }

    int sumOfLeftLeavesv2(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) return 0;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
                sum += node->left->val;
            }
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return sum;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, 8};
    TreeNode* root = constructBinaryTree(vec);
    Solution solve;
    int res = solve.sumOfLeftLeavesv2(root);
    cout << res << endl;
}