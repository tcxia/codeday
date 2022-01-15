#include <vector>
#include <iostream>
using namespace std;

/**
 * dp[i] 代表到i-1之前的最大和
 * dp[i] = max(dp[i], dp[i-1] + nums[i])
 * dp[0] = nums[0]
 * */
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int sum = INT32_MIN;
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            if(dp[i] > sum){
                sum = dp[i];
            }
        }
        return sum;
    }
};


int main(){
    vector<int> nums = {5,4,-1,7,8};
    Solution solve;
    int ret = solve.maxSubArray(nums);
    cout << ret << endl;
}