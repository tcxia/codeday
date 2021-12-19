#include <iostream>
#include <vector>
using namespace std;

class findJudge {
   public:
    int findjudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1);
        vector<int> outDegree(n + 1);

        for (auto& egde : trust) {
            int x = egde[0], y = egde[1];
            ++inDegree[y];
            ++outDegree[x];
        }

        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};