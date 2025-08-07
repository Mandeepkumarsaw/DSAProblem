#include <bits/stdc++.h> 
using namespace std;

class generateparenthesis {
public:

   void printRes(vector<string> result){
    cout<<"All Permutation of bracket : ";
    for(const auto& val:result){
        cout<<"'"<<val<<"'";
    }
    cout<<endl;
   }


    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }


    void backtrack(vector<string>& result, string current, int open, int close, int max) {  //as we can see current & result are of str data type as we  concatinate () in it and another for storing res which is in str......and  here n==max
        if (current.length() == max * 2) {  //TO push in result str
            result.push_back(current);
            return;
        }
        if (open < max)
            backtrack(result, current + "(", open + 1, close, max);
        if (close < open)
            backtrack(result, current + ")", open, close + 1, max);
    }
};

int main(){
    generateparenthesis obj;
    int n = 3;

    vector<string> result=obj.generateParenthesis(n);
     obj.printRes(result);
    
   
    return 0;
}