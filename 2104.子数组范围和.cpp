/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    

   public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret;
        for(int i = 0; i < nums.size(); i++){
            int minv = INT32_MAX, maxv = INT32_MIN;
            for(int j = i; j < nums.size(); j++){
                minv = min(minv, nums[j]);
                maxv = max(maxv, nums[j]);
                ret += (maxv - minv);
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solve;
    solve.subArrayRanges(nums);
}
