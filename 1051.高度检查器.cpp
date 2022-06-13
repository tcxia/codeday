/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int heightChecker(vector<int>& heights) {
        vector<int> origin = heights;
        sort(heights.begin(), heights.end());

        int count = 0;
        for (int i = 0; i < origin.size(); i++) {
            if (heights[i] != origin[i]) count++;
        }
        return count;
    }
};
// @lc code=end
