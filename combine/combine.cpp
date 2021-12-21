#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear(); // 可以不写
        backtracking(n, k, 1);
        return result;
    }

    void backtracking(int n, int k, int index) {
        if (path.size() == k){
            result.push_back(path);
            return;
        }

        // for(int i = index; i <= n - (k - path.size()) + 1; i++)
        for(int i = index; i <= n; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};

int main(){
    int n = 4, k = 2;
    Solution s;
    vector<vector<int>> result;
    result = s.combine(n, k);
    for(auto &res : result){
        cout <<"[" << res[0] << " " << res[1] << "]"<< endl;
    }
}