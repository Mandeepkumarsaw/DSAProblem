#include <bits/stdc++.h> 
using namespace std;

class aggressivecows {
  public:

      
   bool isValid(vector<int>& arr,int N, int C ,int maxAllowDist) {   //mid is assign/renamed as maxAlloweDist   O(N)           HELPER FUNC OF MAIN FUNC
         
           int cows = 1, lastStallCowsPos=arr[0];
         
   
         
           for(int i =1; i<N; i++) {
         
               if((arr[i] - lastStallCowsPos) >= maxAllowDist) {
         
               cows++;
         
                     lastStallCowsPos == arr[i];
         
                   }
         
   
         
              if(cows == C) return true;
         
           }
         
           return false;
         
       }
   
       
       int getDistance(vector<int> &arr, int N , int C) {                                           //MAIN FUNC OF ALGORITHM
           
           sort(arr.begin(),arr.end());      //O(NlogN)
       
            
       
            int st = arr[0] , end=(N-1) - arr[0], ans=-1;       //We got the Range of the ans (ans exist in between of them)
       
   
       
             while(st <=end) {                //O(log(Range) * N)
       
               int mid = st +(end-st)/ 2;
       
   
       
               if (isValid(arr ,N,C ,mid)) {   //right
       
                   ans=mid;
       
                   st=mid+1;
       
               } else {
       
                   end = mid - 1;   //left
       
               }
       
           }
       
           return ans;
       
       }
};




int main(){
    int N = 5, C = 3;
    vector<int> arr = {1,2,8,4,9};
    aggressivecows obj;

    cout<<"The LARGEST Minimum distance b/w cows: "<<obj.getDistance(arr,N,C)<<endl;
    return 0;
}