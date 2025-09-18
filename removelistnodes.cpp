#include<bits/stdc++.h>
using namespace std;

struct ListNode {   //class 1 
    int val;
    ListNode * next;

    //Type - 1(Member Initialize List)                                                     Type-2(Assignment inside Constructor Body)
    ListNode(int x):val(x),next(nullptr) {}                       //ListNode(int x) {
                                                                  //val = x;    next = nullptr; }
    ListNode(int x,ListNode * next):val(x),next(next) {}
};



class List {
public:
    ListNode * head;
    List() {
        head = nullptr;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
      

        //compute length;
        int length = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next; 
            length++;
        }

        //base case when n target head of Linked list
        if(n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        //find previous of nth node & point prev
        int limit = length - n;
        ListNode* prev = NULL;
        ListNode* curr = head;
       
        for (int count = 0; count < limit; count++) {
            prev = curr;
            curr = curr->next;
         }

         //delete the target node
         prev->next = curr->next;   //linked
         delete curr;
         

        return head;
    }

    void printLL( ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL)
        {
            cout<<temp->val<<"-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
};
int main(){
    ListNode* node5 = new ListNode(5);        
    ListNode* node4 = new ListNode(4,node5);        
    ListNode* node3 = new ListNode(3,node4);        
    ListNode* node2 = new ListNode(2, node3);        
    ListNode* head  = new ListNode(1, node2);

    List ll;

    
    cout<<"Original List: \n";
    ll.printLL(head);

   
    int n = 3;
    ListNode* res =ll.removeNthFromEnd(head,n);
    cout<<"Removed List: \n";
    ll.printLL(res);


    return 0;
}