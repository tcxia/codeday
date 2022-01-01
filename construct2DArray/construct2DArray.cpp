#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;

   public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // original 能被转换成 m * n, 即 original.size() = m * n;
        if (original.size() != (m * n)) return result;

        // 如果可以转换，则0 ~ n-1 为0行 n ~ 2*n -1 为1行
        for(int i = 0; i < original.size(); i+=n){
            vector<int> temp;
            for(int j = i; j < (i+n); j++){
                temp.push_back(original[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    vector<int> original = {1, 2, 3, 4, 5, 6};
    Solution solve;
    vector<vector<int>> result = solve.construct2DArray(original, 2, 3);
    for (auto& res : result) {
        for (auto& r : res) {
            cout << r << ",";
        }
        cout << endl;
    }
}