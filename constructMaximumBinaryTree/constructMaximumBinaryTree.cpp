#include <algorithm>
#include <vector>

#include "../common/binaryTree.h"
using namespace std;
class Solution {
   public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        if (nums.size() == 1) {
            root->val = nums[0];
            return root;
        }

        int maxValue = *max_element(nums.begin(), nums.end());
        int maxIndex = *find(nums.begin(), nums.end(), maxValue);

        TreeNode* root = new TreeNode(maxValue);

        vector<int>::const_iterator firstLeft = nums.begin();
        vector<int>::const_iterator secondLeft = nums.begin() + maxIndex;
        vector<int> numsLeft;
        numsLeft.assign(firstLeft, secondLeft);

        vector<int>::const_iterator firstRight = nums.begin() + maxIndex;
        vector<int>::const_iterator secondRight = nums.end();
        vector<int> numsRight;
        numsRight.assign(firstRight, secondRight);


        int maxValuev2 = 0;
        int maxIndexv2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxValuev2){
                maxValuev2 = nums[i];
                maxIndexv2 = i;
            }
        }

        if (maxIndex > 0) {
            root->left = constructMaximumBinaryTree(numsLeft);
        }
        if (maxIndex < (nums.size() - 1)) {
            root->right = constructMaximumBinaryTree(numsRight);
        }

        return root;
    }
};