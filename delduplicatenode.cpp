#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy =new ListNode(0);
        dummy->next = head;
         ListNode* prev = dummy;
         ListNode* curr = head;

         while(curr != NULL) {

            if(curr->next != NULL && curr->val == curr->next->val) {
                int dup = curr->val;
                while(curr != NULL && curr->val == dup) {
                    curr = curr->next;          // skip all duplicates

                }
                prev->next = curr;            // link to next unique node


            } else {
                prev = curr;
                curr = curr->next;
            }
         }

        return dummy->next;
    }

    void print_ll(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
   
    Solution ll;

    ListNode* node5 = new ListNode(50);
    ListNode* node4 = new ListNode(40,node5);
    ListNode* node3 = new ListNode(20,node4);
    ListNode* node2 = new ListNode(20,node3);
    ListNode* head = new ListNode(10,node2);

    cout<<"Original List: \n";
    ll.print_ll(head);

    cout<<"Modify List: \n";
    ListNode* res = ll.deleteDuplicates(head);
    ll.print_ll(res);

   return 0;
}