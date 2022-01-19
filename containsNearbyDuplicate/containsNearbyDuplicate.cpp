#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && (j - i) <= k) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsNearbyDuplicatev2(vector<int>& nums, int k) {
        // 左右两个指针，分别计算 是否小于等于k
        unordered_set<int> us;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i > k) {
                us.erase(nums[i - k - 1]);
            }
            if (us.count(nums[i])) {
                return true;
            }
            us.emplace(nums[i]);
        }
        return false;
    }

    bool containsNearbyDuplicatev23(vector<int>& nums, int k) {
        // 左右两个指针，分别计算 是否小于等于k
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (um.count(num) && i - um[num] <= k) {
                return true;
            }
            um[num] = i;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 0, 1, 1};
    Solution solve;
    bool ret = solve.containsNearbyDuplicatev2(nums, 3);
    cout << ret << endl;
}