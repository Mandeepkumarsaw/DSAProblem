#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class stringpair{
    public:
    int maximumNumberOfStringPairs(vector<string>& words){
        int count=0;
        unordered_set<string> seen;

        for(auto &s:words){
            string reversed =s;
            reverse(reversed.begin(),reversed.end());

            if(seen.count(reversed)){
                count++;
            }
            seen.insert(s);
        }
        return count;
    }
};

int main(){
    vector<string> words = {"cd","ac","dc","ca","zz"};
    stringpair obj;
    int result= obj.maximumNumberOfStringPairs(words);
    cout<<"Maximum number of pairs:-"<<result<<endl;
    return 0;

}