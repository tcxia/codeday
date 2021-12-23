#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int searchv2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; 
        while (left <= right) { // 注意区间细节
            int mid = left + ((right - left) >> 1);  
            // cout << mid << endl;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;  // 
            } else {
                left = mid + 1;  
            }
        }
        return -1;
    }
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();  // 0, 6
        while (left < right) {
            int mid = left + ((right - left) >> 1);  // (3, 5)
            // cout << mid << endl;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid;  // (5
            } else {
                left = mid + 1;  // (4
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    Solution solve;
    int result = solve.search(nums, 9);
    cout << result << endl;
}