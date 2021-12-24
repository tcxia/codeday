#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> searchRangev23(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 2);
            if (nums[mid] == target) {
                left = mid;
                right = mid;
                while(left > 0 && nums[left] == target){
                    left--;
                }
                result[0] = left;

                while(right < nums.size() && nums[right] == target){
                    right++;
                }
                result[1] = right;
            }else if(nums[mid] > target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return result;
    }

   public:
    // O(n)
    vector<int> searchRangev2(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result[1] = i;
                count++;
            }
        }
        if (count > 0) {
            result[0] = result[1] - count + 1;
        }

        return result;
    }

   public:
    // O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] == target) {
                temp.push_back(left);
            }

            if (nums[right] == target) {
                temp.push_back(right);
            }

            left++;
            right--;
        }
        if (temp.empty()) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            int min_value = *min_element(temp.begin(), temp.end());
            result.push_back(min_value);
            int max_value = *max_element(temp.begin(), temp.end());
            result.push_back(max_value);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution solve;
    vector<int> result = solve.searchRangev2(nums, 7);
    for (auto& res : result) {
        cout << res << endl;
    }
}