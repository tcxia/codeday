/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = 0; // 当前覆盖的最远距离下标, 记录当前走的最大步数
        int jumps = 0; // 下一步的覆盖的最远距离
        for(int i = 0; i < n - 1; i++){
            farthest = max(nums[i] + i, farthest); // 更新下一步覆盖的最远距离
            if (end == i){ // 遇到当前覆盖的最远距离下标
                jumps++; 
                end = farthest; // 更新当前覆盖的最远距离下标
            }
        }
        return jumps;
    }
};
// @lc code=end

