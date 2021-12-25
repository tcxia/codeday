#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // 无参构造
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // 构建二叉树
    TreeNode *createTree() {
        TreeNode *root = NULL;
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(3);
        node1->right = node2;
        node2->left = node3;
        root = node1;
        return root;
    }

   public:
    // 递归遍历
    vector<int> result;
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return result;
        } else {
            result.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return result;
    }

    // 迭代遍历
    vector<int> preorderTraversalv2(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();  // 返回栈顶元素，但不删除元素
            st.pop();                   // 删除栈顶元素但不返回其值
            // cout << node->val << endl;
            result.push_back(node->val);
            if (node->right) st.push(node->right);  // 在栈顶压入新元素
            if (node->left) st.push(node->left);
        }
        return result;
    }
};

int main() {
    Solution solve;
    TreeNode *root = solve.createTree();
    vector<int> result = solve.preorderTraversalv2(root);
    for (auto &res : result) {
        cout << res << endl;
    }
}