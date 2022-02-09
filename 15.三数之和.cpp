/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
   public:

   // 去重
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){ // 排序后如果第一个元素大于0，则不能凑成三元组
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]){ // 三元组元素a去重
                continue;
            }

            unordered_set<int> set;
            for(int j = i+1; j < nums.size(); j++){
                if (j > i + 2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]){ // 三元组b去重
                    continue;
                }

                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()){
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c); // 三元组c去重
                }else{
                    set.insert(nums[j]);
                }
            }
        }

        return result;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    Solution solve;
    vector<vector<int>> ret = solve.threeSum(nums);
}
