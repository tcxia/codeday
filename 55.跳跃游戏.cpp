/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farpath = 0;
        if (n == 1) return true;
        for (int i = 0; i <= farpath; i++) {
            farpath = max(nums[i] + i, farpath);
            if (farpath >= n - 1) return true;
        }
        return false;
    }
};
// @lc code=end
