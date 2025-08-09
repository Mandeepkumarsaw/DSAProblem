#include <bits/stdc++.h> 
using namespace std;

class binarywatch {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    result.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") +
                                     to_string(m));
                }
            }
        }
        return result;
    }
};

int main(){
    binarywatch obj;
    int turnedOn = 1;

      cout<<"Final watch time :";
     for(auto& val: obj.readBinaryWatch(turnedOn)) {
            cout<<"'"<<val<<"'";
        }
        return 0;
}