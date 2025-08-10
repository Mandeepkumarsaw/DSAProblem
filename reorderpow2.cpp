#include <bits/stdc++.h> 
using namespace std;


class reorderpow2 {
public:

   string countDigits(int num) { //helper func of main func
        string s = to_string(num);
        sort(s.begin(),s.end());
        return s;
    }


    bool reorderedPowerOf2(int n) {
        string target = countDigits(n);
        for(int i=0;i<=31;i++) {
            int power = 1 << i;  //1<<0 == 2 ka power 0 which is 1, 1<<1 == 2 ka pow 1 which is 2 & ,,,,,etc until 1<<31(bcoz int is of 32 bit 0 to 31)
            if(countDigits(power) == target) return true;  //countDigits(power) is used to convert value of power into str so that we can compare it to target string(to make datatype of both var same),,if we ddirectly use power == target tehn one is of int & another is of str(but value are same in both such as if n=821 after sort it become 128 & when power = 1<<7(128) so it convert to str to compare if not then it looks like 128 & "128" ) but due to this line ---->countDigits(power)<---- it  converting and becomes "128"=="128" & ret true?
        }
        return false;
    }
};

int main(){
    reorderpow2 obj;
    int n = 821;

    cout<<boolalpha<<obj.reorderedPowerOf2(n)<<endl;
    return 0;
}