#include <iostream>
#include <string>
#include <climits>
using namespace std;

class minWindowSubstr {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) return "";

        int hashArr[128] = {0};  // Frequency map for characters in t

        for (char ch : t) {
            hashArr[ch]++;
        }

        int l = 0, r = 0;
        int ct = 0;
        int minLen = INT_MAX;
        int sIndex = -1;

        while (r < m) {
            char rightChar = s[r];
            if (hashArr[rightChar] > 0) {
                ct++;
            }
            hashArr[rightChar]--;

            // Try to contract the window
            while (ct == n) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                char leftChar = s[l];
                hashArr[leftChar]++;
                if (hashArr[leftChar] > 0) {
                    ct--;
                }
                l++;
            }

            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

int main(){
    minWindowSubstr obj;
    string s = "DDAAABBCA";
    string t = "ABC";
    string res=obj.minWindow(s,t);
    
    cout<<"The minimum window substr is: "<<res<<endl;
}