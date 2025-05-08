#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class reversestring {
public:

void isreverse(vector<char>& s){
    reverse(s.begin(),s.end());
}

};

int main(){
    vector<char>  s = {'h','e','l','l','o'};
        reversestring obj;
        obj.isreverse(s);

      for(char c:s){
        cout<<c;
      }

      cout<<endl;

      return 0;
}