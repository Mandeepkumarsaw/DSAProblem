#include <bits/stdc++.h>    
using namespace std;

class removeoccurance {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.find(part) != string::npos){
       s.erase(s.find(part),part.size());
                 }
            return s;
        }
    
};

int main(){
    removeoccurance obj;

    string s="axxxxyyyyb";
    string part="xy";
    string res=obj.removeOccurrences(s,part);

    if(s.find(part) != string::npos){
        cout<<"Remaining Substring!:-"<<res<<endl;
    }

    else{
        cout<<"Substring Not found!"<<endl;
    }
}
