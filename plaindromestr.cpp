#include<bits/stdc++.h>
using namespace std;

class palindromestr {
public:
    int countSubstrings(string s) {
        int res=0;
        
        for(int i=0;i<s.size();i++){
           int l=i;
           int r=i;
                  while(l>=0 && r<=s.size() && s[l]==s[r]){
                     res +=1;
                     l--;
                     r++;
                    }
            l=i;
            r=i+1;
                   while(l>=0 && r<=s.size() && s[l]==s[r]){
                     res +=1;
                     l--;
                     r++;
                    }
        }
      return res;
    }
};

int main(){
    string s = "aba";     //you can take user input also
    palindromestr obj;
    int res=obj.countSubstrings(s);

    cout<<"Count is:"<<res<<endl;
    return 0;
}