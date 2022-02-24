/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   private:
    class MyQueue { 
       public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出
        // 同时pop之前判断队列当前是否为空
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止
        // 这样就保持了队列里的数值是单调从大到小的了
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 查询当前队列的最大值，直接返回队列前端也就是front就可以了
        int front() {
            return que.front();
        }
    };

   public:
    vector<int> maxSlidingWindowv2(vector<int>& nums, int k) {
        int low = 0;
        vector<int> result;
        while (low + k - 1 < nums.size()) {
            int temp = *max_element(nums.begin() + low, nums.begin() + low + k);
            result.push_back(temp);
            low++;
        }
        return result;
    }

    vector<int> maxSlidingWindowv3(vector<int>& nums, int k) {
        vector<int> result;
        stack<int> st;
        int low = 0;
        while (low + k - 1 < nums.size()) {
            st.push(nums[low]);
            for (int i = low + 1; i < low + k; i++) {
                if (nums[i] > st.top()) {
                    st.pop();
                    st.push(nums[i]);
                }
            }
            low++;
        }
        while (!st.empty()) {
            int num = st.top();
            result.push_back(num);
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for(int i = 0; i < k; i++){ // 现将前k个元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k; i < nums.size(); i++){ // result记录前k的元素的最大值
            que.pop(nums[i-k]); // 滑动窗口移除最前面的元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution solve;
    vector<int> ret = solve.maxSlidingWindow(nums, 3);
    for (auto& r : ret) {
        cout << r << endl;
    }
}
