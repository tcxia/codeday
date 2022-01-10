#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mulValue = releaseTimes[0];
        int mulIndex = INT32_MIN;
        int retIndex = 0;
        for (int i = 1; i < releaseTimes.size(); i++) {
            int spendTime = releaseTimes[i] - releaseTimes[i - 1];
            if (spendTime >= mulValue) {
                mulValue = spendTime;
                if ((keysPressed[i] - '0') >= mulIndex) {
                    mulIndex = keysPressed[i] - '0';
                    retIndex = i;
                }
            }
        }
        return keysPressed[retIndex];
    }
};

int main() {
    vector<int> rt = {9, 29, 49, 50};
    string kp = "ccbd";
    Solution solve;
    char ret = solve.slowestKey(rt, kp);
    cout << ret << endl;
}