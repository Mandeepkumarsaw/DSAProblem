#include<bits/stdc++.h>
using namespace std;

class longstpalindrometsr {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;

      int result=0;

    //example for swap -- if words = {"hello", "world", "cpp"};   after using the swap method which is written here the output will be --Modified Words: ehllo owrld pcp
          

      for(string &word : words){                    // Reference to modify elements directly  
        string reverseWord = word;
        swap(reverseWord[0],reverseWord[1]);         // Swaps first two characters

        if(mp[reverseWord] > 0){
            result += 4;
            mp[reverseWord]--;
        }
        else{
            mp[word]++;
        }
      }

      //check equal character words, use only once bcoz we cannot use  same ch "qq" in between more than once ie "lcggcl", if there are  more same ch "pp",then it cannot be added in between bcoz length of substr is 2 it may --> "lcggppcl" or "lcppggcl" (which not be a palindrome)..

      for(auto &it : mp){
        string worod=it.first;
        int count=it.second;

        if(worod[0] == worod[1] && count > 0){
            result +=2;
            break;
        }
      } 
     return result;
    }
};

int main(){
    vector<string> words={"lc","cl","gg","pp"};

    longstpalindrometsr obj;
    int res=obj.longestPalindrome(words);
   
    cout<<"Count of Palindrome: "<<res<<endl;


}