#include <iostream>
#include <stack>
#include <vector>

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
    vector<int> result;

   public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root) {
            inorderTraversal(root->left);
            result.push_back(root->val);
            inorderTraversal(root->right);
        }
        return result;
    }

    vector<int> inorderTraversalv2(TreeNode *root) {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        if (root == NULL) return result;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;   // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据
                st.pop();   // 中
                result.push_back(cur->val);
                cur = cur->right;  // 右
            }
        }
        return result;
    }
};