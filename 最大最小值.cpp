// 题目定义：给定一个大小为n的数组，无序，找到其中的最大值和最小值，要求元素间的比较次数尽可能少
// 时间复杂度为0(3n/2)

/**
 * 记录已知的最大值和最小值，然后对输入元素成对地处理。
 * 首先，将一对输入元素相互比较，然后把较小的与当前最小值比较，把较大的与当前最大值比较，这样，对每个元素共需3次比较
 *
 * 已知的最大值和最小值依赖n是奇数还是偶数，
 *  如果是奇数，将最大值和最小值的初值都设置为第一个元素的值，
 *  如果是偶数，就将前两个元素做一次比较，决定最大值和最小值的初值
 */

#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int max, min;
};

class Solution {
   public:
    int min, max;
    void findMaxMin(vector<int> &arr, int n, int &min, int &max) {
        int begin = 0;
        if (n % 2 == 1) {
            min = max = arr[0];
            begin = 1;
        } else {
            if (arr[0] < arr[1]) {
                min = arr[0];
                max = arr[1];
            } else {
                min = arr[1];
                max = arr[0];
            }
            begin = 2;
        }

        for (int i = begin; i < n - 1; i += 2) {
            if (arr[i] < arr[i + 1]) {
                if (arr[i] < min) {
                    min = arr[i];
                }
                if (arr[i + 1] > max) {
                    max = arr[i + 1];
                }
            } else {
                if (arr[i + 1] < min) {
                    min = arr[i + 1];
                }
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
        }
    }

    Pair findMaxMinV2(int arr[], int begin, int end) {
        Pair P;
        if (end - begin <= 1) {
            P.max = arr[begin] > arr[end] ? arr[begin] : arr[end];
            P.min = arr[begin] < arr[end] ? arr[begin] : arr[end];
            return P;
        }

        Pair PL = findMaxMinV2(arr, begin, begin + (end - begin) / 2);
        Pair PR = findMaxMinV2(arr, begin + (end - begin) / 2 + 1, end);

        P.max = PL.max > PR.max ? PL.max : PR.max;
        P.min = PL.min < PR.min ? PL.min : PR.min;

        return P;
    }
};

int main() {
    Pair P;
    int a[] = {3, 6, 1, 8, 0};
    int n = 5;

    Solution solve;
    P = solve.findMaxMinV2(a, 0, n - 1);
    cout << P.max << "," << P.min << endl;
}