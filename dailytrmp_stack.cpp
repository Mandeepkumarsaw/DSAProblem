#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     int n = temperatures.size();   
     stack<int> s;
     vector<int> ans(n,0);   

     for(int i=n-1; i>=0; i--) {
        while(!s.empty() &&  temperatures[i] >= temperatures[s.top()]) {    //temperatures[index]
            s.pop();
        }
        if(!s.empty()) {
            ans[i]=s.top()-i;
        } 

        s.push(i);                              //store index value not actual values
     }

     return ans;
    }
};

int main() {
    Solution obj;
    vector<int> temperatures = {73,74,75,71,69,72,76};
    cout<<"Dailt Temperatures: ";
    cout<<"{";
    for(int sol:temperatures){
        cout<<sol<<",";
    }cout<<"}"<<endl;

    vector<int> res = obj.dailyTemperatures(temperatures);
    cout<<"[";  
    for(int val:res){
        cout<<val<<",";
    } 
    cout<<"]"<<endl;

    return 0;
}