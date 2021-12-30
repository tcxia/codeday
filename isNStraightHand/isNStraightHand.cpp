#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 贪心法
class Solution {
    vector<vector<int>> result;
    vector<int> path;

    bool continueHand(vector<int>& nums, int size) {
        for (int i = 1; i < size; i++) {
            if ((nums[i] - nums[i - 1]) != 1) {
                return false;
            }
        }
        return true;
    }

    void backtracking(vector<int>& hand, int groupSize, vector<bool>& used) {
        if (path.size() == groupSize) {
            sort(path.begin(), path.end());
            if (continueHand(path, groupSize)) {
                result.push_back(path);
                return;
            }
        }

        for (int i = 0; i < hand.size(); i++) {
            if (used[i]) {
                continue;
            }
            path.push_back(hand[i]);
            used[i] = true;
            backtracking(hand, groupSize, used);
            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> isNStraightHand(vector<int>& hand, int groupSize) {
        result.clear();
        path.clear();
        vector<bool> used(hand.size(), false);
        backtracking(hand, groupSize, used);
        return result;

        // int splitNum = hand.size() / groupSize;
        // cout << splitNum << endl;
        // if (result.size() != splitNum) {
        //     cout << "f" << endl;
        //     return false;
        // } else {
        //     cout << "t" << endl;
        //     return true;
        // }
    }

    bool isNStraightHandv2(vector<int>& hand, int groupSize){
        if(hand.size() % groupSize != 0){
            return false;
        }

        sort(hand.begin(), hand.end());
        unordered_map<int, int> cnt;
        for(auto& num : hand){
            cnt[num]++;
        }

        for(auto& x : hand){
            if (!cnt.count(x)){
                continue;
            }
            for(int j = 0; j < groupSize; j++){
                int num = x + j;
                if(!cnt.count(num)){
                    return false;
                }
                cnt[num]--;
                if(cnt[num] == 0){
                    cnt.erase(num);
                }
            }
        }
        return true;
    }
    
};

int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    Solution solve;
    vector<vector<int>> result = solve.isNStraightHand(hand, 3);
    for (auto& res : result) {
        for (auto& r : res) {
            cout << r << ",";
        }
        cout << endl;
    }
}