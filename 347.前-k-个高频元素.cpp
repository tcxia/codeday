/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        vector<pair<int, int>> vMap;
        for (auto it = map.begin(); it != map.end(); it++) {
            vMap.push_back(make_pair(it->first, it->second));
        }

        sort(vMap.begin(), vMap.end(), [](const pair<int, int> &x, const pair<int, int> &y) -> int {
            return x.second > y.second;
        });

        for(auto it = vMap.begin(); it != vMap.end(); it++){
            result.push_back(it->first);
        }
        
        return result;
    }
};
// @lc code=end
