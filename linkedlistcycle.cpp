#include<bits/stdc++.h>
using namespace std;

struct ListNode{
   int val;
    ListNode* next;

    ListNode(int x) : val(x),next(NULL) {};
    ListNode(int x, ListNode* next) : val(x),next(next) {};
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow =head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) return true;
        }
        return false;
    }

    void printLL(ListNode *head) {
        ListNode *temp=head;
        while(temp != NULL) {
            cout<<temp->next<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    Solution LL;
   
    // Create nodes without linking yet

    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* head = new ListNode(1);

    // Link nodes
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Create cycle: node5 points back to node2
     node5->next = node2;

    cout<<boolalpha<<LL.hasCycle(head)<<"! Cycle in List";

    return 0;
}
