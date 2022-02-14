/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int singleNonDuplicatev2(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }
        for(auto iter = counts.begin(); iter != counts.end(); ++iter){
            if (iter->second == 1){
                return iter->first;
            }
        }
        return 0;
    }

    int singleNonDuplicate(vector<int>& nums){
        if(nums.size() == 1){
            return nums[0];
        }
        int i = 0, j = 1;
        while (j < nums.size() - 1){
            if (nums[j] != nums[i]){
                return nums[i];
            }else{
                j += 2;
                i += 2;
            }
        }
        return 0;
    }
};
// @lc code=end

