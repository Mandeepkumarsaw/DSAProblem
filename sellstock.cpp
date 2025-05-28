#include<bits/stdc++.h>
using namespace std;

class sellstock {
public:
    int maxProfit(vector<int>& prices) {
         int maxprofit=0;
         int bestbuy=prices[0];
       
         for(int i=1;i<prices.size();i++){
            if(prices[i]>bestbuy){
                maxprofit = max(maxprofit,prices[i]-bestbuy);
               
            }
            bestbuy = min(bestbuy,prices[i]);
         }
         return maxprofit;
    
        

    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    sellstock obj;
    int res=obj.maxProfit(prices);
    cout<<"Maximum profit : $"<<res<<endl;
}