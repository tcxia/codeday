#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> subvec;
        int subvalue = INT32_MIN;
        int keyindex = INT32_MIN;
        int retindex = 0;
        vector<int> subindex;
        subvec.push_back(releaseTimes[0]);
        for (int i = 1; i < releaseTimes.size(); i++) {
            subvec.push_back(releaseTimes[i] - releaseTimes[i - 1]);
        }
        for (int i = 0; i < subvec.size(); i++) {
            if (subvec[i] >= subvalue) {
                subvalue = subvec[i];
            }
        }
        for (int i = 0; i < subvec.size(); i++) {
            if (subvec[i] == subvalue) {
                subindex.push_back(i);
            }
        }
        for (int i = 0; i < subindex.size(); i++) {
            if (keysPressed[subindex[i]] - '0' > keyindex) {
                keyindex = keysPressed[subindex[i]] - '0';
                retindex = subindex[i];
            }
        }
        return keysPressed[retindex];
    }
};

int main() {
    vector<int> rt = {12, 23, 36, 46, 62};
    string kp = "spuda";
    Solution solve;
    char ret = solve.slowestKey(rt, kp);
    cout << ret << endl;
}