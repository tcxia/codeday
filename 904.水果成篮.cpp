/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;

        int left = 0, sublen = 0;
        int result = 0;

        for(int i = 0; i < fruits.size(); i++){
            basket[fruits[i]]++;
            sublen++;
            while(basket.size() > 2){
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) basket.erase(fruits[left]);
                left++;
                sublen--;
            }
            result = sublen > result ? sublen : result;
        }
        return result;
    }
};
// @lc code=end

int main(){

    vector<int> fruits = {1, 2, 1};

    Solution solve;
    int ret = solve.totalFruit(fruits);
}