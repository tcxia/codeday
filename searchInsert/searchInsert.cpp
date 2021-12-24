#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution solve;
    int result = solve.searchInsert(nums, 7);
    cout << result << endl;
}