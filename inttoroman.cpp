#include <bits/stdc++.h>
using namespace std;


// sol 1
class inttoroman {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string rmn = "";


        // This below for loop is not supported in C++ below 17 so we used another loop
    //     for (auto &[value, symbol] : mp) {
    //         while (num >= value) {
    //             rmn += symbol;  // Append the correct Roman numeral
    //             num -= value;    // Subtract its value from num
    //         }
    //     }
    

   for (auto it = mp.begin(); it != mp.end(); ++it) {
    int value = it->first;
    string symbol = it->second;
    while (num >= value) {
        rmn += symbol;
        num -= value;
      }
   }


return rmn;
    }
};

// sol-2
// class inttoroman {
// public:
//     string intToRoman(int num) {
//         string rmn = "";

//         while (num > 0) {
//             if (num >= 1000) {
//                 rmn += "M";
//                 num -= 1000;
//             } 
//             else if (num >= 900) {
//                 rmn += "CM";
//                 num -= 900;
//             } 
//             else if (num >= 500) {
//                 rmn += "D";
//                 num -= 500;
//             } 
//             else if (num >= 400) {
//                 rmn += "CD";
//                 num -= 400;
//             } 
//             else if (num >= 100) {
//                 rmn += "C";
//                 num -= 100;
//             } 
//             else if (num >= 90) {
//                 rmn += "XC";
//                 num -= 90;
//             } 
//             else if (num >= 50) {
//                 rmn += "L";
//                 num -= 50;
//             } 
//             else if (num >= 40) {
//                 rmn += "XL";
//                 num -= 40;
//             } 
//             else if (num >= 10) {
//                 rmn += "X";
//                 num -= 10;
//             } 
//             else if (num >= 9) {
//                 rmn += "IX";
//                 num -= 9;
//             } 
//             else if (num >= 5) {
//                 rmn += "V";
//                 num -= 5;
//             } 
//             else if (num >= 4) {
//                 rmn += "IV";
//                 num -= 4;
//             } 
//             else {
//                 rmn += "I";
//                 num -= 1;
//             }
//         }
//         return rmn;
//     }
// };

int main(){
    int num = 3749;
     inttoroman obj;
     string res=obj.intToRoman(num);

     cout<<"In roman : "<<res<<endl;

     return 0;
}