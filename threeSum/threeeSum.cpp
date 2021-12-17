#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class threeSum {
   public:
    vector<vector<int>> threeSumv1(vector<int>& nums) {
        vector<vector<int>> result;
        // sort(nums.begin(), nums.end()); // 排序减少重复？
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int z = j + 1; z < nums.size(); z++) {
                    // cout << i <<" "<< j <<" " << z << endl;
                    if ((nums[i] + nums[j] + nums[z]) == 0) {
                        vector<int> resonce;
                        resonce.push_back(nums[i]);
                        resonce.push_back(nums[j]);
                        resonce.push_back(nums[z]);
                        result.push_back(resonce);
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> threeSumv2(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {  //三元组元素a去重
                continue;
            }
            unordered_set<int> set;  // 无序哈希
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {  // 三元组元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);  // 三元组元素c去重
                } else {
                    set.insert(nums[j]);  // 插入元素
                }
            }
        }
        return result;
    }

    vector<vector<int>> threeSumv3(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result;
            }

            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if ((nums[i] + nums[left] + nums[right]) > 0) {
                    right--;
                } else if ((nums[i] + nums[left] + nums[right]) < 0) {
                    left++;
                } else {
                    // vector<int> resonce;
                    // resonce.push_back(nums[i]);
                    // resonce.push_back(nums[left]);
                    // resonce.push_back(nums[right]);
                    // result.push_back(resonce);
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (right > left && nums[right] == nums[right - 1]) right--; // 去重
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum ts;
    vector<vector<int>> res = ts.threeSumv3(nums);
    // cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
}