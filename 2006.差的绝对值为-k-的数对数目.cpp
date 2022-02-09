/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                if ((nums[i] - nums[j] == k) || (nums[j] - nums[i] == k)){
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

