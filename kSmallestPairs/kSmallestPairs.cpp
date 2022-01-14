#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = 0;
                sum = nums1[i] + nums2[j];
                ret.push_back({nums1[i], nums2[j], sum});
            }
        }
        sort(ret.begin(), ret.end(), compare);
        vector<vector<int>> retFinal;
        for (int i = 0; i < k; i++) {
            retFinal.push_back({ret[i][0], ret[i][1]});
        }

        return retFinal;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    Solution solve;
    vector<vector<int>> ret = solve.kSmallestPairs(nums1, nums2, 2);
    for (const auto& item : ret) {
        for (auto i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}