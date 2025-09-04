#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode* next;

    ListNode(int x) : val(x),next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow == fast) {
                slow = head;

                while( slow != fast){
                    slow = slow->next;
                    fast = fast->next;

                    if(slow == fast) {
                        return slow;
                    }
                }
            }
        }
      return nullptr;
    }

    void printLL(ListNode *head,ListNode  *temp) {
        ListNode *st = head; 
        int idx = 0;
        while(st != temp){
            cout<<st->val<<"->";
            st=st->next;
            idx++;
        }
        cout<<"NULL\n";
        cout<<"At index: "<<idx;
    }
};     

int main(){
    Solution LL;
 
    //Creating Node
    ListNode* node5 = new ListNode(50);
    ListNode* node4 = new ListNode(40);
    ListNode* node3 = new ListNode(30);
    ListNode* node2 = new ListNode(20);
    ListNode* head = new ListNode(10);

    //Linking Node
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    //cycle
    node5->next =  node3;

   ListNode *temp = LL.detectCycle(head);

   LL.printLL(head,temp);

   return 0;
}