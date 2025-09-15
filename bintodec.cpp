#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class List {     //class 1 
    public:    
          ListNode *head;
          ListNode *tail;
    public:
      List() {            //    List() : head(NULL) {}
        head = tail =  NULL;
      }

    public:
      int getDecimalValue(ListNode* head) {
          int decimalVal = 0;
          ListNode* curr = head;
  
          while(curr != NULL){
               decimalVal = (decimalVal << 1) | curr->val;
                curr = curr->next;
  
          }
          return decimalVal;
      }
    void printList(ListNode* head) {
       while (head != nullptr)
       {
           cout<< head->val << "-->";
           head = head->next;
       }
       cout<<"NULL"<<endl;
    }
};

int main(){
    List ll;

              
    ListNode* node3 = new ListNode(1);        // Node 3 → node4
    ListNode* node2 = new ListNode(0, node3);        // Node 2 → node3
    ListNode* head  = new ListNode(1, node2);
    
    ll.head=head;

    ll.printList(ll.head);
    cout<<"In decimal: "<<ll.getDecimalValue(ll.head);

    return 0;
}