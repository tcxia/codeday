/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
class Solution {
   public:
    class mycomparsion {
       public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

   public:
    vector<int> topKFrequentv2(vector<int> &nums, int k) {
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

        for (auto it = vMap.begin(); it != vMap.end(); it++) {
            result.push_back(it->first);
        }

        return result;
    }


    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if (pri_que.size() > k){ // 如果堆的大小大于k，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        vector<int> result(k);

        // 前k个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        for(int i = k - 1; i >= 0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
// @lc code=end
