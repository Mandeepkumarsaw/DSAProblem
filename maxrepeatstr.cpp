#include <bits/stdc++.h>    
using namespace std;

class maxrepeatstr {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string repeated = word;

        while(sequence.find(repeated) != string::npos){
            count++;
            repeated += word;
        }
        return count;
        
    }
};

int main(){
    string sequence="abcabcxyabc";
    string word="abc";

    maxrepeatstr obj;
    int res=obj.maxRepeating(sequence,word);

    cout<<"Max Repeat Substring: "<<res<<endl;
}