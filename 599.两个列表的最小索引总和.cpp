/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size();
        int n2 = list2.size();

        vector<string> result;
        int dist = INT32_MAX;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if (list1[i] == list2[j]){
                    if (i + j == dist){
                        result.push_back(list1[i]);
                    }else if (i + j < dist){
                        dist = i + j;
                        result.clear(); // 清空vector
                        result.push_back(list1[i]);
                    }
                }
            }
        }
    
        return result;
    }
};
// @lc code=end
