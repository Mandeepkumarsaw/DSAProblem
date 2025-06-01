#include <bits/stdc++.h>    
using namespace std;

class divisorgame {
public:
    bool divisorGame(int n) {
        return n%2==0 ? true : false;
    }
};

int main(){
    int n=3;
    divisorgame obj;
    obj.divisorGame(n);
    
    cout<<"Alice win the game -> "<<boolalpha<<(n%2==0 ? true : false)<<endl;
}
