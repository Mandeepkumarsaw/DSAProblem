#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class merge2ll {
public:  
                              //Recursive Approach
    ListNode* mergeTwoLists(ListNode *head1,ListNode *head2) {

      if(head1 == NULL || head2 == NULL){                 //base case
        return head1 == NULL ? head2 : head1;
      }

 
      if(head1->val <= head2->val) {
          head1->next=mergeTwoLists(head1->next,head2);      //call recursive func again with incre of resultant node
        return head1;                                        //The output of recursive func after calling is resultant node ie  head1->next  = resultant node & again calling until both node become null
      } else {
       head2->next=mergeTwoLists(head1,head2->next);      //calling recursive func with incre
        return head2;                                     //head2->next = output of recursive func runs again n again till both node ends.
      }
    }
};




 
                        //Iterative Approach
class merge2linkedlist {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) tail->next = l1, l1 = l1->next;
            else tail->next = l2, l2 = l2->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};







void printList(ListNode* head) {
    while (head) cout << head->val << " -> ", 
    head = head->next;
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);       //1 -> 3 -> 5 

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);        //2 -> 4 -> 6 

    // merge2linkedlist m;
    // ListNode* merged = m.mergeTwoLists(l1, l2);
    // printList(merged);                  //1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    merge2ll obj;
    ListNode *ans = obj.mergeTwoLists(l1,l2);
    printList(ans);                       //1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL


    return 0;
}