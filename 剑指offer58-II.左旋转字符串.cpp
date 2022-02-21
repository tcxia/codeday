#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for(int i = 0, j = n - 1 ; i < j; i++, j--){
            swap(s[i], s[j]);
        }
        
        for(int i = n, j = s.size() - 1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
        
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main(){

    string s = "lrloseumgh";
    Solution solve;
    string ret = solve.reverseLeftWords(s, 6);
    cout << ret << endl;

}