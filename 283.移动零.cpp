/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start

#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int startIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if (nums[fastIndex] != 0){
                nums[startIndex] = nums[fastIndex];
                startIndex++;
            }
        }
        for(int flag = startIndex; flag < nums.size(); flag++){
            nums[flag] = 0;
        }
    }
};
// @lc code=end

