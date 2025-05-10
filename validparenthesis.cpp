#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;





class validparenthesis {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c : s){
            if(c=='{' || c=='(' || c=='['){
                st.push(c);
            }

            else {
                if(st.empty() ||
                   (c==')' && st.top()!='(') ||
                    (c=='}' && st.top()!='{') ||
                     (c==']' && st.top()!='[')) {
                        return false;
                     }
              st.pop();

            }
        }
        return st.empty();
    }
};

int main(){
    string s = {"()[]{}"};
    validparenthesis obj;
    cout << (obj.isValid(s) ? "Valid" : "Invalid") << endl;

    return 0;
}