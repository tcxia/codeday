/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            result.push_back(nums[i] * nums[i]);
        }

        sort(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

