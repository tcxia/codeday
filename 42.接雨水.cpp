/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int n = height.size();
        int result = 0;
        vector<int> l_max(n), r_max(n);

        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            l_max[i] = max(height[i], l_max[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            r_max[i] = max(height[i], r_max[i + 1]);
        }

        for(int i = 0; i < n - 1; i++){
            result += min(l_max[i], r_max[i]) - height[i];
        }

        return result;
    }
};
// @lc code=end
