#include <bits/stdc++.h> 
using namespace std;

class largest3digit {
public:
    string largestGoodInteger(string num) {
       string maxgood = "";

        for(int i=0;i<=num.length()-3;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string current = num.substr(i,3);
                if(maxgood.empty() || current > maxgood){
                    maxgood = current;
                }
               
            }
        }
     return  maxgood;
    }

};

int main(){
    largest3digit obj;
    string num = "0121545644448999841122";

    cout<<"The Largest 3-Digot number would be: ";
    cout<<obj.largestGoodInteger(num);
    return 0;
}