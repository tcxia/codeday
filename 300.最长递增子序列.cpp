/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int result;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > result) result = dp[i];
        }

        return result;
    }
};
// @lc code=end
