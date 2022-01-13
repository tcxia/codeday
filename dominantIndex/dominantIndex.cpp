#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        int ret = INT32_MIN;
        int retindex = -1;
        if (nums.size() == 1) {
            retindex = 0;
            return retindex;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= ret) {
                ret = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ret) {
                retindex = i;
                continue;
            } else if (ret < 2 * nums[i]) {
                return -1;
            }
        }
        return retindex;
    }
};

int main() {
    vector<int> nums = {3};
    Solution solve;
    int ret = solve.dominantIndex(nums);
    cout << ret << endl;
}