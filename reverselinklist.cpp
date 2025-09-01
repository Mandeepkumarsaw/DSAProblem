#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x),next(nullptr) {};
    ListNode(int x , ListNode* next) : val(x) , next(next) {};
};

    ListNode* reverseList(ListNode* head) {
       ListNode *curr = head;
       ListNode *prev = nullptr;
       ListNode *next;

       while(curr != nullptr) {
         next = curr->next;
         curr->next = prev;

         prev=curr;
         curr=next;
       } 

       return prev;
    }

void printList(ListNode* head) {
    while (head != nullptr)
    {
        cout<< head->val << " ";
        head = head->next;
    }
    cout<<endl;
}    

int main(){
    //Create list: 1 -> 2 -> 3 -> 4

    ListNode* node4 = new ListNode(4);               // Node with value 4, no next
    ListNode* node3 = new ListNode(3, node4);        // Node 3 → node4
    ListNode* node2 = new ListNode(2, node3);        // Node 2 → node3
    ListNode* head  = new ListNode(1, node2);        // Head → node2


    cout<<"Original List : ";
    printList(head);

    ListNode* reverseHead =  reverseList(head);

    cout<<"Reversed List : ";
    printList(reverseHead);

    return 0;
}