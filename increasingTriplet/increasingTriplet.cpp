#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 2; i++) {
            if((nums[i] < nums[i+1]) && (nums[i+1] < nums[i+2])){
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2, 6, 5, 0, 4, 6};
    Solution solve;
    bool ret = solve.increasingTriplet(nums);
    cout << ret << endl;
}