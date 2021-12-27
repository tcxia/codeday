#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    bool isFriend(int x, int y) {
        if ((y<= (0.5 * x + 7)) || (y > x) || (y > 100 && x < 100)){
            return false;
        }
        return true;
    }

    void backtracking(vector<int>& ages, vector<bool>& used) {
        if (path.size() == 2) {
            if (isFriend(path[0], path[1])){
                result.push_back(path);
                return;
            } 
        }

        for (int i = 0; i < ages.size(); i++) {
            if (used[i]){
                continue;
            }
                
            path.push_back(ages[i]);
            used[i] = true;

            backtracking(ages, used);

            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> numFriendRequests(vector<int>& ages) {
        result.clear();
        path.clear();

        vector<bool> used(ages.size(), false);
    
        backtracking(ages, used);

        return result;

    }
};

int main(){
    vector<int> ages = {20,30,100,110,120};
    Solution solve;
    vector<vector<int>> result = solve.numFriendRequests(ages);
    for(auto& res: result){
        cout << res[0] << "," << res[1] << endl;
    }
    
}