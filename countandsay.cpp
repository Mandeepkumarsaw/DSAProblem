#include<bits/stdc++.h>
using namespace std;

class countandsay {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string say = countAndSay(n-1);  //calling

        //processing
        string result = "";

        for(int i=0;i<say.size();i++){
                 char ch=say[i];
                 int count =1;

                 while(i<say.size()-1 && say[i]==say[i+1]){
                    count++;
                    i++;
                 }
                 result += to_string(count) + string(1,ch);
        } 
        return result;
    }
};

int main(){
    int n=4;
    countandsay obj;
    string out=obj.countAndSay(n);

    cout<<out<<endl;
}