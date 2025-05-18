#include <bits/stdc++.h>
using namespace std;

class isomorphicstr {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,char> mapS ,mapT;
        for(int i=0;i<s.size();i++){
            char chS=s[i] , chT=t[i];

            if(mapS.count(chS) && mapS[chS] != chT) return false;

            if(mapT.count(chT) && mapT[chT] != chS) return false;

            mapS[chS]=chT;
            mapT[chT]=chS;
        }
        return true;
    }
};

int main(){
    string s="egg";
    string t="add";
   isomorphicstr obj;
   bool res=obj.isIsomorphic(s,t);

   cout<<boolalpha<<res<<"! String is Isomorphic"<<endl;
   return 0;
}