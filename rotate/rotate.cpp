#include <iostream>
#include <vector>

using namespace std;

class rotateNums {
   public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size(); //
        backSort(nums, 0, nums.size() - 1);
        backSort(nums, 0, k - 1);
        backSort(nums, k, nums.size() - 1);
    }

    void backSort(vector<int> &nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

int main() {
    rotateNums rn;
    int a[4] = {-1, -100, 3, 99};
    vector<int> nums(a, a + 4);
    rn.rotate(nums, 2);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}