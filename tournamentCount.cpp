#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n > 1){
           int temp = n/2;
           matches += temp;
           n=n-temp;
        }
        return matches;
    }
};
int main() {
    Solution obj;
    int n = 14;

    cout<<obj.numberOfMatches(n);
    return 0;
}