/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */
#include <vector>

using namespace std;
// @lc code=start
class RecentCounter {
    vector<int> reqs;

   public:
    RecentCounter() {
        reqs.clear();
    }

    int ping(int t) {
        reqs.push_back(t);
        int minReqTime = t - 3000;
        int maxReqTime = t;
        int count = 0;
        for (int i = 0; i < reqs.size(); i++) {
            if (reqs[i] >= minReqTime && reqs[i] <= maxReqTime) count++;
        }

        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
