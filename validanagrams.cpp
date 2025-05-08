#include <iostream>
#include <unordered_map>
using namespace std;

class validanagrams {
public:
bool isAnagrams(string s,string t){
    if(s.size() != t.size()) return false;


unordered_map<char,int>myMap;

for(char c:s){
    myMap[c]++;
}

for(char c:t){
    myMap[c]--;

    if(myMap[c] < 0) return false;
}

return true;

}
};


int main(){
      
      string s = "listen",t="silent";
      validanagrams obj;
      bool result = obj.isAnagrams(s,t);

      if(result){
        cout<<"The strings are anagrams!"<<endl;
      }

      else{
        cout<<"The strings are NOT anagrams!" <<endl;
      }
       return 0;

      
}