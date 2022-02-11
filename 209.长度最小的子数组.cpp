/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> counts;

   public:
    int minSubArrayLenv2(int target, vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int sum = nums[i];
            if (sum >= target) return 1;
            for (int j = i + 1; j < size; j++) {
                sum += nums[j];
                if (sum >= target) {
                    counts.push_back(j - i + 1);
                    continue;
                }
            }
        }
        if (counts.size() == 0) {
            return 0;
        } else {
            return *min_element(counts.begin(), counts.end());
        }
    }

    int minSubArrayLen(int target, vector<int>& nums){
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 不断变更i
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1,1,1,1,1,1,1,1};
    Solution solve;
    int ret = solve.minSubArrayLen(11, nums);
    cout << ret << endl;
}
