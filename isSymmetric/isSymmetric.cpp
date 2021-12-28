#include <queue>

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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right != nullptr)
            return false;
        else if (left->val != right->val)
            return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }

    bool isSymmetricv2(TreeNode *root) {
        queue<TreeNode *> que;
        if (root == nullptr) return true;
        que.push(root->left); // 将左子树头结点加入队列
        que.push(root->right);

        while(!que.empty()){
            TreeNode* leftNode = que.front();
            que.pop();

            TreeNode* rightNode = que.front();
            que.pop();
            if(!leftNode && !rightNode){
                continue;
            }
            if( (!leftNode || !rightNode || (leftNode->val != rightNode->val))){
                return false;
            }

            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};