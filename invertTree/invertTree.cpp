#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return root;
        swap(root->left, root->right);  // 交换左右两个数值即可
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode *invertTreev2(TreeNode *root) {
        stack<TreeNode *> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != nullptr) {
                st.pop();
                // swap(node->left, node->right);
                if (node->left) st.push(node->left);
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
    }
};