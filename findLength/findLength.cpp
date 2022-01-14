#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] 代表以下标i-1结尾的数组A, 以下标j-1结尾的数组B
        // dp[i][j] = dp[i-1][j-1] + 1
        // 初始化: dp[i][0] = 1 或者 dp[0][j] = 1 初始化范围确定: 若取值到最后一个元素 dp(n+1) 否则 dp(n)
        // 从前往后遍历
        // 返回nums1.size() 和 nums2.size()


        int ret = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        // for (int i = 0; i < nums1.size(); i++) dp[i][0] = 1;
        // for (int j = 0; j < nums2.size(); j++) dp[0][j] = 1;

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > ret) ret = dp[i][j];
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 2, 1, 4};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    Solution solve;
    int ret = solve.findLength(nums1, nums2);
    cout << ret << endl;
}