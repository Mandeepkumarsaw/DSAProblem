#include<bits/stdc++.h>
using namespace std;

struct ListNode {
public:
     int val;
     ListNode* next;
     
     ListNode(int x):val(x),next(nullptr) {}
     ListNode(int x ,ListNode* next):val(x),next(next) {}
};


class List {
public:
    ListNode* head;
    List() : head(nullptr) {}

    ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next  || k==0) return head;

     //computr length
     int length = 1;
     ListNode* temp = head;
     while(temp->next){
        temp = temp->next;
        length++;
     }
     ListNode* tail = temp;

     //Normalze
      k %= length;
      if(k==0) return head;

      //make circular
      tail->next = head;

      //find new tail
      temp = head;
      for(int i = 0 ;i < length - k - 1;i++) {
        temp = temp->next;
      }

      //break the circle 
      ListNode* newHead = temp->next;
      temp->next = nullptr;

      return newHead;
      }

      //prnt
      void printLL(ListNode *head) {        //O(n)
        ListNode *temp = head;
        while(temp != NULL) {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;;
      }

};
int main(){
    List ll;

    // Manually creating the linked list: 1 → 2 → 3 → 4
    ll.head = new ListNode(1);
    ll.head->next = new ListNode(2);
    ll.head->next->next = new ListNode(3);
    ll.head->next->next->next = new ListNode(4);

   cout<<"Original List: \n";
   ll.printLL(ll.head);

   ListNode* res = ll.rotateRight(ll.head,2);
   cout<<"Rotated List: \n";
   ll.printLL(res);

  return 0;
}