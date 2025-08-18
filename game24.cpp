#include<bits/stdc++.h>
using namespace std;

class game24 {
public:
    double epsilon = 0.1;

    bool solve(vector<double>& cards) {   //this cards are basically copy of  Original cards
        if (cards.size() == 1) {
            return abs(cards[0] - 24) <= epsilon;
        }

        // pick any two possible num
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j)
                    continue;

                vector<double> temp;
                for (int k = 0; k < cards.size(); k++) {
                    if (k != i && k != j) {
                        temp.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];
                vector<double> possibleval = {
                    a + b, a - b, b - a,
                    a * b}; // a/b and b/a are add after perform checking

                if (abs(b) > 0.0) { // checking denominator , must be > 0
                    possibleval.push_back(a / b);
                }

                if (abs(a) > 0.0) { // checking denominator , must be > 0
                    possibleval.push_back(b / a);
                }

                for(double val : possibleval) {
                    temp.push_back(val);  //Do
                    if(solve(temp) == true)  return true;  //Explore
                       temp.pop_back();    //Undo

                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& Ocards) {   //initially Original cards (given in qstn)
        vector<double> nums;               //convert int to float for real division
        for (int i = 0; i < Ocards.size(); i++) {
            nums.push_back(Ocards[i]);
        }
        return solve(nums); // calling solve function
    }
};

int main(){
    game24 obj;
    vector<int> Ocards = {4,1,8,7};
    int res = obj.judgePoint24(Ocards);

    cout << (res ? "True" : "False") << endl;
    
}