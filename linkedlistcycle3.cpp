#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
   int val;
   ListNode *next;

   ListNode(int x) : val(x) , next(NULL) {};
   ListNode(int x , ListNode *next) : val(x) , next(next) {};
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode *slow = head;
     ListNode *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow=slow->next;
        fast=fast->next->next;

        if(slow == fast) {    //1st meet confirms that it's cycled or not
           slow=head;     //reset slow to head
           ListNode *prev = NULL;
            while( slow != fast){
                slow=slow->next;
                prev = fast;
                fast=fast->next;
             
                // if(slow == fast) {
                //    return slow;
                // }
            }
            prev->next = NULL;   //cycle removed
        }
    }

   return nullptr;

    }

     void printLL(ListNode *head,ListNode  *temp) {
        ListNode *st = head; 
       
        while(st != temp){
            cout<<st->val<<"->";
            st=st->next;
            
        }
        cout<<"NULL\n";
        
    } 
};   

int main(){
    Solution LL;
 
    //create Nodes
    ListNode *node5 = new ListNode(55);
    ListNode *node4 = new ListNode(44);
    ListNode *node3 = new ListNode(33);
    ListNode *node2 = new ListNode(22);
    ListNode *head = new ListNode(11);

    //Link Nodes
    head->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;

    //cycle
    node5->next = node3;

    ListNode *temp = LL.detectCycle(head);

    LL.printLL(head,temp);

    return 0;
}
