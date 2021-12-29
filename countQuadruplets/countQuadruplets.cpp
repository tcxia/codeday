#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int n = j + 1; n < nums.size(); n++) {
                    int sum = nums[i] + nums[j] + nums[n];
                    vector<int>::iterator temp = find(nums.begin(), nums.end(), sum);
                    if (temp != nums.end()) {
                        int index = distance(nums.begin(), temp);
                        if (index > n) {
                            count++;
                        }
                    } else {
                        continue;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {3,3,6,4,5};
    Solution solve;
    int count = solve.countQuadruplets(nums);
    cout << count << endl;
}