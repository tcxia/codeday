#include <iostream>
#include <vector>

using namespace std;

class threeSum {
   public:
    vector<vector<int>> threeSumFunc(vector<int> &nums) {
        vector<vector<int>> result;
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
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum ts;
    vector<vector<int>> res = ts.threeSumFunc(nums);
    // cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
}