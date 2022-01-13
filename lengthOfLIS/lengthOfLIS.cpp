#include <vector>

using namespace std;
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 表示i之前包括i的最长上升子序列的长度
        // if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)  // j in [0, i - 1]
        //  dp[i] = 1
        // 从前往后遍历

        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > ret) ret = dp[i];
        }
        return ret;
    }
};
