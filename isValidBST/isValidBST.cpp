#include "../common/binaryTree.h"

class Solution {
    bool compare(TreeNode* cur){
        bool retLeft;
        if(cur->left){
            if(cur->left->val < cur->val){
                return true;
            }else{
                return false;
            }
        }
        if(cur->right){
            if(cur->right->val > cur->val){
                return true;
            }else{
                return false;
            }
        }
    }
   public:
    bool isValidBST(TreeNode* root) {
        
    }
};