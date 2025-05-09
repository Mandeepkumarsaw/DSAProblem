#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

//using reverse & loop
class stringpair {
public:
    int maximumNumberOfStringPairs(std::vector<std::string>& words) {
        int n = words.size();
        int tally= 0;

        vector<string> reversedWords = words; // Preserve original words
        for (auto &s : reversedWords) {
            reverse(s.begin(), s.end()); // Reverse each word
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {        //O(n^2*k)  O(N)
                if(reversedWords[i] == words[j]) {
                    tally++;
                }
            }
        }

        return tally;
    }
};


//using unordered set
// class stringpair{
//     public:
//     int maximumNumberOfStringPairs(vector<string>& words){
//         int tally=0;
//         unordered_set<string> seen;

//         for(auto &s:words){
//             string reversed =s;               //O(n*k),k= strings O(N)
//             reverse(reversed.begin(),reversed.end());

//             if(seen.count(reversed)){
//                 tally++;
//             }
//             seen.insert(s);
//         }
//         return tally;
//     }
// };

int main(){
    vector<string> words = {"cd","ac","dc","ca","zz"};
    stringpair obj;
    int result= obj.maximumNumberOfStringPairs(words);
    cout<<"Maximum number of pairs:-"<<result<<endl;
    return 0;

}