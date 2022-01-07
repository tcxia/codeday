#include "../common/binaryTree.h"

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val == key) {
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr){
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            else if(root->right == nullptr){
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }else{
                TreeNode* cur = root->right;
                while(cur->left != nullptr){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};