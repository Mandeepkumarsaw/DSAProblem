#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSteps(int n) {
        int count=0;

        while(n != 0){
            if(n%2==0){
                n=n/2;
            } else {
                n=n-1;
            }
         count =count+1;
        }
        return count;
    }
};

int main(){
    Solution obj;
    int n = 14;
    cout<<obj.numberOfSteps(n);
    return 0;
}