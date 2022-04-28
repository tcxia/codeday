/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> left, right;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        int nl = right.size();
        for (int i = 0; i < nl; i++) {
            left.push_back(right[i]);
        }
        return left;
    }
};
// @lc code=end
