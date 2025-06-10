#include <bits/stdc++.h>
#include <cmath>
using namespace std;


class maxdiffbtwevenandodds {
public:
    int maxDifference(string s) 
    {
        unordered_map<char,int> freq;
       
       for (char c : s) {     // Count character frequencies
          freq[c]++;  
        }

        int maxOdd = INT_MIN, minEven = INT_MAX;  

     for (const auto &pair : freq) 
                {
                    if (pair.second % 2 == 1) {  // Odd frequency
                       maxOdd = max(maxOdd, pair.second);
                        } else {                     // Even frequency
                        minEven = min(minEven, pair.second);
                        }
                }
        
        return (maxOdd == INT_MIN || minEven == INT_MAX) ? -1 : maxOdd - minEven;
    }
  
};


int main(){
    string s = "aaaaabbc";     //a=5  b=2  ie 5-2=3(Output)
    maxdiffbtwevenandodds obj;  
    int res=obj.maxDifference(s);

    cout<<"The Maximum Difference btw even & odd : "<<res<<endl;
}