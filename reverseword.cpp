#include <bits/stdc++.h>
using namespace std;

class reverseword {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        string ans="";
        

        for(int i=0;i<n;i++){
            string word="";
             while(i<n && s[i] !=' '){
             word +=s[i];
             i++;                    }
        reverse(word.begin(),word.end());
        if(word.length()>0){
            ans += " "+word;
        }
        }
        return ans.substr(1);
    }
};

int main(){
    reverseword obj;
    string s = {"the sky is blue"};
    
    string result = obj.reverseWords(s);
    cout << "Reverse of this word is:- "<<result<<endl;
    
    return 0;
}