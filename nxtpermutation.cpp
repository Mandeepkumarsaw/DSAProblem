#include <bits/stdc++.h> 
using namespace std;

class nxtpermutation {
public:
    void nextPermutation(vector<int>& A) {
        //FIND pivot
        int pivot = -1 ;
        int n =A.size();

        for(int i =n-2;i>=0 ; i--){
            if(A[i] < A [i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(A.begin(),A.end());  //in place changes
            return;
        }
        

        //2nd step ; next largest elements
        for(int i =n-1 ; i>pivot ; i--){
            if(A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        //3rd step:reverse (piv+1  to n-1);

        int i= pivot+1 , j=n-1;
       while(i <= j){
        swap(A[i++], A[j--]);
       }
        
    }

    void printArray(vector<int> A){
        cout<<"Nxt permutation of Array A : ";
        for(int val : A){
            cout<<val<<" ";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> A = {1,2,3,5,4};
    nxtpermutation obj;

    obj.nextPermutation(A);
    obj.printArray(A);
    return 0;
}