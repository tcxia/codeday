#include <iostream>
using namespace std;

class Solution {
   public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (mid == (num / mid)) {
                return true;
            } else if (mid > (num / mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution slove;
    bool result = slove.isPerfectSquare(36);
    cout << result << endl;
}
