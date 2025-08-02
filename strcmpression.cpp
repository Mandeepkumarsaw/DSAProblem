#include <bits/stdc++.h> 
using namespace std;

class strcmpression {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        int idx = 0;

        for(int i=0;i<n;i++){
             char ch = chars[i]; 
             int count = 0;

            while(i<n && chars[i]==ch){
                count++; i++; 
            }
            if(count == 1){
                chars[idx++] = ch;
            } else {
                chars[idx++] =  ch;
                string str =  to_string(count);
                for (char dig : str){
                    chars[idx++] = dig;
                }
            }

            i--;
        }

        chars.resize(idx);
        
        return idx;
    }

    void printStr(vector<char> chars){   //func for printing of new vector chars
        cout<<"Compressed Str is : ";
        for(char pr : chars){
            cout<<pr;
        }
        cout<<endl;
    }
};

int main(){
    strcmpression obj;
    vector<char> chars = {'a','a','b','b','b','c','c','c'};
    
    
    obj.printStr(chars);
    cout<<"The new str size will be : "<<obj.compress(chars)<<endl;

    return 0;
}