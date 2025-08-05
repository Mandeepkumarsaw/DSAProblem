#include <bits/stdc++.h> 
using namespace std;


class lstwordlength {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int length=0;

        while(i>=0 && s[i]==' '){
            i--;
        }

        while(i>=0 && s[i]!=' '){
            length++;
            i--;
        }
        return length;
    }
};

int main(){
    lstwordlength obj;
    string s = "Hello World";

    cout<<"Length Of the lst word: "<<obj.lengthOfLastWord(s)<<endl;
    return 0;
}