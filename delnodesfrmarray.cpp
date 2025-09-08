#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode* next;

     ListNode(int x):val(x),next(nullptr) {}
     ListNode(int x,ListNode* next):val(x),next(next) {}
};

class Solution {
public:   
    ListNode* modifiedList(vector<int>& arr,ListNode* head) {
      
        unordered_set<int> s(arr.begin(),arr.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next =  head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL) {
            if(s.find(curr->val) != s.end()) {
               prev->next=curr->next;
               curr=curr->next;
            } else{
              prev=curr;
              curr=curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;

    }

};

void printList(ListNode* head) {
    while(head != NULL) {
        cout<<head->val<<"-->";
        head = head->next;
    } 
    cout<<"NULL"<<endl;
}

int main(){
    Solution obj;

    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* head = new ListNode(1,node2);

    vector<int> arr = {1,2};
    ListNode* res = obj.modifiedList(arr,head);
  
    printList(res);
    return 0;
}