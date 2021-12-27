#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    bool isFriend(vector<int> ages, int x, int y) {
        if ((ages[y] <= (0.5 * ages[x] + 7)) || (ages[y] > ages[x]) || (ages[y] > 100 && ages[x] < 100)){
            return false;
        }
        return true;
    }

    void backtracking(vector<int>& ages) {
        if (path.size() == 2) {
            result.push_back(path);
        }

        for (int i = 0; i < ages.size(); i++) {
            
            
        }
    }

   public:
    int numFriendRequests(vector<int>& ages) {
    }
};