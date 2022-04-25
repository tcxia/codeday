/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // unordered_map<int, vector<int>> map;
    // Solution(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         map[nums[i]].push_back(i);
    //     }
    // }

    // int pick(int target) {
    //     int rd = rand() % map[target].size();
    //     return map[target][rd];
    // }


    // 蓄水池抽样法
    vector<int> mNums;
    Solution(vector<int>& nums) : mNums(nums) {
    }

    int pick(int target) {
        int iCnt = 0, iIndex;
        for (int i = 0; i < mNums.size(); i++) {
            if (target == mNums[i]) {
                iCnt++;
                if (rand() % iCnt == 0) {
                    iIndex = i;
                }
            }
        }
        return iIndex;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
