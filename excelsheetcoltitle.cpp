#include <bits/stdc++.h> 
using namespace std;

class excelsheetcoltitle {
public:
    string convertToTitle(int columnNumber) {
      string res="";

      while(columnNumber > 0){
        columnNumber--;
        char letter ='A' + (columnNumber % 26);
        res = letter + res;
        columnNumber/=26;
      } 

        
      return res;;
    }
};

int main(){
    excelsheetcoltitle obj;
    int columnNumber = 28;

    cout<<"New String is : "<<obj.convertToTitle(columnNumber);
    return 0;
}