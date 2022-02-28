/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
   public:
    int threeSumClosestv2(vector<int>& nums, int target) {
        int result; 
        int minvalue = INT32_MAX;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int z = j + 1; z < nums.size(); z++){
                    int temp = abs(target - (nums[i] + nums[j] + nums[z]));
                    if (temp < minvalue){
                        minvalue = temp;
                        result = nums[i] + nums[j] + nums[z];
                    }
                }
            }
        }
        return result;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        // 根据差值来更新答案
        auto update = [&](int cur){
            if (abs(cur - target) < abs(best - target)){
                best = cur;
            }
        };

        // 枚举a
        for(int i = 0; i < n; i++){

            // 保证和上次枚举的不一致
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                // 如果和为target直接返回答案
                if (sum == target){
                    return target;
                }
                update(sum);

                if (sum > target){ // 如果和大于target, 移动c对应的指针
                    int k0 = k - 1;
                    // 移动到下一个不一样的元素
                    while (j < k0 && nums[k0] == nums[k]){
                        --k0;
                    }
                    k = k0;
                }else{ // 
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]){
                        ++j0;
                    }
                    j =j0;
                }
            }
        }
        return best;
    }
};
// @lc code=end
