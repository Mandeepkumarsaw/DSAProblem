#include<bits/stdc++.h>
using namespace std;

class Solution {   //1652
public:
    vector<int> decrypt(vector<int>& code, int k) {
       int n = code.size();

       vector<int> res(n,0);
       if(k == 0) return res;

       for(int i=0;i<n;i++){
        int Sum = 0;     //initialize with 0

        if(k>0){
            for(int j=1;j<=k;j++){
             Sum += code[(i+j)%n];   //forward propagation
            }
            
        }else {
            for(int j=1;j<=-k;j++){
              Sum += code[(i-j+n)%n];     //backward propagation
            }
            
        }

        res[i] = Sum;             //insert Sum in res

    }
       return res;

    }
};

int main(){
  Solution obj;
  vector<int> code = {5,7,1,4};
  int k = 3;

  vector<int> res = obj.decrypt(code,k);
  for(int &ele : res){
    cout<<ele<<" ";
  }

  return 0;
}

//EXP--> Each number is replaced by the sum of the next 3 numbers(which is k). 
// The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.