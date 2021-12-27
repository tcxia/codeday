#include <queue>
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
    vector<vector<int>> result;

   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> que;
        if (root == nullptr) return result;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // 使用固定大小的size, 不能使用que.size()，因为que.size()是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};