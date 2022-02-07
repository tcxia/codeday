#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<int, int> map;

   public:
    int sumOfUnique(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); i++) {
        //     int c = count(nums.begin(), nums.end(), nums[i]);
        //     cout << c << endl;
        // }
        // int count = 1;
        int sum = 0;
        // 统计元素个数
        for (int i = 0; i < nums.size(); i++) {
            // map.insert(pair<int, int>(i, nums[i]));
            // map.insert(make_pair(nums[i], count));
            map[nums[i]]++;
        }
        // 遍历unordered_map
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->second == 1) {
                sum += it->first;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution solve;
    int ret = solve.sumOfUnique(nums);
    cout << ret << endl;
}