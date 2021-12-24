#include <iostream>

using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        int left = 0;
        int right = x - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (mid == (x / mid)) {
                return mid;
            } else if (mid > (x / mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};

int main() {
    Solution solve;
    int result = solve.mySqrt(15);
    cout << result << endl;
}