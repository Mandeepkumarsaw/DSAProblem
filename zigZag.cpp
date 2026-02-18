#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
     if(s.length() == 1) return s;
     if(numRows == 1) return s;

     vector<string> rowString(numRows);
  

     int index = 0;   //iterate over char of string s
     int i = 0; //Starting point of first row
     int j = 0; //starting point of first col
     while(index < s.length()){
          //Downward motion and increment i as long as possible
         while(index < s.length() && i<numRows){
            rowString[i].push_back(s[index++]);
            i++;
        }

        //move i upward 
        i=i-2;
        j++;

        //diagonal upward motion
         while(index < s.length() && i>=0) {
            rowString[i].push_back(s[index++]);
            i--;
            j++;
         }

         i=1;
         j--;
     }
     string res = "";
     for(int i=0;i<numRows;i++){
        res.append(rowString[i]);
     }
     return res;
    }

};

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;

    Solution obj;
    string ans= "";
    ans = obj.convert(s,numRows);

     //print str
    for(char ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}