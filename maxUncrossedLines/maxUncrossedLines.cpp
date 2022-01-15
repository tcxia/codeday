#include <vector>
using namespace std;

/**
 * dp[i][j] 表示[0, i-1]和[0, j-1]之前连接的数
 * 递推公式：
 * nums1[i-1] == nums2[j-1]:
 *  dp[i][j] = dp[i-1][j-1] + 1
 * dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 */

class Solution {
   public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};