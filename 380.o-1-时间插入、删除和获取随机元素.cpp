/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class RandomizedSet {
    vector<int> randomNum;
public:
    RandomizedSet(){
        randomNum.clear();
    }
    
    bool insert(int val) {
        if (find(randomNum.begin(), randomNum.end(), val) == randomNum.end()){
            randomNum.push_back(val);
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        vector<int>::iterator iter = find(randomNum.begin(), randomNum.end(), val);
        if (iter == randomNum.end()){
            return false;
        }else{
            int valIndex = distance(randomNum.begin(), iter);
            randomNum.erase(randomNum.begin() + valIndex);
            return true;
        }

    }
    
    int getRandom() {
        if (randomNum.size() == 0) return -1;
        int randomIndex = rand() % randomNum.size();
        return randomNum[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

