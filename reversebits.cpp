#include <bits/stdc++.h>    
using namespace std;

class reversebits {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32;i++){
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
        
    }
};

int main(){
    uint32_t n= 0b01000100000000000010100010100010;
    reversebits obj;
    uint32_t res=obj.reverseBits(n);

    cout<<"Reverse of bits: "<<res<<endl;
}