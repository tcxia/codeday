/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int size = nums.size();
        int min_diff = INT32_MAX;

        sort(nums.begin(), nums.end()); // 排序后判断

        int i = 0;
        while(i < nums.size()){
            if (i + k - 1 >= nums.size()) break;
            int sub = nums[i + k - 1] - nums[i];
            if (sub < min_diff){
                min_diff = sub;
            }
            i += 1;
        }
        return min_diff;
    }
};
// @lc code=end

