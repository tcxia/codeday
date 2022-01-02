#include "../common/binaryTree.h"

class Solution {
    TreeNode* mergeOnce(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == nullptr && tree2 == nullptr)
            return nullptr;
        else if (tree1 != nullptr && tree2 == nullptr)
            return tree1;
        else if (tree1 == nullptr && tree2 != nullptr)
            return tree2;

        tree1->val += tree2->val;

        tree1->left = mergeOnce(tree1->left, tree2->left);

        tree1->right = mergeOnce(tree1->right, tree2->right);

        return tree1;
    }

   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // return mergeTrees(root1, root2);
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};