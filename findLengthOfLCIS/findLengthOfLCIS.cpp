#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i] 表示i之前包括i的最长连续上升子序列长度
        // dp[i] = max(dp[i], dp[i-1] + 1)
        // if(nums[i+1] > nums[i]) dp[i+1] = dp[i] + 1
        // 初始化: dp[i] = 1
        // 遍历顺序: 从前往后遍历

        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int ret = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            // if (nums[i] > nums[i - 1]) dp[i] = max(dp[i], dp[i - 1] + 1);
            if (nums[i+1] > nums[i]){
                dp[i+1] = dp[i] + 1;
            }
            if (dp[i+1] > ret) ret = dp[i+1];
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};
    Solution solve;
    int ret = solve.findLengthOfLCIS(nums);
    cout << ret << endl;
}