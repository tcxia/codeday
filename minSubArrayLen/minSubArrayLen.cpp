#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // i
        // j
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    int distance = j - i + 1;
                    vec.push_back(distance);
                    break;
                }
            }
        }
        if (vec.size() == 0) {
            return 0;
        } else {
            int minValue = *min_element(vec.begin(), vec.end());
            return minValue;
        }
    }
};

int main() {
    Solution solve;
    vector<int> nums = {1, 4, 4};
    int ret = solve.minSubArrayLen(4, nums);
    cout << ret << endl;
}