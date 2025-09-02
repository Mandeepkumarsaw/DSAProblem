#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x),next(nullptr) {};
    ListNode(int x , ListNode* next) : val(x) , next(next) {};
};




class Solution {
public:
                                                 //APROACH -1--  O(n)+O(n/2)=O(n) time, O(1) space 
    // ListNode* middleNode(ListNode* head) {

    //     ListNode* temp = head;
    //     int size = 0;
    //     while(temp != NULL) {
    //         size++;
    //         temp = temp->next;
    //     }

    //     int mid=size/2;

    //    temp=head;
    //    for(int i=0;i<mid;i++){
    //     temp=temp->next;
    //    }

    //    return temp;
    // }

                                                 //APROACH - 2-- { (O(n) time, O(1) space }  

    ListNode* middleNode(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != NULL && fast->next != NULL) {
        slow=slow->next;
        fast=fast->next->next;
      }
      return slow;
    }


    void printList(ListNode* head) {
    while (head != nullptr)
    {
        cout<< head->val << "->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    }  
};

int main(){
   Solution LL;

    ListNode* node5 = new ListNode(5,NULL);
    ListNode* node4 = new ListNode(4,node5);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* head = new ListNode(1,node2);

    ListNode* ans = LL.middleNode(head);
    cout<<"New Linked List: ";
    LL.printList(ans);

   return 0;  
}
 